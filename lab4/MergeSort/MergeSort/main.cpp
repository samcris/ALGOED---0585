#include <algorithm>
#include <iostream>

void merge(int *arr,int ini,int med,int fin) {
    int lizq=med-ini+1;
    int lder=fin-med;
    int izq[lizq+1];
    int der[lder+1];

    for (int i=ini;i<=med;i++)izq[i-ini]=arr[i];
    for (int i=med+1;i<=fin;i++)der[i-med-1]=arr[i];



}

void mergesort(int *arr,int ini,int fin) {
    if (ini==fin)
        return;
    int med = (ini+fin)/2;
    mergesort(arr,ini,med);
    mergesort(arr,med+1,fin);
    merge(arr,ini,med,fin);
}


int main() {


    return 0;
}
