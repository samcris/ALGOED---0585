#include <iostream>
using namespace std;

int encontrarUnico(int *arr, int ini, int fin) {
    if (ini == fin) return arr[ini];
    int medio = (ini+fin)/2;
    if (medio%2 ==0 ) {
        if (arr[medio] == arr[medio+1]) {
            return encontrarUnico(arr, medio +2, fin) ;
        }else {
            return encontrarUnico(arr, ini , medio);
        }
    }
    if (medio %2 != 0) {
        if (arr[medio] == arr[medio-1]) {
            return encontrarUnico(arr, medio +1, fin);
        }else {
            return encontrarUnico(arr, ini , medio -1);
        }
    }

    return -1;
}

int contador_ceros(int *arr, int ini, int fin, int cont ) {
    if (ini ==fin) { return cont;
    }

    int medio = (ini+fin)/2;
    if (arr[medio]==0) {
        return contador_ceros(arr, ini, medio -1, cont + fin - medio +1 );
    }else {
        return contador_ceros(arr, medio +1, fin, cont );
    }

    return -1;
}
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    int arr[] = {1,1,3,3,4,5,5,7,7,8,8};
    int num = encontrarUnico(arr, 0, 10);
    cout << "PRIMER EJERCICIO" << endl;
    cout << num << endl;

    cout << "------------------" << endl;

    int arrceros[] = {1,1,1,0,0,0,0};
    int n = sizeof(arrceros)/sizeof(arrceros[0]);
    int contador = contador_ceros(arrceros, 0, n-1,0);
    cout << contador << endl;
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}