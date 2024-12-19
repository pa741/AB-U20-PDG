
#include "AB-U20-PDG.h"
#include "CLI.h"
#include "FileProvider.h"
#include <iostream>
#include <fstream>
int main()
{
	

	
	FileProvider* test = new FileProvider();
	test->GetPacientes();
	test->GetMedicos();
	test->GetCitas();
	CLI interface = *new CLI(test);
	while (interface.Run())
	{

	}
	return 0;
}