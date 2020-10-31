#include <iostream>
using namespace std;
//Sa se determine daca 2 numere sunt gemene (p şi q sunt gemene daca ambele sunt numere prime şi q-p = 2).
//EX: 3 si 5, 5 si 7, 11 si 13, 17 si 19, 29 si 31 sunt numere gemene.

bool EPrim(int x){
    if(x<=1)
        return false;
    if(x==2)
        return true;
    if(x%2==0)
        return false;
    for(int i=3; i*i<x; i+=2)
        if(x%i==0)
            return false;
    return true;
}

bool SuntGemene(int a, int b){
    if(EPrim(a)==false || EPrim(b)==false)
        return false;
    if(b-a!=2)
        return false;
    return true;
}

int main(){
    int a,b; cout<<"Dati numerele: "; cin>>a>>b;
    cout<<"Numerele "<<a<<" si "<<b<<(SuntGemene(a,b) ? "":" nu")<<" sunt gemene"<<endl;
}