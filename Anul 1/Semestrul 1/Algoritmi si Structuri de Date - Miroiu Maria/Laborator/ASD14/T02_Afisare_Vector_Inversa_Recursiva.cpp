#include <iostream>
using namespace std;
//Folosind functii recursive, descrieti algoritmul pentru afisarea elementelor unui vector

void Citire(int *a, int n){
    if(n>=0){
        Citire(a,n-1);
        cin>>a[n];
    }
}

void Afisare(int *a, int n){
    if(n>=0){
        cout<<a[n]<<" ";
        Afisare(a,n-1);
    }
}

int main(){
    int *a, n; cout<<"Dati numarul de elemente: "; cin>>n;
    a = new int[n];
    cout<<"Dati elementele: "; Citire(a,n-1);
    cout<<"Vector: "; Afisare(a,n-1);
    cout<<endl;
    delete[] a;
}