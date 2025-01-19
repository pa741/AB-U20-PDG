#pragma once
#include <string>
#include "IRecord.h"
using namespace std;


class AbsPersona : public IRecord {
public:
	string Nombre;
	string DNI;

	AbsPersona(IDataProvider* proeedor) : IRecord(proeedor) {
		ProveedorDatos = proeedor;
	}
	AbsPersona(string nombre, string Dni, IDataProvider* proeedor) : IRecord(proeedor) {
		Nombre = nombre;
		DNI = Dni;
		ProveedorDatos = proeedor;

	}
	bool Save();
	bool Delete();
	string ToReport();
	bool validarDNI(string dni);
	bool AddBaseInputData();
};
