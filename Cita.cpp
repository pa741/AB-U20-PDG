#include "AbsPersona.h"
#include "IDataProvider.h"
#include "Cita.h"
#include <list>
#include <string>
bool Cita::Save()
{
	return ProveedorDatos->UpdateCita(this);
}
bool Cita::Delete()
{
	return ProveedorDatos->DeleteCita(this);
}
string Cita::ToReport()
{
	return "Cita con " + MedicalPatient.Nombre + " con el doctor " + Doctor.Nombre + " Descripcion: " + Descripcion;
}