#include <iostream>
using namespace std;
//Sa se descrie un algoritm pentru a verifica criteriul de divizibilitate cu 9.
//Un numar se divide cu 9 daca si numai daca suma cifrelor sale se divide cu 9.
//EX: 25146 se divide cu 9, iar 416 nu se divide cu 9

int SumaCifre(int n){
    int s=n%10;
    while(n/=10)
        s+=n%10;
    return s;
}

int DivizibilCu9(int n){
    int s = SumaCifre(n);
    return s/9 * 9 == s;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Numarul "<<(DivizibilCu9(n) ? "":"nu ")<<"este divizibil cu 9."<<endl;
}