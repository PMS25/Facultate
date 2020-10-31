#include <iostream>
using namespace std;
//Se citesc 3 numere. Sa se descrie un algoritm pentru a verifica daca ele sunt consecutive. 
//EX: 2,3,4 sunt consecutive ; 2,4,3 nu sunt consecutive ; 4,3,2 nu sunt consecutive

void Citire(int *&v, int &n){
    cout<<"Dati numarul de termeni: "; cin>>n;
    cout<<"Dati numerele: ";
    v = new int[n];
    for(int i=0; i<n; i++)
        cin>>v[i];
}

bool CrescatorConsecutive(int *v, int n){
    if(n<=1)
        return false;
    for(int i=2; i<n; i++)
        if(v[i]-v[i-1]!=1)
            return false;
    return true;
}

int main(){
    int *v, n;
    Citire(v,n);
    cout<<"Numerele "<<(CrescatorConsecutive(v,n) ? "":"nu ")<<"sunt consecutive"<<endl;
    delete[] v;
}