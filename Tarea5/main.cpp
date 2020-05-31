#include <iostream>
#include <iomanip>
#include <vector>
#include "EmpleadoAsalariado.h" 
#include "EmpleadoPorComision.h" 
#include "EmpleadoBaseMasComision.h"
using namespace std;

void virtualViaApuntador(const Empleado* const); // prototipo 
void virtualViaReferencia(const Empleado&); // prototipo

int main()
{
    // establece el formato de salida de punto flotante
    cout « fixed « setprecision(2);

    // crea objetos de las clases derivadas
    EmpleadoAsalariado empleadoAsalariado("John", "Smith", "111-11-1111", 800);
    EmpleadoPorComision empleadoPorComision("Sue", "Jones", "333 - 33 - 3333", 10000, .06);
    EmpleadoBaseMasComision empleadoBaseMasComdsion(  "Bob", "Lewis", "444-44-4444", 5000, .04, 300);

    cout « "Empleados procesados en forma Individual, usando vinculacion estatica:\n\n";

    // imprime la informaciOn de cada empleado y sus ingresos, usando vinculacion 
    empleadoAsalariado.imprimir();
    cout «"\nobtubo $" « empleadoAsalariado.ingresos0 cc "\n\n";
    empleadoPorComision.imprimir();
    cout «"\nobtubo $" « empleadoPorComision.ingresos() « "\n\n";
    empleadoBaseMasComdsion.imprimir();
    cout «"\nobtubo $" « empleadoBaseMasComdsion.ingresos() «"\n\n";

    vector< Empleado* > empleados(3);

    empleados[0] = &empleadoAsalariado;
    empleados[1] = &empleadoPorComision;
    empleados[2] = &empleadoBaseMasComdsion;

    cout « "Empleados procesados en forma polimorfica mediante vinculacion dinamica:\n\n";

        cout « "Llamadas a funciones virtuales realizadas desde apuntadores de la  clase base : \n\n";

        for (const Empleado* empleadoPtr : empleados)
            virtualViaApuntador(empleadoPtr);

            // llama a virtualViaReferencia para imprimir la information de cada Empleado 
            // y a ingresos mediante el uso de vinculaciOn dinamica
            cout « "Llamadas a funciones virtuales realizadas desde referencias de la clase base : \n\n";

