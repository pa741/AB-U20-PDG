
#include "AB-U20-PDG.h"
#include "CLI.h"
#include "FileProvider.h"
#include <iostream>
#include <fstream>
int main()
{
	

	

	CLI interface = *new CLI(new FileProvider());
	while (interface.Run())
	{

	}
	return 0;
}