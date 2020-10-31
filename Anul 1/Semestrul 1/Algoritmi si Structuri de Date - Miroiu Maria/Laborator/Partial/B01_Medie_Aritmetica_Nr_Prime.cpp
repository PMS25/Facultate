#include <iostream>
using namespace std;
//Sa se descrie un algoritm pentru a determina media aritmetica a numerelor prime dintr-un vector dat.
//Daca nu exista numere prime, sa se afiseze un mesaj.

bool EPrim(int x){
    if(x<=1)
        return false;
    if(x==2)
        return true;
    if(x%2==0)
        return false;
    for(int d=3; d*d<=x; d+=2)
        if(x%d==0)
            return false;
    return true;
}

int SumaNumerePrime(int *a, int n){
    int s=0;
    for(int i=0; i<n; i++)
        s+=(EPrim(a[i]) ? a[i]:0);
    return s;
}

void Citire(int *&a, int &n){
    cout<<"Dati numarul de elemente: "; cin>>n;
    cout<<"Dati elementele: ";
    a = new int[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
}

int main(){
    int *a,n;
    Citire(a,n);
    int s = SumaNumerePrime(a,n);
    if(s==0)
        cout<<"Nu avem numere prime."<<endl;
    else
        cout<<"Suma: "<<s<<endl;
    delete[] a;
}