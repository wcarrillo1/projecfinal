#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
using namespace std;

class Persona
{
	protected: string nombres, apellidos, fecha_ingreso;
			 int telefono = 0;
			 char genero ='M';

			 Persona() {}

			 Persona(string nom, string ape, int tel, string fi, char gen) {
				 nombres = nom;
				 apellidos = ape;
				 telefono = tel;
				 fecha_ingreso = fi;
				 genero = gen;
				 
			 }
			 

	
};

