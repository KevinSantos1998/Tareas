
#include <iostream>
#include <conio.h>
#include "EmpresaLista.h"

using namespace std;

int main()
{

	EmpresaLista el;

	(el.agregarEmpleado(100, "Kevin", 2500))? cout << "se arego empleado\n" : cout << "no se pudo agregar Empleado\n";
	el.imprimirEmpleados();
	(el.agregarEmpleado(101, "Samara", 1500)) ? cout << "se arego empleado\n" : cout << "no se pudo agregar Empleado\n";
	el.imprimirEmpleados();
	(el.agregarEmpleado(102, "Carlos", 3500)) ? cout << "se arego empleado\n" : cout << "no se pudo agregar Empleado\n";
	el.imprimirEmpleados();
	(el.agregarEmpleado(103, "Juan", 4500)) ? cout << "se arego empleado\n" : cout << "no se pudo agregar Empleado\n";
	el.imprimirEmpleados();
	(el.insertarEmpleado(99, "Pedro", 4500)) ? cout << "se inserto empleado\n" : cout << "no se pudo insertar Empleado\n";
	el.imprimirEmpleados();
	(el.insertarEmpleado(98, "Gabriel", 4500)) ? cout << "se inserto empleado\n" : cout << "no se pudo inserto Empleado\n";
	el.imprimirEmpleados();
	(el.eliminarEmpleado(98)) ? cout << "se elimino empleado\n" : cout << "no se pudo eliminar Empleado\n";
	el.imprimirEmpleados();
	(el.eliminarEmpleado(99)) ? cout << "se elimino empleado\n" : cout << "no se pudo eliminar Empleado\n";
	el.imprimirEmpleados();
	(el.eliminarEmpleado(103)) ? cout << "se elimino empleado\n" : cout << "no se pudo eliminar Empleado\n";
	el.imprimirEmpleados();
	el.ActualizarSalario(0.5);
	el.imprimirEmpleados();

	_getch();
}