#pragma once
#ifndef NOTAS_H
#define NOTAS_H

#include <fstream>
using namespace std;

struct NotaRegistro
{
	int numeroCuenta;
	int codigoMateria;
	float nota;
};

class Nota {
private:
	fstream nota;

public:
	Nota();
	void agregarNota();
	void Actualizar();
	void EnlistarNota(int);
};

#endif // !NOTAS_H
