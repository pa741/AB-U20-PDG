#pragma once
#include "IRecord.h"
#include "IDataProvider.h"
#include "Filtro.h"
#include <list>
#include <type_traits>

template <typename T>
class AbsSearchable {
	//static_assert(std::is_base_of<IRecord, T>::value, "T debe ser IRecord");

public:
	AbsSearchable(IDataProvider* proveedor) {
		ProveedorDatos = proveedor;
	}
	IDataProvider* ProveedorDatos;
	list<Filtro<T>> ActiveFiltros;
	list<T*> GetAllItems() const;
	virtual list<T> GetResults() const; 
	void ToggleFiltro(Filtro<T> filtro);
	//list<Filtro<T>> GetFilters()  { return ActiveFiltros; };
protected:
	list<Filtro<T>> AllFiltros() const;

};