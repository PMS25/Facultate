#include <iostream>
using namespace std;
//Determinati toate punctele "sa" ale unei matrice si pozitiile acestora. Daca nu exista se va afisa un mesaj.
//Definitie: Aij este punct "sa" daca este minim pe linia i si maxim pe coloana j
//EX: A = |12 10  4| => 4 pe pozitia (1,3) ; A = |1 1| => 2 pe pozitia (2,2) ; 
//        | 1  3  2|                       ;     |3 2|

int MinimLinie(int **a, int l, int n){
    int minim = a[l][0], p=0;
    for(int i=1; i<n; i++)
        if(minim>a[l][i]){
            minim = a[l][i];
            p = i;
        }
    return p;
}

int MaximColoana(int **a, int c, int m){
    int maxim = a[0][c], p =0;
    for(int i=1; i<m; i++)
        if(maxim<a[i][c]){
            maxim = a[i][c];
            p = i;
        }
    return p;
}

void PuncteSA(int **a, int m, int n){
    cout<<"Rezultat: ";
    int c; bool sem=true;
    for(int i=0; i<m; i++){
        c = MinimLinie(a,i,n);
        if(i==MaximColoana(a,c,m)){
            sem=false;
            cout<<a[i][c]<<" de pe pozitia ("<<i<<","<<c<<"); ";
        }
    }
    if(sem)
        cout<<"Niciun punct 'sa' gasit.";
    cout<<endl;
}

void AlocareM(int **&a, int m, int n){
    a = new int*[m];
    for(int i=0; i<m; i++)
        a[i] = new int[n];
}

void CitireM(int **&a, int &m, int &n){
    cout<<"Dati numarul de linii si coloane: "; cin>>m>>n;
    cout<<"Dati elementele matricei:"<<endl;
    AlocareM(a,m,n);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
}

void DeleteM(int **&a, int m, int n){
    for(int i=0; i<m; i++)
        delete[] a[i];
    delete[] a;
}

int main(){
    int **a,m,n;
    CitireM(a,m,n);
    PuncteSA(a,m,n);
    DeleteM(a,m,n);
}