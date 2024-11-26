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
	void MostrarPacientes();
	void DarAltaPaciente();
	IDataProvider* ProveedorDatos;
	PacienteManager* Pacientes;
	
	
};