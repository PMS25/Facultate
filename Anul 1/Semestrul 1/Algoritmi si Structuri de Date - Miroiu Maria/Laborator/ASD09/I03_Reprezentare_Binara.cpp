#include <iostream>
using namespace std;
//Sa se determine ultimele cifre binare din reprezentarea in baza 2 a unui numar natural dat.

double Binar(int n){
    double b=0, p = 1;
    while(n>0){
        b += p*(n%2);
        p*=10;
        n/=2;
    }
    return b;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Numarul in baza 2: "<<Binar(n)<<endl;
}