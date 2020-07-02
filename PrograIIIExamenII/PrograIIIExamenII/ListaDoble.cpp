#include "ListaDoble.h"
#include <iostream> 


using namespace std;

ListaDoble::ListaDoble() : primero(nullptr), ultimo(nullptr){}

bool ListaDoble::estaVacia()
{
	return primero == nullptr;
}

bool ListaDoble::estaLlena()
{
	return primero != nullptr;
}

void ListaDoble::agregarElementoInicio(int _valor, char _nombre[])
{
	deque <int> gquiz;
	gquiz.push_front(_valor);

	Nodo* nuevo = new Nodo(_valor,_nombre, nullptr, nullptr);

	if (estaVacia())
	{
		primero = nuevo;
		ultimo = nuevo;

	}
	else
	{
		primero->setAnterior(nuevo);
		nuevo->setSiguiente(primero);
		primero = nuevo;
	}

	cout << "Elemento ingresado al Inicio!\n";

}

void ListaDoble::agregarElementoFinal(int _valor, char _nombre[])
{
	deque <int> gquiz;
	gquiz.push_back(_valor);

	Nodo* nuevo = new Nodo(_valor, _nombre,nullptr, nullptr);

	if (estaVacia())
	{
		primero = nuevo;
		ultimo = nuevo;

	}
	else
	{
		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		ultimo = nuevo;
	}

	cout << "Elemento ingresado al final!\n";

}

void ListaDoble::imprimirLista()
{

	if (estaVacia())
		return;

	Nodo* actual = primero;

	do
	{
		cout << "[ Codigo: " << actual->getValor() << ", Nombre: " << actual->getNombre() <<" ] ";
		actual = actual->getSiguiente();

	} while (actual != nullptr);

	cout << "\n";

}


void ListaDoble::PopFinal()
{
	deque <int> gquiz;
	gquiz.pop_back();

	if (estaVacia())
		return;

	Nodo* actual = ultimo;
	actual->getAnterior()->setSiguiente(nullptr);
	actual->setAnterior(nullptr);
	ultimo = actual;
	delete actual;

}

void ListaDoble::PopInicio()
{
	deque <int> gquiz;
	gquiz.pop_front();

	if (estaVacia())
		return;

	Nodo* actual = primero;
	actual->getSiguiente()->setAnterior(nullptr);
	actual->setSiguiente(nullptr);
	primero = actual;
	delete actual;

}

void ListaDoble::ObtenerInicio()
{
	deque <int> gquiz;
	cout << "\nElemento del inicio : " <<"Codigo: " << primero->getValor() <<", Nombre: " <<primero->getNombre();
	
}

void ListaDoble::ObtenerFinal()
{
	deque <int> gquiz;
	cout << "\nElemento del inicio : " << "Codigo: " << ultimo->getValor() << ", Nombre: " << ultimo->getNombre();
}

void ListaDoble::Guardarlista()
{
	if (estaVacia())
		return;

	Nodo* actual = primero;

	do
	{
		actual->GuardarArchivo(actual->getValor(), actual->getNombre());
		actual = actual->getSiguiente();

	} while (actual != nullptr);
}

