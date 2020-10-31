#include <iostream>
using namespace std;
//Generarea compunerilor lui n cu m termeni.
//Regula Urmatorului

void CitireDate(int &n, int &m){
    cout<<"Dati numarul: "; cin>>n;
    cout<<"Dati nr de termeni: "; cin>>m;
}

void Afisare(int *c, int m, int n){
    cout<<n<<" = ";
    for(int i=1; i<=m; i++)
        cout<<c[i]<<" + ";
    cout<<"\b\b \n";
}

void Compuneri(int n, int m){
    int *c = new int[m+1], k;
    for(k=1; k<m; k++) c[k] = 0;
    c[k] = n;
    Afisare(c,m,n);
    do{
        k = m;
        while(k>1 && c[k]==0)
            k--;
        if(k>1){
            c[k-1]++;
            c[m]=c[k]-1;
            if(k<m)
                c[k] = 0;
            Afisare(c,m,n);
        }
    }while(k>1);
    delete[] c;
}

int main(){
    int n,m;
    CitireDate(n,m);
    Compuneri(n,m);
}