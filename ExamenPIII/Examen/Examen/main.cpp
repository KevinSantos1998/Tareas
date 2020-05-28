#include <iostream>
#include <conio.h>
#include "Conjunto.h"

using namespace std;

int main ()
{
	Conjunto lol("1964700000");
	Conjunto lol2("7589600000");
	Conjunto lol3;
	lol3 = lol + lol2;
	cout << lol3<<"\n";
	lol3 = lol & lol2;
	cout << lol3 << "\n";
	lol3 = lol - lol2;
	cout << lol3 << "\n";
	if(lol==lol2)
	{
		cout << "los conjuntos son iguales";
	}
	else
	{
		cout << "los conjuntos son diferentes";
	}
	_getch();
}
