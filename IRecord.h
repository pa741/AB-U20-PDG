#include <string>
#include "IDataProvider.h"
using namespace std;
class IRecord
{
public:
	IDataProvider* ProveedorDatos;
	IRecord(IDataProvider* proveedor) : ProveedorDatos{proveedor}
	{
	}

	bool Save();
	bool Delete();
	string ToReport();
};