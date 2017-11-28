#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Enemigo.h"
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

void main()
{

	std::vector<Enemigo *> enemigos;

	std::string naux;

	float vit, atk, def, fatk, exp;

	rapidxml::xml_document<> doc;
	
	std::ifstream file("Enemies.xml");
	
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();

	std::string content(buffer.str());

	doc.parse<0>(&content[0]);

	rapidxml::xml_node<> *pRaiz = doc.first_node();

	for (rapidxml::xml_node<> *pNodo = pRaiz->first_node("Enemigo"); pNodo; pNodo = pNodo->next_sibling())
	{
		for (rapidxml::xml_attribute<> *pAtr = pNodo->first_attribute(); pAtr; pAtr = pAtr->next_attribute())
		{
			naux = pAtr->value();
		}

			rapidxml::xml_node<> *pNodo2;
			pNodo2=pNodo->first_node("vitalidad");
			std::string cad1(pNodo2->value());
			vit = stof(cad1);

			pNodo2 = pNodo->first_node("ataque");
			std::string cad2(pNodo2->value());
			atk = stof(cad2);

			pNodo2 = pNodo->first_node("defensa");
			std::string cad3(pNodo2->value());
			def = stof(cad3);

			pNodo2 = pNodo->first_node("frec_atk");
			std::string cad4(pNodo2->value());
			fatk = stof(cad4);

			pNodo2 = pNodo->first_node("exp");
			std::string cad5(pNodo2->value());
			exp = stof(cad5);

		enemigos.push_back(new Enemigo(naux, vit, atk, def, fatk, exp));
	}


	for (int i = 0; i < enemigos.size(); i++)
	{
		std::cout << enemigos[i]->nombre << ":" << std::endl;
		std::cout << "Ataque = " << enemigos[i]->atk << std::endl;
		std::cout << "Defensa = " << enemigos[i]->def << std::endl;
		std::cout << "Vida = " << enemigos[i]->vitalidad << std::endl;
		std::cout << "Frecuencia Ataque = " << enemigos[i]->frecAtk << std::endl;
		std::cout << "Experiencia = " << enemigos[i]->exp << std::endl;

		std::cout << std::endl;
	}
}