#include <iostream>
using namespace std;
//Afisarea elementelor distincte dintr-un vector.
//EX: V = (1 2 5 2 4 1 2) -> 1, 2, 5, 4.

void AfisareDate(int V[], int n){
    for(int i=0; i<n; i++)
        cout<<V[i]<<" ";
    cout<<endl;
}

void FiltrareDistincte(int V[], int &n){
    int k=1;
    bool aux;
    for(int i=1; i<n; i++){
        aux = true;
        for(int j=0; j<i; j++)
            aux = (V[j] == V[i] ? false:aux);
        if(aux)
            V[k++]=V[i];
    }
    n=k;
}

void CitireDate(int *&V, int &n){
    cout<<"Dati numarul de elemente: "; cin>>n;
    V = new int[n];
    cout<<"Dati elementele: ";
    for(int i=0; i<n; i++) cin>>V[i];
}

int main(){
    int *V, n;
    CitireDate(V,n);
    FiltrareDistincte(V,n);
    AfisareDate(V,n);
    delete[] V;
}
