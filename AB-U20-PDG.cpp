
#include "AB-U20-PDG.h"
#include "CLI.h"
#include "FileProvider.h"
#include <iostream>
#include <fstream>
#include "FakeData.h"
int main()
{
	FileProvider* test = new FileProvider();
	FakeData fd = FakeData(test);
	fd.GenerateData(100,100);
	CLI interface = *new CLI(test);
	while (interface.Run()){} 
	return 0;
}