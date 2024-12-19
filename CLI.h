#pragma once
#include "IDataProvider.h"
#include "PacienteManager.h"
#include "MedicoManager.h"
#include "CitaManager.h"
class CLI {
public:
	CLI(IDataProvider* proveedor) {
		ProveedorDatos = proveedor;
	
		//Pacientes = *new PacienteManager(proveedor);
	}
	bool Run();
	void MostrarMenu();
	bool RunPacientes();
	void MostrarMenuPacientes();
	bool RunMostrarPacientes(int* page);
	void MostrarPacientesMenu(int* page);
	Paciente GetPacienteEnPag(int page, int pos);
	bool MostrarPacientes(int page);
	bool RunSeleccionarPaciente(Paciente pac);
	void MenuSeleccionarPaciente(Paciente pac);
	void DarAltaPaciente();
	IDataProvider* ProveedorDatos;
	PacienteManager Pacientes{ProveedorDatos};
	MedicoManager Medicos{ProveedorDatos};
	CitaManager Citas{ProveedorDatos};
	
	
};