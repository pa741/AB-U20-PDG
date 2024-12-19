#pragma once
#include "IDataProvider.h"
#include <list>
#include "Medico.h"
#include "Paciente.h"
using namespace std;
class Cita : IRecord
{
public:
	Cita(IDataProvider *proveedor) : IRecord(proveedor), Doctor(proveedor), MedicalPatient(proveedor)
	{
	}
	Cita(Medico medico, Paciente paciente, IDataProvider *proveedor) : IRecord(proveedor), Doctor(medico), MedicalPatient(paciente)
	{
	}
	Medico Doctor;
	
	Paciente MedicalPatient;
	string Descripcion;
};
