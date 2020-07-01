#include "alumno.h"
#include <iostream>

alumno::alumno()
{
	Alumnos.open("alumnos.dat", ios::in | ios::out | ios::app | ios::binary);

	if (!Alumnos)
		cout << "Error en aertura en archivo de alumnos";

	Alumnos.close();
}

void alumno::AgregarAlumno()
{
	Alumnos.open("alumnos.dat", ios::in | ios::out | ios::app | ios::binary);

	alumnoRegistro nuevoAlumno;

	cout << "Ingrese numero de cuenta: ";
	cin >> nuevoAlumno.numeroCuenta;

	cout << "Ingrese nombre de alumno: ";
	cin >> nuevoAlumno.nombre;

	nuevoAlumno.promedio = 0;

	Alumnos.seekp(0, ios::end);// coloca el cursor de ESCRITURA en un byte especifico

	Alumnos.write(reinterpret_cast<const char*>(&nuevoAlumno), sizeof(alumnoRegistro));

	Alumnos.close();

	cout << "Alumno agregado\n";
}

void alumno::EnlistarAlumnis()
{
	Alumnos.open("alumnos.dat", ios::in | ios::binary);

	alumnoRegistro alumnoLectura;
	//colaca el cursor de LECTURA en un byte indicado
	Alumnos.seekg(0, ios::beg);

	Alumnos.read(reinterpret_cast<char*>(&alumnoLectura), sizeof(alumnoRegistro));

	while (!Alumnos.eof())
	{
		cout << "Alumno { cuenta: " << alumnoLectura.numeroCuenta << ", nombre : "
			<< alumnoLectura.nombre << ", promedio: " << alumnoLectura.promedio << " }\n";
		Alumnos.read(reinterpret_cast<char*>(&alumnoLectura), sizeof(alumnoRegistro));
	}

	Alumnos.close();
}


