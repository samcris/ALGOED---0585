//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
using namespace std;



void despacha(ABB &arbol,int cant) {
    NodoABB *parbol;
    if (esArbolVacio(arbol) and cant!=0) {
        cout <<endl<< "Falta stock"<<endl;
        return;
    }

    if (cant==0) return;
    parbol=minimoArbol(arbol.raiz);
    if (cant>=parbol->elemento.cantidad) {
        int resto=parbol->elemento.cantidad;
        eliminar(arbol,parbol->elemento);
        despacha(arbol,cant-resto);
    }
    else {
        parbol->elemento.cantidad-=cant;
    }
}

int main(int argc, char **argv) {
    ABB arbol;

    construir(arbol);
    insertar(arbol,{20251201,100});
    insertar(arbol,{20251105,50});
    insertar(arbol,{20260605,100});
    insertar(arbol,{20250910,50});
    insertar(arbol,{20251020,50});

    recorrerEnOrden(arbol);
    despacha(arbol,350);
    cout <<endl;
    recorrerEnOrden(arbol);
    return 0;
}