#include <iostream>
#include <cmath>
using namespace std;
//Determinati, folosind schema lui Horner, catul si restul impartirii polinomului P la un polinom Q = X ─ t.

void CitireDate(int *&V, int &n, int &t){
    cout<<"Dati gradul polinomului: "; cin>>n;
    cout<<"Dati coeficientii (incepand de la cel mai semnificativ): ";
    V = new int[n+1];
    for(int i=n; i>=0; i--) cin>>V[i];
    cout<<"Dati t: "; cin>>t;
}

void AfisarePolinom(int A[], int n){
    cout<<"Catul: ";
    while(A[n]==0)
        n--;
    cout<<A[n]<<"X^"<<n;
    for(int i=n-1; i>=2; i--)
        if(A[i])
            cout<<(A[i]>=0 ? " + ":" - ")<<abs(A[i])<<"X^"<<i;
    if(A[1])
        cout<<(A[1]>=0 ? " + ":" - ")<<abs(A[1])<<"X";
    if(A[0])
        cout<<(A[0]>=0 ? " + ":" - ")<<abs(A[0]);
    cout<<endl;
}

void AfisareRest(int x){ cout<<"Restul: "<<x<<endl; }

void SchemaLuiHorner(int V[], int n, int t){
    int *A = new int[n+1];
    A[n] = 1;
    for(int i=n-1; i>=0; i--)
        A[i] = A[i+1]*t + V[i];
    int aux = A[0];
    for(int i=0; i<n; i++)
        A[i] = A[i+1];
    AfisarePolinom(A,n-1);
    AfisareRest(aux);
    delete[] A;
}

int main(){
    int *V, n, t;
    CitireDate(V,n,t);
    SchemaLuiHorner(V,n,t);
    delete[] V;
}