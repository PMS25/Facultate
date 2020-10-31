#include <iostream>
using namespace std;
//Se citesc n,m1,...,mn si c1c2...cn.
//Sa se verifice daca c1c2...cn este element al produsului cartezian {1,2,...,m1} x {1,2,...,m2} x ... x {1,2,...,mn}
//si daca da sa se afiseze numarul de ordine al acestui element, conform ordinii lexicografice, fara generare.
//EX: Pentru n = 5, m1 = 3, m2 = 4, m3 = 2, m4 = 3, m5 = 4 si c1c2c3c4c5 = 23214 => k = 160.

void CitireDate(int *&m, int &n, long &nr){
    cout<<"Dati numarul multimilor: "; cin>>n;
    m = new int[n+1];
    for(int i=1; i<=n; i++){
        cout<<"Card(A"<<i<<") = ";
        cin>>m[i];
    }
    cout<<"Dati numarul: "; cin>>nr;
}

void Afisare(int k, long nr){
    cout<<"Ordinul numarului "<<nr<<" : "<<k<<endl;
}

bool Valid(int *m, int n, int nr){
    for(int i=n; i>=1; i--)
        if(nr%10 > m[i])
            return false;
        else
            nr/=10;
    return true;
}

void Numar2Ordin(int *m, int n, long nr){
    int *p = new int[n+1], i; long copy_nr = nr, aux = 1;
    //23214 - 11111 = 12103
    for(int i=1; i<=n; i++){
        nr-=aux;
        aux=aux*10;
    }
    //p = 96,24,12,4,1
    p[n]=1;
    for(i=n-1; i>=1; i--)
        p[i] = p[i+1]*m[i+1];
    //1*96+2*24+1*12+0*4+1*3 + 1 = ordin
    aux = 1;
    for(int i=n; i>=1; i--){
        aux+=p[i]*(nr%10);
        nr/=10;
    }
    Afisare(aux,copy_nr);
    delete[] p;
}

int main(){
    int *m,n; long nr;
    CitireDate(m,n,nr);
    if(Valid(m,n,nr)==0)
        cout<<"Numar invalid";
    else
        Numar2Ordin(m,n,nr);
    delete[] m;
}