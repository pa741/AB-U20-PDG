#include <string>
#include <list>
#include "IDataProvider.h"
#include "Medico.h"
#include "Cita.h"
#include "Paciente.h"



list<Medico> IDataProvider::GetMedicos()  { return list<Medico>();}
list<Paciente> IDataProvider::GetPacientes() 
{
	return list<Paciente>();
}
list<Cita> IDataProvider::GetCitas()  { return list<Cita>();}
//list<Paciente> IDataProvider::GetPacientes() const { return list<Paciente>();}

Medico IDataProvider::GetMedico(string dni)  { return NULL; }
Paciente IDataProvider::GetPaciente(string dni)  { return NULL; }
Cita IDataProvider::GetCita(string dniPac, string dniMed)  { return NULL; }
bool IDataProvider::UpdateMedico(Medico* medico)  { return false; }
bool IDataProvider::UpdatePaciente(Paciente* paciente)  { return false ; }
bool IDataProvider::UpdateCita(Cita* cita) { return false; }
bool IDataProvider::DeleteMedico(Medico* medico) { return false; }
bool IDataProvider::DeleteCita(Cita* cita)  { return false; }
bool IDataProvider::DeletePaciente(Paciente* paciente)  { return false; }
