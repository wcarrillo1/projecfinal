#include <iostream>
#include <string>
#include <fstream>
#include <mysql.h>
#include "Estudiantes.h"
#include "Puesto.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Marca.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Compra.h"
#include "Compra_detalle.h"
#include "Venta.h"
#include "Venta_detalle.h"
using namespace std;

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void menuPrincipal() {

	system("cls"); system("color f0");

	gotoxy(45,2); cout << "******Menu Principal********" << endl;
	gotoxy(45, 3); cout << "*  1.Administracion       *" << endl;
	gotoxy(45, 4); cout << "*  2.Operador             *" << endl;
	gotoxy(45, 5); cout << "*  3.Salir                *" << endl;
	gotoxy(45, 6); cout << "*  Seleccione una Opcion: *";
	gotoxy(45, 7); cout << "***************************" << endl;
}

void menuAdministracion() {
	gotoxy(45, 2); cout << "Bienvendio al menu de administracion" << endl;
	gotoxy(45, 3); cout << "1.Puestos" << endl;
	gotoxy(45, 4); cout << "2.Clientes" << endl;
	gotoxy(45, 5); cout << "3.Empleados" << endl;
	gotoxy(45, 6); cout << "4.Marcas" << endl;
	gotoxy(70, 3); cout << "5.Producto" << endl;
	gotoxy(70, 4); cout << "6.Proveedores" << endl;
	gotoxy(70, 5); cout << "7.Compras" << endl;
	gotoxy(45, 7); cout << "Selecciona una Opcion:" << endl;
}

void menuOperador() {
	gotoxy(45, 2); cout << "Bienvendio al menu de Operador" << endl;
	gotoxy(45, 3); cout << "1.Ventas" << endl;
}

void menuPuestos() {
	string puesto;
	int opP = 0, idpuestos = 0;
	do {
		opP = 0;
		system("cls");
		gotoxy(45, 2); cout << "Catalogo de puestos" << endl;
		gotoxy(45, 3); cout << "1.Ver Registro" << endl;
		gotoxy(45, 4); cout << "2.Crear" << endl;
		gotoxy(45, 5); cout << "3.Editar registro" << endl;
		gotoxy(45, 6); cout << "4.Eliminar registro" << endl;
		gotoxy(45, 7); cout << "5.Salir al menu principal" << endl;
		gotoxy(45, 8); cout << "Ingresa una Opcion: " << endl;
		gotoxy(64, 8); cin >> opP;

		if (opP == 1) {
			system("cls");
			
			Puesto Pue = Puesto();
			Pue.leer();
			
		}
		if (opP == 2) {
			system("cls");
			gotoxy(45, 2); cout << "<<<<<Ingresar Puesto>>>>>" << endl;
			gotoxy(45, 3); cout << "Ingresa el nombre del puesto" << endl;
			gotoxy(45, 4); cin >> puesto;
			Puesto Pue = Puesto(idpuestos, puesto);
			Pue.crear();
			gotoxy(45, 6); system("pause");
		}
		if (opP == 3) {

			system("cls");
			Puesto Pue1 = Puesto();
			Pue1.leer();
			system("cls");
			gotoxy(45, 2); cout << "<<<<<Editar Puesto>>>>" << endl;
			gotoxy(45, 3); cout << "Ingresa el id del puesto: " << endl;
			gotoxy(45, 4); cin >> idpuestos;
			gotoxy(45, 5); cout << "Ingresa el nombre del puesto" << endl;
			gotoxy(45, 6); cin >> puesto;
			Puesto Pue = Puesto(idpuestos, puesto);
			Pue.actualizar();
			gotoxy(45, 9); system("pause");
		}
		if (opP == 4) {

			Puesto Pue1 = Puesto();
			Pue1.leer();
			system("cls");
			gotoxy(45, 2); cout << "<<<<<Eliminar Puesto>>>>" << endl;
			gotoxy(45, 3); cout << "Ingresa el id del puesto: " << endl;
			gotoxy(45, 4); cin >> idpuestos;
			Puesto Pue = Puesto(idpuestos, puesto);
			Pue.eliminar();
			gotoxy(45, 9); system("pause");
		}

	} while (opP != 5);
	
	system("pause");
}

void ingresoCliente() {
	char genero = {};
	string nombres, apellidos, nit, correo_electronico, fechaIngreso;
	int  telefono = 0, idcliente = 0;
	cout << "<<<<<Ingresar Cliente" << endl;
	cout << "Ingresa los nombres del Cliente" << endl;
	getline(cin,nombres);
	getline(cin, nombres);
	cout << "Ingresa los apellidos del Cliente" << endl;
	cin >> apellidos;
	cout << "Ingresa el telefono del Cliente" << endl;
	cin >> telefono;
	cout << "Ingresa el nit del Cliente" << endl;
	cin >> nit;
	cout << "Ingresa el Genero del Cliente" << endl;
	cout << "Ingresa 1.Masculino o 2.Femenino" << endl;
	cin >> genero;
	cout << "Ingresa el email del Cliente" << endl;
	cin >> correo_electronico;
	cout << "Ingresa la fecha de Ingreso del Cliente" << endl;
	cin >> fechaIngreso;
	Cliente Obj = Cliente(idcliente,nombres,apellidos,telefono,fechaIngreso,genero,nit,correo_electronico);
	Obj.crear();
}

void menuClientes() {
	char genero = {};
	string nombres, apellidos, nit, correo_electronico, fechaIngreso;
	int  telefono = 0, idcliente = 0, opC = 0;
	do {
		
		system("cls");
		cout << "Catalogo de clientes" << endl;
		cout << "1.Ver Registro" << endl;
		cout << "2.Crear" << endl;
		cout << "3.Editar registro" << endl;
		cout << "4.Eliminar registro" << endl;
		cout << "5.Salir al menu principal" << endl;
		cin >> opC;

		if (opC == 1) {
			system("cls");
			cout << "<<<<<Ver registros>>>>>" << endl;
			Cliente Obj = Cliente();
			Obj.leer();
			system("pause");
		}
		if (opC == 2) {
			system("cls");
			ingresoCliente();
			system("pause");
		}
		if (opC == 3) {
			system("cls");
			Cliente Cli1 = Cliente();
			Cli1.leer();

			cout << "<<<<<Editar Cliente" << endl;
			cout << "Ingresa el id del cliente" << endl;
			cin >> idcliente;
			cin.ignore();
			cout << "Ingresa los nombres del Cliente" << endl;
			
			getline(cin, nombres);
			cout << "Ingresa los apellidos del Cliente" << endl;
			cin >> apellidos;
			cout << "Ingresa el telefono del Cliente" << endl;
			cin >> telefono;
			cout << "Ingresa el nit del Cliente" << endl;
			cin >> nit;
			cout << "Ingresa el Genero del Cliente" << endl;
			cout << "Ingresa 1.Masculino o 2.Femenino" << endl;
			cin >> genero;
			cout << "Ingresa el email del Cliente" << endl;
			cin >> correo_electronico;
			cout << "Ingresa la fecha de Ingreso del Cliente" << endl;
			cin >> fechaIngreso;
			Cliente Obj = Cliente(idcliente, nombres, apellidos, telefono, fechaIngreso, genero, nit, correo_electronico);
			Obj.actualizar();

			system("pause");
		}
		if (opC == 4) {
			system("cls");
			Cliente cl = Cliente();
			cl.leer();
			cout << "<<<<<Eliminar Puesto" << endl;
			cout << "Ingresa el Codigo del puesto a eliminar" << endl;
			cin >> idcliente;
			Cliente Obj = Cliente(idcliente, nombres, apellidos, telefono, fechaIngreso, genero, nit, correo_electronico);
			Obj.eliminar();
		}

	} while (opC != 5);

	system("pause");
}

void menuEmpleados() {
	char genero = {};
	string nombres, apellidos,direccion, DPI, fecha_nacimiento,fecha_inicio_labores, fechaIngreso;
	int  telefono = 0, idempleado = 0, opC = 0, puestos = 0;
	do {

		system("cls");
		cout << "Catalogo de Empleados" << endl;
		cout << "1.Ver Registro" << endl;
		cout << "2.Crear" << endl;
		cout << "3.Editar registro" << endl;
		cout << "4.Eliminar registro" << endl;
		cout << "5.Salir al menu principal" << endl;
		cin >> opC;

		if (opC == 1) {
			system("cls");
			cout << "<<<<<Ver registros>>>>>" << endl;
			Empleado Obj = Empleado();
			Obj.leer();
			system("pause");
		}
		if (opC == 2) {
			system("cls");

			cout << "<<<<<Ingresar Empleados" << endl;
			cout << "Ingresa los nombres del Empleado" << endl;
			getline(cin, nombres);
			getline(cin, nombres);
			cout << "Ingresa los apellidos del Empleado" << endl;
			cin >> apellidos;
			cout << "Ingresa el telefono del Empleado" << endl;
			cin >> telefono;
			cout << "Ingresa el nit del Empleado" << endl;
			cin >> DPI;
			cout << "Ingresa el Genero del Empleado" << endl;
			cout << "Ingresa 1.Masculino o 2.Femenino" << endl;
			cin >> genero;
			cout << "Ingresa la fecha de Nacimiento del Empleado" << endl;
			cin >> fecha_nacimiento;
			cout << "Ingresa la fecha de Inicio de labores del Empleado" << endl;
			cin >> fecha_inicio_labores;
			cout << "Ingresa la fecha de Ingreso del Empleado" << endl;
			cin >> fechaIngreso;

			Puesto p = Puesto();
			p.leer();

			cout << "Ingresa el Puesto" << endl;
			cin >> puestos;
			Empleado Obj = Empleado(idempleado, nombres, apellidos, telefono, fechaIngreso, genero, direccion,DPI,fecha_nacimiento,fecha_inicio_labores,puestos);
			Obj.crear();

			system("pause");

		}
		if (opC == 3) {
			system("cls");
			Empleado Cli1 = Empleado();
			Cli1.leer();

			cout << "<<<<<Editar Empleado" << endl;
			cout << "Ingresa el id: " << endl;
			cin >> idempleado;
			cout << "Ingresa los nombres del Cliente" << endl;
			getline(cin, nombres);
			getline(cin, nombres);
			cout << "Ingresa los apellidos del Empleado" << endl;
			cin >> apellidos;
			cout << "Ingresa el telefono del Empleado" << endl;
			cin >> telefono;
			cout << "Ingresa el nit del Empleado" << endl;
			cin >> DPI;
			cout << "Ingresa el Genero del Empleado" << endl;
			cout << "Ingresa 1.Masculino o 2.Femenino" << endl;
			cin >> genero;
			cout << "Ingresa la fecha de Nacimiento del Empleado" << endl;
			cin >> fecha_nacimiento;
			cout << "Ingresa la fecha de Inicio de labores del Empleado" << endl;
			cin >> fecha_inicio_labores;
			cout << "Ingresa la fecha de Ingreso del Empleado" << endl;
			cin >> fechaIngreso;
			Puesto p = Puesto();
			p.leer();

			cout << "Ingresa el Puesto" << endl;
			cin >> puestos;

			Empleado Obj = Empleado(idempleado, nombres, apellidos, telefono, fechaIngreso, genero, direccion, DPI, fecha_nacimiento, fecha_inicio_labores, puestos);
			Obj.actualizar();

			system("pause");
		}
		if (opC == 4) {
			system("cls");
			Empleado cl = Empleado();
			cl.leer();
			cout << "<<<<<Eliminar Puesto" << endl;
			cout << "Ingresa el Codigo del puesto a eliminar" << endl;
			cin >> idempleado;
			Empleado Obj = Empleado(idempleado, nombres, apellidos, telefono, fechaIngreso, genero, direccion, DPI, fecha_nacimiento, fecha_inicio_labores, puestos);
			Obj.eliminar();
		}

	} while (opC != 5);

	system("pause");
}

void menuMarcas(){
	string marcas;
	int opM = 0, idMarcas = 0;
	do {
		opM = 0;
		system("cls");
		cout << "Catalogo de Marcas" << endl;
		cout << "1.Ver Registro" << endl;
		cout << "2.Crear" << endl;
		cout << "3.Editar registro" << endl;
		cout << "4.Eliminar registro" << endl;
		cout << "5.Salir al menu principal" << endl;
		cin >> opM;

		if (opM == 1) {
			system("cls");
			cout << "<<<<<Ver registros>>>>>" << endl;
			 Marca Obj = Marca();
			 Obj.leer();
			system("pause");
		}
		if (opM == 2) {
			system("cls");
			cout << "<<<<<Ingresar Marca" << endl;
			cout << "Ingresa el nombre de la marca" << endl;
			cin >> marcas;
			Marca Obj = Marca(idMarcas, marcas);
			Obj.crear();
			system("pause");
		}
		if (opM == 3) {

			system("cls");
			Marca Obj1 = Marca();
			Obj1.leer();

			cout << "<<<<<Editar Marca" << endl;
			cout << "Ingresa el id de la marca" << endl;
			cin >> idMarcas;
			cout << "Ingresa el nombre de la marca" << endl;
			cin >> marcas;
			Marca Obj = Marca(idMarcas, marcas);
			Obj.actualizar();
			system("pause");
		}
		if (opM == 4) {

			Marca Obj1 = Marca();
			Obj1.leer();
			cout << "<<<<<Eliminar Marca" << endl;
			cout << "Ingresa el Marca del puesto a eliminar" << endl;
			cin >> idMarcas;
			Marca Obj = Marca(idMarcas, marcas);
			Obj.eliminar();
		}

	} while (opM != 5);

	system("pause");
}

void menuProducto(){
	string producto, descripcion, fecha_ingreso;
	int idMarca = 0, idProducto = 0, existencia = 0, opP = 0;
	float precio_costo = 0.0, precio_venta = 0.0;

	do {
		opP = 0;
		system("cls");
		cout << "Catalogo de Producto" << endl;
		cout << "1.Ver Registro" << endl;
		cout << "2.Crear" << endl;
		cout << "3.Editar registro" << endl;
		cout << "4.Eliminar registro" << endl;
		cout << "5.Salir al menu principal" << endl;
		cin >> opP;

		if (opP == 1) {
			system("cls");
			cout << "<<<<<Ver registros>>>>>" << endl;
			Producto Obj = Producto();
			Obj.leer();
			system("pause");
		}
		if (opP == 2) {
			system("cls");
			cout << "<<<<<Ingresar Producto" << endl;
			cout << "Ingresa el nombre del Producto" << endl;
			cin >> producto;
			cout << "Ingresa Descripcion del Producto" << endl;
			cin >> descripcion;

			Marca M = Marca();
			M.leer();

			cout << "ingresa el id de la marca del Producto" << endl;
			cin >> idMarca;
			cout << "Ingresa la fecha de ingreso año/mes/dia del Producto" << endl;
			cin >> fecha_ingreso;
			cout << "ingresa el precio costo del Producto" << endl;
			cin >> precio_costo;
			cout << "ingresa el precio venta del Producto" << endl;
			cin >> precio_venta;
			cout << "ingresa la existencia del Producto" << endl;
			cin >> existencia;


			Producto Obj = Producto(idProducto,producto,descripcion,fecha_ingreso,idMarca,existencia,precio_costo,precio_venta);
			Obj.crear();
			system("pause");
		}
		if (opP == 3) {

			system("cls");
			Producto Obj = Producto();
			Obj.leer();

			cout << "<<<<<Editar Producto" << endl;
			cout << "Ingresa el id del puesto" << endl;
			cin >> idProducto;
			cout << "Ingresa el nombre del Producto" << endl;
			cin >> producto;
			cout << "Ingresa Descripcion del Producto" << endl;
			cin >> descripcion;

			Marca M = Marca();
			M.leer();

			cout << "ingresa el id de la marca del Producto" << endl;
			cin >> idMarca;
			cout << "Ingresa la fecha de ingreso año/mes/dia del Producto" << endl;
			cin >> fecha_ingreso;
			cout << "ingresa el precio costo del Producto" << endl;
			cin >> precio_costo;
			cout << "ingresa el precio venta del Producto" << endl;
			cin >> precio_venta;
			cout << "ingresa la existencia del Producto" << endl;
			cin >> existencia;


			Producto Obj2 = Producto(idProducto, producto, descripcion, fecha_ingreso, idMarca, existencia, precio_costo, precio_venta);
			Obj2.actualizar();
			system("pause");


			
		}
		if (opP == 4) {

			Producto Obj = Producto();
			Obj.leer();
			cout << "<<<<<Eliminar Producto" << endl;
			cout << "Ingresa el Codigo del Producto a eliminar" << endl;
			cin >> idProducto;
			Producto Obj2 = Producto(idProducto, producto, descripcion, fecha_ingreso, idMarca, existencia, precio_costo, precio_venta);
			Obj2.eliminar();
		}

	} while (opP != 5);

	system("pause");

}

void menuProveedores(){
	string proveedor, nit, direccion, telefono;
	int idProveedor = 0, opP = 0;
	do {
		opP = 0;
		system("cls");
		cout << "Catalogo de Proveedores" << endl;
		cout << "1.Ver Registro" << endl;
		cout << "2.Crear" << endl;
		cout << "3.Editar registro" << endl;
		cout << "4.Eliminar registro" << endl;
		cout << "5.Salir al menu principal" << endl;
		cin >> opP;

		if (opP == 1) {
			system("cls");
			cout << "<<<<<Ver registros>>>>>" << endl;
			Proveedor Pue = Proveedor();
			Pue.leer();
			system("pause");
		}
		if (opP == 2) {
			system("cls");
			cout << "<<<<<Ingresar Proveedor" << endl;
			cout << "Ingresa el nombre del proveedor" << endl;
			cin >> proveedor;
			cout << "Ingresa el nit del proveedor" << endl;
			cin >> nit;
			cout << "Ingresa la direccion del proveedor" << endl;
			cin >> direccion;
			cout << "Ingresa el telefono del proveedor" << endl;
			cin >> telefono;

			Proveedor obj = Proveedor(idProveedor,proveedor,nit,direccion,telefono);
			obj.crear();
			system("pause");
		}
		if (opP == 3) {

			system("cls");
			Proveedor Pue1 = Proveedor();
			Pue1.leer();

			cout << "<<<<<Editar Proveedor" << endl;
			cout << "Ingresa el id del proveedor" << endl;
			cin >> idProveedor;
			cout << "Ingresa el nombre del proveedor" << endl;
			cin >> proveedor;
			cout << "Ingresa el nit del proveedor" << endl;
			cin >> nit;
			cout << "Ingresa la direccion del proveedor" << endl;
			cin >> direccion;
			cout << "Ingresa el telefono del proveedor" << endl;
			cin >> telefono;
			
			Proveedor obj = Proveedor(idProveedor, proveedor, nit, direccion, telefono);
			obj.actualizar();
				
			system("pause");
		}
		if (opP == 4) {

			Proveedor Pue1 = Proveedor();
			Pue1.leer();
			cout << "<<<<<Eliminar Proveedor" << endl;
			cout << "Ingresa el Codigo del Proveedor a eliminar" << endl;
			cin >> idProveedor;
			Proveedor obj = Proveedor(idProveedor, proveedor, nit, direccion, telefono);
			obj.eliminar();
		}

	} while (opP != 5);

	system("pause");


}

void ingresarDetalle(int idC) {

	string fecha_orden;
	int idCompra_detalle = 0, idCom = idC, idProducto = 0, cantidad = 0, OPT = 0;
	float precio_uni = 0.0;
	gotoxy(45,2); cout << "-------Ingresar Detalle de la compra-------" << endl;
	gotoxy(45, 3); cout << "Ingresa el id. del producto" << endl;
	gotoxy(45, 4); cin >> idProducto;
	gotoxy(45, 5); cout << "Ingresa la cantidad" << endl;
	gotoxy(45, 6); cin >> cantidad;
	gotoxy(45, 7); cout << "Ingresa el precio de costo unitario" << endl;
	gotoxy(45, 8); cin >> precio_uni;
	Compra_detalle obj = Compra_detalle(idCompra_detalle, idCom, idProducto, cantidad, precio_uni);
	obj.crear();



}

void ingresarVenta(int idrev) {


	int idVenta_detalle = 0, idVenta = idrev, idProducto = 0, cantidad = 0;
	float precio_unitario = 0.00;

	gotoxy(45, 2); cout << "-------Ingresar Detalle de la Venta-------" << endl;
	gotoxy(45, 3); cout << "Ingresa el id. del producto" << endl;
	gotoxy(45, 4); cin >> idProducto;
	gotoxy(45, 5); cout << "Ingresa la cantidad" << endl;
	gotoxy(45, 6); cin >> cantidad;
	gotoxy(45, 7); cout << "Ingresa el precio de costo unitario" << endl;
	gotoxy(45, 8); cin >> precio_unitario;
	Venta_detalle obj = Venta_detalle(idVenta_detalle, idVenta, idProducto, cantidad, precio_unitario);
	obj.crear();

}

void ingresoCompra() {
	string fecha_orden;
	float precio_costo = 0.00;
	int idCompra = 0, op=0, no_orden_compra = 0, idProveedor = 0, idreq = 0, idCompra_detalle = 0, idProducto = 0, cantidad = 0;
	system("cls");
	Proveedor pro = Proveedor();
	pro.leerMenu();
	system("cls");
	gotoxy(45, 2); cout << "<<<<<Ingresar Compra" << endl;
	gotoxy(45, 3); cout << "Ingresa el No. Orden del proveedor" << endl;
	gotoxy(45, 4); cin >> no_orden_compra;
	gotoxy(45, 5); cout << "Ingresa el id del proveedor" << endl;
	gotoxy(45, 6); cin >> idProveedor;
	gotoxy(45, 7); cout << "Ingresa la fecha de la orden año/mes/dia" << endl;
	gotoxy(45, 8); cin >> fecha_orden;

	Compra obj = Compra(idCompra,fecha_orden,no_orden_compra,idProveedor);
	obj.crear();
	idreq = obj.validarID();

	do {
		op = 0;
		system("cls");
		Compra c = Compra(idreq, fecha_orden, no_orden_compra, idProveedor);
		c.oneCompra();
		Compra_detalle cd = Compra_detalle(idCompra_detalle, idreq, idProducto, cantidad, precio_costo);
		cd.leer();
		system("cls");
		gotoxy(45, 2); cout << "Desea Ingresar Detalle de la compra"<<endl;
		gotoxy(45, 3); cout << "1.Si o 2.No" << endl;
		gotoxy(45, 4); cin >> op;
		system("cls");
		

		if (op == 1) {
			ingresarDetalle(idreq);
		}


	} while (op != 2);
	

	


}

void menuCompras() {
	float precio_cost = 0.00;
	string fecha_orden;
	int idCompra = 0, idComDe = 0, idProducto = 0, cantidad = 0, no_orden_compra = 0, idProveedor = 0, opP = 0, idR = 0;
	

	do {
		opP = 0;
		system("cls");
		gotoxy(45, 2); cout << "Catalogo de Compras" << endl;
		gotoxy(45, 3); cout << "1.Ver Registro de Compras" << endl;
		gotoxy(45, 4); cout << "2.Crear" << endl;
		gotoxy(45, 5); cout << "3.Ver Registro Detallado" << endl;
		gotoxy(45, 6); cout << "4.Editar registro" << endl;
		gotoxy(45, 7); cout << "5.Eliminar registro" << endl;
		gotoxy(45, 8); cout << "6.Salir al menu principal" << endl;
		gotoxy(45, 9); cin >> opP;

		if (opP == 1) {
			system("cls");
			cout << "<<<<<Ver registros>>>>>" << endl;
			Compra Pue = Compra();
			Pue.leer();
			system("pause");
		}
		if (opP == 2) {
			
			ingresoCompra();
			system("pause");
		}
		if (opP == 3) {
			int idreq = 0, idCompra_detalle = 0;
			float precio_costo = 0.00;
			system("cls");
			gotoxy(45, 2); cout << "Ingresa el id de la compra que deseas consultar:";
			gotoxy(45, 3); cin >> idreq;
			system("cls");

			Compra c = Compra(idreq, fecha_orden, no_orden_compra, idProveedor);
			c.oneCompra();
			Compra_detalle cd = Compra_detalle(idCompra_detalle, idreq, idProducto, cantidad, precio_costo);
			cd.leer();
			system("pause");
		}
		if (opP == 4) {
			system("cls");
			gotoxy(45, 2); cout << "Ingresa el Codigo de la compra a editar" << endl;
			gotoxy(45, 3); cin >> idCompra;
			gotoxy(45, 4); cout << "<<<<<Editar Compra>>>>>" << endl;
			gotoxy(45, 5); cout << "Ingresa el No. Orden del proveedor" << endl;
			gotoxy(45, 6); cin >> no_orden_compra;
			gotoxy(45, 7); cout << "Ingresa el id del proveedor" << endl;
			gotoxy(45, 8); cin >> idProveedor;
			gotoxy(45, 9); cout << "Ingresa la fecha de la orden año/mes/dia" << endl;
			gotoxy(45, 10); cin >> fecha_orden;

			Compra obj = Compra(idCompra, fecha_orden, no_orden_compra, idProveedor);
			obj.crear();

		}
		if (opP == 5) {

			Proveedor Pue1 = Proveedor();
			Pue1.leer();
			cout << "<<<<<Eliminar Compra" << endl;
			cout << "Ingresa el Codigo del Proveedor a eliminar" << endl;
			cin >> idCompra;
			Compra obj = Compra(idCompra, fecha_orden, no_orden_compra, idProveedor);
			obj.eliminar();
		}

	} while (opP != 6);

	system("pause");
}

void menuVentas() {
	int op = 0, idProducto = 0, cantidad =  0, precio_costo = 0, idVenta = 0, idVenta_detalle = 0, noFactura = 0, idcliente = 0, idempleado = 0, telefono = 0,  opC = 0, puestos = 0, EmpExis=0, CliExis=0, opF = 0, idrev = 0;
	char serie = {}, genero = {};
	string fechafactura, nombres, apellidos, nit, correo_electronico, fechaIngreso,  direccion, DPI, fecha_nacimiento, fecha_inicio_labores;


	system("cls");
	


	do {

		system("cls");
		gotoxy(45, 2); cout << "ingrese el id del empleado: ";
		gotoxy(45, 3); cin >> idempleado;

		Empleado Obj = Empleado(idempleado, nombres, apellidos, telefono, fechaIngreso, genero, direccion, DPI, fecha_nacimiento, fecha_inicio_labores, puestos);
		EmpExis = Obj.validarEmpleado();
		
		if (EmpExis == 0) {

			cout << "Empleado no encontrado";
			cout << "Desea buscar de nuevo: ";
			cout << "1.Si o 2.No";
			cin >> opF;
		}

		if (EmpExis == 1) {

			system("cls");
			gotoxy(45, 2); cout << "ingrese el numero de nit para buscar al cliente";
			gotoxy(45, 3); cin >> nit;

			Cliente Obj = Cliente(idcliente, nombres, apellidos, telefono, fechaIngreso, genero, nit, correo_electronico);
			CliExis = Obj.validarCliente();

			if (CliExis > 0) {
				    system("cls");
					op = 0;
					Cliente Obj2 = Cliente(CliExis, nombres, apellidos, telefono, fechaIngreso, genero, nit, correo_electronico);
					Obj2.datosCliente();

					gotoxy(45, 4); cout << "<<<<<Ingresar Venta>>>>>" << endl;
					gotoxy(45, 5); cout << "Ingresa el No. factura" << endl;
					gotoxy(45, 6); cin >> noFactura;
					gotoxy(45, 7); cout << "Ingresa la serie" << endl;
					gotoxy(45, 8); cin >> serie;
					gotoxy(45, 9); cout << "Ingresa la fecha de la factura año/mes/dia" << endl;
					gotoxy(45, 10); cin >> fechafactura;

					Venta obv = Venta(idVenta, noFactura, CliExis, serie,fechafactura, idempleado);
					obv.crear();
					idrev = obv.validarID();

					do {
						op = 0;
						system("cls");
						Cliente Obj2 = Cliente(CliExis, nombres, apellidos, telefono, fechaIngreso, genero, nit, correo_electronico);
						Obj2.datosCliente();
						Venta obd = Venta(idVenta, noFactura, idcliente, serie, fechafactura, idempleado);
						obd.oneVenta();

						Venta_detalle cd = Venta_detalle(idVenta_detalle, idrev, idProducto, cantidad, precio_costo);
						cd.leer();
						system("cls");
						gotoxy(45, 2); cout << "Desea Ingresar Detalle de la Venta" << endl;
						gotoxy(45, 3); cout << "1.Si o 2.No" << endl;
						gotoxy(45, 4); cin >> op;
						system("cls");


						if (op == 1) {
							ingresarVenta(idrev);
						}


					} while (op != 2);




				}

			

			if (CliExis < 0) {
				int opI = 0;

				cout << "Cliente no encontrado desea Ingresarlo: ";
				cout << "1.Si o 2.No: ";
				cin >> opI;

				if (opI == 1) {
					ingresoCliente();
				}



			}


			

			system("cls");
		}
		


	
    
		


	} while (opF != 2);

	



	/*gotoxy(45, 2); cout << "<<<<<Ingresar Venta>>>>>" << endl;
	gotoxy(45, 3); cout << "Ingresa el No. Facuta" << endl;
	gotoxy(45, 4); cin >> noFactura;
	gotoxy(45, 5); cout << "Ingresa el id del proveedor" << endl;
	gotoxy(45, 6); cin >> idProveedor;
	gotoxy(45, 7); cout << "Ingresa la fecha de la orden año/mes/dia" << endl;
	gotoxy(45, 8); cin >> fecha_orden;

	Compra obj = Compra(idCompra, fecha_orden, no_orden_compra, idProveedor);
	obj.crear();
	idreq = obj.validarID();*/

	system("pause");
}

int main()
{
	int op = 0, opA = 0, opO = 0;

	do {
		system("cls");
		menuPrincipal();
		gotoxy(70, 6); cin >> op;
		switch (op)
		{
			case 1:
				system("cls");
				menuAdministracion();
				gotoxy(67, 7);cin >> opA;

					switch (opA)
					{
						case 1:
							menuPuestos();
						break;
						case 2:
							menuClientes();
							break;
						case 3:
							menuEmpleados();
							break;
						case 4:
							menuMarcas();
							break;
						case 5:
							menuProducto();
							break;
						case 6:
							menuProveedores();
							break;
						case 7:
							menuCompras();
							break;
						default:
						break;
					};
			break;

		case 2:
			system("cls");
			menuOperador();
			gotoxy(67, 7); cin >> opO;
					switch (opO)
					{
					case 1:
						menuVentas();
						break;
					default:
						break;
					}

			system("pause");
			break;
		default:
			break;
		}
			


			

	

			
			
	} while (op != 3);

	

}

