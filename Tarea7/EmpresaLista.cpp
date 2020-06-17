#include "EmpresaLista.h"

#include <iostream>

using std::cout;

EmpresaLista::EmpresaLista() : primero(nullptr), ultimo(nullptr)
{}

bool EmpresaLista::estaVacia()
{
	return primero == nullptr;
}

bool EmpresaLista::agregarEmpleado(int _codigo, const char* _nombre, double _salario)
{

	NodoEmpleado* nuevo = new NodoEmpleado(_codigo,_nombre,_salario, nullptr, nullptr);

	if (estaVacia())
	{
		primero = nuevo;
		ultimo = nuevo;

		return true;
	}
	else
	{

		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);

		ultimo = nuevo;
		return true;
	}

	return false;

}


bool EmpresaLista::insertarEmpleado(int _codigo, const char* _nombre, double _salario)
{

	NodoEmpleado* nuevo = new NodoEmpleado(_codigo, _nombre, _salario, nullptr, nullptr);

	if (estaVacia())
	{
		return false;
	}
	else
	{
		nuevo->setSiguiente(primero);
		primero->setAnterior(nuevo);
		primero = nuevo;
		return true;
	}

	return false;

}

bool EmpresaLista::eliminarEmpleado(int _codigo)
{

	if (estaVacia())
		return false;

	NodoEmpleado* actual = primero;

	while (actual != nullptr)
	{

		if (actual->getCodigo() == _codigo)
		{

			if (actual == primero)
			{
				primero = actual->getSiguiente();
				delete actual;
			}
			else if (actual == ultimo)
			{
				ultimo = actual->getAnterior();
				ultimo->setSiguiente(nullptr);
				delete actual;
			}
			else
			{
				actual->getAnterior()->setSiguiente(actual->getSiguiente());
				actual->getSiguiente()->setAnterior(actual->getAnterior());

				delete actual;
			}

			return true;

		}
		else
			actual = actual->getSiguiente();

	}
	return false;
}

void EmpresaLista::ActualizarSalario(double valor)
{
	if (estaVacia())
		return;

	NodoEmpleado* actual = primero;

	while (actual != nullptr)
	{
		actual->setSalario((actual->getSalrio() * valor) + actual->getSalrio());
		actual = actual->getSiguiente();
	}
}

void EmpresaLista::imprimirEmpleados()
{

	if (estaVacia())
		return;

	NodoEmpleado* actual = primero;

	while (actual != nullptr)
	{
		cout << "[ Codio: " << actual->getCodigo() << ", Nombre: " << actual->getNombre()<< ", Salario: "<< actual->getSalrio() <<" ] ";
		actual = actual->getSiguiente();

	}

	cout << "\n";

}
