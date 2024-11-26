#include "CLI.h"
#include <iostream>
#include "Paciente.h"
#include "IDataProvider.h"

int GetOption() {
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
		return -1;

	}
	catch (const std::out_of_range&) {
		cout << "Error. Numero muy grande";
		return -1;

	}
	return option;
}
bool CLI::Run()
{
	MostrarMenu();

	int option = GetOption();
	if (option == -1) return false;
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
	int option = GetOption();
	if (option == -1) return false;

	int page = 0;
	switch (option)
	{
	case 1:
		page = 0;
		while (RunMostrarPacientes(&page) ){};
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

bool CLI::RunMostrarPacientes(int* page)
{
	cout << "-------------------------------------------------\n";

	bool hasResults = MostrarPacientes(*page);
	if (!hasResults) {
		(*page)--;
		cout << "Has llegado al final \n";
	}
	MostrarPacientesMenu(page);

	int option = GetOption();
	if (option == -1) return false;

	switch (option)
	{
	case 1:
		(*page)--;
		if ((*page) < 0) {
			cout << "Estas en el principio \n";
			(*page) = 0;
		}

		break;
	case 2:
		(*page)++;
		break;
	case 3:

	case 0:
	default:
		cout << "Volviendo al menu...\n";

		return false;
	}

	return true;
}
void CLI::MostrarPacientesMenu(int* page) {
	cout << "-------------------------------------------------\n";
	cout << "LISTA PACIENTES - PAGINA " + (std::to_string(*page)) + "\n";
	cout << "0. Salir\n";
	cout << "1. Pagina Anterior\n";
	cout << "2. Pagina Siguiente\n";
	cout << "3. Seleccionar Paciente\n";


}

bool CLI::MostrarPacientes(int page)
{


	list<Paciente> lista = Pacientes->GetResults(page);
	if (lista.empty()) {
		return false;
	}
	int i = 0;
	cout << "\tNOMBRE\t\tDNI\n";
	cout << "--------------------------------------\n";


	for (Paciente var : lista)
	{
		i++;
		cout << std::to_string(i)+ ".\t"+var.Nombre + "\t\t"+var.DNI+"\n";
	}
	return true;
}

bool CLI::RunSeleccionarPaciente(int page) {
	return false;
}
void CLI::MenuSeleccionarPaciente() {

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
