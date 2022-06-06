#pragma once
#include "ConexionBD.h"
#include <string>
#include <iostream>
using namespace std;
class Venta
{
protected: int idVenta = 0, noFactura = 0, idcliente = 0, idempleado = 0;
		   char serie = {};
		   string fechafactura;

public:  Venta() {
		   }
		   Venta(int idv, int noF,int idc, char s, string ff, int ide) {
			   idVenta = idv;
			   noFactura = noF;
			   idcliente = idc;
			   idempleado = ide;
			   serie = s;
			   fechafactura = ff;
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
			   string nf = to_string(noFactura);
			   string idC = to_string(idcliente);
			   string idE = to_string(idempleado);
			   string se = to_string(serie);
			   if (cn.getConectar()) {
				   string insert = "INSERT INTO ventas(noFactura,serie,fechafactura,idcliente,idempleado,fechaingreso)values(" + nf + ",'"+ serie +"',now(), " + idC + ", " + idE + ", now()); ";
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


		   void leer() {
			   int q_estado;
			   ConexionBD cn = ConexionBD();
			   MYSQL_ROW fila;
			   MYSQL_RES* resultado;
			   cn.abrir_conexion();

			   if (cn.getConectar()) {
				   string consulta = "select v.noFactura,v.serie,v.fechafactura, concat(c.nombres,' ',c.apellidos) as cliente, concat(e.nombres, ' ',e.apellidos) as empleado from ventas v left join clientes c on c.idCliente = v.idcliente left join empleados e on e.idEmpleado = v.idempleado";
				   const char* c = consulta.c_str();
				   q_estado = mysql_query(cn.getConectar(), c);
				   if (!q_estado) {
					   resultado = mysql_store_result(cn.getConectar());
					   cout << "------------Venta---------------" << endl;
					   while (fila = mysql_fetch_row(resultado)) {
						   cout << "Codigo: " << fila[0] << " " << "No. Factura: " << fila[1] << " " << "Serie: " << fila[2] << " " << "Fecha Factura: " << fila[3] << " " << "cliente: " << fila[4] << " " << "Operador: " << fila[5] << endl;
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

		   void oneVenta() {
			   int q_estado;
			   ConexionBD cn = ConexionBD();
			   MYSQL_ROW fila;
			   MYSQL_RES* resultado;
			   cn.abrir_conexion();
			   string ID = to_string(idVenta);
			   if (cn.getConectar()) {
				   string consulta = "select v.noFactura,v.serie,v.fechafactura from ventas v left join clientes c on c.idCliente = v.idcliente left join empleados e on e.idEmpleado = v.idempleado where idVenta = '" + ID + "';";
				   const char* c = consulta.c_str();
				   q_estado = mysql_query(cn.getConectar(), c);
				   if (!q_estado) {
					   resultado = mysql_store_result(cn.getConectar());
					   gotoxy(45, 1); cout << "------------Datos de la venta---------------" << endl;
					   while (fila = mysql_fetch_row(resultado)) {
						   gotoxy(5, 2); cout << "No. Factura: " << fila[0];
						   gotoxy(25, 2); cout << "Serie: " << fila[1];
						   gotoxy(45, 2); cout << "Fecha Factura: " << fila[2];
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


		   int validarID() {
			   int idRequest = {};
			   int q_estado;
			   ConexionBD cn = ConexionBD();
			   MYSQL_ROW fila;
			   MYSQL_RES* resultado;
			   cn.abrir_conexion();
			   if (cn.getConectar()) {
				   string consulta = "select * from ventas order by idVenta desc limit 1;";
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

