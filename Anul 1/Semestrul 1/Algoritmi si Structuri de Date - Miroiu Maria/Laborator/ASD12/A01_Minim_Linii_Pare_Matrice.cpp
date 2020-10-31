#include <iostream>
using namespace std;
//Determinati valorile minime dintre elementele pare de pe fiecare linie dintr-o matrice.

bool MinimPar(int a, int b){
    if(a%2==1 && b%2==0)
        return true;
    if(b%2==0 and b<a)
        return true;
    return false;
}

void ParcurgereMatrice(int **a, int m, int n, bool(Conditie)(int,int)){
    int k,aux=0;
    for(int i=0; i<m; i++){
        k=a[i][0];
        for(int j=1; j<n; j++)
            if(Conditie(k,a[i][j]))
                k=a[i][j];
        if(k%2==0)
            cout<<"Linia "<<i<<": "<<k<<endl;
        else
            aux++;
    }
    if(aux==m)
        cout<<"Nu avem niciun numar par"<<endl;
}


void AlocareMatrice(int **&a, int m, int n){
    a = new int*[m];
    for(int i=0; i<m; i++)
        a[i] = new int[n];
}

void CitireMatrice(int **&a, int &m, int &n){
    cout<<"Dati numarul de linii si coloane: "; cin>>m>>n;
    cout<<"Dati elementele: "<<endl;
    AlocareMatrice(a,m,n);
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
    ParcurgereMatrice(a,m,n,MinimPar);
    EliminareMatrice(a,m,n);
}