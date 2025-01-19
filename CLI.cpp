#include "CLI.h"
#include <iostream>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#include "IDataProvider.h"

int GetOption(int max)
{
	string respuesta;
	cin >> respuesta;
	int option;
	try
	{
		option = std::stoi(respuesta);
	}
	catch (const std::invalid_argument &)
	{
		cout << "Error. Opcion no valida";
		return -1;
	}
	catch (const std::out_of_range &)
	{
		cout << "Error. Numero muy grande";
		return -1;
	}
	if (option < 0 || option > max)
	{

		cout << "Error. Opcion no valida \n";
		return -1;
	}
	return option;
}
bool CLI::Run()
{
	MostrarMenu();

	int option = GetOption(3);
	if (option == -1)
		return false;
	switch (option)
	{
	case 1:
		while (RunPacientes())
		{
		}
		break;
	case 2:
		while (RunMedicos())
		{
		}
		break;
	case 3:
		while (RunCitas())
		{
		}
		break;
	case 0:
	default:
		cout << "Saliendo...";

		return false;
	}
	return true;
}

void CLI::MostrarMenu()
{
	cout << "0. Salir\n1. Administrar Pacientes\n2. Administrar Medicos\n3. Administrar Citas\n";
}

bool CLI::RunPacientes()
{
	MostrarMenuPacientes();
	int option = GetOption(2);
	if (option == -1)
		return false;

	int page = 0;
	switch (option)
	{
	case 1:
		page = 0;
		while (RunMostrarPacientes(&page))
		{
		};
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

bool CLI::RunMostrarPacientes(int *page)
{
	cout << "-------------------------------------------------\n";

	bool hasResults = MostrarPacientes(*page);
	if (!hasResults)
	{
		(*page)--;
		cout << "Has llegado al final \n";
	}

	int pageSize = Pacientes.PageSize;
	int total = Pacientes.GetTotalItemCount();
	int totalPages = total / pageSize;

	MostrarPacientesMenu(page, totalPages);
	int max = 3;
	if (*page == 0)
	{
		max--;
	}
	if (*page == totalPages)
	{
		max--;
	}

	int option = GetOption(max);
	if (option == -1)
		return true;

	switch (option)
	{
	case 1:
		(*page)--;
		if ((*page) < 0)
		{
			cout << "Estas en el principio \n";
			(*page) = 0;
		}

		break;
	case 2:
		(*page)++;
		break;
	case 3:
	{
		cout << "Introduce el indice del paciente que se quiere seleccionar...\n";
		int maxIndex = Pacientes.PageSize;
		if (*page == totalPages)
		{
			maxIndex = total % Pacientes.PageSize;
		}

		int index = GetOption(maxIndex);
		index--; // empezamos en 0;
		Paciente pac = GetPacienteEnPag((*page), index);
		while (RunSeleccionarPaciente(pac))
		{
		};
		break;
	}
	case 0:
	default:
		cout << "Volviendo al menu...\n";

		return false;
	}

	return true;
}
void CLI::MostrarPacientesMenu(int *page, int totalPages)
{
	/*^
	cout << "-------------------------------------------------\n";
	cout << "LISTA MEDICOS - PAGINA " + (std::to_string(*page)) + " de " + (std::to_string(totalPages)) + "\n";
	int option = 0;
	cout << (std::to_string(option)) + ". Salir\n";

	option++;
	if (*page != 0)
	{
		cout << (std::to_string(option)) + ". Pagina Anterior\n";
		option++;
	}
	if (*page != totalPages)
	{
		cout << (std::to_string(option)) + ". Pagina Siguiente\n";
		option++;
	}
	cout << (std::to_string(option)) + ". Seleccionar Medico\n";*/
	cout << "-------------------------------------------------\n";
	cout << "LISTA MEDICOS - PAGINA " + (std::to_string(*page)) + " de " + (std::to_string(totalPages)) + "\n";
	cout << "LISTA MEDICOS - PAGINA " + (std::to_string(*page)) + " de " + (std::to_string(totalPages)) + "\n";
	int option = 0;
	cout << (std::to_string(option)) + ". Salir\n";

	option++;
	if (*page != 0)
	{
		cout << (std::to_string(option)) + ". Pagina Anterior\n";
		option++;
	}
	if (*page != totalPages)
	{
		cout << (std::to_string(option)) + ". Pagina Siguiente\n";
		option++;
	}
	cout << (std::to_string(option)) + ". Seleccionar Paciente\n";
}
Paciente CLI::GetPacienteEnPag(int page, int pos)
{
	list<Paciente> lista = Pacientes.GetResults(page);
	std::vector<Paciente> v{std::make_move_iterator(std::begin(lista)),
							std::make_move_iterator(std::end(lista))};
	return v.at(pos);
}
bool CLI::MostrarPacientes(int page)
{

	list<Paciente> lista = Pacientes.GetResults(page);
	if (lista.empty())
	{
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

bool CLI::RunSeleccionarPaciente(Paciente pac)
{
	MenuSeleccionarPaciente(pac);
	int opcion = GetOption(2);
	if (opcion == -1)
	{
		return false;
	}
	switch (opcion)
	{
	case 1:
		cout << "Dando de baja...\n";
		if (pac.Delete())
		{
			cout << "Paciente eliminado!\n";

			return false;
		}
		else
		{

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
void CLI::MenuSeleccionarPaciente(Paciente pac)
{

	cout << "Opciones para: " + pac.Nombre + "\n";
	cout << "0. Salir\n";
	cout << "1. Dar de baja\n";
	cout << "2. Ver Reporte\n";
}
void CLI::DarAltaPaciente()
{
	if (Pacientes.DarAlta())
	{
		cout << "Paciente creado\n";
	}
	else
	{
		cout << "No se pudo crear el paciente\n";
	}
}
bool CLI::RunMedicos()
{
	MostrarMenuMedicos();
	int option = GetOption(2);
	if (option == -1)
		return true;

	int page = 0;
	switch (option)
	{
	case 1:
		page = 0;
		while (RunMostrarMedicos(&page))
		{
		};
		break;
	case 2:
		DarAltaMedico();
		break;
	case 0:
	default:
		cout << "Volviendo al menu...\n";

		return false;
	}
	return true;
}

void CLI::MostrarMenuMedicos()
{
	cout << "\n-------MEDICOS----------\n0. Ir al menu\n1. Ver Medicos\n2. Dar Medico de Alta\n";
}

bool CLI::RunMostrarMedicos(int *page)
{
	cout << "-------------------------------------------------\n";

	bool hasResults = MostrarMedicos(*page);
	if (!hasResults)
	{
		(*page)--;
		cout << "Has llegado al final \n";
	}

	int pageSize = Medicos.PageSize;
	int total = Medicos.GetTotalItemCount();
	int totalPages = total / pageSize;

	MostrarMedicosMenu(page, totalPages);
	int max = 3;
	if (*page == 0)
	{
		max--;
	}
	if (*page == totalPages)
	{
		max--;
	}

	int option = GetOption(max);
	if (option == -1)
		return true;
	if (option == 1 && *page == 0)
	{
		option++;
	}
	if (option == 2 && *page == totalPages)
	{
		option++;
	}
	cout << "Option: " + std::to_string(option) + "\n";

	switch (option)
	{
	case 1:
		(*page)--;
		if ((*page) < 0)
		{
			cout << "Estas en el principio \n";
			(*page) = 0;
		}
		break;
	case 2:
		(*page)++;
		break;
	case 3:
	{
		cout << "Introduce el indice del medico que se quiere seleccionar...\n";
		int maxIndex = Medicos.PageSize;
		if (*page == totalPages)
		{
			maxIndex = total % Medicos.PageSize;
		}

		int index = GetOption(maxIndex);
		if (index <= 0)
		{
			cout << "Volviendo al menu...\n";
			break;
		}
		index--; // empezamos en 0;
		Medico med = GetMedicoEnPag((*page), index);
		while (RunSeleccionarMedico(med))
		{
		};
		break;
	}
	case 0:
	default:
		cout << "Volviendo al menu...\n";

		return false;
	}

	return true;
}
void CLI::MostrarMedicosMenu(int *page, int totalPages) // obtener total de pags
{

	cout << "-------------------------------------------------\n";
	cout << "LISTA MEDICOS - PAGINA " + (std::to_string(*page)) + " de " + (std::to_string(totalPages)) + "\n";
	int option = 0;
	cout << (std::to_string(option)) + ". Salir\n";

	option++;
	if (*page != 0)
	{
		cout << (std::to_string(option)) + ". Pagina Anterior\n";
		option++;
	}
	if (*page != totalPages)
	{
		cout << (std::to_string(option)) + ". Pagina Siguiente\n";
		option++;
	}
	cout << (std::to_string(option)) + ". Seleccionar Medico\n";
}
Medico CLI::GetMedicoEnPag(int page, int pos)
{
	list<Medico> lista = Medicos.GetResults(page);
	std::vector<Medico> v{std::make_move_iterator(std::begin(lista)),
						  std::make_move_iterator(std::end(lista))};
	return v.at(pos);
}
bool CLI::MostrarMedicos(int page)
{

	list<Medico> lista = Medicos.GetResults(page);
	if (lista.empty())
	{
		return false;
	}
	int i = 0;
	cout << "\tNOMBRE\t\tDNI\n";
	cout << "--------------------------------------\n";
	for (Medico var : lista)
	{
		i++;
		cout << std::to_string(i) + ".\t" + var.Nombre + "\t\t" + var.DNI + "\n";
	}
	return true;
}

bool CLI::RunSeleccionarMedico(Medico med)
{
	MenuSeleccionarMedico(med);
	int opcion = GetOption(2);
	if (opcion == -1)
	{
		return false;
	}
	switch (opcion)
	{
	case 1:
		cout << "Dando de baja...\n";
		if (med.Delete())
		{
			cout << "Medico eliminado!\n";

			return false;
		}
		else
		{

			cout << "Medico no se pudo eliminar.\n";
		}
		break;
	case 2:
	{
		string reporte = med.ToReport();

		cout << "Reporte del medico: \n";
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
void CLI::MenuSeleccionarMedico(Medico med)
{

	cout << "Opciones para: " + med.Nombre + "\n";
	cout << "0. Salir\n";
	cout << "1. Dar de baja\n";
	cout << "2. Ver Reporte\n";
}
void CLI::DarAltaMedico()
{
	if (Medicos.DarAlta())
	{
		cout << "Medico creado\n";
	}
	else
	{
		cout << "No se pudo crear el medico\n";
	}
}
bool CLI::RunCitas()
{
	MostrarMenuCitas();
	int option = GetOption(2);
	if (option == -1)
		return true;

	int page = 0;
	switch (option)
	{
	case 1:
		page = 0;
		while (RunMostrarCitas(&page))
		{
		};
		break;
	case 2:
		DarAltaCita();
		break;
	case 0:
	default:
		cout << "Volviendo al menu...\n";

		return false;
	}
	return true;
}

void CLI::MostrarMenuCitas()
{
	cout << "\n-------CITAS----------\n0. Ir al menu\n1. Ver Citas\n2. Dar Cita de Alta\n";
}

bool CLI::RunMostrarCitas(int *page)
{
	cout << "-------------------------------------------------\n";

	bool hasResults = MostrarCitas(*page);
	if (!hasResults)
	{
		(*page)--;
		cout << "Has llegado al final \n";
	}
	int pageSize = Citas.PageSize;
	int total = Citas.GetTotalItemCount();
	int totalPages = total / pageSize;

	MostrarCitasMenu(page, totalPages);
	int max = 3;
	if (*page == 0)
	{
		max--;
	}
	if (*page == totalPages)
	{
		max--;
	}

	int option = GetOption(max);
	if (option == -1)
		return true;

	switch (option)
	{
	case 1:
		(*page)--;
		if ((*page) < 0)
		{
			cout << "Estas en el principio \n";
			(*page) = 0;
		}

		break;
	case 2:
		(*page)++;
		break;
	case 3:
	{
		cout << "Introduce el indice de la cita que se quiere seleccionar...\n";
		int maxIndex = Citas.PageSize;
		if (*page == totalPages)
		{
			maxIndex = total % Citas.PageSize;
		}

		int index = GetOption(maxIndex);
		index--; // empezamos en 0;
		Cita cit = GetCitaEnPag((*page), index);
		while (RunSeleccionarCita(cit))
		{
		};
		break;
	}
	case 0:
	default:
		cout << "Volviendo al menu...\n";

		return false;
	}

	return true;
}

void CLI::MostrarCitasMenu(int *page, int totalPages)
{

	cout << "-------------------------------------------------\n";
	cout << "LISTA Citas - PAGINA " + (std::to_string(*page)) + " de " + (std::to_string(totalPages)) + "\n";
	int option = 0;
	cout << (std::to_string(option)) + ". Salir\n";
	option++;
	if (*page != 0)
	{
		cout << (std::to_string(option)) + ". Pagina Anterior\n";
		option++;
	}
	if (*page != totalPages)
	{
		cout << (std::to_string(option)) + ". Pagina Siguiente\n";
		option++;
	}
	cout << (std::to_string(option)) + ". Seleccionar Cita\n";
}
Cita CLI::GetCitaEnPag(int page, int pos)
{
	list<Cita> lista = Citas.GetResults(page);
	std::vector<Cita> v{std::make_move_iterator(std::begin(lista)),
						std::make_move_iterator(std::end(lista))};
	return v.at(pos);
}
bool CLI::MostrarCitas(int page)
{

	list<Cita> lista = Citas.GetResults(page);
	if (lista.empty())
	{
		return false;
	}
	int i = 0;
	cout << "\tPACIENTE\t\tMEDICO\n";
	cout << "--------------------------------------\n";
	for (Cita var : lista)
	{
		i++;
		cout << std::to_string(i) + ".\t" + var.MedicalPatient.Nombre + "\t\t" + var.Doctor.Nombre + "\n";
	}
	return true;
}

bool CLI::RunSeleccionarCita(Cita cit)
{
	MenuSeleccionarCita(cit);
	int opcion = GetOption(2);
	if (opcion == -1)
	{
		return false;
	}
	switch (opcion)
	{
	case 1:
		cout << "Dando de baja...\n";
		if (cit.Delete())
		{
			cout << "Cita eliminada!\n";

			return false;
		}
		else
		{

			cout << "Cita no se pudo eliminar.\n";
		}
		break;
	case 2:
	{
		string reporte = cit.ToReport();

		cout << "Reporte de la cita: \n";
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
void CLI::MenuSeleccionarCita(Cita cit)
{

	cout << "Opciones para la cita con " + cit.MedicalPatient.Nombre + " y " + cit.Doctor.Nombre + "\n";
	cout << "0. Salir\n";
	cout << "1. Dar de baja\n";
	cout << "2. Ver Reporte\n";
}
void CLI::DarAltaCita()
{
	if (Citas.DarAlta())
	{
		cout << "Cita creada\n";
	}
	else
	{
		cout << "No se pudo crear la cita\n";
	}
}
