#include "Cuenta.h"
#include <iostream>
#include <conio.h>
using namespace std;

Cuenta::Cuenta():saldo(0)
{
	cout << "se creo una cuenta con un monto de 0 que es invalido";
}

Cuenta::Cuenta(double _saldo):saldo(_saldo)
{
	cout << "se creo una cuenta con un Saldo de: "<<_saldo;
}

void Cuenta::setSaldo(double _saldo)
{
	this->saldo = _saldo;
}

double Cuenta::getSaldo()
{
	return this->saldo;
}

Cuenta::~Cuenta()
{
	cout << "se destruyo esta cuenta";
}

void Cuenta::abonar(double monto) 
{

	setSaldo(getSaldo() + monto);

}

void Cuenta::cargar(double monto)
{
	if (getSaldo() < monto)
	{
		cout << "El monto de: {"<< monto <<"} es demasiado alto para el Saldo de: {"<<getSaldo()<<"} que contiene la cuenta";
	}
	else
	{
		setSaldo(getSaldo() - monto);
	}
	
}

void Cuenta::ImprimirCuenta()
{
	cout << "El saldo de la cuenta es de: " << getSaldo();
}