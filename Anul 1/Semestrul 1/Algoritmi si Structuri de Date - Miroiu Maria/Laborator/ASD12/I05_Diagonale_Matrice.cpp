#include <iostream>
using namespace std;
//Se da o matrice patrata de ordin n numar par.
//Inlocuiti toate elementele de pe diagonala principala cu 11 de pe diagonala secundara cu 22.
//Sa se afiseze matricea modificata.

void DiagonalaPrincipala(int **a, int n, int x){
    for(int i=0; i<n; i++)
        a[i][i]=x;
}

void DiagonalaSecundara(int **a, int n, int x){
    for(int i=0; i<n; i++)
        a[i][n-i-1] = x;
}

void CitireMatricePatratica(int **&a, int &n, int &x, int &y){
    cout<<"Dati numarul de linii (matrice patratica): "; cin>>n;
    a = new int*[n];
    for(int i=0; i<n; i++)
        a[i] = new int[n];
    cout<<"Dati elementele: "<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    cout<<"Dati valoare pentru DP: "; cin>>x;
    cout<<"Dati valoare pentru DS: "; cin>>y;
}

void AfisareMatricePatratica(int **&a, int n){
    cout<<"Matrice: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void EliminareMatrice(int **a, int n){
    for(int i=0; i<n; i++)
        delete[] a[i];
    delete[] a;
}

int main(){
    int **a, n, x, y;
    CitireMatricePatratica(a,n,x,y);
    DiagonalaPrincipala(a,n,x);
    DiagonalaSecundara(a,n,y);
    AfisareMatricePatratica(a,n);
}