#include "AbsPersona.h"
#include "IDataProvider.h"
#include "Paciente.h"
#include <list>

using namespace std;
bool Paciente::Save() {
	return ProveedorDatos->UpdatePaciente(this);
}
bool Paciente::Delete() {
	return ProveedorDatos->DeletePaciente(this);
}
string Paciente::ToReport() {
	return "DNI: " + DNI + "\nNombre: " + Nombre;
}