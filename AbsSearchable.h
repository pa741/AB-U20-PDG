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
	int PageSize;
	AbsSearchable(IDataProvider* proveedor) {
		ProveedorDatos = proveedor;
		PageSize = 30;
	}
	IDataProvider* ProveedorDatos;
	list<Filtro<T>> ActiveFiltros;
	virtual list<T> GetAllItems() const { return list<T>(); };
	virtual list<T> GetResults(int page) const {
		list<T> items = GetAllItems();
		for (Filtro<T> filto : ActiveFiltros)
		{
			items = filto.filtro(items);
		}
		int offset = page * PageSize;
		
		list<T> result();
		if (items.size >= offset) {
			return result;
		}
		std::vector<T> v{ std::make_move_iterator(std::begin(items)),
				  std::make_move_iterator(std::end(items)) };
		for (int i = offset; i < v.size && i - offset < PageSize && i++) {
			result.push_back(v.at(i));
		}

		return items;
	}
	void ToggleFiltro(Filtro<T> filtro);
	//list<Filtro<T>> GetFilters()  { return ActiveFiltros; };
protected:
	list<Filtro<T>> AllFiltros() const;

};