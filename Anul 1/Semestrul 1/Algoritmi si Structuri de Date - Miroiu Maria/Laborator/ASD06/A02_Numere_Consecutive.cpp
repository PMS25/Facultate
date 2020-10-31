#include <iostream>
using namespace std;
//Se citesc 2 numere. Sa se descrie un algoritm pentru a verifica daca ele sunt consecutive. 
//EX: 3, 4 sunt consecutive ; 7, 6 nu sunt consecutive ; 3, 5 nu sunt consecutive

int main(){
    int a,b; cout<<"Dati numerele: "; cin>>a>>b;
    cout<<"Numerele "<<(b-a==1 ? "":" nu ")<<"sunt consecutive"<<endl;
}