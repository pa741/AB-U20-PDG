#pragma once
#include <string>
#include "IDataProvider.h"



Medico* IDataProvider::GetMedico(string dni) const { return NULL; }
Paciente* IDataProvider::GetPaciente(string dni) const { return NULL; }
Cita* IDataProvider::GetCita(string dniPac, string dniMed) const { return NULL; }
bool IDataProvider::UpdateMedico() { return false; }
bool IDataProvider::UpdatePaciente() { return false; }
bool IDataProvider::UpdateCita() { return false; }
bool IDataProvider::DeleteMedico() { return false; }
bool IDataProvider::DeleteCita() { return false; }
bool IDataProvider::DeletePaciente() { return false; }
