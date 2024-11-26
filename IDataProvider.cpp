#pragma once
#include <string>
#include "IDataProvider.h"



Medico* IDataProvider::GetMedico(string dni) const { return nullptr; }
Paciente* IDataProvider::GetPaciente(string dni) const { return nullptr; }
Cita* IDataProvider::GetCita(string dniPac, string dniMed) const { return nullptr; }
bool IDataProvider::UpdateMedico(Medico* medico) const { return false; }
bool IDataProvider::UpdatePaciente(Paciente* paciente) const { return false; }
bool IDataProvider::UpdateCita(Cita* cita)const { return false; }
bool IDataProvider::DeleteMedico(Medico* medico)const { return false; }
bool IDataProvider::DeleteCita(Cita* cita) const { return false; }
bool IDataProvider::DeletePaciente(Paciente* paciente) const { return false; }
