#include <iostream>
using namespace std;
//Determinati celui mai mare divizor comun dintre 3 numere naturale.

int Cmmdc(int a, int b){
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int Cmmdc(int a, int b, int c){
    return Cmmdc(Cmmdc(a,b),c);
}

int main(){
    int a, b, c; cout<<"Dati numarele: "; cin>>a>>b>>c;
    cout<<"Cmmdc: "<<Cmmdc(a,b,c)<<endl;
}