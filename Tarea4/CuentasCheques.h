#pragma once
#ifndef CUENTASCHEQUES_H
#define CUENTASCHEQUES_H
#include "Cuenta.h"

class CuentasCheques : public Cuenta
{
public:
	CuentasCheques();
	CuentasCheques(double, double);
	~CuentasCheques();
	double getCuota();
	void setCuota(double);
	void AbonarCuota(double);
	void CargarCuota(double);
	void ImprimirCuota();

private:
	double cuota;
};



#endif // !CUENTASCHEQUES