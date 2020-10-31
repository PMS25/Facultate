#include <iostream>
using namespace std;
//Sa se descrie un algoritm pentru a afisa toate numerele perfecte mai mici sau egale cu un n dat.
//k este numar perfect daca: 1 + suma divizorilor proprii ai lui k = k

int SumaDivizori(int x){
    int i,s=1;
    for(i=2; i<x/i; i++)
        if(x%i==0)
            s+=i+x/i;
    s+=(i*i==x ? i:0);
    return s;
}

void NumerePerfecte(int n){
    cout<<"Numere perfecte: ";
    for(int i=1; i<n; i++)
        if(SumaDivizori(i)==i)
            cout<<i<<" ";
    cout<<endl;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    NumerePerfecte(n);
}