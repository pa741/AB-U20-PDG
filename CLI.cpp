#include "CLI.h"
#include <iostream>
#include "Paciente.h"
#include "IDataProvider.h"
bool CLI::Run()
{
	MostrarMenu();
	string respuesta;
	cin >> respuesta;
	int option;
	try
	{
		option = std::stoi(respuesta);
	}
	catch (const std::invalid_argument&)
	{
		cout << "Error. Opcion no valida";
		return false;

	}
	catch (const std::out_of_range&) {
		cout << "Error. Numero muy grande";
		return false;

	}
	switch (option)
	{
	case 1:
		while (RunPacientes()){}
	case 0:
	default:
		cout << "Saliendo...";

		return false;
	}
	return true;
}

void CLI::MostrarMenu()
{
	cout << "0. Salir\n1. Administrar Pacientes\n";
}

bool CLI::RunPacientes()
{
	MostrarMenuPacientes();
	string respuesta;
	cin >> respuesta;
	int option;
	try
	{
		option = std::stoi(respuesta);
	}
	catch (const std::invalid_argument&)
	{
		cout << "Error. Opcion no valida\n";
		return false;

	}
	catch (const std::out_of_range&) {
		cout << "Error. Numero muy grande\n";
		return false;

	}
	switch (option)
	{
	case 1:
		cout << "Abriendo buscador...\n";
		MostrarPacientes();
		break;
	case 2:
		DarAltaPaciente();
		break;
	case 0:
	default:
		cout << "Volviendo al menu...\n";

		return false;
	}
	return true;
}

void CLI::MostrarMenuPacientes()
{
	cout << "\n-------PACIENTES----------\n0. Ir al menu\n1. Ver Pacientes\n2. Dar Paciente de Alta\n";
}

void CLI::MostrarPacientes()
{
	list<Paciente*> lista = Pacientes->GetResults();
	for (Paciente* var : lista)
	{
		cout << var->Nombre + "\n";
	}
}

void CLI::DarAltaPaciente()
{
	if (Pacientes->DarAlta()) {
		cout << "Paciente creado\n";

	}
	else {
		cout << "No se pudo crear el paciente\n";

	}
}
