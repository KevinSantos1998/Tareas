#include "alumno.h"
#include "Materia.h"
#include "Notas.h"
#include <conio.h>
int main()
{
	alumno Alumno;
	Materia ma;
	Nota nota;
	
	Alumno.AgregarAlumno();
	Alumno.AgregarAlumno();
	Alumno.AgregarAlumno();
	Alumno.EnlistarAlumnis();

	ma.AgregarMateria();
	ma.AgregarMateria();
	ma.AgregarMateria();
	ma.EnlistarMateria();

	nota.agregarNota();
	nota.agregarNota();
	nota.agregarNota();
	nota.EnlistarNota(21811066);
	

	_getch();
}