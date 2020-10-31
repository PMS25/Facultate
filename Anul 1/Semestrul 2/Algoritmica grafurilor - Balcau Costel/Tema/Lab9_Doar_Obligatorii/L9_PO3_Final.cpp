#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 100
#define FILEIN "date1.in"
//Verificarea daca un graf orientat dat este eulerian si, in caz afirmativ, determinarea unui circuit eulerian.

struct GRAF{
    int nV, nE;
    int A[NMAX][NMAX];
}G;

int CC[NMAX], VIZ[NMAX];

void CitireDate(GRAF &G){
    ifstream f(FILEIN);
    f>>G.nV>>G.nE;
    int i,j,k;
    for(k=1; k<=G.nE; k++){
        f>>i>>j;
        G.A[i][j]++;
        G.A[i][G.nV+1]++;
        G.A[j][G.nV+1]--;
    }
}

void Viziteaza(int x){
    CC[x]++;
}

void DF(GRAF G, int x){
    int i;

    VIZ[x]=1;
    Viziteaza(x);

    for(i=1;i<=G.nV;i++)
        if(G.A[x][i]>=1 && VIZ[i]==0){
            G.A[x][i]++;
            G.A[i][x]++;
            DF(G,i);
        }
}

int ComponenteConexe(GRAF G){
    int i,nrc=0;
    for(i=1; i<=G.nV; i++)
        if(!CC[i]){
            nrc++;
            DF(G,i);
        }
    return nrc;
}

bool GrafPartial(GRAF G){
    for(int i=1; i<=G.nV; i++)
        if(G.A[i][G.nV+1])
            return 0;
    return 1;
}

void CicluEulerian(GRAF G, int x){
    int i,j;

    i=x;

    do{
        cout<<i<<" ";
        
        j=1;
        while(G.A[i][j]!=1 && j<=G.nV){ j++; }

        if(j<=G.nV){
            G.A[i][j]=0;
            // G.A[j][i]=0;
            i=j;
        }
        else{
            j=1;
            while(G.A[i][j]!=2 && j<=G.nV){ j++; }
            
            if(j<=G.nV){
                G.A[i][j]=0;
                // G.A[j][i]=0;
                i=j;
            }
        }
    }while(j<=G.nV);
    cout<<endl;
}

void Validare(GRAF G){
    if(ComponenteConexe(G)==1 && GrafPartial(G)){
        cout<<"Graful este eulerian"<<endl;
        CicluEulerian(G,1);
    }
    else
        cout<<"Graful nu este eulerian"<<endl;
}


int main(){
    CitireDate(G);
    Validare(G);
}