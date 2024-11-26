#pragma once
#include <string>
#include <list>
#include "IDataProvider.h"
#include "Medico.h"
#include "Cita.h"
#include "Paciente.h"



list<Medico> IDataProvider::GetMedicos() const { return list<Medico>();}
list<Cita> IDataProvider::GetCitas() const { return list<Cita>();}
list<Paciente> IDataProvider::GetPacientes() const { return list<Paciente>();}

Medico IDataProvider::GetMedico(string dni) const { return nullptr; }
Paciente IDataProvider::GetPaciente(string dni) const { return nullptr; }
Cita IDataProvider::GetCita(string dniPac, string dniMed) const { return nullptr; }
bool IDataProvider::UpdateMedico(Medico* medico) const { return false; }
bool IDataProvider::UpdatePaciente(Paciente* paciente) const { return false; }
bool IDataProvider::UpdateCita(Cita* cita)const { return false; }
bool IDataProvider::DeleteMedico(Medico* medico)const { return false; }
bool IDataProvider::DeleteCita(Cita* cita) const { return false; }
bool IDataProvider::DeletePaciente(Paciente* paciente) const { return false; }
