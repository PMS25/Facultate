#include <iostream>
using namespace std;
//Descompunerea unui numar natural nenul in factori primi.

void Factori_Primi(int n){
    int k=0;
    cout<<"n = ";
    while(n%2==0){
        k++;
        n/=2;
    }
    if(k)
        cout<<"2^"<<k<<" * ";
    for(int d=3; d<=n; d+=2){
        k=0;
        while(n%d==0){
            k++;
            n/=d;
        }
        if(k)
            cout<<d<<"^"<<k<<" * ";
    }
    cout<<"\b\b "<<endl;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    Factori_Primi(n);
}