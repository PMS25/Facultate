#include <iostream>
#include <cmath>
using namespace std;
//Determinati valoarea maxima (in modul) dintr-o matrice dreptunghiulara.

int MaximModul(int a, int b){ return abs(a)>abs(b) ? abs(a):abs(b); }

int FiltrareAritmetica(int **a, int n, int(Filtrare)(int,int)){
    int x = a[0][0];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            x = Filtrare(x,a[i][j]);
    return x;
}

void CitireMatrice(int **&a, int &n){
    cout<<"Dati numarul de linii (matrice patratica): "; cin>>n;
    a = new int*[n];
    for(int i=0; i<n; i++)
        a[i] = new int[n];
    cout<<"Dati elementele: "<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
}

void EliminareMatrice(int **a, int n){
    for(int i=0; i<n; i++)
        delete[] a[i];
    delete[] a;
}

int main(){
    int **a, n;
    CitireMatrice(a,n);
    cout<<"Maxim (in modul): "<<FiltrareAritmetica(a,n,MaximModul)<<endl;
    EliminareMatrice(a,n);
}