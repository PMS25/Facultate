#include <iostream>
using namespace std;
//Se citesc un numar de temperaturi medii din anumite luni ca numere intregi.
//Sa se afiseze cu doua zecimale media celor pozitive si media celor negative.

float Raport(int x, int k){ return float(x)/k; }

void Citire(int &s1, int &k1, int &s2, int &k2){
    int n; cout<<"Dati numarul de inregistrari: "; cin>>n;
    cout<<"Dati temperaturile: ";
    int x; s1=0; k1=0; s2=0; k2=0;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x>=0){
            k1++;
            s1+=x;
        }else{
            k2++;
            s2+=x;
        }
    }
}

int main(){
    int s1,s2,k1,k2;
    Citire(s1,k1,s2,k2);
    cout<<"Medie temperaturi pozitive (+0): "<<Raport(s1,k1)<<endl;
    cout<<"Medie temperaturi negative: "<<Raport(s2,k2)<<endl;
}