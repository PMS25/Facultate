#include <iostream>
using namespace std;
//Sa se determine media aritmetica a elementelor impare dintr-un vector dat.

float MedieAritmetica(int *a, int n){
    int s=0, k=0;
    for(int i=0; i<n; i++)
        if(a[i]%2){
            k++;
            s+=a[i];
        }
    return s/float(k);
}

void CitireV(int *&a, int &n){
    cout<<"Dati numarul de elemente: "; cin>>n;
    cout<<"Dati elementele: ";
    a = new int[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
}

int main(){
    int *a,n;
    CitireV(a,n);
    cout<<"Media aritmetica nr impare: "<<MedieAritmetica(a,n)<<endl;
    delete[] a;
}