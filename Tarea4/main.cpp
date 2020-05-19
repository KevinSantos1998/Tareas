#include <iostream>
#include "CuentaAhorros.h"
#include "CuentasCheques.h"
#include <conio.h>

using namespace std;

int main()
{

	CuentaAhorros c1(5000,0.25);
	cout << endl;
	c1.AbonarAhorro(1000);
	cout << endl;
	c1.ImprimirAhorros();
	cout << endl;
	c1.CargarAhorro(500);
	cout << endl;
	c1.ImprimirAhorros();
	cout << endl;
	cout << endl;
	CuentasCheques c2(5000, 500);
	cout << endl;
	c2.AbonarCuota(750);
	cout << endl;
	c2.ImprimirCuota();
	cout << endl;
	c2.CargarCuota(500);
	cout << endl;
	c2.ImprimirCuota();
	cout << endl;

	_getch();

}