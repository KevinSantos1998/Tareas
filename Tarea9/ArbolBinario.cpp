
#include "ArbolBinario.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

ArbolBinario::ArbolBinario() : raiz(nullptr)
{}

void ArbolBinario::agregarElemento(const char* _nombre) 
{
	 
	raiz = agregarAux(raiz, _nombre);

}

NodoArbol* ArbolBinario::agregarAux(NodoArbol* _raiz, const char* _nombre) 
{

	if (_raiz == nullptr)
	{
		NodoArbol* nuevo = new NodoArbol(_nombre, nullptr, nullptr);
		_raiz = nuevo;
	}
	else if (strcmp(_nombre, _raiz->getNombre()) > 0)
		_raiz->setHijoDerecho(agregarAux(_raiz->getHijoDerecho(), _nombre));
	else if (strcmp(_nombre, _raiz->getNombre()) < 0)
		_raiz->setHijoIzquierdo(agregarAux(_raiz->getHijoIzquierdo(), _nombre));

	return _raiz;
}

void ArbolBinario::imprimirArbol() 
{
	imprimirAux(raiz);
}

void ArbolBinario::imprimirAux(NodoArbol* _raiz) 
{

	if (_raiz == nullptr)
		return;

	cout << "[ " << _raiz->getNombre() << " ] ";
	imprimirAux(_raiz->getHijoIzquierdo());
	imprimirAux(_raiz->getHijoDerecho());
}

int ArbolBinario::ObtenerPeso()
{
	peso = 0;
	if (raiz == nullptr)
		return peso;
	else
	{
		return ObtenerPesoAux(raiz);
	}
}

int ArbolBinario::ObtenerPesoAux(NodoArbol* _raiz)
{
	if (_raiz == nullptr)
		return peso++;
	else
	{
		ObtenerPesoAux(_raiz->getHijoDerecho());
		ObtenerPesoAux(_raiz->getHijoIzquierdo());
	}
}

int ArbolBinario::ObtenerMaximaAltura()
{
	if (raiz == nullptr)
		return 0;
	else
	{
		return ObtenerMaximaAlturaAux(raiz);
	}
}

int ArbolBinario::ObtenerMaximaAlturaAux(NodoArbol* _raiz)
{
	if (_raiz == nullptr)
		return 0;
	else
	{
		return 1 + (max(ObtenerMaximaAlturaAux(_raiz->getHijoIzquierdo()), ObtenerMaximaAlturaAux(_raiz->getHijoDerecho())));
	}
}

void ArbolBinario::GuardarElementos() 
{
	GuardarElementosAux(raiz);
}

void ArbolBinario::GuardarElementosAux(NodoArbol*_raiz)
{
	ofstream Arbol("arbol.dat", ios::app);

	if (!Arbol)
	{
		cout << "Error al intentar abrir archivo alumnos.dat\n";
		return;
	}

	int cantidad = ObtenerPeso();

	if (_raiz==nullptr)
	{
		return;
	}
	else
	{
		Arbol << _raiz->getNombre() << ","; 
		Arbol.close();
		GuardarElementosAux(_raiz->getHijoIzquierdo());
		GuardarElementosAux(_raiz->getHijoDerecho());
		cout << "\nSe guardo Elemento\n";
	}
}

void ArbolBinario::CargarElementos()
{
	ifstream Arbol("arbol.dat", ios::in);
	if (!Arbol)
	{
		cout << "Error al intentar abrir archivo alumnos.dat\n";
		return;
	}
	int filas = 0;
	string linea;
	while (getline(Arbol, linea)) 
	{
		stringstream linestream(linea);
		int posicionCaracter = 0;

		for (int i = 0; i < 9; i++)
		{
			string valor;
			string linea = linestream.str();
			//lectura campo a campo (atributo)
			getline(linestream, valor, ',');

			posicionCaracter += valor.length() + 1;
			const char* hola = valor.c_str();
			agregarElemento(hola);
		}
			break;
	}
}

void ArbolBinario::verificarArbol()
{
	verificarArbolAux(raiz,0);
}

void ArbolBinario::verificarArbolAux(NodoArbol* _raiz,int cont)
{
	if (_raiz->getHijoIzquierdo() != nullptr)
	{
		cout << "no es un arbol lista";
		return;
	}
	else if(cont<ObtenerPeso()&& _raiz->getHijoDerecho() == nullptr)
	{
		cout << "es un arbol lista";
		return;
	}
	else
	{
		verificarArbolAux(_raiz->getHijoDerecho(), cont + 1);
	}

}

