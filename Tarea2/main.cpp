#include <iostream>
#include <conio.h>
#include "Racional.h"

using namespace std;

int main()
{
	Racional n1;
	Racional n2(1, 2);
	Racional n3(6, 3);

	cout << "n1: \n";
	n1.imprimirRacional();
	n1.imprimirDecimal();

	cout << "\nn2: \n";
	n2.imprimirRacional();
	n2.imprimirDecimal();

	cout << "\nn3: \n";
	n3.imprimirRacional();
	n3.imprimirDecimal();

	cout << "\nsuma de n2 + n3: \n";
	n1 = n2.Suma(n3);
	n1.imprimirRacional();
	n1.imprimirDecimal();

	cout << "\nresta de n2 + n3: \n";
	n1 = n2.Resta(n3);
	n1.imprimirRacional();
	n1.imprimirDecimal();

	cout << "\nmultiplicacion de n2 + n3: \n";
	n1 = n2.Multiplicacion(n3);
	n1.imprimirRacional();
	n1.imprimirDecimal();

	cout << "\ndivision de n2 + n3: \n";
	n1 = n2.Division(n3);
	n1.imprimirRacional();
	n1.imprimirDecimal();

	_getch();
}