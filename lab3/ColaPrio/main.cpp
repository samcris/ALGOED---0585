//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "funciones.h"
using namespace std;

void ordenarec(Cola &cola,int n) {
    int cont=1;
    if (n==0) return;
    int max=desencolar(cola).codigo;
    while (cont<n) {
        int aux=desencolar(cola).codigo;
        if (aux>max) {
            encolar(cola,{max});
            max=aux;
        }
        else
            encolar(cola,{aux});
        cont++;
    }
    ordenarec(cola,n-1);
    encolar(cola,{max});

}


int main(int argc, char **argv) {
    Cola cola;

    construir(cola);
    encolarprioridad(cola,{2,1});
    encolarprioridad(cola,{1,1});
    encolarprioridad(cola,{2,2});
    encolarprioridad(cola,{2,3});
    encolarprioridad(cola,{1,2});

    imprimir(cola);


    return 0;
}
