#include "PacienteManager.h"
#include "Paciente.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
list<Paciente> PacienteManager::GetAllItems() const
{
	return ProveedorDatos->GetPacientes();;
}

bool PacienteManager::DarAlta() const
{
	Paciente* pac = new Paciente(ProveedorDatos);
	cout << "Introduzca el DNI del paciente: ";
	cin >> pac->DNI;
	cout << "Introduzca el nombre del paciente: ";
	cin >> pac->Nombre;
	cout << "Introduzca las enfermedades del paciente separadas por comas.";
	string enfermedades;
	cin >> enfermedades;
	stringstream strm(enfermedades);
	list<string> enfList;
	string segment;
	while (std::getline(strm, segment, ','))
	{
		enfList.push_back(segment);
	}
	pac->Enfermedades = enfList;
	return pac->Save();
}

bool PacienteManager::DarBaja(Paciente* pac) const
{
	return pac->Delete();
}

string PacienteManager::GetReporte(Paciente* pac) const
{
	return pac->ToReport();
}
