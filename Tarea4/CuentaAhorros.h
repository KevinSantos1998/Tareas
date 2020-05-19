#pragma once
#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H

#include "Cuenta.h"

class CuentaAhorros : public Cuenta
{
public:
	CuentaAhorros();
	CuentaAhorros(double,double);
	~CuentaAhorros();
	double calcularInteres();
	double getInteres();
	void setInteres(double);
	void ImprimirAhorros();
	void AbonarAhorro(double);
	void CargarAhorro(double);

private:
	double Tasa;
};


#endif // !CUENTAAHORROS_H
