#include <iostream>
using namespace std;
//Afisati toate numerele de 2 cifre care au cel putin o cifra de 5 si sunt divizibile cu 17.
//Solutie: 51 si 85.

bool AreCifra(int n, int c){
    while(n){
        if(n%10==c)
            return true;
        n/=10;
    }
    return false;
}

bool EDivizibil(int n, int d){ return n%d==0; }

int main(){
    int c; cout<<"Dati cifra: "; cin>>c;
    int d; cout<<"Dati divizibilitate: "; cin>>d;
    cout<<"Solutie: ";
    for(int i=10; i<100; i++)
        if(AreCifra(i,c) && EDivizibil(i,d))
            cout<<i<<" ";
    cout<<endl;
}