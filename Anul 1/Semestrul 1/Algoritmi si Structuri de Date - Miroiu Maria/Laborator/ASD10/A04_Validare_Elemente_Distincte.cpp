#include <iostream>
using namespace std;
//Stabiliti daca elementele dintr-un vector sunt toate distincte sau nu.

bool SuntDistincte(int V[], int &n){
    bool aux;
    for(int i=1; i<n; i++){
        aux = false;
        for(int j=0; j<i; j++)
            aux = (V[j] == V[i] ? true:aux);
        if(aux)
            return false;
    }
    return true;
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
    cout<<"Elemente vectorului "<<(SuntDistincte(V,n) ? "":"nu ")<<"sunt distincte."<<endl;
    delete[] V;
}
