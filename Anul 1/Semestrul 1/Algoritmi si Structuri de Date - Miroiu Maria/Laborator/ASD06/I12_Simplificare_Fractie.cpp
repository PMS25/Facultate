#include <iostream>
using namespace std;
//Se dau numerele intregi a, b si k. Sa se determine daca fractia  a / b poate fi simplificata prin k.
//EX: 6/4 poate fi simplificata prin 2 ; 4/9 nu poate fi simplificata prin 2. 

int main(){
    int a,b; cout<<"Dati termenii fractiei: "; cin>>a>>b;
    int k; cout<<"Dati valoarea: "; cin>>k;
    if(a%k==0 && b%k==0)
        cout<<"Fractia poate fi simplificata => "<<a/k<<"/"<<b/k<<endl;
    else
        cout<<"Fractia nu poate fi simplificata"<<endl;
}