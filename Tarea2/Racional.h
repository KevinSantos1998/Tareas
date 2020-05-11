#pragma once
#ifndef RACINAL_H
#define RACINAL_H

class Racional
{
public:
	Racional();
	Racional(int, int);
	void imprimirRacional();
	void imprimirDecimal();
	Racional Suma(Racional);
	Racional Resta(Racional);
	Racional Multiplicacion(Racional);
	Racional Division(Racional);

private:
	int n;
	int d;
	void simplificar(void);
	int obtenerOperandoMenor(void);
};

#endif // !RACINAL_H#pragma once
