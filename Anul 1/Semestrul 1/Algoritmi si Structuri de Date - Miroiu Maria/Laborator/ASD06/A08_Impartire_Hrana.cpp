#include <iostream>
#include <cmath>
using namespace std;
//La ferma fiecare gaina primeste exact acelasi numar de boabe de porumb, cele ramase sunt trimise la curcan.
//Stabiliti cine a primit mai multe boabe si cu cat.
//Date de intrare: nr de gaini, nr de boabe
//EX: 100 4050  => curcanul are mai mult cu 10 boabe. 

inline int NrBoabeGaini(int g, int n){ return n/g; }
inline int NrBoabeCurcan(int g, int n){ return n%g; }

int main(){
    int g,n; cout<<"Dati nr. de gaini si nr. de boabe: "; cin>>g>>n;
    int a = NrBoabeGaini(g,n), b = NrBoabeCurcan(g,n);
    if(a==b)
        cout<<a<<" boabe distribuite egal"<<endl;
    else
        cout<<(a>b ? "Gaina":"Curcanul")<<" are cu "<<abs(a-b)<<" boabe"<<endl;
}