
#include "AlumnoNodo.h"
#include <string.h>

AlumnoNodo::AlumnoNodo(void) : Nombre(nullptr), Nota(-1), siguiente(nullptr)
{}

AlumnoNodo::AlumnoNodo(const char* _nombre, double _nota, AlumnoNodo* _siguiente)
{
	setNombre(_nombre);
	setNota(_nota);
	setSiguiente(_siguiente);
}

void AlumnoNodo::setNota(double _nota)
{
	this->Nota = _nota;
}

void AlumnoNodo::setNombre(const char* _nombre)
{
	this->Nombre = _nombre;
}

void AlumnoNodo::setSiguiente(AlumnoNodo* _siguiente)
{
	this->siguiente = _siguiente;
}

double AlumnoNodo::getNota(void)
{
	return Nota;
}

const char* AlumnoNodo::getNombre(void)
{
	return Nombre;
}

AlumnoNodo* AlumnoNodo::getSiguiente(void)
{
	return siguiente;
}