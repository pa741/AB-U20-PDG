#pragma once
#include "AbsSearchable.h"
class MedicoManager :public  AbsSearchable<Medico> {
public:
	MedicoManager(IDataProvider* proveedor) : AbsSearchable<Medico>(proveedor) {
	}
	list<Medico> GetAllItems() const;
	bool DarAlta() const;
	bool DarBaja(Medico* pac) const;
	string search1;
	string GetReporte(Medico* pac) const;
protected:
	list<Filtro<Medico>> AllFiltros() const;
};