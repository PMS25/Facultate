#include <iostream>
using namespace std;
//Descrieti un algoritm pentru adunarea a doua fractii, prin aducerea la acelați numitor comun.

int Cmmdc(int a, int b){
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main(){
    int a1, b1; cout<<"Dati coeficientii primei fractii: "; cin>>a1>>b1;
    int a2, b2; cout<<"Dati coeficientii celei de-a doua fractii: "; cin>>a2>>b2;
    int a = a1*b2 + a2*b1, b = b1*b2, c = Cmmdc(a,b);
    a/=c; b/=c; 
    cout<<"Suma: "<<a<<"/"<<b<<" "<<endl;
}