#pragma once
#ifndef CUENTA_H
#define CUENTA_H

class Cuenta
{
protected:
	double saldo;
	void ImprimirCuenta();
	void abonar(double);
	void cargar(double);
	void setSaldo(double);
	double getSaldo();

public:
	Cuenta();
	~Cuenta();
	Cuenta(double);
	

};



#endif // !CUENTA_H
