#include <iostream>
using namespace std;
//Pentru o matrice patratica de ordinul n, se considera ca diagonalele impart matricea in patru zone: nord, sud, est si vest.
//Determinati suma elementelor din zona de sud.
//OBS: elementele de pe diagonala nu fac parte din nicio zona
// A = |1  2  1 2| => S=2+(-1) ; A = |1 2  1 2 1| => S=3+1+(-2)+1
//     |1 -1  0 1|    S=1      ;     |2 1  2 3 2|    S=3
//     |2  1 -1 0|             ;     |3 3 -1 2 1|
//     |1  2 -1 2|             ;     |1 2  3 1 2|
//                             ;     |5 1 -2 1 2|

int SumaSud(int **a, int n){
    int s = 0;
    for(int i=n-1; i>=n/2+n%2; i--)
        for(int j=n-i; j<=i-1; j++)
            s+=a[i][j];
    return s;
}

void AlocareM(int **&a, int n){
    a = new int*[n];
    for(int i=0; i<n; i++)
        a[i] = new int[n];
}

void CitireM(int **&a, int &n){
    cout<<"Dati numarul de linii: "; cin>>n;
    cout<<"Dati elementele matricei:"<<endl;
    AlocareM(a,n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
}

void DeleteM(int **&a, int n){
    for(int i=0; i<n; i++)
        delete[] a[i];
    delete[] a;
}

int main(){
    int **a,n;
    CitireM(a,n);
    cout<<"Suma: "<<SumaSud(a,n)<<endl;
    DeleteM(a,n);
}