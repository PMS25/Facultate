#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 100
#define FILEIN "date1.in"
//Verificarea daca un graf conex dat este bipartit si, in caz afirmativ, determinarea partitiei corespunzătoare.

struct GRAF{
    int nV, nE;
    int A[NMAX][NMAX];
}G;

int b[NMAX], c[NMAX], na, nb;

void CitireDate(GRAF &G){
    ifstream f(FILEIN);
    f>>G.nV>>G.nE;
    int i,j,k;
    for(k=1; k<=G.nE; k++){
        f>>i>>j;
        G.A[i][j]++;
        G.A[j][i]++;
    }
    f.close();
}

void BF(GRAF G, int x){
    int i,j,k;
    int VIZ[NMAX], TATA[NMAX], S[NMAX], URM[NMAX];
    int varf=1, coada=1;

    VIZ[x]=1;
    TATA[x]=0;
    c[++na]=x;
    S[coada]=x;
    
    while(varf <= coada){
        i=S[varf];
        j=URM[i]+1;

        while(G.A[i][j]==0 && j<=G.nV){ j++; }

        if(j>G.nV)
            varf++;
        else{
            URM[i]=j;
            if(VIZ[j]==0){
                VIZ[j]=1;
                TATA[j]=i;
                S[++coada]=j;

                for(k=1; k<=na; k++)
                    if(TATA[j]==c[k])
                        break;

                if(k!=na+1) b[++nb]=j;
                else c[++na]=j;
            }
        }
    }
}

int Bipartit(GRAF G){
    int i,j;
    for(i=1; i<=na; i++)
        for(j=i+1; j<=na; j++)
            if(G.A[c[i]][c[j]]==1)
                return 0;

    for(i=1; i<=nb; i++)
        for(j=i+1; j<=nb; j++)
            if(G.A[b[i]][b[j]]==1)
                return 0;

    return 1;
}

void Validare(GRAF G){
    if(Bipartit(G)){
        int i;
        cout<<"Graf bipartid"<<endl;
        for(i=1; i<=na; i++)
            cout<<c[i]<<" ";
        cout<<endl;

        for(i=1; i<=nb; i++)
            cout<<b[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"Graf nebipartid"<<endl;
}

int main(){
    CitireDate(G);
    BF(G,1);
    Validare(G);
}
