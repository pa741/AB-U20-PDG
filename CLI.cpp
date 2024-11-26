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
		while (RunPacientes()) {}
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
		while (RunMostrarPacientes(&page)) {};
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
	case 3: {
		cout << "Introduce el indice del paciente que se quiere seleccionar...\n";
		int index = GetOption();
		index--; // empezamos en 0;
		Paciente pac = GetPacienteEnPag((*page), index);
		while (RunSeleccionarPaciente(pac)) {};
		break;
	}
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
Paciente CLI::GetPacienteEnPag(int page, int pos) {
	list<Paciente> lista = Pacientes.GetResults(page);
	std::vector<Paciente> v{ std::make_move_iterator(std::begin(lista)),
				  std::make_move_iterator(std::end(lista)) };
	return v.at(pos);
}
bool CLI::MostrarPacientes(int page)
{

	list<Paciente> lista = Pacientes.GetResults(page);
	if (lista.empty()) {
		return false;
	}
	int i = 0;
	cout << "\tNOMBRE\t\tDNI\n";
	cout << "--------------------------------------\n";


	for (Paciente var : lista)
	{
		i++;
		cout << std::to_string(i) + ".\t" + var.Nombre + "\t\t" + var.DNI + "\n";
	}
	return true;
}

bool CLI::RunSeleccionarPaciente(Paciente pac) {
	MenuSeleccionarPaciente(pac);
	int opcion = GetOption();
	if (opcion == -1) {
		return false;
	}
	switch (opcion)
	{
	case 1:
		cout << "Dando de baja...\n";
		if (pac.Delete()) {
			cout << "Paciente eliminado!\n";

			return false;
		}
		else {

			cout << "Paciente no se pudo eliminar.\n";
		}
		break;
	case 2:
	{
		string reporte = pac.ToReport();

		cout << "Reporte del paciente: \n";
		cout << "-------------\n";
		cout << reporte + "\n";
		cout << "-------------\n";
		break;
	}
	case 0:
	default:
		return false;
	}

	return true;
}
void CLI::MenuSeleccionarPaciente(Paciente pac) {

	cout << "Opciones para: " + pac.Nombre + "\n";
	cout << "0. Salir\n";
	cout << "1. Dar de baja\n";
	cout << "2. Ver Reporte\n";

}
void CLI::DarAltaPaciente()
{
	if (Pacientes.DarAlta()) {
		cout << "Paciente creado\n";

	}
	else {
		cout << "No se pudo crear el paciente\n";

	}
}
