#include <iostream>
using namespace std;

int NrFctInjective(int nA, int nB){
    long p=1, aux=nB-nA+1;
    while(aux<=nB)
        p*=aux++;
    return p;
}

int main(){
    int nA; cout<<"Dati cardinalul multimii A: "; cin>>nA;
    int nB; cout<<"Dati cardinalul multimii B: "; cin>>nB;
    if(nA<=nB)
        cout<<"Nr functii injective: "<<NrFctInjective(nA,nB)<<endl;
    else
        cout<<"Date invalide"<<endl;
}