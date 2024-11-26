#include "AbsOrdernable.h"
template<typename T>
void AbsOrdenable<T>::ToggleOrder(Filtro<T> filtro)
{
	if (ActiveOrder.Nombre == filtro.Nombre) {
		ActiveOrder = NULL;
	}
	else {
		ActiveOrder = filtro;
	}
}
template<typename T>
list<T> AbsOrdenable<T>::GetResults() const
{
	list<T> base = AbsSearchable<T>::GetResults();
	if (ActiveOrder == NULL) {
		return base;
	}
	function<list<T>(list<T>)> activo = ActiveOrder.filtro;

	return activo(base);
}