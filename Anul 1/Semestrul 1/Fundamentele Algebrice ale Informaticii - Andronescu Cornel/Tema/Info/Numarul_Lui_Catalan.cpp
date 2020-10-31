#include <iostream>
using namespace std;

double Combinari(int n, int k){
    double p = 1, q = n-k+1;
    ++n; ++k;
    while(--n)  p*=n;
    while(--k)  p/=k;
    while(--q)  p/=q;
    return p;
}

float Catalan(int n){
    return Combinari(2*n,n) * (1.0/(n+1));
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Numarul lui Catalan: "<<Catalan(n)<<endl;
}