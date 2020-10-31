#include <iostream>
#include <iomanip>
using namespace std;
//Calculul numerelor P(n,k) si P (n) - Tabel.

void CitireDate(int &n, int &k){
    cout<<"Dati numarul: "; cin>>n;
    cout<<"Dati nr de termeni: "; cin>>k;
}

void Generare_Partitii(int n, int k, int &aux){
    int *c = new int[k+1],i,j,r;
    for(i=1; i<k; i++)
        c[i]=1;
    c[k] = n-k+1;
    aux++;
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
            aux++;
        }
    }while(i>0);
    delete[] c;
}

void GenerareMatrice(int **&m, int n){
    int aux, s;
    for(int i=1; i<=n; i++){
        s = 0;
        for(int j=1; j<=i; j++){
            aux = 0;
            Generare_Partitii(i,j,aux);
            m[i][j] = aux;
            s += aux;
        }
        m[i][n+1] = s;
    }
}

void SetHeader(int n){
    cout<<setw(6)<<"P(n,k)";
    for(int i=1; i<=n; i++)
        cout<<setw(3)<<i;
    cout<<setw(5)<<"P(n)"<<endl;
}

void Afisare(int **m, int n){
    SetHeader(n);
    for(int i=1; i<=n; i++){
        cout<<setw(3)<<i<<"   ";
        for(int j=1; j<=n; j++)
            cout<<setw(3)<<m[i][j];
        cout<<setw(5)<<m[i][n+1]<<endl;
    }
}

void AlocareMemorie(int **&m, int n){
    m = new int*[n+1];
    for(int i=0; i<=n; i++){
        m[i] = new int[n+2];
        for(int j=0; j<=n; j++)
            m[i][j] = 0;
    }
}

void EliminareMemorie(int **&m, int n){
    for(int i=0; i<n; i++)
        delete[] m[i];
    delete[] m;
}

int main(){
    int **m,n; cout<<"Dati n: "; cin>>n;
    AlocareMemorie(m,n);
    GenerareMatrice(m,n);
    Afisare(m,n);
    EliminareMemorie(m,n);
}