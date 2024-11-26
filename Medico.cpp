#include "AbsPersona.h"
#include "IDataProvider.h"
#include <list>

using namespace std;
class Medico : AbsPersona {
public:
	string Especialidad;


	Medico(string nombre, string dni, IDataProvider* proveedor, string especialidad) : AbsPersona(nombre, dni, proveedor)
	{
		Especialidad = especialidad;

	}

};