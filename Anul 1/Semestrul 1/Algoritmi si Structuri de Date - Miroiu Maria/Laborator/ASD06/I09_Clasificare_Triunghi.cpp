#include <iostream>
using namespace std;
//Stiind valoarea unghiurilor unui triunghi sa se verifice daca este triunghi, apoi determinati tipul triunghiului.
//EX: A=60, B=70, C=50 => ascutitunghic

struct triunghi{ float u1,u2,u3; };
bool ETriunghi(triunghi t){ return t.u1+t.u2+t.u3==180; }
string TipTriunghi(triunghi t){
    if(t.u1<90 && t.u2<90 && t.u3<90) return "ascutitunghic";
    if(t.u1==90 || t.u2==90 || t.u3==90) return "dreptunghic";
    return "obtuzunghic";
}

int main(){
    triunghi t;
    cout<<"Dati unghiurile: "; cin>>t.u1>>t.u2>>t.u3;
    if(ETriunghi(t))
        cout<<"Tip triunghi: "<<TipTriunghi(t)<<endl;
    else
        cout<<"Unghiurile nu alcatuiesc un triunghi"<<endl;
    
}