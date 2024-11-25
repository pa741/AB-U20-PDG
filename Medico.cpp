#include "AbsPersona.h"
#include "IDataProvider.h"
#include <list>

using namespace std;
using namespace Abstract;
class Medico : AbsPersona {
public:
	string Especialidad;


	Medico(string nombre, string dni, IDataProvider proveedor, string especialidad) : AbsPersona(nombre, dni, proveedor)
	{
		Especialidad = especialidad;

	}

};