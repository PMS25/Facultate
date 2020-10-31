#include <iostream>
using namespace std;
//Descrieti un algoritm pentru calculul sumei S = 1*3 + 2*4 +...+ n*(n+2), pentru n>=1.

int Suma(int n){
    int s=0;
    for(int i=1; i<=n; i++)
        s+=i*(i+2);
    return s;
}

int main(){
    int n; cout<<"Dati n: "; cin>>n;
    cout<<"Rezultatul sumei: "<<Suma(n)<<endl;
}