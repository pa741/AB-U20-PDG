#pragma once
#include "IDataProvider.h"
#include <list>
#include "Medico.h"
#include "Paciente.h"
using namespace std;
	class Cita : IRecord {
	public:
		
		Cita(IDataProvider* proveedor) : IRecord(proveedor) {
		
		}
		Cita(Medico medico, Paciente paciente, IDataProvider* proveedor) : IRecord(proveedor)
		{
			Medico = medico;
			Paciente = paciente;

		}
		Medico Medico{ ProveedorDatos };
		Paciente Paciente{ ProveedorDatos };
		string Descripcion;
	};
