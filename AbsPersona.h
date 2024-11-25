#pragma once
#include <string>
#include "IRecord.h"
#include "IDataProvider.h"
using namespace std;

namespace Abstract {

	class AbsPersona : IRecord {
	public:
		string Nombre;
		string DNI;
		AbsPersona(string nombre, string Dni, IDataProvider proeedor) : IRecord(proeedor) {
			Nombre = nombre;
			DNI = Dni;
		}
	};
};

