#pragma once
#include "IDataProvider.h"
#include <list>

using namespace std;
	class Cita : IRecord {
	public:
		

		Cita(Medico* medico, IDataProvider* proveedor) : IRecord(proveedor)
		{
			Medico = medico;

		}
		Medico* Medico;
		string Descripcion;
	};
