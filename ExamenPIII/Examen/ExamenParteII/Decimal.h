#pragma once
#ifndef DECIMAL_H
#define DECIMAL_H
#include "Datos.h"
class Decimal : public Datos
{
public:
	int Suma(int, int);
	int resta(int, int);
	int multiplicacion(int, int);
	double division(int, int);
	Decimal(int, int, int);
private:
	int num;

};


#endif // DECIMAL_H