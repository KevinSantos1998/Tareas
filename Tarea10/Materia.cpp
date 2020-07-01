#include "Materia.h"
#include <iostream>

using namespace std;

Materia::Materia() {
	MateriaB.open("materias.dat", ios::in | ios::out | ios::app | ios::binary);

	if (!MateriaB)
		cout << "Error en aertura en archivo de alumnos";

	MateriaB.close();

}

void Materia::AgregarMateria() {
	MateriaB.open("materias.dat", ios::in | ios::out | ios::app | ios::binary);

	MateriaRegistro nuevaMateria;

	cout << "Ingrese codigo de materia: ";
	cin >> nuevaMateria.codigoMateria;

	cout << "Ingrese nombre de materia: ";
	cin >> nuevaMateria.nombre;
	cout << "Ingrese uv: ";
	cin >>nuevaMateria.UnidadesValorativas;

	MateriaB.seekp(0, ios::end);// coloca el cursor de ESCRITURA en un byte especifico
	MateriaB.write(reinterpret_cast<const char*>(&nuevaMateria), sizeof(MateriaRegistro));

	MateriaB.close();

	cout << "Materia agregadA\n";

}

void Materia::EnlistarMateria() {
	MateriaB.open("materias.dat", ios::in | ios::binary);

	MateriaRegistro Lectura;
	//colaca el cursor de LECTURA en un byte indicado
	MateriaB.seekg(0, ios::beg);

	MateriaB.read(reinterpret_cast<char*>(&Lectura), sizeof(MateriaRegistro));

	while (!MateriaB.eof())
	{
		cout << "Materia { Codigo: " << Lectura.codigoMateria << ", nombre : "
			<< Lectura.nombre << ", Uv: " << Lectura.UnidadesValorativas << " }\n";
		MateriaB.read(reinterpret_cast<char*>(&Lectura), sizeof(MateriaRegistro));
	}
	MateriaB.close();
}


