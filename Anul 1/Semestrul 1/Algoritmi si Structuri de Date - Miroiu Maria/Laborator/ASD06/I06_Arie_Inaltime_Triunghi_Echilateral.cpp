#include <iostream>
#include <cmath>
using namespace std;
//Calculati inaltimea si aria unui triunghi echilateral de latura cunoscuta
//h = l * sqrt(3) / 2 ; arie = l^2 * sqrt(3) / 4 ;
//EX: l = 2 (cm) => h = sqrt(3) = 1.7 (cm) ; arie = sqrt(3) = 1.7 (cm^2) 

float InaltimeTriunghi(int l){ return l*sqrt(3)/2; }
float ArieTriunghi(int l){ return l*l*sqrt(3)/4; }

int main(){
    int l; cout<<"Dati latura: "; cin>>l;
    cout<<"Arie triunghi: "<<ArieTriunghi(l)<<endl;
    cout<<"Inaltime triunghi: "<<InaltimeTriunghi(l)<<endl;
}