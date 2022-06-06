#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
using namespace std;
class Estudiante
{
protected: string carnet, nombres, apellidos, direccion, email,genero, fecha_nacimiento;
		 int telefono = 0, idestudiante = 0;

public:

	Estudiante(){}
	
		 Estudiante(int id, string car,string nom, string ape, string dir, string ema, int tel, string fn, string gen) {
			 idestudiante = id;
			 carnet = car;
			 nombres = nom;
			 apellidos = ape;
			 direccion = dir;
			 telefono = tel;
			 email = ema;
			 fecha_nacimiento = fn;
			 genero = gen;
			 
		 }


		 void crear() {
			 int q_estado;
			 ConexionBD cn = ConexionBD();
			 cn.abrir_conexion();
			 if (cn.getConectar()) {
				 string t = to_string(telefono);

				 string insert = "INSERT INTO estudiantes(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento)values('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + genero + "','" + email + "','" + fecha_nacimiento + "');";
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

		 void actualizar() {
			 int q_estado;
			 ConexionBD cn = ConexionBD();
			 cn.abrir_conexion();
			 if (cn.getConectar()) {
				 string t = to_string(telefono);
				 string ID = to_string(idestudiante);

				 string insert = "UPDATE estudiantes SET carnet = '" + carnet + "',"+
													  "nombres = '" + nombres + "',"+
													  "apellidos = '" + apellidos + "',"+
													  "direccion = '" + direccion + "'," +
													  "telefono = '" + t + "'," +
													  "genero = '" + genero + "'," +
					                                  "email = '" + email + "'," +
					                                  "fecha_nacimiento = '" + fecha_nacimiento + "'" +
					                                 "WHERE idestudiantes = '" + ID + "'";


				
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

		 void eliminar() {
			 int q_estado;
			 ConexionBD cn = ConexionBD();
			 cn.abrir_conexion();
			 if (cn.getConectar()) {
				 string ID = to_string(idestudiante);
				 string insert = "DELETE FROM estudiantes WHERE idestudiantes = '" + ID + "';";



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
				 string consulta = "select * from estudiantes";
				 const char* c = consulta.c_str();
				 q_estado = mysql_query(cn.getConectar(), c);
				 if (!q_estado) {
					 resultado = mysql_store_result(cn.getConectar());
					 cout << "------------Estudiantes---------------" << endl;
					 while (fila = mysql_fetch_row(resultado)) {
						 cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << ", " << fila[8] << ", " << fila[9] << endl;
					 }
				 }
				 else {
					 cout << "---Error al Ingresar la informacion---" << endl;
				 }
			 }
			 else {
				 cout << "...Error en la conexion...";
			 }
			 system("pause");
			 cn.cerrar_conexion();
		 }


};

