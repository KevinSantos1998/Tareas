#include "SeccionLista.h"
#include <iostream>

using std::cout;

SeccionLista::SeccionLista() : primero(nullptr)
{}

bool SeccionLista::estaVacia()
{
	return primero == nullptr;
}

void SeccionLista::agregarAlumno(const char* _nombre, double _nota)
{

	AlumnoNodo* nuevo = new AlumnoNodo(_nombre, _nota, nullptr);

	if (estaVacia())
	{
		primero = nuevo;
	}
	else
	{
		if ((strcoll(nuevo->getNombre(), primero->getNombre())) < 0)
		{
			nuevo->setSiguiente(primero);
			primero = nuevo;
		}
		else
		{
			AlumnoNodo* actual = primero;

			while (actual->getSiguiente() != nullptr)
			{
				if((strcoll(nuevo->getNombre(), primero->getNombre())) > 0|| (strcoll(nuevo->getNombre(), primero->getNombre())) == 0)
				{
					nuevo->setSiguiente(actual->getSiguiente());
					actual->setSiguiente(nuevo);
					break;
				}
				actual = actual->getSiguiente();
			}

			
		}
		
	}

	cout << "¡Nodo agregado!\n";

}

void SeccionLista::ListarSeccion()
{

	AlumnoNodo* actual = primero;

	while (actual != nullptr)
	{
		cout << "[Nombre: "<<actual->getNombre()<<" Nota: " << actual->getNota() << " ] ";
		actual = actual->getSiguiente();
	}

	cout << "\n";
}

void SeccionLista::CantidadAprobados()
{
	AlumnoNodo* actual = primero;
	int contador = 0;
	while (actual != nullptr)
	{
		if (actual->getNota() >= 70)
			contador++;
		actual = actual->getSiguiente();
	}
	cout << "La cantidad de alumnos aprobados es de "<<contador;
}