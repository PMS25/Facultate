#include <iostream>
using namespace std;
//Generarea produsului cartezian pentru multimi standard.
//Regula Urmatorului

void CitireDate(int *&m, int &n){
    cout<<"Dati numarul multimilor: "; cin>>n;
    m = new int[n+1];
    for(int i=1; i<=n; i++){
        cout<<"Card(A"<<i<<") = ";
        cin>>m[i];
    }
}

void Afisare(int *c, int n){
    for(int i=1; i<=n; i++)
        cout<<c[i]<<" ";
    cout<<endl;
}

void ProdusCartezian(int *m, int n){
    int *c = new int[n+1], k;
	for(k=1; k<=n; k++) c[k]=1;
    Afisare(c,n);
	do{
        k=n;
        while(k>0 && c[k]==m[k]) k--;
        if(k>0){
            c[k]++;
            for(int i=k+1; i<=n; i++) c[i]=1;
            Afisare(c,n);
        }
    }while(k>0);
    delete[] c;
}

int main(){
    int *m,n;
    CitireDate(m,n);
    ProdusCartezian(m,n);
}