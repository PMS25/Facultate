#include <iostream>
using namespace std;
//Pentru o matrice A de tip Mm×n(R) determinati indicele liniilor ce contin cel putin k elemente nule.
//In cazul in care nu exista astfel de linii se va afisa un mesaj.

void AlocareM(int **&a, int m, int n){
    a = new int*[m];
    for(int i=0; i<m; i++)
        a[i] = new int[n];
}

void CitireM(int **&a, int &m, int &n, int &k){
    cout<<"Dati numarul de linii si coloane: "; cin>>m>>n;
    cout<<"Dati elementele matricei:"<<endl;
    AlocareM(a,m,n);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    cout<<"Dati numarul minim de elemente nule: "; cin>>k;
}

void DeleteM(int **&a, int m, int n){
    for(int i=0; i<m; i++)
        delete[] a[i];
    delete[] a;
}

void ElementeNule(int **a, int m, int n, int k){
    cout<<"Rezultat: ";
    int aux; bool sem = true;
    for(int i=0; i<m; i++){
        aux = 0;
        for(int j=0; j<n; j++)
            aux += (a[i][j]==0 ? 1:0);
        if(aux>=k){
            sem = false;
            cout<<i<<" ";
        }
    }
    if(sem)
        cout<<"Nicio solutie gasita.";
    cout<<endl;
}

int main(){
    int **a,m,n,k;
    CitireM(a,m,n,k);
    ElementeNule(a,m,n,k);
    DeleteM(a,m,n);
}