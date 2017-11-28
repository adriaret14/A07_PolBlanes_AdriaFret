#include <string>
#pragma once
class Enemigo
{
public:
	Enemigo(std::string, float, float, float, float, float);
	~Enemigo();

	std::string nombre;
	float vitalidad;
	float atk;
	float def;
	float frecAtk;
	float exp;
};

