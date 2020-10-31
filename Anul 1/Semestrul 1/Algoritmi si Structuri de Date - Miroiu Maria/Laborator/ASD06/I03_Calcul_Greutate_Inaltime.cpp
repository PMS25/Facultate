#include <iostream>
using namespace std;
//Ana vrea sa verifice daca greutatea si inaltimea ei corespund varstei pe care o are.
//Ea a gasit urmatoarele formule de calcul, unde v=varsta: greutate = 2*v + 8 (kg), inaltime = 5*v + 80 (cm).
//Calculati greutatea si inaltimea "ideala" pentru un copil folosind formula de mai sus.
//EX: v = 10 (ani) => g = 28 (kg) si h = 130 (cm). 

int Greutate(int v){ return 2*v+8; }
int Inaltime(int v){ return 5*v+80; }

int main(){
    int v; cout<<"Dati varsta: "; cin>>v;
    cout<<"Greutate: "<<Greutate(v)<<" (kg)"<<endl;
    cout<<"Inaltime: "<<Inaltime(v)<<" (cm)"<<endl;
}