#include <iostream>
using namespace std;
//Implementarea secventiala a listelor liniare
// x-vector , n-nr elemente , a-valoare , k-pozitie
#define NMAX 50

void Inserare(int x[], int &n, int a, int k){
    if(n==NMAX)  cout<<"Lipsa spatiu disponibil."<<endl;
    else{
        for(int i=++n; i>k; i--)
            x[i] = x[i-1];
        x[k] = a;
    }
}
void InserareInceput(int x[], int &n, int a){ Inserare(x,n,a,0); }
void InserareSfarsit(int x[], int &n, int a){ Inserare(x,n,a,n); }

void Stergere(int x[], int &n, int k){
    if(n==0) cout<<"Nu exista elemente de sters."<<endl;
    else{
        for(int i=k+1; i<n; i++)
            x[i-1] = x[i];
        n--;
    }
}
void StergereInceput(int x[], int &n){ Stergere(x,n,0); }
void StergereSfarsit(int x[], int &n){ Stergere(x,n,n); }

int main(){
    int x[NMAX] = {1,2,3}, n=3;
    InserareInceput(x,n,5);
    InserareSfarsit(x,n,5);
    for(int i=0; i<n; i++)
        cout<<x[i]<<" ";
    cout<<endl;
    StergereInceput(x,n);
    StergereSfarsit(x,n);
    for(int i=0; i<n; i++)
        cout<<x[i]<<" ";
}
