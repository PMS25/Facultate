#include <iostream>
using namespace std;
//Generarea partitiilor multimii {1, 2, ..., n} cu k parti.

int *c,k,n;

void CitireDate(int &n, int &k){
    cout<<"Dati dimensiunea multimii: "; cin>>n;
    cout<<"Dati nr de parti: "; cin>>k;
}

void Afisare (int *c){
    int i,j;
    for(j=1; j<=k; j++){
        cout<<"{";
        for(i=1; i<=n; i++)
            if(c[i] == j)
                cout<<i<<", ";
        cout<<"\b\b}, ";
    }
    cout<<"\b\b \n";
    for(i=1; i<=n; i++)
        cout<<c[i]<<" ";
    cout<<endl<<"==="<<endl;
}

void Generare_S(int n,int k){
    int i;
    if(k == 1){
        for(i=1; i<=n; i++)
            c[i] = 1;
        Afisare(c);
    }else
        if(k == n){
            for(i=1; i<=n; i++)
                c[i] = i;
            Afisare(c);
        }else{
            c[n] = k;
            Generare_S(n-1,k-1);
            for(i=1; i<=k; i++){
                c[n] = i;
                Generare_S(n-1,k);
            }
        }
}
int main(){
    CitireDate(n,k);
    c = new int[n+1];
    Generare_S(n,k);
    delete[] c;
}