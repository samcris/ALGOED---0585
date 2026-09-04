#include <iostream>
using namespace std;

void triangulo(int a,int b) {
    if (a>b) return; //caso base
    for (int i=0;i<a;i++)cout << "* ";
    cout <<endl;
    triangulo(a+1,b);
    for (int i=0;i<a;i++)cout << "* ";
    cout <<endl;
    return;
}

int main() {

    triangulo(3,5);
    
    return 0;
}
