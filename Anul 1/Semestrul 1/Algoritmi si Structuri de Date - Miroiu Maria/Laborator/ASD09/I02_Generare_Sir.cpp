#include <iostream>
using namespace std;
//Fie x0 si x1 date, iar xn+2 = xn+1+2xn. Generati n valori ale sirului.

void GenSir(int n, int a, int b){
    cout<<"Sir: "<<a<<", "<<b<<", ";
    int c;
    while(n--){
        c=2*a+b;
        a=b;
        b=c;
        cout<<c<<", ";
    }
    cout<<"\b\b \n";
}

int main(){
    int n; cout<<"Dati numarul de termeni: "; cin>>n;
    int x0, x1; cout<<"Dati primi 2 termeni ai sirului: "; cin>>x0>>x1;
    GenSir(n,x0,x1);
}