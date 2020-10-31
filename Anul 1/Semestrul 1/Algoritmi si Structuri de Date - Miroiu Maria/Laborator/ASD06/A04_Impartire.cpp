#include <iostream>
using namespace std;
//Se introduc doua numere. Daca al doilea numar este diferit de 0, sa se afiseze valoarea raportulului lor.
//EX: 10 3 => 3.33 ; 45 0 => "impartire imposibila".

int main(){
    int a,b; cout<<"Dati termenii impartirii: "; cin>>a>>b;
    if(b==0)
        cout<<"Impartire imposibila"<<endl;
    else
        cout<<"Rezultat: "<<float(a)/b<<endl;
}