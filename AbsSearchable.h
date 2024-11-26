#pragma once
#include "IRecord.h"
#include "IDataProvider.h"
#include "Filtro.h"
#include <list>
#include <type_traits>

template <typename T>
class AbsSearchable {
	//static_assert(std::assigna<IRecord, T>::value, "T debe ser IRecord");

public:
	AbsSearchable(IDataProvider* proveedor) {
		ProveedorDatos = proveedor;
	}
	IDataProvider* ProveedorDatos;
	list<Filtro<T*>> ActiveFiltros;
	list<T*> GetAllItems() const { return *new list<T*>(); };
	virtual list<T*> GetResults() const {
		list<T*> items = GetAllItems();
		for (Filtro<T*> filto : ActiveFiltros)
		{
			items = filto.filtro(items);
		}
		return items;
	}
	void ToggleFiltro(Filtro<T*> filtro);
	//list<Filtro<T>> GetFilters()  { return ActiveFiltros; };
protected:
	list<Filtro<T*>> AllFiltros() const;

};