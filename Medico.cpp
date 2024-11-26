#include "AbsPersona.h"
#include "IDataProvider.h"
#include "Medico.h"
#include <list>

using namespace std;

bool Medico::Save() {
	return ProveedorDatos->UpdateMedico(this);
}
bool Medico::Delete() {
	return ProveedorDatos->DeleteMedico(this);
}
string Medico::ToReport() {
	return "DNI: " + DNI + "\nNombre: " + Nombre + "\nEspecialidad: " + Especialidad;
}