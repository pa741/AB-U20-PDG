#pragma once
using namespace std;
namespace Abstract {
	class IDataProvider
	{
		virtual bool UpdateMedico() { false; };
		virtual bool UpdatePaciente() { false; };
		virtual bool UpdateCita() { false; };
		virtual bool DeleteMedico() { false; };
		virtual bool DeleteCita() { false; };
		virtual bool DeletePaciente() { false; };

	};
}