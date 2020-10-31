#include <iostream>
using namespace std;
//Generarea submultimilor unei multimi oarecare.
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
        if(c[i]==1)
            cout<<m.s[i]<<" ";
    cout<<endl;
}

void Submultimi(multime m){
    int *c = new int[m.n+1], k;
	for(k=1; k<=m.n; k++) c[k]=1;
    Afisare(c,m);
	do{
        k=m.n;
        while(k>0 && c[k]==2) k--;
        if(k>0){
            c[k]=2;
            for(int i=k+1; i<=m.n; i++) c[i]=1;
            Afisare(c,m);
        }
    }while(k>0);
    delete[] c;
}

int main(){
    multime m;
    CitireDate(m);
    Submultimi(m);
}