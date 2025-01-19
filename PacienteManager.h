#pragma once
#include "AbsSearchable.h"
#include "Paciente.h"
class PacienteManager : public AbsSearchable<Paciente> {

public:
	PacienteManager(IDataProvider* proveedor) : AbsSearchable<Paciente>(proveedor) {
	}
	list<Paciente> GetAllItems() const;
	int GetTotalItemCount() const;
	bool DarAlta() const;
	bool DarBaja(Paciente* pac) const;
	string GetReporte(Paciente* pac) const;
};