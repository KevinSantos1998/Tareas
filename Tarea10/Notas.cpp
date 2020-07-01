#include "Notas.h"

#include <iostream>
using namespace std;

Nota::Nota()
{

	nota.open("notas.dat", ios::in | ios::out | ios::app | ios::binary);
	if (!nota) {
		cout << "Error al intentar abrir el archivo\n";
		return;
	}

	nota.close();
}

void Nota::agregarNota() {
	nota.open("notas.dat", ios::in | ios::out | ios::app | ios::binary);

	NotaRegistro nuevaMateria;

	cout << "Ingrese Numero de cuenta: ";
	cin >> nuevaMateria.numeroCuenta;

	cout << "Ingrese Codigo de Materia: ";
	cin >> nuevaMateria.codigoMateria;
	cout << "Ingrese Nota: ";
	cin >> nuevaMateria.nota;

	nota.seekp(0, ios::end);// coloca el cursor de ESCRITURA en un byte especifico
	nota.write(reinterpret_cast<const char*>(&nuevaMateria), sizeof(nota));

	nota.close();

	cout << "Materia agregadA\n";
}

void Nota::EnlistarNota(int _numeroCuenta) {
	nota.open("notas.dat", ios::in | ios::binary);
	nota.seekg(0, ios::beg);

	NotaRegistro Lectura;

	nota.read(reinterpret_cast<char*>(&Lectura), sizeof(NotaRegistro));
	while (!nota.eof())
	{
		if (Lectura.numeroCuenta == _numeroCuenta) {
			cout << "Alumno { cuenta: " << Lectura.numeroCuenta << ", Codigo de Materia: " << Lectura.codigoMateria << ", promedio: " << Lectura.nota << " }\n";
			nota.read(reinterpret_cast<char*>(&Lectura), sizeof(NotaRegistro));
			nota.close();
		}

	}
}
