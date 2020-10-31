#include <iostream>
#include <cmath>
using namespace std;
//Sa se determine care din numerele pana la un n numar natural dat are numar maxim de divizori naturali.

int NrDivizori(int n){
    int k=0, p = sqrt(n);
    for(int i=1; i<=p; i++)
        if(n%i==0)
            k+=2;
    if(p*p==n)
        k--;
    return k;
}

void MaximDivizori(int n){
    int k=0, m=0;
    for(int i=1; i<=n; i++)
        if(NrDivizori(i)>k){
            k=NrDivizori(i);
            m=i;
        }
    cout<<"Rezultat: numarul "<<m<<" cu "<<k<<" divizori."<<endl;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    MaximDivizori(n);
}