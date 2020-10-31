#include <iostream>
using namespace std;
//Determinati media aritmetica a elementelor pozitive dintr-o matrice. 

bool EPozitiv(int n){ return n>0; }

float MedieAritmetica(int **a, int m, int n, bool(Conditie)(int)){
    float s=0; int k=0;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(Conditie(a[i][j])){
                s+=a[i][j];
                k++;
            }
    return s/k;
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
    cout<<"Medie aritmetica numare pozitive: "<<MedieAritmetica(a,m,n,EPozitiv)<<endl;
    EliminareMatrice(a,m,n);
}