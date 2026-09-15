#include <iostream>
#define N 7

using namespace std;

int estaonoesta(int pos,int opo,int n, int red[N][N]) {
    if (opo==n) return pos;
    if (red[pos][opo]>0)
        return estaonoesta(pos,opo+1,n,red);
    else
        return estaonoesta(opo,opo+1,n,red);
}

int main() {
    int red[N][N]={
        {0,0,0,0,0,0,0},
        {10,0,20,30,0,20,40},
        {0,0,0,0,0,100,0},
        {0,0,0,0,0,80,0},
        {50,10,5,10,0,100,4},
        {100,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };
    int n=N;
    int pos=estaonoesta(0,1,n,red);
    int cont1=0,cont2=0;
    for (int i=0;i<n;i++)
        if (i!=pos) {
            if (red[pos][i]>0) cont1++;
            if (red[i][pos]>0) cont2++;
        }
    if (cont2==0 and cont1==n-1)
        cout <<"SkyNerd: "<< pos+1 << endl;
    else
        cout <<" No esta ";

    return 0;
}
