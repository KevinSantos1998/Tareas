#include <iostream>
#include <conio.h>
#include "Racional.h"

using namespace std;

Racional::Racional() :d(0), n(0)
{}

Racional::Racional(int _n, int _d) : n(_n), d(_d)
{
	simplificar();
}

void Racional::imprimirRacional()
{
	if (d == 0 && n == 0)
	{
		cout << "resultado no definido";
	}
	else if (d == 0)
	{
		cout << "No se puede dividir por cero\n";
		return;
	}
	else
	{
		cout << "Forma Racional: { " << n << "/" << d << " }\n";
	}
}

void Racional::imprimirDecimal()
{
	if (d == 0 && n == 0)
	{
		cout << "resultado no definido";
		return;
	}
	else if (d == 0)
	{
		cout << "No se puede dividir por cero\n";
		return;
	}
	else
	{
		cout << "Foma Decimal: { " << (float(n) / float(d)) << " }\n";
	}
}

void Racional::simplificar(void)
{
	//  2/6 = 1/3

	int numeroMenor = obtenerOperandoMenor();

	for (int i = 2; i <= numeroMenor; i++)
	{
		if (n % i == 0 && d % i == 0)
		{
			n = n / i;
			d = d / i;
			i = 1;
		}
	}

}

int Racional::obtenerOperandoMenor()
{
	return (n < d ? n : d);
}

Racional Racional::Suma(Racional op)
{
	int denomidador;
	int numerador;
	if (d == op.d)
	{
		numerador = n + op.n;
		denomidador = d;
		return Racional(numerador, denomidador);
	}
	else
	{
		denomidador = d * op.d;
		numerador = (n * op.d) + (op.n * d);
		return Racional(numerador, denomidador);
	}
}

Racional Racional::Resta(Racional op)
{
	int denomidador;
	int numerador;
	if (d == op.d)
	{
		numerador = n - op.n;
		denomidador = d;
		return Racional(numerador, denomidador);
	}
	else
	{
		denomidador = d * op.d;
		numerador = (n * op.d) - (op.n * d);
		return Racional(numerador, denomidador);
	}
}

Racional Racional::Multiplicacion(Racional op)
{
	return Racional((n * op.n), (d * op.d));
}

Racional Racional::Division(Racional op)
{
	return Racional((n * op.d), (d * op.n));
}
