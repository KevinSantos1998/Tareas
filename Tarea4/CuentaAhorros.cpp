
#include "CuentaAhorros.h"
#include <iostream>

using namespace std;

CuentaAhorros::~CuentaAhorros() 
{
	cout << "se destruyo la cuenta de Ahorro";
}

CuentaAhorros::CuentaAhorros():Tasa(0), Cuenta(){}

CuentaAhorros::CuentaAhorros(double _saldo,double interes):Tasa(interes),Cuenta(_saldo)
{
	cout << "se creo una cuenta de ahorro";
}

double CuentaAhorros::getInteres()
{
	return this->Tasa;
}

void CuentaAhorros::setInteres(double interes)
{
	this->Tasa;
}

double CuentaAhorros::calcularInteres()
{
	return (this->getSaldo() * this->Tasa);
}

void CuentaAhorros::ImprimirAhorros()
{
	this->ImprimirCuenta();
	cout << "La Tasa de la cuenta de Ahorros es: " << getInteres()<<" por lo cual eol monto de interes es: " <<calcularInteres();
}

void CuentaAhorros::AbonarAhorro(double monto)
{
	this->abonar(monto);
}

void CuentaAhorros::CargarAhorro(double monto)
{
	this->cargar(monto);
}

