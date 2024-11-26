#pragma once
#include "IDataProvider.h"
#include "PacienteManager.h"
class CLI {
public:
	CLI(IDataProvider* proveedor) {
		ProveedorDatos = proveedor;
		Pacientes = new PacienteManager(proveedor);
	}
	bool Run();
	void MostrarMenu();
	bool RunPacientes();
	void MostrarMenuPacientes();
	bool RunMostrarPacientes(int* page);
	void MostrarPacientesMenu(int* page);
	bool MostrarPacientes(int page);
	bool RunSeleccionarPaciente(int page);
	void MenuSeleccionarPaciente();
	void DarAltaPaciente();
	IDataProvider* ProveedorDatos;
	PacienteManager* Pacientes;
	
	
};