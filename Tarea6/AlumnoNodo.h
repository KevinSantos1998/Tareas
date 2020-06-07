#pragma once

#ifndef ALUMNONODO_H
#define ALUMNONODO_H

class AlumnoNodo
{
private:
	const char* Nombre;
	double Nota;
	AlumnoNodo* siguiente;

public:
	AlumnoNodo();
	AlumnoNodo(const char*, double, AlumnoNodo*);

	void setNota(double);
	void setNombre(const char*);
	void setSiguiente(AlumnoNodo*);

	double getNota();
	const char* getNombre();
	AlumnoNodo* getSiguiente();

};


#endif // !ALUMNONODO_H