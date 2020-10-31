#include <iostream>
using namespace std;
//Determinati valorile minima si maxima dintre toate elementele unei matrice.

int Minim(int a, int b){ return a<b ? a:b; }
int Maxim(int a, int b){ return a>b ? a:b; }

int FiltrareAritmetica(int **a, int m, int n, int(Filtrare)(int,int)){
    int x = a[0][0];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            x = Filtrare(x,a[i][j]);
    return x;
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
    cout<<"Minim matrice: "<<FiltrareAritmetica(a,m,n,Minim)<<endl;
    cout<<"Maxim matrice: "<<FiltrareAritmetica(a,m,n,Maxim)<<endl;
    EliminareMatrice(a,m,n);
}