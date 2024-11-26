#pragma once
#include "AbsPersona.h"
#include "json.hpp"

#include <list>
using json = nlohmann::json;
using namespace std;
class Paciente : public AbsPersona {
public:

	Paciente(IDataProvider* proveedor) : AbsPersona(proveedor) {

	}
	Paciente(string nombre, string dni, IDataProvider* proveedor, list<string> enfermedades) : AbsPersona(nombre, dni, proveedor) 
	{
		Enfermedades = enfermedades;

	}
	list<string> Enfermedades;
	bool Save();
	bool Delete();
	string ToReport();
};