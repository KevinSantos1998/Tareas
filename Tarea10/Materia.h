#pragma once
#include <fstream>

#ifndef MATERIA_H
#define MATERIA_H

using namespace std;
struct MateriaRegistro
{
	int codigoMateria;
	char nombre[20];
	int UnidadesValorativas;
};

class Materia
{
private:
	fstream MateriaB;

public:
	Materia();
	void AgregarMateria();
	void EnlistarMateria();
};

#endif // !ALUMNO_H