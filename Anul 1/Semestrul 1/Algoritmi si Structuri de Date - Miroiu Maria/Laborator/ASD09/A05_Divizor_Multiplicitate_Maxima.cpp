#include <iostream>
using namespace std;
// Sa se determine divizorul prim ce are multiplicitate maxima pentru un numar natural dat.

int Exponent(int n, int x){
    int k=0;
    while(n%x==0){
        n/=x;
        k++;
    }
    return k;
}

void ExponentMaxim(int n){
    int x=0, k=0;
    if(n%2==0){
        k = Exponent(n,2);
        x=2;
    }
    for(int d=3; d*d<=n; d+=2)
        if(Exponent(n,d) > k){
            k=Exponent(n,d);
            x=d;
        }
    if(x==0){
        x=n;
        k=1;
    }
    cout<<"Rezultat: numarul "<<x<<" la puterea "<<k<<endl;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    ExponentMaxim(n);
}