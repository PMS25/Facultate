#include <iostream>
using namespace std;
//Descrieti un algoritm pentru a calcula S = 1 + 1/2 + 1/3 + ... + 1/n, pentru n nr natural nenul.

float Suma(int n){
    float s=0;
    for(int i=1; i<=n; i++)
        s+=1.0/i;
    return s;
}

int main(){
    int n; cout<<"Dati n: "; cin>>n;
    cout<<"Rezultatul sumei: "<<Suma(n)<<endl;
}