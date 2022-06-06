#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <string>
using namespace std;
class Proveedor
{
protected: string proveedor, nit, direccion, telefono;
		 int idProveedor = 0;

public:	Proveedor() {}

	  Proveedor(int idProv,string pro , string n, string dir, string tel) {
		  idProveedor = idProv;
		  proveedor = pro;
		  nit = n;
		  direccion = dir;
		  telefono = tel;
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
			  string insert = "INSERT INTO Proveedores(proveedor,nit,direccion,telefono)values('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "');";
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
			  string ID = to_string(idProveedor);
			  string insert = "DELETE FROM Proveedores WHERE idProveedor = '" + ID + "';";
			  const char* i = insert.c_str();
			   //executar el query
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
			  string consulta = "select * from Proveedores";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  cout << "------------Proveedor---------------" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Codigo: " << fila[0] << " " << "Nombre: " << fila[1] << " " << "nit: " << fila[2] << " " << "direccion: " << fila[3] << " " << "telefono: " << fila[4] << endl;
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

	  void leerMenu() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();

		  if (cn.getConectar()) {
			  string consulta = "select * from Proveedores";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  int column = 4;
				  resultado = mysql_store_result(cn.getConectar());
				  gotoxy(45, 2); cout << "------------Proveedor---------------" << endl;
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
			  string ID = to_string(idProveedor);

			  string insert = "UPDATE Proveedores SET Proveedor = '" + proveedor + "'" +
				  "WHERE idProveedor = '" + ID + "'";
			  const char* i = insert.c_str();
			   //executar el query
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

