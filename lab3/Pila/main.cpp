//Fecha:  lunes 01 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;

void pasapila(Pila & pila1,Pila & pila2){
    ElementoPila ele,aux;
    while (not esPilaVacia(pila1)) {
        ele=desapilar(pila1);
        int n=0;
        while (not esPilaVacia(pila1)) {
            apilar(pila2,ele);
            ele=desapilar(pila1);
            n++;}
        while (not esPilaVacia(pila2) and n>0) {
            aux=desapilar(pila2);
            apilar(pila1,aux);
            n--;
        }
        apilar(pila2,ele);
    }
}
void ordenapila(Pila &pila,int n){
    ElementoPila max,valor;
    Pila aux;
    if (n==0)return;
    construir(aux);
    max=desapilar(pila);
    for (int i=1;i<n;i++) {
        valor=desapilar(pila);
        if (valor.numero>max.numero) {
            apilar(aux,max);
            max=valor;
        }else
            apilar(aux,valor);
    }
    apilar(pila,max);
    while (not esPilaVacia(aux)) {
        valor=desapilar(aux);
        apilar(pila,valor);
    }
    ordenapila(pila,n-1);

}



int main(int argc, char ** argv) {
    Pila pila1,pila2;
    ElementoPila ele;

    construir(pila1);

    ele.numero=20;
    apilar(pila1,ele);
    ele.numero=10;
    apilar(pila1,ele);
    ele.numero=30;
    apilar(pila1,ele);
    ele.numero=50;
    apilar(pila1,ele);
    imprimir(pila1);

    construir(pila2);
    pasapila(pila1,pila2);
    imprimir(pila1);
    imprimir(pila2);

    ordenapila(pila2,4);
    imprimir(pila2);

    return 0;
}
