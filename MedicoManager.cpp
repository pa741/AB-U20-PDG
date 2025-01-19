#include "MedicoManager.h"
#include "Medico.h"
#include <iostream>
list<Medico> MedicoManager::GetAllItems() const
{
	return ProveedorDatos->GetMedicos();
}
list<Medico> searchFiltro(list<Medico> lista, string search) {

	list<Medico>* result = new list<Medico>();
	for (Medico med : lista) {
		if (med.Nombre.find(search) != std::string::npos) {
			result->push_back(med);
		}
	}
	return *result;
}


bool MedicoManager::DarAlta() const
{
	Medico* pac = new Medico(ProveedorDatos);
	//cout << "Introduzca el DNI del medico: ";
	//cin >> pac->DNI;
	//cout << "Introduzca el nombre del medico: ";
	//cin >> pac->Nombre;
	if(!pac->AddBaseInputData()){
		return false;
	}
	cout << "Introduzca la especialidad del medico. ";
	cin >> pac->Especialidad;

	return pac->Save();
}

bool MedicoManager::DarBaja(Medico* pac) const
{
	return pac->Delete();
}

string MedicoManager::GetReporte(Medico* pac) const
{
	return pac->ToReport();
}

list<Filtro<Medico>> MedicoManager::AllFiltros() const
{
	list<Filtro<Medico>> filtros = list<Filtro<Medico>>();
	function<list<Medico>(list<Medico>)> func = [&](list<Medico> list) {return searchFiltro(list, search1); };
	Filtro<Medico> search = { "Buscar", func };
	filtros.push_back(search);
	return filtros;

}
int MedicoManager::GetTotalItemCount() const
{
    return ProveedorDatos->GetMedicosCount();
}