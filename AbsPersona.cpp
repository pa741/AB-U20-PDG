#include <iostream>

#include <string>
#include "AbsPersona.h"

bool AbsPersona::Save()
{
    return false;
}

bool AbsPersona::Delete()
{
    return false;
}

string AbsPersona::ToReport()
{
    return string();
}
bool AbsPersona::AddBaseInputData()
{
    cout << "Introduzca el DNI: ";
    string dni;
    cin >> dni;
    if (!validarDNI(dni)) {
        cout << "DNI no valido" << endl;
        return false;
    }
	cout << "Introduzca el nombre: ";
	cin >> this->Nombre;

    return true;
}
bool AbsPersona::validarDNI(string dni)
{
    //16650196J
    if (dni.length() != 9) {
        return false;
    }
    char letra = dni[8];
    string num = dni.substr(0, 8);
    try {
        int numDni = stoi(num);
        int resto = numDni % 23;
        string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
        if (letras[resto] == letra) {
            return true;
        }
        else {
            return false;
        }
    }
    catch (const std::exception& e) {
        return false;
    }
}
