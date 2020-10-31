#include <iostream>
using namespace std;
//Cunoscand numarul familiilor dintr-un judet, valoarea veniturilor lor, precum si valoarea "cosului minim",
//sa descrie un algoritm pentru a stabili numarul de familii ce traiesc sub nivelul minim de trai.
//EX: Pt 6 familii, veniturile (900, 750, 700, 800, 680, 600) şi coşul minim de 700 -> 2

void Citire(int *&V, int &n, int &m){
    cout<<"Dati numarul familiilor: "; cin>>n;
    V = new int[n];
    cout<<"Dati veniturile: ";
    for(int i=0; i<n; i++) cin>>V[i];
    cout<<"Dati valoarea cosul minim: "; cin>>m;
}

int NrFamili(int V[], int n, int m){
    int k=0;
    for(int i=0; i<n; i++)
        k+=(V[i]<m ? 1:0);
    return k;
}

int main(){
    int *V, n, m;
    Citire(V,n,m);
    cout<<"Nr familii sub nivelul minim de trai: "<<NrFamili(V,n,m)<<endl;
    delete[] V;
}