#include <iostream>
using namespace std;
//Generarea submultimilor unei multimi standard.
//Regula Urmatorului

void CitireDate(int &m){
    cout<<"Dati cardinalul multimii: "; cin>>m;
}

void Afisare(int *c, int n){
    for(int i=1; i<=n; i++)
        if(c[i]==1)
            cout<<i<<" ";
    cout<<endl;
}

void Submultimi(int n){
    int *c = new int[n+1], k;
	for(k=1; k<=n; k++) c[k]=1;
    Afisare(c,n);
	do{
        k=n;
        while(k>0 && c[k]==2) k--;
        if(k>0){
            c[k]=2;
            for(int i=k+1; i<=n; i++) c[i]=1;
            Afisare(c,n);
        }
    }while(k>0);
    delete[] c;
}

int main(){
    int m;
    CitireDate(m);
    Submultimi(m);
}