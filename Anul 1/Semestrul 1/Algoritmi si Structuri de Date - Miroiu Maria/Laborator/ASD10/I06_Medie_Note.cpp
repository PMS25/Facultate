#include <iostream>
using namespace std;
//Se considera rezultatele obtinute la examen al studentilor de la mate-info.
//Calculati media notelor celor promovati.

bool EPromovat(int V[], int n){
    for(int i=0; i<n; i++)
        if(V[i]<5)
            return false;
    return true;
}

float MediaNotelor(int V[], int n){
    float s = V[0];
    for(int i=1; i<n; i++) s+=V[i];
    return s/n;
}

void Citire(int *&V, int &n){
    cout<<"Dati numarul de note: "; cin>>n;
    V = new int[n];
    cout<<"Dati notele: ";
    for(int i=0; i<n; i++) cin>>V[i];
}

int main(){
    int *V, n;
    Citire(V,n);
    if(EPromovat(V,n))
        cout<<"Media notelor: "<<MediaNotelor(V,n)<<endl;
    else
        cout<<"Elev nepromovat."<<endl;
    delete[] V;
}