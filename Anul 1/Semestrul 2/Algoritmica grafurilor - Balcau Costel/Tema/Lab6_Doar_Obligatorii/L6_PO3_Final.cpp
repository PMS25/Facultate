#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 100
#define FILEIN "date.txt"
//Calculul numarului ciclomatic al unui graf dat.

int VIZ[NMAX], TATA[NMAX], nrc;

struct GRAF_N{
    int nV, nE, A[NMAX][NMAX];
}G;

void CitireGraf(GRAF_N &G){
    ifstream f(FILEIN);
    f>>G.nV>>G.nE;
    int i,x,y;
    for(i=1; i<=G.nE; i++){
        f>>x>>y;
        G.A[x][y]++;
        if(x!=y)
            G.A[y][x]++;
    }
    f.close();
}

void DF_Recursiv(GRAF_N G, int x){
    VIZ[x]=1;
    for(int y=1; y<=G.nV; y++)
        if(G.A[x][y]>=1 && VIZ[y]==0){
            TATA[y]=x;
            DF_Recursiv(G,y);
        }
}

void ComponenteConexe(GRAF_N G){
    nrc=0;
    
    for(int i=1; i<=G.nV; i++)
        if(VIZ[i]==0){
            nrc++;
            DF_Recursiv(G,i);
        }

    cout<<"Numarul ciclomatic este: "<<G.nE-G.nV+nrc<<endl;
}

int main(){
    CitireGraf(G);
    ComponenteConexe(G);
}