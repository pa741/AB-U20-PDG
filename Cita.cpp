#include "AbsPersona.h"
#include "IDataProvider.h"
#include <list>

using namespace std;
using namespace Abstract;
class Cita : IRecord {
public:
	
	Cita(IDataProvider proveedor) : IRecord(proveedor)
	{

	}

};