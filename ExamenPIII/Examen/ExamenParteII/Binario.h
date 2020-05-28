#pragma once
#ifndef BINARIO_H
#define BINARIO_H
#include "Datos.h"
class Binario : public Datos
{
public:
	int Suma(int, int);
	int resta(int, int);
	int multiplicacion(int, int);
	double division(int, int);
	Binario(const char, int, int);
private:
	int num[10];

};


#endif // !BINARIO_H