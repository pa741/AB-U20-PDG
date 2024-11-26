#pragma once
#include "AbsSearchable.h"
class PacienteManager : public AbsSearchable<Paciente> {

public:
	PacienteManager(IDataProvider* proveedor) : AbsSearchable<Paciente>(proveedor) {
	}
	list<Paciente*> GetAllItems() const;
	bool DarAlta() const;
	bool DarBaja(Paciente* pac) const;
	string GetReporte(Paciente* pac) const;
};