#include <iostream>
using namespace std;
//Sa se contorizeze numarul de elemente din vector egale cu produsul vecinilor sai.
//EX: V = (2 8 4 54 18) -> 2 (8 = 2·4, 4 != 8·54, 54 = 4·18)

int Contorizare(int V[], int n){
    int k=0;
    for(int i=1; i<n-1; i++)
        k += (V[i] == V[i-1] * V[i+1] ? 1:0);
    return k;
}

void Citire(int *&V, int &n){
    cout<<"Dati numarul de elemente: "; cin>>n;
    V = new int[n];
    cout<<"Dati elementele: ";
    for(int i=0; i<n; i++) cin>>V[i];
}

int main(){
    int *V, n;
    Citire(V,n);
    cout<<"Numar elemente ce indeplinesc proprietatea: "<<Contorizare(V,n)<<endl;
    delete[] V;
}