#include <iostream>
using namespace std;
//Se introduce un numar par de numere reale.
//Sa se adune cate doua de pe pozitii consecurive si sa se afiseze sumele obtinute.
//EX: n=6 si V = {5 4 3 6 5 5} -> 9 9 10.

void AfisareDate(int V[], int n){
    cout<<"Rezultat: ";
    for(int i=0; i<n; i++)
        cout<<V[i]<<" ";
    cout<<endl;
}

void Operatie(int V[], int &n){
    int k=0, aux;
    for(int i=0; i<n; i++){
        aux = V[i];
        if(i%2){
            V[k]+=aux;
            k++;
        }else{
            V[k]=0;
            V[k]+=aux;
        }
    }
    n/=2;
}

void CitireDate(int *&V, int &n){
    cout<<"Dati numarul de componente (par): "; cin>>n;
    V = new int[n];
    cout<<"Dati elementele: ";
    for(int i=0; i<n; i++) cin>>V[i];
}

int main(){
    int *V, n;
    CitireDate(V,n);
    Operatie(V,n);
    AfisareDate(V,n);
    delete[] V;
}
