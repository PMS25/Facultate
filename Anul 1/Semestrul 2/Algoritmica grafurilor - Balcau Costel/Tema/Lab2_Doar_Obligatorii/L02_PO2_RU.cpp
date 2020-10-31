#include <iostream>
using namespace std;
//Generarea combinarilor pentru multimi oarecare.
//Regula Urmatorului

struct multime{
    int n;
    string *s;
};

void CitireDate(multime &m, int &n){
    cout<<"Dati cardinalul multimii: "; cin>>m.n;
    m.s = new string[m.n+1];
    cout<<"Elementele: ";
    for(int i=1; i<=m.n; i++)
        cin>>m.s[i];
    cout<<"Dati lungimea cuvintelor: "; cin>>n;
}

void Afisare(int *c, int n, multime m){
    for(int i=1; i<=n; i++)
        cout<<m.s[c[i]]<<" ";
    cout<<endl;
}

void Combinari(multime m, int n){
    int *c = new int[n+1], k;
    for(k=1; k<=n; k++) c[k]=k;
    Afisare(c,n,m);
    do{
        k=n;
        while(c[k]==m.n-n+k && k>0)
            k--;
        if(k>0){
            c[k]++;
            for(int i=k+1; i<=n; i++)
                c[i]=c[i-1]+1;
            Afisare(c,n,m);
        }
    }while(k>0);
    delete[] c;
}

int main(){
    multime m; int n;
    CitireDate(m,n);
    Combinari(m,n);
    delete[] m.s;
}