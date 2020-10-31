#include <iostream>
using namespace std;
//Generarea aranjamentelor cu repetitie pentru multimi oarecare.
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
    cout<<"Dati lungimea aranjamentelor: "; cin>>n;
}

void Afisare(int *c, multime m, int n){
    for(int i=1; i<=n; i++)
        cout<<m.s[c[i]]<<" ";
    cout<<endl;
}

void Aranjamente_Repetitie(multime m, int n){
    int *c = new int[n+1], k;
	for(k=1; k<=n; k++) c[k]=1;
    Afisare(c,m,n);
	do{
        k=n;
        while(k>0 && c[k]==m.n) k--;
        if(k>0){
            c[k]++;
            for(int i=k+1; i<=n; i++) c[i]=1;
            Afisare(c,m,n);
        }
    }while(k>0);
    delete[] c;
}

int main(){
    multime m; int n;
    CitireDate(m,n);
    Aranjamente_Repetitie(m,n);
}