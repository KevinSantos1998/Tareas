
#include "Byte.h"
#include <conio.h>

using std::cout;

int main()
{

	Byte b1("00010101‬");
	Byte b2("00000101");
	

	cout << "Byte: { " << b1 << " }\n";
	cout << "Decimal: { " << b1.obtenerDecimal() << " }\n";
	cout << "Byte: { " << b2 << " }\n";
	cout << "Decimal: { " << b2.obtenerDecimal() << " }\n";
	Byte b3 = b1 + b2; 

	cout << "Suma: { " << b3 << " }\n";

	cout << "Decimal: { " << b3.obtenerDecimal() << " }\n";

	Byte b4 = b1 - b2; 

	cout << "Resta: { " << b4 << " }\n";

	cout << "Decimal: { " << b4.obtenerDecimal() << " }\n";

	Byte b5 = b1 * b2;

	cout << "Multiplicacion: { " << b5 << " }\n"; 

	cout << "Decimal: { " << b5.obtenerDecimal() << " }\n";

	~b1;

	cout << "NOT:  { " << b1 << " }\n";


	_getch();
}