#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <string>
using namespace std;
class Producto
{
protected: string producto, descripcion, fecha_ingreso;
		 int idMarca = 0, idProducto = 0, existencia = 0;
		 float precio_costo = 0.0, precio_venta = 0.0;

public:	Producto() {}

	  Producto(int idP, string pro, string des, string fi, int idM, int exi, float pc, float pv) {
		  idProducto = idP;
		  idMarca = idM;
		  descripcion = des;
		  producto = pro;
		  fecha_ingreso = fi;
		  existencia = exi;
		  precio_costo = pc;
		  precio_venta = pv;
	  }

	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  string im = to_string(idMarca);
		  string e = to_string(existencia);
		  string p_c = to_string(precio_costo);
		  string p_v = to_string(precio_venta);




		  if (cn.getConectar()) {
			  string insert = "INSERT INTO productos(producto,idMarca,descripcion,precio_costo,precio_venta, existencia,fecha_ingreso)values('" + producto + "'," + im + ", '" + descripcion + "', " + p_c + ", " + p_v + ", " + e + ", '" + fecha_ingreso + "'); ";
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
			  string ID = to_string(idProducto);
			  string insert = "DELETE FROM productos WHERE idProducto = '" + ID + "';";
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
			  string consulta = "select p.idProducto,p.producto,marca,p.descripcion,p.precio_costo,p.precio_venta,p.existencia,p.fecha_ingreso from productos p left join marcas m on m.idMarca = p.idMarca";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  cout << "------------Productos---------------" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "Id: " << fila[0] << " " << "Producto: " << fila[1] << " " << "Marca: " << fila[2] << " " << "Descripcion: " << fila[3] << " " << "Existencia: " << fila[6] << endl;
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
		  string im = to_string(idMarca);
		  string e = to_string(existencia);
		  string p_c = to_string(precio_costo);
		  string p_v = to_string(precio_venta);

		  if (cn.getConectar()) {
			  string ID = to_string(idMarca);

			  string insert = "UPDATE productos SET producto = '" + producto + "'," +
				  "idMarca = " + im + "," +
				  "descripcion = '" + descripcion + "'," +
				  "precio_costo = " + p_c + "," +
				  "precio_venta = " + p_v + "," +
				  "existencia = " + e + "," +
				  "fecha_ingreso = '" + fecha_ingreso + "'" +
				  "WHERE idProducto = '" + ID + "'";



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

