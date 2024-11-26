#pragma once
#include <string>
#include <functional>

template<typename T>
struct Filtro {
public:
	std::string Nombre;
    std::function<list<T>(list<T>)> filtro;
};