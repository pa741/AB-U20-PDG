#include "FileProvider.h"

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "Medico.h"
#include "Paciente.h"
#include "Cita.h"
// for convenience


using json = nlohmann::json;
namespace fs = std::filesystem;


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
				j.at("Enfermedades").get_to(p.Enfermedades);
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
				{ "Enfermedades", t.Enfermedades }
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
				Medico* med = prov->GetMedico(dniMed);
				Paciente* pac = prov->GetPaciente(dniPac);
				p.Medico = med;
				p.Paciente = pac;
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
				{ "Medico", t.Medico->DNI },
				{ "Paciente", t.Paciente->DNI },
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
		cout << myText;
	}
	// Close the file
	MyReadFile.close();
	return myText;
}
ofstream  GetFile(string path) {
	ofstream  file;
	file.open(path, std::ofstream::out | std::ofstream::trunc);
	return file;
}

Medico* FileProvider::GetMedico(string dni) const
{
	//std::filesystem::path filepath = std::string("data\\medicos\\" + dni);
	string path = "data\\medicos\\" + dni + ".json";
	bool exists = PathExists(path);
	if (!exists) {
		return nullptr;
	}
	string text = ReadFile(path);
	json js = json::parse(text);

	Medico m = js;
	return &m;

}

Paciente* FileProvider::GetPaciente(string dni) const
{
	string path = "data\\pacientes\\" + dni + ".json";
	bool exists = PathExists(path);
	if (!exists) {
		return nullptr;
	}
	string text = ReadFile(path);
	json js = json::parse(text);
	Paciente p = js;
	return &p;

}

Cita* FileProvider::GetCita(string dniPac, string dniMed) const
{
	string path = "data\\citas\\" + dniPac + "-" + dniMed + ".json";
	bool exists = PathExists(path);
	if (!exists) {
		return nullptr;
	}
	string text = ReadFile(path);
	json js = json::parse(text);
	Cita p = js;
	return &p;
}

bool FileProvider::UpdateMedico(Medico* medico) const
{
	string path = "data\\medicos\\" + medico->DNI + ".json";
	ofstream file = GetFile(path);
	json js = *medico;
	file << js;
	file.close();
	return true;
}

bool FileProvider::UpdatePaciente(Paciente* pac) const
{
	string path = "data\\pacientes\\" + pac->DNI + ".json";
	ofstream file = GetFile(path);
	json js = *pac;
	file << js;
	file.close();
	return true;
}

bool FileProvider::UpdateCita(Cita* cita) const
{
	string path = "data\\citas\\" + cita->Paciente->DNI + "-" + cita->Medico->DNI + ".json";
	ofstream file = GetFile(path);
	json js = *cita;
	file << js;
	file.close();
	return true;
}

bool FileProvider::DeleteMedico(Medico* medico) const
{
	string path = "data\\medicos\\" + medico->DNI + ".json";
	return std::filesystem::remove(path);
}

bool FileProvider::DeletePaciente(Paciente* pac) const
{
	string path = "data\\medicos\\" + pac->DNI + ".json";
	return std::filesystem::remove(path);
}

bool FileProvider::DeleteCita(Cita* cita) const
{
	string path = "data\\citas\\" + cita->Paciente->DNI + "-" + cita->Medico->DNI + ".json";
	return std::filesystem::remove(path);

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