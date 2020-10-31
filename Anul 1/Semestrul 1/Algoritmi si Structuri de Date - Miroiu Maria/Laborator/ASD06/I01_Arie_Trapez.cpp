#include <iostream>
using namespace std;
//Calculati aria unui trapez cand se cunosc baza mica (b), baza mare (B) si inaltimea (h).
//EX: b=3, B=6 si h=5 =>  A = (B+b)*h/2 = 22,5

struct trapez{ float b,B,h; };

float ArieTrapez(trapez t){ return (t.B+t.b)*t.h/2; }

void Citire(trapez &t){
    cout<<"Dati baza mica (b): "; cin>>t.b;
    cout<<"Dati baza mare (B): "; cin>>t.B;
    cout<<"Dati inaltimea (h): "; cin>>t.h;
}

int main(){
    trapez t;
    Citire(t);
    cout<<"Arie trapez: "<<ArieTrapez(t)<<endl;
}