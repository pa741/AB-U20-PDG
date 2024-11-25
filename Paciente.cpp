#include "AbsPersona.h"
#include "IDataProvider.h"
#include <list>

using namespace std;
using namespace Abstract;
class Pactiente : AbsPersona {
public:
	list<string> Enfermedades;


	Pactiente(string nombre, string dni, IDataProvider proveedor,list<string> enfermedades) : AbsPersona(nombre, dni, proveedor) 
	{
		Enfermedades = enfermedades;

	}

};