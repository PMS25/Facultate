#include <iostream>
using namespace std;
//Afisarea elementelor prime dintr-un vector.

bool EPrim(int x){
    if(x<=1)
        return false;
    if(x==2)
        return true;
    if(x%2==0)
        return false;
    for(int d=3; d*d<=x; d+=2)
        if(x%d==0)
            return false;
    return true;
}

void AfisarePrime(int V[], int n){
    cout<<"Nr prime V: ";
    for(int i=0; i<n; i++)
        if(EPrim(V[i]))
            cout<<V[i]<<" ";
    cout<<endl;
}

void Citire(int *&V, int &n){
    cout<<"Dati numarul de elemente: "; cin>>n;
    V = new int[n];
    cout<<"Dati elementele: ";
    for(int i=0; i<n; i++) cin>>V[i];
}

int main(){
    int *V, n;
    Citire(V,n);
    AfisarePrime(V,n);
    delete[] V;
}