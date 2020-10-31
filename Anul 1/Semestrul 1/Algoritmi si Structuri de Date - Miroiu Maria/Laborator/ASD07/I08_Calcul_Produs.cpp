#include <iostream>
using namespace std;
//Descrieţi un algoritm pentru a calcula m^n prin înmulţiri repetate. m^n = m*m*...*m (de n ori).

float Produs(int m, int n){
    float p = 1;
    while(n--)
        p*=m;
    return p;
}

int main(){
    int m,n; cout<<"Dati baza si exponentul: "; cin>>m>>n;
    cout<<"Rezultat: "<<Produs(m,n)<<endl;
}