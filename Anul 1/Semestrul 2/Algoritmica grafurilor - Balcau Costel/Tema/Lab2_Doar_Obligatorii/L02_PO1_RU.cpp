#include <iostream>
using namespace std;
//Generarea combinarilor pentru multimi standard.
//Regula Urmatorului

void CitireDate(int &m, int &n){
    cout<<"Dati cardinalul multimii: "; cin>>m;
    cout<<"Dati lungimea cuvintelor: "; cin>>n;
}

void Afisare(int *c, int n){
    for(int i=1; i<=n; i++)
        cout<<c[i]<<" ";
    cout<<endl;
}

void Combinari(int m, int n){
    int *c = new int[n+1], k;
    for(k=1; k<=n; k++) c[k]=k;
    Afisare(c,n);
    do{
        k=n;
        while(c[k]==m-n+k && k>0)
            k--;
        if(k>0){
            c[k]++;
            for(int i=k+1; i<=n; i++)
                c[i]=c[i-1]+1;
            Afisare(c,n);
        }
    }while(k>0);
    delete[] c;
}

int main(){
    int m,n;
    CitireDate(m,n);
    Combinari(m,n);
}