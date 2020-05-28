#pragma once
#ifndef HEXAGECIMAL_H
#define HEXAGECIMAL_H
#include "Datos.h"

#include <string>
using namespace std;
class Decimal : public Datos
{
public:
	int Suma(int, int);
	int resta(int, int);
	int multiplicacion(int, int);
	double division(int, int);
	Decimal(string, int, int);
private:
	string num;

};


#endif // !HEXAGECIMAL_H