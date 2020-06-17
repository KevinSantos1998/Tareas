#pragma once


#ifndef NODOEMPLEADO_H
#define NODOEMPLEADO_H

class NodoEmpleado
{
private:
	int Codigo;
	const char* Nombre;
	double Salario;
	NodoEmpleado* siguiente;
	NodoEmpleado* anterior;

public:
	NodoEmpleado(void);
	//Valor del nodo, ptrAnterior, ptrSiguiente
	NodoEmpleado(int,const char*,double, NodoEmpleado*, NodoEmpleado*);

	void setCodigo(int);
	void setNombre(const char*);
	void setSalario(double);
	void setSiguiente(NodoEmpleado*);
	void setAnterior(NodoEmpleado*);

	const char* getNombre();
	double getSalrio();
	int getCodigo();
	NodoEmpleado* getAnterior();
	NodoEmpleado* getSiguiente();

};

#endif // !NODOEMPLEADO_H