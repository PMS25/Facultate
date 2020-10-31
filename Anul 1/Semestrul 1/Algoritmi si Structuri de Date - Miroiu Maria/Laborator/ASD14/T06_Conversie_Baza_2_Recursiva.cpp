#include <iostream>
using namespace std;
//Descrieti un algoritm recursiv pentru conversia unui numar din baza 10 in baza 2.

float Conversie(int n){
    if(n/2==0)
        return n%2;
    else
        return 10*Conversie(n/2) + n%2;    
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"In baza 2: "<<Conversie(n)<<endl;
}