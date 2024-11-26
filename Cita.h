#pragma once
#include "IDataProvider.h"
#include <list>

using namespace std;
	class Cita : IRecord {
	public:
		
		Cita(IDataProvider* proveedor) : IRecord(proveedor) {

		}
		Cita(Medico* medico, Paciente* paciente, IDataProvider* proveedor) : IRecord(proveedor)
		{
			Medico = medico;
			Paciente = paciente;

		}
		Medico* Medico;
		Paciente* Paciente;
		string Descripcion;
	};
