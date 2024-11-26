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

	virtual bool UpdateMedico();
	virtual bool UpdatePaciente();
	virtual bool UpdateCita();
	virtual bool DeleteMedico();
	virtual bool DeleteCita();
	virtual bool DeletePaciente();

};