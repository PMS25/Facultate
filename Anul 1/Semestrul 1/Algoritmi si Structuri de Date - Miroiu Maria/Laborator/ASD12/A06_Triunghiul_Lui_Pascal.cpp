#include <iostream>
using namespace std;
//Sa se determine si sa se afiseze triunghiul lui Pascal sub forma de piramida.

void AfisareM(int **a, int n){
    cout<<"Matrice: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void Pascal(int **a, int n){
    a[0][0] = 1;
    for(int i=1; i<n; i++){
        a[i][0] = 1;
        a[i][i] = 1;
        for(int j=1; j<i; j++)
            a[i][j] = a[i-1][j-1] + a[i-1][j];
    }
}

void AlocareM(int **&a, int n){
    a = new int*[n];
    for(int i=0; i<n; i++)
        a[i] = new int[i+1];
}

void DeleteM(int **&a, int n){
    for(int i=0; i<n; i++)
        delete[] a[i];
    delete[] a;
}

int main(){
    int **a,n; cout<<"Dati nivelul: "; cin>>n;
    AlocareM(a,n);
    Pascal(a,n);
    AfisareM(a,n);
    DeleteM(a,n);
}