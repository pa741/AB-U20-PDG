
#include "AB-U20-PDG.h"

using namespace std;

int Add(int a, int b)
{
	std::cout << "En Add(), recibido " << a << " y " << b <<"\n";
	return (a + b);
}

int main()
{
	std::cout << "En main()\n" << std::endl;
	std::cout << "llamada Add ()\n" << std::endl;
	std::cout << "El valor devuelto es: " <<  Add(3, 4);
	std::cout << "\nvuelta al main ()\n" << std::endl;
	std::cout << "\n saliendo..\n\n" << std::endl;


	return 0;
}