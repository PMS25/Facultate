#include <iostream>
using namespace std;
//Generarea partitiilor lui n cu k termeni.
//Regula Urmatorului

void CitireDate(int &n, int &k){
    cout<<"Dati numarul: "; cin>>n;
    cout<<"Dati nr de termeni: "; cin>>k;
}

void Afisare(int *c, int k, int n){
    cout<<n<<" = ";
    for(int i=1; i<=k; i++)
        cout<<c[i]<<" + ";
    cout<<"\b\b \n";
}

void Generare_Partitii(int n, int k){
    int *c = new int[k+1],i,j,r;
    for(i=1; i<k; i++)
        c[i]=1;
    c[k] = n-k+1;
    Afisare(c,k,n);
    do{
        i = k-1;
        while(i>0 && c[i]>c[k]-2)
            i--;
        if(i>0){
            c[i]++;
            for(j=i+1; j<k; j++)
                c[j]=c[i];
            r = 0;
            for(j=1; j<k; j++)
                r+=c[j];
            c[k] = n-r;
            Afisare(c,k,n);
        }
    }while(i>0);
    delete[] c;
}

int main(){
    int n,k;
    CitireDate(n,k);
    for(int i=1; i<=k; i++)
        Generare_Partitii(n,i);
}