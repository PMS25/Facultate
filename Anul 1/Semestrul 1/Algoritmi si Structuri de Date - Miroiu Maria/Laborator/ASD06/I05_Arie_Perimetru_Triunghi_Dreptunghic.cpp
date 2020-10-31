#include <iostream>
#include <cmath>
using namespace std;
//Calculati aria si perimetrul unui triunghi dreptunghic cunoscand lungimea catetelor.
//aria = c1*c2/2 ; ipotenuza = sqrt(c1*c1+c2*c2) ; perimetru = ipotenuza + c1 + c2
//EX: c1 = 6(cm) ; c2 = 8(cm) => arie = 24 (cm^2) ; perimetru = 24 (cm)

struct triunghi_dr{ float c1,c2,ip; };
void Calcul_Ipotenuza(triunghi_dr &t){ t.ip = sqrt(t.c1*t.c1 + t.c2*t.c2); } 
float Arie_Triunghi(triunghi_dr t){ return t.c1*t.c2/2; }
float Petimetru_Triunghi(triunghi_dr t){ return t.c1 + t.c2 + t.ip; }

int main(){
    triunghi_dr t;
    cout<<"Dati lungimea catetele: "; cin>>t.c1>>t.c2;
    Calcul_Ipotenuza(t);
    cout<<"Arie triunghi: "<<Arie_Triunghi(t)<<endl;
    cout<<"Petimetru triunghi: "<<Petimetru_Triunghi(t)<<endl;
}