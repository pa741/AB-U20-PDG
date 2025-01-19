
#include "AB-U20-PDG.h"
#include "CLI.h"
#include "FileProvider.h"
#include <iostream>
#include <fstream>
#include "FakeData.h"
int main()
{
	FileProvider* test = new FileProvider();
	cout << "¿Desea cargar datos de prueba? (s/n): ";
	string respuesta;
	cin >> respuesta;
	if (respuesta == "s")
	{
		FakeData fd = FakeData(test);
		fd.GenerateData(100,100);
	}

	CLI interface = *new CLI(test);
	while (interface.Run()){} 
	return 0;
}