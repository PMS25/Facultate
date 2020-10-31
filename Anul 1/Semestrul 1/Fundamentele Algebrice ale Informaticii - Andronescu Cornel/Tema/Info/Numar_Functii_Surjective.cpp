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

long Power(int n, int a){
    long p = n;
    while(--a)
        p*=n;
    return p;
}

long NrFctSurjective(int nA, int nB){
    long p=Power(nB,nA);
    for(int i=1; i<nB; i++)
        p += (i%2 ? -1:1) * Combinari(nB,i) * Power(nB-i, nA);
    return p;
}

int main(){
    int nA; cout<<"Dati cardinalul multimii A: "; cin>>nA;
    int nB; cout<<"Dati cardinalul multimii B: "; cin>>nB;
    if(nA>=nB)
        cout<<"Nr functii surjective: "<<NrFctSurjective(nA,nB)<<endl;
    else
        cout<<"Date invalide"<<endl;
}