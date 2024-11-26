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

	virtual list<Medico*> GetMedicos() const;
	virtual list<Paciente*> GetPacientes() const;
	virtual list<Cita*> GetCitas() const;
	virtual Medico* GetMedico(string dni) const;
	virtual Paciente* GetPaciente(string dni) const;
	virtual Cita* GetCita(string dniPac, string dniMed) const;

	virtual bool UpdateMedico(Medico* medico) const;
	virtual bool UpdatePaciente(Paciente* paciente) const;
	virtual bool UpdateCita(Cita* cita) const;
	virtual bool DeleteMedico(Medico* med) const;
	virtual bool DeleteCita(Cita* cita ) const;
	virtual bool DeletePaciente(Paciente* paciente) const;

};