#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <string>
using namespace std;
class Venta_detalle
{
protected:
	int idVenta_detalle = 0, idVenta = 0, idProducto = 0, cantidad = 0;
	float precio_unitario = 0.00;

public:	Venta_detalle() {}

	  Venta_detalle(int idVd, int idv, int idPro, int cant, float pcu) {
		  idVenta_detalle = idVd;
		  idVenta = idv;
		  idProducto = idPro;
		  cantidad = cant;
		  precio_unitario = pcu;
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
		  string idC = to_string(idVenta);
		  string Ip = to_string(idProducto);
		  string can = to_string(cantidad);
		  string pc = to_string(precio_unitario);
		  if (cn.getConectar()) {
			  string insert = "INSERT INTO venta_detalle(idVenta,idProducto,cantidad,precio_unitario)values(" + idC + "," + Ip + "," + can + "," + pc + ")";
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

	  void leer() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  string ID = to_string(idVenta);
		  if (cn.getConectar()) {
			  string consulta = "select * from venta_detalle where idVenta = '" + ID + "';";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  int column = 5;
				  float tot = 0.00, sum = 0.00;
				  gotoxy(45, 4);	cout << "----------Detalle de la Venta---------------" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  if (fila) {

						  tot = atof(fila[3]) * atof(fila[4]);
						  gotoxy(5, column);	cout << "id Detalle Venta:" << fila[0];
						  gotoxy(30, column); cout << "No. Venta:" << fila[1];
						  gotoxy(45, column); cout << "idProducto:" << fila[2];
						  gotoxy(60, column); cout << "Cantidad:" << fila[3];
						  gotoxy(75, column); cout << "Precio Costo:" << fila[4];
						  gotoxy(95, column); cout << "Total:" << tot;

						  sum = sum + tot;
						  column++;
					  }
					  else {
						  cout << "sin datos aun";
					  }
				  }
				  gotoxy(5, column); cout << "----------------------------------------------------------------------------------------------------------";
				  gotoxy(82, column + 1); cout << "Total de la venta:" << sum;
				  gotoxy(5, column + 2); system("pause");
			  }
			  else {
				  cout << "---No existen datos en el detalle de la compra---" << endl;
			  }


		  }
		  else {
			  cout << "...Error en la conexion...";
		  }
		  cn.cerrar_conexion();
	  }


};

