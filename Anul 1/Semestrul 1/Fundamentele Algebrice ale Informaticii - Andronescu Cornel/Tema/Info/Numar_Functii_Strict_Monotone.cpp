#include <iostream>
using namespace std;

long Combinari(int n, int k){
    long p = 1, q = n-k+1;
    ++n; ++k;
    while(--n)  p*=n;
    while(--k)  p/=k;
    while(--q)  p/=q;
    return p;
}

int main(){
    int nA; cout<<"Dati cardinalul multimii A: "; cin>>nA;
    int nB; cout<<"Dati cardinalul multimii B: "; cin>>nB;
    if(nA<=nB)
        cout<<"Nr functii strict crescatoare: "<<Combinari(nB,nA)<<endl;
    else
        cout<<"Date invalide"<<endl;
}