#pragma once

#include <fstream>

#ifndef ALUMNO_H
#define ALUMNO_H

using namespace std;
struct alumnoRegistro
{
	int numeroCuenta;
	char nombre[30];
	float promedio;
};

class alumno
{
private:
	fstream Alumnos;

public:
	alumno();
	void AgregarAlumno();
	void EnlistarAlumnis();

};

#endif // !ALUMNO_H