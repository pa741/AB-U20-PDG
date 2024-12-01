#pragma once
using namespace std;
#include "IDataProvider.h";

class FileProvider : public IDataProvider {

public: 
	string basePath;
	static FileProvider* getInstance()
	{
		static FileProvider instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		if (singleton_ == nullptr) {
			singleton_ = new FileProvider();
		}
		return singleton_;
	}
	static FileProvider* singleton_;


	FileProvider() {
		basePath = "C:\\data\\";
}

	virtual list<Medico> GetMedicos() const;
	virtual list<Paciente> GetPacientes() const;
	virtual list<Cita> GetCitas() const;
	virtual Medico GetMedico(string dni) const;
	virtual Paciente GetPaciente(string dni) const;
	virtual Cita GetCita(string dniPac, string dniMed) const;

	virtual bool UpdateMedico(Medico* medico) const;
	virtual bool UpdatePaciente(Paciente* paciente) const;
	virtual bool UpdateCita(Cita* cita) const;
	virtual bool DeleteMedico(Medico* med) const;
	virtual bool DeleteCita(Cita* cita) const;
	virtual bool DeletePaciente(Paciente* paciente) const;
};