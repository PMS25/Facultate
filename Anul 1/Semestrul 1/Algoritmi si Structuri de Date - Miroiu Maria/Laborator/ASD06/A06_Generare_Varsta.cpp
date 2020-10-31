#include <iostream>
using namespace std;
//Cunoscand data curenta precum si data nasterii unei persoane, sa se calculeze varsta persoanei in numar de ani impliniti.
//EX: data curenta 2014 10 25 si data nasterii 1969 11 2 => 44 de ani.

struct data_timp{ int an,luna,zi; };
void Citire(data_timp &prezent, data_timp &nastere){
    cout<<"Dati data nasterii (zi/luna/an)"; cin>>nastere.zi>>nastere.luna>>nastere.an;
    cout<<"Dati data curenta (zi/luna/an)"; cin>>prezent.zi>>prezent.luna>>prezent.an;
}

int Ani(data_timp prezent, data_timp nastere){
    int ani = prezent.an - nastere.an;
    if(prezent.luna < nastere.luna)
        ani--;
    else if(prezent.luna == nastere.luna && prezent.zi<nastere.zi)
        ani--;
    return ani;
}

int main(){
    data_timp prezent, nastere;
    Citire(prezent,nastere);
    cout<<"Ani impliniti: "<<Ani(prezent,nastere)<<endl;
}