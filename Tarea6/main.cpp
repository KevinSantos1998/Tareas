#include "SeccionLista.h"
#include <conio.h>

int main()
{

	SeccionLista ls;
	ls.agregarAlumno("Pedro", 50);
	ls.agregarAlumno("Maria", 70);
	ls.agregarAlumno("Carlos", 30);
	ls.agregarAlumno("Ana",70);
	

	ls.ListarSeccion();
	ls.CantidadAprobados();

	_getch();
}