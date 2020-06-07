#pragma once


#ifndef SECCIONLISTA_H
#define SECCIONLISTA_H

#include "AlumnoNodo.h"

class SeccionLista
{
private:
	AlumnoNodo* primero;

public:
	SeccionLista();

	bool estaVacia();
	void agregarAlumno(const char*, double);
	void ListarSeccion();
	void CantidadAprobados();

};

#endif // !SECCIONLISTA_H