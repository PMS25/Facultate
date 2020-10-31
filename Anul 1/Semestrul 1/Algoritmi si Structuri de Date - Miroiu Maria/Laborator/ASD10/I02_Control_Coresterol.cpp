#include <iostream>
using namespace std;
//Fie c1...cn valorile colesterolului a n persoane.
//Se considera ca o persoana este sanatoasa daca are valoarea este in intervalul 50...200.
//Determinati numarul persoanelor sanatoase.

int NrPersoaneSanatoase(int V[], int n){
    int k=0;
    for(int i=0; i<n; i++)
        k+=(V[i]>=50 && V[i]<=200 ? 1:0);
    return k;
}

void Citire(int *&V, int &n){
    cout<<"Dati numarul persoane: "; cin>>n;
    V = new int[n];
    cout<<"Dati valori colesterol: ";
    for(int i=0; i<n; i++) cin>>V[i];
}

int main(){
    int *V, n;
    Citire(V,n);
    cout<<"Nr persoane sanatoase: "<<NrPersoaneSanatoase(V,n)<<endl;
    delete[] V;
}