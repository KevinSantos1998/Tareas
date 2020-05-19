#include "CuentasCheques.h"
#include <iostream>

using namespace std;

CuentasCheques:: CuentasCheques():cuota(0),Cuenta(0){}

CuentasCheques::CuentasCheques(double _saldo,double monto):cuota(monto),Cuenta(_saldo)
{
	cout << "se creo una cuenta de Cheques";
}

CuentasCheques::~CuentasCheques()
{
	cout << "se destruyo la cuenta de Cheques";
}

double CuentasCheques::getCuota()
{
	return this->cuota;
}

void CuentasCheques::setCuota(double monto) 
{
	this->cuota = monto;
}

void CuentasCheques::AbonarCuota(double monto)
{
	if(monto>getCuota())
	{
		this->setSaldo(this->getSaldo() + (monto - getCuota()));
		cout << "se logro el abono";
	}
	else
	{
		cout << "el monto no es mayor que la cuota";
	}
}

void CuentasCheques::CargarCuota(double monto)
{
	if (monto < (this->getSaldo()-getCuota()))
	{
		this->setSaldo(this->getSaldo() - monto - getCuota());
		cout << "se logro el Cargar se logro";
	}
	else
	{
		cout << "el monto es mayor que la cuota y el saldo que contiene la cuenta";
	}
}

void CuentasCheques::ImprimirCuota()
{
	this->ImprimirCuenta();
	cout << "La Tasa de la cuenta de Ahorros es: " << getCuota();
}