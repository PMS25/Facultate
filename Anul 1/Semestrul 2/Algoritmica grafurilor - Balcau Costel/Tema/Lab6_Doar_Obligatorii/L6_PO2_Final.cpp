#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 100
#define FILE_IN "gn.txt"
//Determinarea componentelor tare-conexe ale unui graf orientat dat.

struct GRAF_N{
    int nV, A[NMAX+1][NMAX+1];
};

void Roy_Warshall(GRAF_N &D, GRAF_N &G){
    D.nV = G.nV;
    int i,j,k;

    //D^0 - Copiere
    for(i=1; i<=G.nV; i++)
        for(j=1; j<=G.nV; j++)
            D.A[i][j] = G.A[i][j];
    
    //Determinare D^k in acelasi matrice
    for(k=1; k<=D.nV; k++)
        for(i=1; i<=D.nV; i++)
            for(j=1; j<=D.nV; j++)
                D.A[i][j] = D.A[i][j] || (D.A[i][k] && D.A[k][j]);
}

void Initializare_Matrice_Adiacenta(GRAF_N &G){
    int i,j;
    for(i=1; i<=G.nV; i++)
        for(j=1; j<=G.nV; j++)
            G.A[i][j] == (G.A[i][j] ? 1:0);
}

void CitireGraf(GRAF_N &G){
    ifstream f(FILE_IN);
    f>>G.nV;
    int i,j;
    for(i=1; i<=G.nV; i++)
        for(j=1; j<=G.nV; j++)
            f>>G.A[i][j];
    Initializare_Matrice_Adiacenta(G);
    f.close();
}

void Afisare_Componente_TConexe(int *CTC, int nCTC, int nV){
    int i,j;
    for(i=1; i<=nCTC; i++){
        for(j=1; j<=nV; j++)
            if(CTC[j]==i)
                cout<<j<<" ";
        cout<<endl;
    }
}

void Componente_Tare_Conexe(int *&CTC, GRAF_N G){
    int i,j,nrc = 0;

    //Initializare cu 0
    for(i=1; i<=G.nV; i++)
        CTC[i] = 0;

    GRAF_N D;
    Roy_Warshall(D,G);

    for(i=1; i<=D.nV; i++)
        if(CTC[i] == 0){
            nrc++;
            CTC[i] = nrc;
            for(j=i+1; j<=D.nV; j++)
                if(CTC[j]==0 && D.A[i][j]==1 && D.A[j][i]==1)
                    CTC[j] = nrc;
        }

    Afisare_Componente_TConexe(CTC,nrc,D.nV);
}

int main(){
    GRAF_N G;
    CitireGraf(G);
    int *CTC = new int[G.nV+1];
    Componente_Tare_Conexe(CTC,G);
}