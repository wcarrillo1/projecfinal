#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <string>
using namespace std;
class Compra_detalle
{
protected: 
		 int idCompra_detalle = 0, idCompra = 0, idProducto = 0, cantidad = 0;
		 float precio_costo_unitario = 0.00;

public:	Compra_detalle() {}

	  Compra_detalle(int idCd,int idC, int idPro, int cant, float pcu) {
		  idCompra_detalle = idCd;
		  idCompra = idC;
		  idProducto = idPro;
		  cantidad = cant;
		  precio_costo_unitario = pcu;
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
		  string idC = to_string(idCompra);
		  string Ip = to_string(idProducto);
		  string can = to_string(cantidad);
		  string pc = to_string(precio_costo_unitario);
		  if (cn.getConectar()) {
			  string insert = "INSERT INTO compras_detalle(idCompra,idProducto,cantidad,precio_costo_unitario)values(" + idC + "," + Ip + "," + can + "," + pc + ")";
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
		  string ID = to_string(idCompra);
		  if (cn.getConectar()) {
			  string consulta = "select * from compras_detalle where idCompra = '" + ID + "';";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  int column = 5;
				  float tot = 0.00, sum = 0.00;
				     gotoxy(45, 4);	cout << "----------Detalle de la compra---------------" << endl;
							while (fila = mysql_fetch_row(resultado)) {
								if (fila) {
									
									tot = atof(fila[3]) * atof(fila[4]);
									gotoxy(5, column);	cout << "id Detalle Compra:" << fila[0];
									gotoxy(30, column); cout << "No. Compra:" << fila[1]; 
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
							gotoxy(82, column+1); cout << "Total de la Compra:" << sum;
							gotoxy(5, column+2); system("pause");
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

