#pragma once
#include "IRecord.h"
#include "IDataProvider.h"
#include "Filtro.h"
#include <list>
#include <type_traits>
#include "AbsSearchable.h"

template <typename T>
class AbsOrdenable : public AbsSearchable<T> {
	static_assert(std::is_base_of<IRecord, T>::value, "T debe ser IRecord");

public:
	AbsOrdenable(IDataProvider proveedor) : AbsSearchable<T>(proveedor){
	}
	Filtro<T> ActiveOrder;
	void ToggleOrder(Filtro<T> filtro);
	virtual list<T> GetResults() const;
protected:
	list<Filtro<T>> AllOrder;
	void AddOrder(string nombre, std::function<list<T>(list<T>)> filtro) {
		Filtro f = { nombre,filtro };
		AllOrder.push_back(f);
	}
};

