#include "Enemigo.h"



Enemigo::Enemigo(std::string n, float v, float a, float d, float fa, float ex):
	nombre(n),
	vitalidad(v),
	atk(a),
	def(d),
	frecAtk(fa),
	exp(ex)

{
}


Enemigo::~Enemigo()
{
}
