#include <iostream>
using namespace std;
//Sa se descrie un algoritm pentru a verifica criteriul de divizibilitate cu 8.
//Un numar se divide cu 8 daca ultimele 3 cifre ale sale se divid cu 8.
//EX: 23144 se divide cu 8, iar 35102 nu se divide cu 8

long Power(int a, int k){
    long p=1;
    while(k--)
        p*=a;
    return p;
}

long Modul(long n, int k){ return n % Power(10,k); }

int main(){
    long n; cout<<"Dati numarul: "; cin>>n;
    if(Modul(n,3)%8==0) cout<<"Se divide cu 8."<<endl;
    else cout<<"Nu se divide cu 8."<<endl;
}