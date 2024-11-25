#include <string>
#include "IDataProvider.h"
using namespace std;
namespace Abstract {
	class IRecord
	{
	public:
		IRecord(IDataProvider proveedor) {
			ProveedorDatos = proveedor;
		}
		bool Save() { return false; };
		bool Delete() { return false; };
		string ToReport() { return false; };
		IDataProvider ProveedorDatos;
	};
}