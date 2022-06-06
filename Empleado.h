#pragma once
#include "Persona.h"
#include <iostream>
using namespace std;

class Empleado : Persona
{
	string direccion, DPI, fecha_nacimiento, fecha_ingreso_labores;
	int puesto = 0, idempleado = 0;

public:
	Empleado() {}

	Empleado(int idEmp,string nom, string ape, int tel, string fi, char gen, string dir, string _dpi, string fn,string fil, int p) : Persona(nom, ape, tel, fi, gen)
	{
		direccion = dir;
		DPI = _dpi;
		fecha_nacimiento = fn;
		fecha_ingreso_labores = fil;
		puesto = p;
		idempleado = idEmp;
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "SELECT e.idEmpleado, e.nombres,e.apellidos,e.telefono,e.DPI, if(e.genero = 1,'masculino', 'femenino') as genero, e.fecha_nacimiento, p.puestos, e.fecha_inicio_labores, e.fechaingreso FROM empleados e left join puestos p on p.idPuestos = e.idPuestos";

			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "------------Empleados---------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Id: " << fila[0] << " " << "Nombres: " << fila[1] << " " << "Apellidos: " << fila[2] << " " << " " << "Telefono: " << fila[3] << " " << "DPI: " << fila[4] << " " << "genero:" << fila[5] << " " << "Fecha Nacimiento: " << fila[6]<<endl;
					cout << "Puesto: " << fila[7] << " " << "Fecha Inicio Labores: " << fila[8] << " " << "Fecha Ingresso" << fila[9] << endl;
				}
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

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string p = to_string(puesto);

			string insert = "INSERT INTO empleados(nombres,apellidos,direccion,telefono,DPI, genero, fecha_nacimiento,idPuestos,fecha_inicio_labores,fechaingreso)values('" + nombres + "', '" + apellidos + "', '" + direccion + "', " + t + ", '" + DPI + "', " + genero + ", '" + fecha_nacimiento + "', '" + p + "', '" + fecha_ingreso_labores + "', '" + fecha_ingreso + "');";
			const char* i = insert.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
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
			string ID = to_string(idempleado);
			string insert = "DELETE FROM empleados WHERE idEmpleado = '" + ID + "';";



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
		system("pause");

	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string p = to_string(puesto);
			string ID = to_string(idempleado);

			string insert = "UPDATE empleados SET nombres = '" + nombres + "'," +
				"apellidos = '" + apellidos + "'," +
				"direccion = '" + direccion + "'," +
				"telefono = '" + t + "'," +
				"DPI = '" + DPI + "'," +
				"genero = " + genero + "," +
				"fecha_nacimiento = '" + fecha_nacimiento + "'," +
				"idPuestos = '" + p + "'," +
				"fecha_inicio_labores = '" + fecha_ingreso_labores + "'," +
				"fechaingreso = '" + fecha_ingreso + "'" +
				"WHERE idEmpleado = '" + ID + "'";



			const char* i = insert.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Actualizar  xxx" << endl;
			}

		}
		else {
			cout << "...Error en la conexion...";
		}
		cn.cerrar_conexion();


	}

	bool validarEmpleado() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string ID = to_string(idempleado);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT * FROM empleados where idEmpleado ='" + ID + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				fila = mysql_fetch_row(resultado);
				
				if (fila) {
					return 1;
				}
				else {
					return 0;
				}

			}
		}
		else {
			cout << "...Error en la conexion...";
		}
		cn.cerrar_conexion();
	}

};

