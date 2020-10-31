#include <iostream>
using namespace std;
//Determinati numarului de elemente care au valoarea mai mare decat media tuturor elementelor unei matrice.

int Suma(int k, int a){ return a; }
int Contor(int x, int a){ return (a>x ? 1:0); }

int ParcurgereMatrice(int **a, int m, int n, int(Operatie)(int, int), int x){
    int k=0;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            k += Operatie(x, a[i][j]);
    return k;
}

void CitireMatrice(int **&a, int &m, int &n){
    cout<<"Dati numarul de linii si coloane: "; cin>>m>>n;
    a = new int*[m];
    for(int i=0; i<m; i++)
        a[i] = new int[n];
    cout<<"Dati elementele: "<<endl;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
}

void EliminareMatrice(int **a, int m, int n){
    for(int i=0; i<m; i++)
        delete[] a[i];
    delete[] a;
}

int main(){
    int **a, m, n;
    CitireMatrice(a,m,n);
    int suma = ParcurgereMatrice(a,m,n,Suma,0);
    cout<<"Nr elemente mai mare decat media matricei: "<<ParcurgereMatrice(a,m,n,Contor,suma/(n*m))<<endl;
    EliminareMatrice(a,m,n);
}

