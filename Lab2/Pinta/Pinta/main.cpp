#include <iostream>
#define N 5

using namespace std;

void imprime(int n,int matriz[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }

}

void pinta(int x,int y,int colini,
    int colfin,int matriz[N][N]) {
    if (x>=N or x<0 or y>=N or y<0)
        return;
    if (matriz[x][y] != colini)
        return;
    matriz[x][y] = colfin;
    //nos vamos de avance
    pinta(x-1,y,colini,colfin,matriz);
    pinta(x,y+1,colini,colfin,matriz);
    pinta(x+1,y,colini,colfin,matriz);
    pinta(x,y-1,colini,colfin,matriz);
}


int main() {

    int matriz[N][N]={
        {2,3,4,2,1},
        {2,4,1,2,1},
        {2,4,1,2,1},
        {2,4,4,4,1},
        {2,3,1,2,4}};
    imprime(N, matriz);
    cout << endl;
    // 2, 1
    pinta(2,1,4,8,matriz);
    imprime(N, matriz);

    return 0;
}
