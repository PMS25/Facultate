#include <iostream>
using namespace std;
//Scrieti in C++ algoritmul pentru determinarea produsului cifrelor unui numar natural.

long ProdusCifre(int n){
    long p=n%10;
    while(n/=10)
        p*=n%10;
    return p;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Produsul cifrelor: "<<ProdusCifre(n)<<endl;
}