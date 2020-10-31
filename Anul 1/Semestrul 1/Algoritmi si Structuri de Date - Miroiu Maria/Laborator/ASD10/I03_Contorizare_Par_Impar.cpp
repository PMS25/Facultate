#include <iostream>
using namespace std;
//Descrieti un algoritm pentru a determina cate numere pare, respectiv impare contine un vector

int ContorPare(int V[], int n){
    int k=0;
    for(int i=0; i<n; i++)
        k+=(V[i]+1)%2;
    return k;
}

int ContorImpare(int V[], int n){
    int k=0;
    for(int i=0; i<n; i++)
        k+=V[i]%2;
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
    cout<<"Vectorul contine "<<ContorPare(V,n)<<" nr pare si "<<ContorImpare(V,n)<<" nr impare"<<endl;
    delete[] V;
}