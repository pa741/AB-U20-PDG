#pragma once
#include "AbsPersona.h"

#include <list>

using namespace std;
class Paciente : AbsPersona {
public:


	Paciente(string nombre, string dni, IDataProvider* proveedor, list<string> enfermedades) : AbsPersona(nombre, dni, proveedor) 
	{
		Enfermedades = enfermedades;

	}
	list<string> Enfermedades;

};