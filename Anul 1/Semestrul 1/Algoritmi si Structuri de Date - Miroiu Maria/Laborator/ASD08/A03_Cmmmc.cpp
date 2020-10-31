#include <iostream>
using namespace std;
//Determinati celui mai mic multiplu comun dintre 2 numere naturale.

int Cmmdc(int a, int b){
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int Cmmmc(int a, int b){
    return a*b/Cmmdc(a,b);
}

int main(){
    int a, b; cout<<"Dati numarele: "; cin>>a>>b;
    cout<<"Cmmmc: "<<Cmmdc(a,b)<<endl;
}