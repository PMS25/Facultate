#include <iostream>
using namespace std;
//Se citesc numere reale pana la intalnirea numarului 0.
//Scrieti in C++ algoritmul pentru determinarea mediei aritmetice a numerelor citite.

void MedieAritmetica(){
    int x, k=0;
    float s=0;
    while(cin>>x && x){
        s+=x;
        k++;
    }
    cout<<"Media aritmetica a nr: "<<s/k<<endl;
}

int main(){
    cout<<"Dati numerele: ";
    MedieAritmetica();
}