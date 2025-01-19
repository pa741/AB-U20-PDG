#pragma once
#include "IDataProvider.h"
#include "PacienteManager.h"
#include "MedicoManager.h"
#include "CitaManager.h"
class CLI {
public:
	CLI(IDataProvider* proveedor) {
		ProveedorDatos = proveedor;
	
		Pacientes = *new PacienteManager(proveedor);
		Medicos = *new MedicoManager(proveedor);
		Citas = *new CitaManager(proveedor);
	}
	bool Run();
	void MostrarMenu();
	bool RunPacientes();
	bool RunMedicos();
	bool RunCitas();
	//Pacientes
	void MostrarMenuPacientes();
	bool RunMostrarPacientes(int* page);
	void MostrarPacientesMenu(int* page, int totalPages);
	Paciente GetPacienteEnPag(int page, int pos);
	bool MostrarPacientes(int page);
	bool RunSeleccionarPaciente(Paciente pac);
	void MenuSeleccionarPaciente(Paciente pac);
	void DarAltaPaciente();
	//Medicos
	void MostrarMenuMedicos();
	bool RunMostrarMedicos(int* page);
	void MostrarMedicosMenu(int* page, int totalPages);
	Medico GetMedicoEnPag(int page, int pos);
	bool MostrarMedicos(int page);
	bool RunSeleccionarMedico(Medico med);
	void MenuSeleccionarMedico(Medico med);
	void DarAltaMedico();
	//Citas
	void MostrarMenuCitas();
	bool RunMostrarCitas(int* page);
	void MostrarCitasMenu(int* page, int totalPages);
	Cita GetCitaEnPag(int page, int pos);
	bool MostrarCitas(int page);
	bool RunSeleccionarCita(Cita cit);
	void MenuSeleccionarCita(Cita cit);
	void DarAltaCita();
	

	IDataProvider* ProveedorDatos;
	PacienteManager Pacientes{ProveedorDatos};
	MedicoManager Medicos{ProveedorDatos};
	CitaManager Citas{ProveedorDatos};
	
	
};