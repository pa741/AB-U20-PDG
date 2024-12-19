#include "AbsPersona.h"
#include "IDataProvider.h"
#include "Cita.h"
#include <list>
namespace Data {
	class Cita : IRecord {
	public:

		Cita(IDataProvider* proveedor) : IRecord(proveedor)
		{
	
		}
		bool Save() {
			return false;
		}

	};
}