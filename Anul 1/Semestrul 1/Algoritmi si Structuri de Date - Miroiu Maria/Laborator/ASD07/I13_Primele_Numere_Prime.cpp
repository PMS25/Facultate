#include <iostream>
using namespace std;
//Determinati primele n numere prime de forma 4k-1, k numar natural.

bool EPrim(int x){
    if(x<=1)
        return false;
    if(x==2)
        return true;
    if(x%2==0)
        return false;
    for(int i=3; i*i<x; i+=2)
        if(x%i==0)
            return false;
    return true;
}

void NumerePrime(int n){
    cout<<"Primele "<<n<<" numere prime: ";
    for(int k=1; n; k++)
        if(EPrim(4*k-1)){
            cout<<4*k-1<<" ";
            n--;
        }
    cout<<endl;
}

int main(){
    int n; cout<<"Dati numarul de termeni: "; cin>>n;
    NumerePrime(n);
}