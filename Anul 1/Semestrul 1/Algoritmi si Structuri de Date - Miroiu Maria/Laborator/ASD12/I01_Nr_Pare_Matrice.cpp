#include <iostream>
using namespace std;
//Determinati numarul elementelor pare dintr-o matrice.

void CitireMatrice(int **&a, int &m, int &n){
    cout<<"Dati numarul de linii si coloane: "; cin>>m>>n;
    a = new int*[m];
    for(int i=0; i<m; i++)
        a[i] = new int[n];
    cout<<"Dati elementele matricei: "<<endl;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
}

int EPar(int x){ return x%2==0; }

int ParcurgereMatrice(int **a, int m, int n, int(Operatie)(int)){
    int k=0;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            k += Operatie(a[i][j]);
    return k;
}

void EliminareMatrice(int **a, int m, int n){
    for(int i=0; i<m; i++)
        delete[] a[i];
    delete[] a;
}

int main(){
    int **a, m, n;
    CitireMatrice(a,m,n);
    cout<<"Nr elemente pare: "<<ParcurgereMatrice(a,m,n,EPar)<<endl;
    EliminareMatrice(a,m,n);
}