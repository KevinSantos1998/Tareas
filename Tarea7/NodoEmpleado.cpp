#include "NodoEmpleado.h"


NodoEmpleado::NodoEmpleado() : Codigo(-1),Nombre(nullptr),Salario(0), anterior(nullptr), siguiente(nullptr)
{}

NodoEmpleado::NodoEmpleado(int _valor,const char* _nombre,double _salario, NodoEmpleado* _anterior, NodoEmpleado* _siguiente)
{
	setNombre(_nombre);
	setSalario(_salario);
	setCodigo(_valor);
	setAnterior(_anterior);
	setSiguiente(_siguiente);
}

void NodoEmpleado::setCodigo(int _codigo)
{
	this->Codigo = _codigo;
}

void NodoEmpleado::setAnterior(NodoEmpleado* _anterior)
{
	this->anterior = _anterior;
}

void NodoEmpleado::setSiguiente(NodoEmpleado* _siguiente)
{
	this->siguiente = _siguiente;
}

int NodoEmpleado::getCodigo()
{
	return Codigo;
}

NodoEmpleado* NodoEmpleado::getAnterior()
{
	return anterior;
}

NodoEmpleado* NodoEmpleado::getSiguiente()
{
	return siguiente;
}	

void NodoEmpleado::setNombre(const char* _nombre) 
{
	this->Nombre = _nombre;
}
void NodoEmpleado::setSalario(double _salario) 
{
	this->Salario = _salario;
}
const char* NodoEmpleado::getNombre()
{
	return Nombre;
}
double NodoEmpleado::getSalrio()
{
	return Salario;
}