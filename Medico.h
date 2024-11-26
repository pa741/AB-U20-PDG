#pragma once
#include "AbsPersona.h"
#include "IDataProvider.h"
#include <list>
#include "json.hpp"
using json = nlohmann::json;

using namespace std;
class Medico : public AbsPersona {
public:
	Medico(IDataProvider* proveedor) : AbsPersona(proveedor){

	}
	Medico(string nombre, string dni, IDataProvider* proveedor, string especialidad) : AbsPersona(nombre, dni, proveedor)
	{
		Especialidad = especialidad;
	}
	string Especialidad;
	bool Save();
	bool Delete();
	string ToReport();


};