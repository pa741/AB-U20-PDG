#pragma once
#include <string>
#include <list>
class Medico;
class Paciente;
class Cita;
using namespace std;
class IDataProvider
{
public:

	virtual list<Medico> GetMedicos() ;
	virtual list<Paciente> GetPacientes() ;
	virtual list<Cita> GetCitas() ;
	virtual Medico GetMedico(string dni) ;
	virtual Paciente GetPaciente(string dni) ;
	virtual Cita GetCita(string dniPac, string dniMed) ;

	virtual bool UpdateMedico(Medico* medico) ;
	virtual bool UpdatePaciente(Paciente* paciente) ;
	virtual bool UpdateCita(Cita* cita) ;
	virtual bool DeleteMedico(Medico* med) ;
	virtual bool DeleteCita(Cita* cita ) ;
	virtual bool DeletePaciente(Paciente* paciente) ;

};