#include <iostream>
using namespace std;
// Sa se determine cifra semnificativa / de control a unui numar.
// EX: n = 293, suma cifrelor este 14, apoi suma cifrelor lui 14 este 5 = cifra de control.

int CifraSemnificativa(int n){
    int s;
    while(n>9){
        s=0;
        while(n){
            s+=n%10;
            n/=10;
        }
        n=s;
    }
    return n;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Cifra Semnificativa: "<<CifraSemnificativa(n)<<endl;
}