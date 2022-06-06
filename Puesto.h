#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <string>
using namespace std;
class Puesto
{
protected: string puestos;
        	int idpuestos = 0;

public:	Puesto() {}

	Puesto(int idp, string pue) {
		idpuestos = idp;
		puestos = pue;
	}

	void gotoxy(int x, int y) {
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string insert = "INSERT INTO puestos(puestos)values('" + puestos + "');";
			const char* i = insert.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				gotoxy(45, 5); cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}

		}
		else {
			cout << "...Error en la conexion...";
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string ID = to_string(idpuestos);
			string insert = "DELETE FROM puestos WHERE idpuestos = '" + ID + "';";
			const char* i = insert.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Registro Eliminado Con Exito ..." << endl;
			}
			else {
				cout << " xxx Error al Eliminar  xxx" << endl;
			}
		}
		else {
			cout << "...Error en la conexion...";
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "select * from puestos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				int column = 4;
				resultado = mysql_store_result(cn.getConectar());
				gotoxy(45, 2); cout << "------------Puestos---------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(45, column); cout << "Codigo: " << fila[0];
					gotoxy(55, column); cout << "Nombre: " << fila[1];
					column = column++;
				}
				gotoxy(45, column); system("pause");
			}
			else {
				cout << "---Error al Ingresar la informacion---" << endl;
			}
		}
		else {
			cout << "...Error en la conexion...";
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string ID = to_string(idpuestos);

			string insert = "UPDATE puestos SET puestos = '" + puestos + "'" +
				"WHERE idPuestos = '" + ID + "'";
			const char* i = insert.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				gotoxy(45, 7); cout << "Actualizacion Exitosa ..." << endl;
			}
			else {
				gotoxy(45, 7); cout << " xxx Error al Actualizar  xxx" << endl;
			}

		}
		else {
			gotoxy(45, 7); cout << "...Error en la conexion...";
		}
		cn.cerrar_conexion();


	}


};

