//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
#include  "BibliotecaLista/ElementoLista.h"

using namespace std;

void invierte(Lista  &lista) {
    NodoLista *prec,*pant,*pini;
    int n=lista.longitud;
    for (int i=1;i<n;i++) {
        prec=lista.ini;
        for (int j=i;j<n;j++) { //los saltitos
            pant=prec;
            prec=prec->siguiente;
        }
        prec->siguiente=pant; //la volteadita
        if (i==1)pini=prec;   //solo pasa una vez en la vida
    }
    lista.ini->siguiente=nullptr;
    lista.ini=pini;
}
NodoLista* inviertereal(NodoLista *plista) {
    if (plista==nullptr)return nullptr;
    if (plista->siguiente==nullptr)return plista;
    NodoLista *pini= inviertereal(plista->siguiente);
    plista->siguiente->siguiente=plista;
    return pini;
}

void invierterec(Lista  &lista) {
    NodoLista*pini=inviertereal(lista.ini);
    lista.ini->siguiente=nullptr;
    lista.ini=pini;
}


int main(int argc, char **argv) {
    Lista lista1,lista2;
    ElementoLista ele;
    construir(lista1); // no te olvides
    ele.cod=12;
    insertarAlInicio(lista1,ele);
    ele.cod=10;
    insertarAlInicio(lista1,ele);
    ele.cod=6;
    insertarAlInicio(lista1,ele);

    construir(lista2);
    ele.cod=14;
    insertarAlInicio(lista2,ele);
    ele.cod=8;
    insertarAlInicio(lista2,ele);
    ele.cod=2;
    insertarAlInicio(lista2,ele);

    imprimir(lista1);
    imprimir(lista2);


    return 0;
}
