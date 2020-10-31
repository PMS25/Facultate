#include <iostream>
using namespace std;
//Folosind recursivitatea, decrieti un algoritm pentru a verifica daca un vector contine cel putin un numar negativ.

void Citire(int *a, int n){
    if(n>=0){
        Citire(a,n-1);
        cin>>a[n];
    }
}

bool Negativ(int *a, int n){
    if(n==0)
        return a[n]<0;
    else
        return a[n]<0 || Negativ(a,n-1);
}

int main(){
    int *a, n; cout<<"Dati numarul de elemente: "; cin>>n;
    a = new int[n];
    cout<<"Dati elementele: "; Citire(a,n-1);
    cout<<"Vecotorul "<<(Negativ(a,n-1) ? "":"nu ")<<"contine valori negative."<<endl;
    delete[] a;
}