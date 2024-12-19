#pragma once
using namespace std;
#include "IDataProvider.h"
#include <list>
#include <string>

class FileProvider : public IDataProvider
{

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

	virtual list<Medico> GetMedicos() ;
	virtual list<Paciente> GetPacientes() ;
	virtual list<Cita> GetCitas() ;
	virtual Medico GetMedico(string dni) ;
	virtual Paciente GetPaciente(string dni) ;
	virtual Cita GetCita(string dniPac, string dniMed);

	virtual bool UpdateMedico(Medico* medico) ;
	virtual bool UpdatePaciente(Paciente* paciente) ;
	virtual bool UpdateCita(Cita* cita) ;
	virtual bool DeleteMedico(Medico* med) ;
	virtual bool DeleteCita(Cita* cita) ;
	virtual bool DeletePaciente(Paciente* paciente) ;
};