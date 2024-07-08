#pragma once
#include <string>

class Persona {
public:
	std::string nombre1;
	std::string nombre2;
	std::string apellidoP;
	std::string apellidoM;
	std::string cedula;
	std::string correo;

	Persona(const std::string& nombre1, const std::string& nombre2, const std::string& apellidoP, const std::string& apellidoM, const std::string& cedula, const std::string& correo)
		: nombre1(nombre1), nombre2(nombre2), apellidoP(apellidoP), apellidoM(apellidoM), cedula(cedula), correo(correo) {}

};