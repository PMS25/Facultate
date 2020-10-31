#include <iostream>
using namespace std;
//Intr-o clasa exista m baieti si n fete care ii plac, insa fiecare fata place numai anumiti baieti.
//Determinati numarul de ordine al baiatului pe care il plac cele mai multe fete.
//EX: pt m=3 baieti si n=4 fete => baiatul nr 1 este indragit de cele mai multe fete
// A = |1 0 1 1|
//     |0 1 1 0|
//     |0 1 0 1|

int SumaLinie(int **a, int n, int l){
    int s = a[l][0];
    for(int i=1; i<n; i++)
        s+=a[l][i];
    return s;
}

int Popular(int **a, int m, int n){
    int l=0, maxim = SumaLinie(a,n,l);
    for(int i=1; i<m; i++)
        if(SumaLinie(a,n,i)>maxim){
            l=i;
            maxim = SumaLinie(a,n,i);
        }
    return l+1;
}

void AlocareM(int **&a, int m, int n){
    a = new int*[m];
    for(int i=0; i<m; i++)
        a[i] = new int[n];
}

void CitireM(int **&a, int &m, int &n){
    cout<<"Dati numar baieti: "; cin>>m;
    cout<<"Dati numar fete: "; cin>>n;
    cout<<"Dati tabelul: "<<endl;
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
    cout<<"Cel mai popular: "<<Popular(a,m,n)<<endl;
    DeleteM(a,m,n);
}