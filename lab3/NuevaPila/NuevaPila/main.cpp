//Fecha:  lunes 01 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/NuevaPila.h"
using namespace std;

void nuevoconstruir(NuevaPila &pila) {
    construir(pila.principal);
    construir(pila.extra);
}

void nuevoapilar(NuevaPila &pila,ElementoPila &ele) {
    apilar(pila.principal,ele);
    if (esPilaVacia(pila.extra))
        apilar(pila.extra,ele);
    else {
        if (ele.numero<cima(pila.extra).numero)
            apilar(pila.extra,ele);
        else
            apilar(pila.extra,cima(pila.extra));
    }
}

ElementoPila nuevodesapila(NuevaPila &pila) {
    desapilar(pila.extra);
    return desapilar(pila.principal);
}

ElementoPila nuevocima(NuevaPila &pila) {
    return cima(pila.principal);
}

ElementoPila minimo(NuevaPila &pila) {
    return cima(pila.extra);
}

void nuevoimprimir(NuevaPila pila) {
    imprimir(pila.principal);
    imprimir(pila.extra);
}

int main(int argc, char ** argv) {
    ElementoPila ele;
    NuevaPila pila;

    nuevoconstruir(pila);
    ele.numero=8;
    nuevoapilar(pila,ele);
    ele.numero=9;
    nuevoapilar(pila,ele);
    ele.numero=7;
    nuevoapilar(pila,ele);
    ele.numero=16;
    nuevoapilar(pila,ele);
    ele.numero=6;
    nuevoapilar(pila,ele);
    nuevoimprimir(pila);
    nuevodesapila(pila);
    nuevoimprimir(pila);
    cout << endl << minimo(pila).numero << endl;
    return 0;
}
