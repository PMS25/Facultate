#include <iostream>
using namespace std;
//Calculati valoarea finala a unui depozit dupa n ani, stiind suma initiala si rata dobanzii.
//Se presupune ca nu exista niciun comision.

int SumaFinala(int s, int d, int n){ return s + s*d/100*n; }

int main(){
    int s; cout<<"Dati suma depozit: "; cin>>s;
    int d; cout<<"Dati dobanda: "; cin>>d;
    int n; cout<<"Dati perioada: "; cin>>n;
    cout<<"Suma finala: "<<SumaFinala(s,d,n)<<endl;
}