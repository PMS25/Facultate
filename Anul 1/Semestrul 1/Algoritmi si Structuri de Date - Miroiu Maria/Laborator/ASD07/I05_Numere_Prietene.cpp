#include <iostream>
using namespace std;
//Determinati daca doua numere intregi sunt prietene <=> 1 + suma divizorilor proprii ai unuia = celalalt)
//EX: 220 si 284 sunt prietene
//sd(220) = 1 + (2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110) = 284
//sd(284) = 1 + (2 + 4 + 71 + 142) = 220.

int SumaDivizoriProprii(int n){
    int s=0;
    for(int i=2; i<=n/2; i++)
        s+=(n%i==0 ? i:0);
    return s;
}

int main(){
    int a,b; cout<<"Dati cele 2 numere: "; cin>>a>>b;
    int sa = SumaDivizoriProprii(a) + 1;
    int sb = SumaDivizoriProprii(b) + 1;
    cout<<"Numerele "<<a<<" si "<<b<<(sa==b && sb==a ? "":" nu")<<" sunt prietene"<<endl;
}