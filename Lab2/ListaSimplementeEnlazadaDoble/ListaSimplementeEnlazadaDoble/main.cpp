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
        prec=lista.ini; //reiniciando
        for (int j=i;j<n;j++) {//salta lejos de ti
            pant=prec; //saltando a tu lado
            prec=prec->sig; // no te me pegues
        }
        if (i==1)pini=prec; //solo una vez
        prec->sig=pant; // la volteadita
    }
    lista.ini->sig=nullptr;
    lista.ini=pini;
}

NodoLista* inviertereal(NodoLista *ptrlista) {
    if (ptrlista==nullptr)return nullptr;
    if (ptrlista->sig==nullptr)return ptrlista;
    NodoLista *pini=inviertereal(ptrlista->sig);
    ptrlista->sig->sig=ptrlista;
    return pini;
}

void invierterec(Lista &lista) {
   NodoLista*pini=inviertereal(lista.ini);
    lista.ini->sig=nullptr;
    lista.ini=pini;
}
void uniendonodos(Lista &l1,Lista l2) {
    NodoLista *ini=nullptr,*fin=nullptr;
    while (not esListaVacia(l1) and not esListaVacia(l2)) {
        if (l1.ini->ele.num<=l2.ini->ele.num) {
            if (fin==nullptr) {
                fin=l1.ini;
                ini=l1.ini;
            }
            else {
                fin->sig = l1.ini;
                fin=l1.ini;
            }
            l1.ini=l1.ini->sig;
        }
        else {
            if (l1.ini->ele.num>l2.ini->ele.num) {
                if (fin==nullptr) {
                    fin=l2.ini;
                    ini=l2.ini;
                }
                else {
                    fin->sig=l2.ini;
                    fin=l2.ini;
                }
                l2.ini=l2.ini->sig;
            }
        }
    }
    while (not esListaVacia(l1)) {
        if (fin==nullptr) {
            fin=l1.ini;
            ini=l1.ini;
        }
        else {
            fin->sig=l1.ini;
            fin=l1.ini;
        }
        l1.ini=l1.ini->sig;
    }
    while (not esListaVacia(l2)) {
        if (fin==nullptr) {
            fin=l2.ini;
            ini=l2.ini;
        }
        else {
            fin->sig=l2.ini;
            fin=l2.ini;
        }
        l2.ini=l2.ini->sig;
    }
    l1.ini=ini;
    l1.fin=fin;
}

void fusiona(Lista &l1,Lista l2) {
    if (not esListaVacia(l1)and not esListaVacia(l2))
    if (l1.fin->ele.num<l2.ini->ele.num) {
        l1.fin->sig=l2.ini;
        l1.fin=l2.fin;
    }
    else {
        if (l2.fin->ele.num<l1.ini->ele.num) {
            l2.fin->sig=l1.ini;
            l1.ini=l2.ini;
        }
        else
            uniendonodos(l1,l2);
    }
}


int main(int argc, char **argv) {
    Lista lista1,lista2,lista3;
    ElementoLista ele;

    construir(lista1);
    ele.num=8;
    insertarAlInicio(lista1,ele);
    ele.num=7;
    insertarAlInicio(lista1,ele);
    ele.num=1;
    insertarAlInicio(lista1,ele);

    construir(lista2);
    ele.num=9;
    insertarAlInicio(lista2,ele);
    ele.num=6;
    insertarAlInicio(lista2,ele);
    ele.num=2;
    insertarAlInicio(lista2,ele);

    imprimir(lista1);
    imprimir(lista2);


    fusiona(lista1,lista2);
    imprimir(lista1);
    construir(lista3);
    fusiona(lista1,lista3);
    imprimir(lista1);

    return 0;
}
