#include <iostream>
using namespace std;
//Se citesc valorile lungimii si latimii unui dreptunghi. Calculati perimetrul si aria dreptunghiului.
//EX: L=5 si l=3 => P=2*(L+l)=16, iar A=L*l=15.

struct dreptunghi{ float L,l; };

float ArieD(dreptunghi d){ return d.L*d.l; }
float PerimetruD(dreptunghi d){ return 2*(d.L+d.l); }

void Citire(dreptunghi &d){
    cout<<"Dati lungimea (L): "; cin>>d.L;
    cout<<"Dati latimea (l): "; cin>>d.l;
}

int main(){
    dreptunghi d;
    Citire(d);
    cout<<"Arie: "<<ArieD(d)<<endl;
    cout<<"Perimetru: "<<PerimetruD(d)<<endl;
}