#include <iostream>
#include <cmath>
using namespace std;
//Calculati aria si lungimea unui cerc cand se cunoaste raza acestuia.
//Aria = PI*raza^2, Lungime = 2*PI*raza
//EX: raza = 1 => aria= 3.14, lungime = 6.28.

float ArieCerc(float r){ return M_PI*r*r; }
float LungimeCerc(float r){ return 2*M_PI*r; }

int main(){
	float r; cout<<"Dati raza cercului: "; cin>>r;
    cout<<"Arie cerc: "<<ArieCerc(r)<<endl;
    cout<<"Lungime cerc: "<<LungimeCerc(r)<<endl;
}