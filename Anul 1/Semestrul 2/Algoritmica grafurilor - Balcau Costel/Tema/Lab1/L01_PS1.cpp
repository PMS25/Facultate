#include <iostream>
using namespace std;
//Se citesc n,m1,m2,...,mn si k.
//Sa se afiseze al k-lea element c1c2...cn al prsudului cartezian {1,2,...,m1} x {1,2,...,m2} x ... x {1,2,...,mn}
//conform ordinii lexicografice, fara generarea produsului cartezian.
//EX: Pentru n = 5, m1 = 3, m2 = 4, m3 = 2, m4 = 3, m5 = 4 si k = 160 => c1c2c3c4c5 = 23214.

void CitireDate(int *&m, int &n, int &k){
    cout<<"Dati numarul multimilor: "; cin>>n;
    m = new int[n+1];
    for(int i=1; i<=n; i++){
        cout<<"Card(A"<<i<<") = ";
        cin>>m[i];
    }
    cout<<"Dati ordinul: "; cin>>k;
}

void Afisare(int *c, int n, int k){
    cout<<"Termenul de ordinul "<<k<<" : ";
    for(int i=1; i<=n; i++)
        cout<<c[i];
    cout<<endl;
}

void Ordin2Numar(int *m, int n, int k){
    int *c = new int[n+1], *p = new int[n+1], i, aux=k;
    //p = 96,24,12,4,1
    p[n]=1;
    for(i=n-1; i>=1; i--)
        p[i] = p[i+1]*m[i+1];
    //c = 1,2,1,1,0
    for(int i=1; i<=n; i++){
        c[i]=aux/p[i];
        aux%=p[i];
    }
    //12110 - 1 = 12103
    c[n]--;
    for(int i=n; i>=1; i--)
        if(c[i]<0){
            c[i]+=m[i];
            c[i-1]--;
        }
    //12103 + 11111 = 23214
    for(i=1; i<=n; i++)
        c[i]++;
    Afisare(c,n,k);
    delete[] c, p;
}

int main(){
    int *m,n,k;
    CitireDate(m,n,k);
    Ordin2Numar(m,n,k);
    delete[] m;
}