#include <iostream>
using namespace std;
//Sa se determine numerele de maxim 4 cifre care sunt egale cu suma cuburilor cifrelor acestuia

int SumaCifreCub(int n){
    int s=(n%10)*(n%10)*(n%10);
    while(n/=10)
        s+=(n%10)*(n%10)*(n%10);
    return s;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Numarul "<<(SumaCifreCub(n)==n ? "":"nu ")<<"este egal cu suma cuburilor cifrelor sale\n";
}