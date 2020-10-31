#include <iostream>
using namespace std;
//Sa se descrie un algoritm prin care sa verificati daca cifrele unui numar sunt in ordine crescatoare sau nu.
//EX: n = 25569 are cifrele in ordine crescatoare, iar n = 25849 nu. 

bool CifreCrescatoare(int n){
    int c = n%10;
    while(n/=10){
        if(n%10>c)
            return false;
        c = n%10;
    }
    return true;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Numarul "<<(CifreCrescatoare(n) ? "":"nu ")<<"are cifre crescatoare"<<endl;
}