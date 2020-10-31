#include <iostream>
#include <iomanip>
using namespace std;
//Calculul numerelor P(n,k) si P (n) - Tabel.

void CitireDate(int &n, int &k){
    cout<<"Dati numarul: "; cin>>n;
    cout<<"Dati nr de termeni: "; cin>>k;
}

inline bool Valid(int *c, int k, int n, int nr){
    int s = 0;
    for(int i=1; i<=n; i++)
        s+=c[i];
    if(k==n)
        return s==nr && c[k]>=c[k-1];
    return c[k]>=c[k-1];
}

void Back(int n, int min, int max, int pas, int fi, int &aux){
    int *c = new int[n+1], k;
    for(k=1; k<=n; k++)
        c[k] = fi;
    k = 1;
    while(k>0)
        if(k==n+1){
            aux++;
            k--;
        }else
            if(c[k]<max){
                c[k] += pas;
                if(Valid(c,k,n,max))
                    k++;
            }else
                c[k--] = fi; 

    delete[] c;
}

void GenerareMatrice(int **&m, int n){
    int aux, s;
    for(int i=1; i<=n; i++){
        s = 0;
        for(int j=1; j<=i; j++){
            aux = 0;
            Back(j,1,i,1,0,aux);
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