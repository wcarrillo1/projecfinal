#pragma once
#include <iostream>
#include "ConexionBD.h"
#include "Compra_detalle.h"
#include <string>
using namespace std;
class Compra
{
protected: string fecha_orden;
		 int idCompraDetalle = 0, idCompra = 0, no_orden_compra = 0, idProveedor = 0, idProducto = 0 ,cantidad = 0, op = 0;
		 float precio_unitario = 0.0;

public:	Compra() {}

	  Compra(int idCom, string fo,int noc, int idP) {
		  idCompra = idCom;
		  fecha_orden = fo;
		  no_orden_compra = noc;
		  idProveedor = idP;
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
		  string No = to_string(no_orden_compra);
		  string Ip = to_string(idProveedor);
		  if (cn.getConectar()) {
			  string insert = "INSERT INTO Compras(no_orden_compra,idProveedor,fecha_orden,fechaingreso)values(" + No + "," + Ip + ",'" + fecha_orden + "',now());";
			  const char* i = insert.c_str();
			  // executar el query
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  gotoxy(45, 9); cout << "Ingreso Exitoso ..." << endl;
			  }
			  else {
				  gotoxy(45, 9); cout << " xxx Error al Ingresar  xxx" << endl;
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
			  string ID = to_string(idCompra);
			  string insert = "DELETE FROM Compras WHERE idCompra = '" + ID + "';";
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
			  string consulta = "select c.idCompra, c.no_orden_compra,p.proveedor,c.fecha_orden,c.fechaingreso from compras c left join proveedores p on p.idProveedor = c.idProveedor";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  cout << "------------Compra---------------" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Codigo: " << fila[0] << " " << "No. Orden: " << fila[1] << " " << "Proveedor: " << fila[2] << " " << "Fecha Orden: " << fila[3] << " " << "Fecha Ingreso: " << fila[4] << endl;
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

	  void oneCompra() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  string ID = to_string(idCompra);
		  if (cn.getConectar()) {
			  string consulta = "select c.no_orden_compra,p.proveedor,c.fecha_orden,c.fechaingreso from compras c left join proveedores p on p.idProveedor = c.idProveedor where idCompra = '" + ID + "';";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  gotoxy(45, 1); cout << "------------Datos de la compra---------------" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  gotoxy(5, 2); cout << "No. Orden: " << fila[0];
					  gotoxy(25, 2); cout << "Proveedor: " << fila[1];
					  gotoxy(45, 2); cout << "Fecha Orden: " << fila[2];
					  gotoxy(75, 2); cout << "Fecha Ingreso: " << fila[3]<<endl;
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
			  string ID = to_string(idCompra);
			  string nO = to_string(no_orden_compra);
			  string Ip = to_string(idProveedor);
			  string insert = "UPDATE Compra SET no_orden_compra = '" + nO + "'," +
				  "idProveedor = '" + Ip + "'," +
				  "fecha_orden = '" + fecha_orden + "'," +
				  "WHERE idCompra = '" + ID + "'";
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

	  int validarID() {
		  int idRequest = {};
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string consulta = "select * from compras order by idCompra desc limit 1;";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar()); 
				   fila = mysql_fetch_row(resultado);
				   idRequest = atoi(fila[0]);
			  }
		  }
		  return idRequest;
	  }
};

