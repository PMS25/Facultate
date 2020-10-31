#include <iostream>
using namespace std;
//Pentru un numar de 3 cifre, sa se elimine una din cifre astfel incat numarul ramas sa fie maxim.

int EliminareCifraMaxim(int n){
    int c=n%10, b=(n/10)%10, a=(n/100)%10;
    if(a>=b && a>=c)
        return a*10 + (b>c ? b:c);
    else if(a>=b || a>=c)
        return a*10 + (b>c ? b:c);
    else
        return b*10 + c;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Maxim rezultat din eliminarea unei cifre: "<<EliminareCifraMaxim(n)<<endl;
}