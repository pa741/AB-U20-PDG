#pragma once
#include <string>
class Medico;
class Paciente;
class Cita;
using namespace std;
class IDataProvider
{
public:

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