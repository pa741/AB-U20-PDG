#include "AbsSearchable.h"
template <typename T>
list<T*> AbsSearchable<T>::GetAllItems() const { return nullptr; }

template <typename T>
list<T> AbsSearchable<T>::GetResults() const {
	list<T> items = GetAllItems();
	for each (Filtro<T> filto in ActiveFiltros)
	{
		items = filto.filtro(items);
	}
	return items;
}
template <typename T>
void AbsSearchable<T>::ToggleFiltro(Filtro<T> filtro) {
	bool found = false;
	for each (Filtro<T> filto in ActiveFiltros)
	{
		if (filtro.nombre == filto.nombre) {
			ActiveFiltros.remove(filto);
			found == true;
			break;
		}
	}
	if (found) {
		return;
	}
	ActiveFiltros.push_back(filtro);
}

template<typename T>
list<Filtro<T>> AbsSearchable<T>::AllFiltros() const { return NULL;}
