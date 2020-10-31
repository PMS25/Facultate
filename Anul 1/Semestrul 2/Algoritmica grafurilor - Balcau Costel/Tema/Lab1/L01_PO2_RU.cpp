#include <iostream>
using namespace std;
//Generarea produsului cartezian pentru multimi oarecare.
//Regula Urmatorului

struct multime{
    int n;
    string *s;
};

void CitireDate(multime *&m, int &n){
    cout<<"Dati numarul multimilor: "; cin>>n;
    m = new multime[n+1];
    for(int i=1; i<=n; i++){
        cout<<"Card(A"<<i<<") = "; cin>>m[i].n;
        m[i].s = new string[m[i].n+1];
        cout<<"Elementele: ";
        for(int j=1; j<=m[i].n; j++)
            cin>>m[i].s[j];
    }
}

void Afisare(int *c, multime *m, int n){
    for(int i=1; i<=n; i++)
        cout<<m[i].s[c[i]]<<" ";
    cout<<endl;
}

void ProdusCartezian(multime *m, int n){
    int *c = new int[n+1], k;
	for(k=1; k<=n; k++) c[k]=1;
    Afisare(c,m,n);
	do{
        k=n;
        while(k>0 && c[k]==m[k].n) k--;
        if(k>0){
            c[k]++;
            for(int i=k+1; i<=n; i++) c[i]=1;
            Afisare(c,m,n);
        }
    }while(k>0);
    delete[] c;
}

int main(){
    multime *m; int n;
    CitireDate(m,n);
    ProdusCartezian(m,n);
}