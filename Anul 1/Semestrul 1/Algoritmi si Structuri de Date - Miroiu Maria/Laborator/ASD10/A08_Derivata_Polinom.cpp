#include <iostream>
#include <cmath>
using namespace std;

void CitireDate(int *&V, int &n){
    cout<<"Dati gradul polinomului: "; cin>>n;
    cout<<"Dati coeficientii (incepand de la cel mai semnificativ): ";
    V = new int[n+1];
    for(int i=n; i>=0; i--) cin>>V[i];
}

void AfisarePolinom(int A[], int n){
    cout<<"Derivata: ";
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

void Derivata(int V[], int n){
    int *A = new int[n];
    for(int i=n; i>0; i--)
        A[i-1] = V[i]*i; 
    AfisarePolinom(A,n-1);
    delete[] A;
}

int main(){
    int *V, n;
    CitireDate(V,n);
    Derivata(V,n);
    delete[] V;
}