#pragma once
#include "AbsSearchable.h"
#include "Cita.h"
#include "Medico.h"
#include "Paciente.h"
class CitaManager : public AbsSearchable<Cita>
{
public:
    CitaManager(IDataProvider *proveedor) : AbsSearchable<Cita>(proveedor)
    {
    }
    list<Cita> GetAllItems() const;
    bool DarAlta() const;
    bool DarBaja(Cita *pac) const;
    string search1;
    string GetReporte(Cita *pac) const;

protected:
    list<Filtro<Cita>> AllFiltros() const;
};