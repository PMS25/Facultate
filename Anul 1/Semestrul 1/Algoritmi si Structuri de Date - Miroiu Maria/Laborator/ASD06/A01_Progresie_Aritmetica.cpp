#include <iostream>
using namespace std;
//Se citesc 3 numere intregi. Sa se determine daca numerele sunt in progresie aritmetica.
// a,b,c in progresie aritmetica <=> b=(a+c)/2
//EX: 9,6,3 sunt in p.a. ; 1,3,6 nu sunt in p.a.

void Citire(int *&v, int &n){
    cout<<"Dati numarul de termeni: "; cin>>n;
    cout<<"Dati numerele: ";
    v = new int[n];
    for(int i=0; i<n; i++)
        cin>>v[i];
}

bool ProgresieAritmetica(int *v, int n){
    if(n<=1)
        return false;
    int r = v[1]-v[0];
    for(int i=2; i<n; i++)
        if(v[i]-v[i-1]!=r)
            return false;
    return true;
}

int main(){
    int *v, n;
    Citire(v,n);
    cout<<"Numerele "<<(ProgresieAritmetica(v,n) ? "":"nu ")<<"sunt in progresie aritmetica"<<endl;
    delete[] v;
}