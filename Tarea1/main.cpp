#include <iostream>

using namespace std;

void Binario()
{
	char Res;
	bool verificar = true, verificar2 = false;
	int n1, n2, n3, n4, n5, n6,n7,n8,n9, decimal = 0;
	do
	{
		cout << "\nIngrese un Numero Binaro de 9 digitos (1,0) para convertir a decimal\n";
		do
		{
			cin >> n1;
			if (n1 == 1 || n1 == 0)
			{verificar2 = false;}	
			else
			{
				verificar2 = true;
				cout << "este no es un numero Binario\n";
			}	
		} while (verificar2);
		
		do
		{
			cin >> n2;
			if (n2 == 1 || n2 == 0)
			{
				verificar2 = false;
			}
			else
			{
				verificar2 = true;
				cout << "este no es un numero Binario\n";
			}
		} while (verificar2);

		do
		{
			cin >> n3;
			if (n3 == 1 || n3 == 0)
			{
				verificar2 = false;
			}
			else
			{
				verificar2 = true;
				cout << "este no es un numero Binario\n";
			}
		} while (verificar2);

		do
		{
			cin >> n4;
			if (n4 == 1 || n4 == 0)
			{
				verificar2 = false;
			}
			else
			{
				verificar2 = true;
				cout << "este no es un numero Binario\n";
			}
		} while (verificar2);

		do
		{
			cin >> n5;
			if (n5 == 1 || n5 == 0)
			{
				verificar2 = false;
			}
			else
			{
				verificar2 = true;
				cout << "este no es un numero Binario\n";
			}
		} while (verificar2);

		do
		{
			cin >> n6;
			if (n6 == 1 || n6 == 0)
			{
				verificar2 = false;
			}
			else
			{
				verificar2 = true;
				cout << "este no es un numero Binario\n";
			}
		} while (verificar2);

		do
		{
			cin >> n7;
			if (n7 == 1 || n7 == 0)
			{
				verificar2 = false;
			}
			else
			{
				verificar2 = true;
				cout << "este no es un numero Binario\n";
			}
		} while (verificar2);

		do
		{
			cin >> n8;
			if (n8 == 1 || n8 == 0)
			{
				verificar2 = false;
			}
			else
			{
				verificar2 = true;
				cout << "este no es un numero Binario\n";
			}
		} while (verificar2);

		do
		{
			cin >> n9;
			if (n9 == 1 || n9 == 0)
			{
				verificar2 = false;
			}
			else
			{
				verificar2 = true;
				cout << "este no es un numero Binario\n";
			}
		} while (verificar2);

		cout << "Esta seguro que este es el numero binario es: "<< n1 << n2 << n3 << n4 << n5 << n6 << n7 << n8 << n9 
			<< "\nquiere convertir a decimal Y(si) o N(no)"<<endl;
		cin >> Res;
		if (Res == 'y' || Res == 'Y')
			verificar = false;
	} while (verificar);
	if (n1 == 1)
		decimal = decimal + 256;
	if (n2 == 1)
		decimal = decimal + 128;
	if (n3 == 1)
		decimal = decimal + 64;
	if (n4 == 1)
		decimal = decimal + 32;
	if (n5 == 1)
		decimal = decimal + 16;
	if (n6 == 1)
		decimal = decimal + 8;
	if (n7 == 1)
		decimal = decimal + 4;
	if (n8 == 1)
		decimal = decimal + 2;
	if (n9 == 1)
		decimal = decimal + 1;
	
	cout << "Numero Binario: " << n1 << n2 << n3 << n4 << n5 << n6 << n7 << n8 << n9 << endl;
	cout << "Numero Decimal: " << decimal<< "\n\n";
}

void Primos() {
	int n, d = 2;
	cout << "\nNumero para sacar los primarios: ";
	cin >> n;
	cout << "{-";
	while (n != 1)
	{
		if (n % d == 0) {
			cout << d << "-";
			n = n / d;
		}
		else
			d = d + 1;
	}
	cout << "}\n\n";
}


void Fibonacci() {
	int cantidad, n1=0, n2=1, suma = 1, contador = 1;
	cout << "\ncantidad de la serie: ";
	cin >> cantidad;
	cout << n1;
	while(contador < cantidad)
	{
		cout << " - " << suma;
		suma = n1 + n2;
		n1 = n2;
		n2 = suma;
		contador++;
	}
	cout << "\n\n";
}


int main()
{
	int opc=0;
	
	while (opc!=4)
	{
		cout << "Menu Tarea #1\n"
			<< "1. Pimarios de un Numero\n"
			<< "2. Binarios a Decimal\n"
			<< "3. Serie Fibonacci\n"
			<< "4. Salri\n"
			<< "Elija una opcion: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			Primos();
		break;

		case 2:
			Binario();
		break;

		case 3:
			Fibonacci();
		break;
		}

	}
}