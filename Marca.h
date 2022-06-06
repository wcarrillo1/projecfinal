#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <string>
using namespace std;
class Marca
{
protected: string marcas;
		 int idMarca = 0;

public:	Marca() {}

	  Marca(int idm, string mar) {
		  idMarca = idm;
		  marcas = mar;
	  }

	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();

		  if (cn.getConectar()) {
			  string insert = "INSERT INTO marcas(marca)values('" + marcas + "');";
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
			  string ID = to_string(idMarca);
			  string insert = "DELETE FROM marcas WHERE idMarca = '" + ID + "';";
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
			  string consulta = "select * from marcas";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  cout << "------------Marcas---------------" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Codigo: " << fila[0] << " " << "Nombre: " << fila[1] << endl;
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

	  void actualizar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string ID = to_string(idMarca);

			  string insert = "UPDATE marcas SET marca = '" + marcas + "'" +
				  "WHERE idMarca = '" + ID + "'";
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


};

