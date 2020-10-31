#include <iostream>
using namespace std;
//Generarea permutarilor pentru multimi oarecare.
//Regula Urmatorului

struct multime{
    int n;
    string *s;
};

void CitireDate(multime &m){
    cout<<"Dati cardinalul multimii: "; cin>>m.n;
    m.s = new string[m.n+1];
    cout<<"Elementele: ";
    for(int i=1; i<=m.n; i++)
        cin>>m.s[i];
}

void Afisare(int *c, multime m){
    for(int i=1; i<=m.n; i++)
        cout<<m.s[c[i]]<<" ";
    cout<<endl;
}

void Permutari(multime m){
    int *c = new int[m.n+1],k;
    for(k=1; k<=m.n; k++) c[k]=k;
    Afisare(c,m);
    do{
        k=m.n-1;
        while(k>0 && c[k]>=c[k+1])
            k--;
        if(k>0){
            int i=m.n;
            while(c[i]<=c[k]) i--;
            swap(c[i],c[k]);
            for(i=1; i<=(m.n-k)/2; i++)
                swap(c[k+i],c[m.n-i+1]);
            Afisare(c,m);
        }
    }while(k>0);
    delete[] c;
}

int main(){
    multime m;
    CitireDate(m);
    Permutari(m);
    delete[] m.s;
}