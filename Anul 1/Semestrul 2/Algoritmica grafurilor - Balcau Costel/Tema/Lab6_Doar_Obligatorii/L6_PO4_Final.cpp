#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 100
#define FILEIN "date.in"
//Determinarea unei baze de cicluri pentru un graf conex dat.

struct GRAF{
    int nV, nE;
    int A[NMAX][NMAX];
}G;

bool VIZ[NMAX];
int TATA[NMAX], CC[NMAX], S[NMAX], URM[NMAX];
int nrc;

void Viziteaza(int x){
    cout<<x<<" ";
    CC[x]=nrc;
}

void CitireDate(){
    ifstream f(FILEIN);
    f>>G.nV>>G.nE;
    int i,j,k;
    for(k=1; k<=G.nV; k++){
        f>>i>>j;
        G.A[i][j]++;
        G.A[j][i]++;
     }
    f.close();
}

void DF(int x){
    int i,j,varf=1;
    Viziteaza(x);

    VIZ[x]=1;
    TATA[x]=0;
    S[varf]=x;

    while(varf>0){
        i=S[varf];
        j=URM[i]+1;
    
        while(G.A[i][j]==0 && (j<=G.nV)){ j++; }
        
        if(j>G.nV)
           varf--;
        else{
            URM[i]=j;
            if(VIZ[j]==0){
                Viziteaza(j);
                VIZ[j]=1;
                TATA[j]=i;
                S[++varf]=j;
            }
        }
    }
}

void ComponenteConexe(){
    int i;
    nrc=0;
    for(i=1; i<=G.nV; i++)
        CC[i]=0;
    
    for(i=1; i<=G.nV; i++)
        if(CC[i]==0){
            nrc++;
            DF(i);
        }
}

void Afisare(){
    for(int i=1; i<=nrc; i++){
        cout<<"Componenta tare-conexa "<<i<<" este: "<<endl;
        for(int j=1; j<=G.nV; j++)
            if(CC[j]==i)
                cout<<j<<" ";
            cout<<endl;
    }
}

int main(){
    CitireDate();
    ComponenteConexe();
    Afisare();
}