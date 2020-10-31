#include <iostream>
using namespace std;
//Scrieti un program pentru determinarea tuturor numerelor prime cu n (c.m.m.d.c(a,n)=1) pana la un numar intreg n dat.

int Cmmdc(int a, int b){
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

void PrimeCuN(int n){
    cout<<"Numere prime cu n: ";
    for(int i=1; i<=n; i++)
        if(Cmmdc(n,i)==1)
            cout<<i<<", ";
    cout<<"\b\b \n";
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    PrimeCuN(n);
}