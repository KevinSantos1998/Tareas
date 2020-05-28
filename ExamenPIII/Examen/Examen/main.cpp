#include <iostream>
#include <conio.h>
#include "Conjunto.h"

using namespace std;

int main ()
{
	Conjunto lol("1964700000");
	Conjunto lol2("7589600000");
	Conjunto lol3;
	lol3 = lol & lol2;
	cout << lol3;
	_getch();
}