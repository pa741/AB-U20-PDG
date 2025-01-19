#include "FileProvider.h"

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
// for convenience


using json = nlohmann::json;
namespace fs = std::filesystem;
FileProvider* FileProvider::singleton_ = nullptr;


namespace nlohmann {
	template <>
	struct adl_serializer<Medico> {
		// note: the return type is no longer 'void', and the method only takes
		// one argument
		static Medico from_json(const json& j) {
			{
				IDataProvider* prov = FileProvider::getInstance();
				Medico p = *new Medico(prov);

				j.at("DNI").get_to(p.DNI);
				j.at("Nombre").get_to(p.Nombre);
				j.at("Especialidad").get_to(p.Especialidad);
				return p;
			}
		}

		// Here's the catch! You must provide a to_json method! Otherwise, you
		// will not be able to convert move_only_type to json, since you fully
		// specialized adl_serializer on that type
		static void to_json(json& j, Medico t) {
			j = json{
				{ "DNI", t.DNI },
				{ "Nombre", t.Nombre },
				{ "Especialidad", t.Especialidad }
			};
		}
	};
	template <>
	struct adl_serializer<Paciente> {
		// note: the return type is no longer 'void', and the method only takes
		// one argument
		static Paciente from_json(const json& j) {
			{
				IDataProvider* prov = FileProvider::getInstance();
				Paciente p = *new Paciente(prov);

				j.at("DNI").get_to(p.DNI);
				j.at("Nombre").get_to(p.Nombre);
				//j.at("Enfermedades").get_to(p.Enfermedades);
				return p;
			}
		}

		// Here's the catch! You must provide a to_json method! Otherwise, you
		// will not be able to convert move_only_type to json, since you fully
		// specialized adl_serializer on that type
		static void to_json(json& j, Paciente t) {
			j = json{
				{ "DNI", t.DNI },
				{ "Nombre", t.Nombre },
				//{ "Enfermedades", t.Enfermedades }
			};
		}
	};
	template <>
	struct adl_serializer<Cita> {
		// note: the return type is no longer 'void', and the method only takes
		// one argument
		static Cita from_json(const json& j) {
			{
				IDataProvider* prov = FileProvider::getInstance();
				Cita p = *new Cita(prov);
				string dniMed = j["Medico"];
				string dniPac = j["Paciente"];
				string desc = j["Descripcion"];
				Medico med = prov->GetMedico(dniMed);
				Paciente pac = prov->GetPaciente(dniPac);
				p.Doctor = med;
				p.MedicalPatient = pac;
				p.Descripcion = desc;
				return p;

				//j.at("Nombre").get_to(p.Nombre);
				//j.at("Enfermedades").get_to(p.Enfermedades);
			}
		}

		// Here's the catch! You must provide a to_json method! Otherwise, you
		// will not be able to convert move_only_type to json, since you fully
		// specialized adl_serializer on that type
		static void to_json(json& j, Cita t) {
			j = json{
				//{ "Paciente", t.pa },
				{ "Medico", t.Doctor.DNI },
				{ "Paciente", t.MedicalPatient.DNI },
				{ "Descripcion", t.Descripcion }
			};
		}
	};
}




bool PathExists(string path) {
	std::filesystem::path filepath = std::string(path);
	return fs::is_regular_file(filepath);
}
string ReadFile(string path) {
	ifstream MyReadFile(path);
	string myText;

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
	
	}
	// Close the file
	MyReadFile.close();
	return myText;
}
fstream  GetFile(string path) {
	fstream  file;
	file.open(path, std::fstream::out | std::fstream::in | std::fstream::trunc);
	return file;
}
list<Medico> FileProvider::GetMedicos() 
{
	list<Medico> result = *(new list<Medico>());
	std::string path = "data/medicos";
	for (auto& entry : fs::directory_iterator(path)) {
		string p = entry.path().filename().string();
		int pos = p.find(".");
		string dni = p.substr(0,pos);
		result.push_back(GetMedico(dni));

	}
	return result;
}
int FileProvider::GetMedicosCount() 
{
	std::string path = "data/medicos";
	int count = 0;
	for (auto& entry : fs::directory_iterator(path)) {
		count++;
	}
	return count;
}

list<Paciente> FileProvider::GetPacientes() 
{
	list<Paciente> result = *(new list<Paciente>());
	std::string path = "data/pacientes";
	for (auto& entry : fs::directory_iterator(path)) {
		string p = entry.path().filename().string();
		int pos = p.find(".");
		string dni = p.substr(0,pos);
		Paciente pac = GetPaciente(dni);
		result.push_back(pac);
	}
	return result; 
}
int FileProvider::GetPacientesCount() 
{
	std::string path = "data/pacientes";
	int count = 0;
	for (auto& entry : fs::directory_iterator(path)) {
		count++;
	}
	return count;
}

list<Cita> FileProvider::GetCitas() 
{
	list<Cita> result = *(new list<Cita>());
	std::string path = "data/citas";
	for (auto& entry : fs::directory_iterator(path)) {
		string p = entry.path().filename().string();
		int pos = p.find(".");
		string dnis = p.substr(0,pos);
		int delimiterPos = dnis.find("-");
		string dniPac = dnis.substr(0, delimiterPos);
		string dnimed = dnis.substr(delimiterPos + 1);
		result.push_back(GetCita(dniPac,dnimed));
	}
	return result;
}
int FileProvider::GetCitasCount() 
{
	std::string path = "data/citas";
	int count = 0;
	
	for (auto& entry : fs::directory_iterator(path)) {
		count++;
	}
	return count;
}

Medico FileProvider::GetMedico(string dni) 
{
	//std::filesystem::path filepath = std::string("data\\medicos\\" + dni);
	string path = "data/medicos/" + dni + ".json";
	bool exists = PathExists(path);
	if (!exists) {
		throw runtime_error("No existe el path");
	}
	string text = ReadFile(path);
	json js = json::parse(text);

	Medico m = js;
	return m;

}

Paciente FileProvider::GetPaciente(string dni) 
{
	string path = "data/pacientes/" + dni + ".json";
	bool exists = PathExists(path);
	if (!exists) {
		throw runtime_error("No existe el path");
	}
	string text = ReadFile(path);
	json js = json::parse(text);
	Paciente p = js;

	return p;

}

Cita FileProvider::GetCita(string dniPac, string dniMed) 
{

	std::filesystem::path path = "data/citas/" + dniPac + "-" + dniMed + ".json";
	bool exists = PathExists(path.string());
	if (!exists) {
		throw runtime_error("No existe el path");
	}
	string text = ReadFile(path.string());
	json js = json::parse(text);
	Cita p = js;
	return p;
}

bool FileProvider::UpdateMedico(Medico* medico) 
{
	//printf("Update medico");
	std::filesystem::path path = "data/medicos/" + medico->DNI + ".json";
	//printf("Path: %s", path.string().c_str());
	fstream file = GetFile(path.string());
	//printf("File");
	json js = *medico;
	//printf("Json: %s", js.dump().c_str());
	file << js.dump();
	file.close();
	return true;
}

bool FileProvider::UpdatePaciente(Paciente* pac) 
{
	std::filesystem::path path = "data/pacientes/" + pac->DNI + ".json";
	fstream file = GetFile(path.string());

	json js = *pac;
	string text = js.dump();
	file << text;
	file.close();
	return true;
}

bool FileProvider::UpdateCita(Cita* cita) 
{
	std::filesystem::path path = "data/citas/" + cita->MedicalPatient.DNI + "-" + cita->Doctor.DNI + ".json";
	fstream file = GetFile(path.string());
	json js = *cita;
	file << js.dump();
	file.close();
	return true;
}

bool FileProvider::DeleteMedico(Medico* medico) 
{
	std::filesystem::path path = "data/medicos/" + medico->DNI + ".json";
	return std::filesystem::remove(path.string());
}

bool FileProvider::DeletePaciente(Paciente* pac) 
{
	std::filesystem::path path = "data/pacientes/" + pac->DNI + ".json";
	return std::filesystem::remove(path.string());
}

bool FileProvider::DeleteCita(Cita* cita) 
{
	std::filesystem::path path = "data/citas/" + cita->MedicalPatient.DNI + "-" + cita->Doctor.DNI + ".json";
	return std::filesystem::remove(path.string());

}


/*
// Medico Json convesion
void to_json(json& j, const Medico& p)
{
	j = json{
		{ "DNI", p.DNI },
		{ "Nombre", p.Nombre },
		{ "Especialidad", p.Especialidad }
	};
}

void from_json(const json& j, Medico& p)
{
	j.at("DNI").get_to(p.DNI);
	j.at("Nombre").get_to(p.Nombre);
	j.at("Especialidad").get_to(p.Especialidad);
}
*/