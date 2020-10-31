#include <iostream>
using namespace std;
//Generarea permutarilor pentru multimi standard.
//Regula Urmatorului

void CitireDate(int &m){
    cout<<"Dati cardinalul multimii: "; cin>>m;
}

void Afisare(int *c, int n){
    for(int i=1; i<=n; i++)
        cout<<c[i]<<" ";
    cout<<endl;
}

void Permutari(int n){
    int *c = new int[n+1],k;
    for(k=1; k<=n; k++) c[k]=k;
    Afisare(c,n);
    do{
        k=n-1;
        while(k>0 && c[k]>=c[k+1])
            k--;
        if(k>0){
            int i=n;
            while(c[i]<=c[k]) i--;
            swap(c[i],c[k]);
            for(i=1; i<=(n-k)/2; i++)
                swap(c[k+i],c[n-i+1]);
            Afisare(c,n);
        }
    }while(k>0);
    delete[] c;
}

int main(){
    int m;
    CitireDate(m);
    Permutari(m);
}