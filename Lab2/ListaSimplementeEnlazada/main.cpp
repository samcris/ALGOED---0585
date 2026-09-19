//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

void invierte(Lista  &lista) {
    NodoLista *prec,*pant,*pini;
    int n=lista.longitud;
    for (int i=1;i<n;i++) { //cuantos saltos debo hacer
        prec=lista.inicio; //reiniciando
        for (int j=i;j<n;j++) {//salta lejos de ti
            pant=prec; //saltando a tu lado
            prec=prec->siguiente; // no te me pegues
        }
        if (i==1)pini=prec; //solo una vez
        prec->siguiente=pant; // la volteadita
    }
    lista.inicio->siguiente=nullptr;
    lista.inicio=pini;
}

NodoLista* inviertereal(NodoLista *ptrlista) {
    if (ptrlista==nullptr)return nullptr;
    if (ptrlista->siguiente==nullptr)return ptrlista;
    NodoLista *pini=inviertereal(ptrlista->siguiente);
    ptrlista->siguiente->siguiente=ptrlista;
    return pini;
}

void invierterec(Lista &lista) {
   NodoLista*pini=inviertereal(lista.inicio);
    lista.inicio->siguiente=nullptr;
    lista.inicio=pini;
}

int main(int argc, char **argv) {
    Lista lista1;
    ElementoLista ele;

    construir(lista1);
    ele.codigo=8;
    insertarAlInicio(lista1,ele);
    ele.codigo=7;
    insertarAlInicio(lista1,ele);
    ele.codigo=4;
    insertarAlInicio(lista1,ele);
    ele.codigo=2;
    insertarAlInicio(lista1,ele);

    imprimir(lista1);
    invierte(lista1);
    imprimir(lista1);
    invierterec(lista1);
    imprimir(lista1);

    return 0;
}
