#include "CitaManager.h" 
#include "Cita.h"
#include <iostream>
#include <string>

list<Cita> CitaManager::GetAllItems() const
{
	return ProveedorDatos->GetCitas();
}
bool CitaManager::DarAlta() const
{
	Cita* pac = new Cita(ProveedorDatos);
	cout << "Introduzca el DNI del paciente: ";
	string dniPac;
    cin >> dniPac;
    Paciente pacP = nullptr;
    try {
    pacP = ProveedorDatos->GetPaciente(dniPac);
    }
    catch (const std::runtime_error &e) {
        cout << "No se encontro el paciente, dar de alta primero\ncancelando...\n";
        return false;
    }
    cout << "Introduzca el DNI del medico: ";
    string dniMed;
    cin >> dniMed;
    Medico med = nullptr;
    try {
        med = ProveedorDatos->GetMedico(dniMed);
    }
    catch (const std::runtime_error &e) {
        cout << "No se encontro el medico, dar de alta primero\ncancelando...\n";
        return false;
    }
    cout << "Introduzca la descripcion de la cita: ";
    string desc;
    cin >> desc;
    pac->Doctor = med;
    pac->MedicalPatient = pacP;
    pac->Descripcion = desc;
    
    return pac->Save();

}

bool CitaManager::DarBaja(Cita* pac) const
{
    return pac->Delete();
}

string CitaManager::GetReporte(Cita* pac) const
{
    return pac->ToReport();
}

int CitaManager::GetTotalItemCount() const
{
    return ProveedorDatos->GetCitasCount();
}