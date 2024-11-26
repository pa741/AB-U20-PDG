#pragma once
#include <string>
#include "IDataProvider.h"
using namespace std;
class IRecord
{
public:

	IRecord(IDataProvider* proveedor) : ProveedorDatos{proveedor}
	{
	}

	bool Save() ;
	bool Delete();
	string ToReport(); 
protected:
	IDataProvider* ProveedorDatos;

};