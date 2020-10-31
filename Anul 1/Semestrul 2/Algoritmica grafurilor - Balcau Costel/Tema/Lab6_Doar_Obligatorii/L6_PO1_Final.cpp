#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 100
#define FILE_IN "test.txt"
//Algoritmul Roy-Warshall

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

void Initializare(GRAF_N &G){
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
    Initializare(G);
    f.close();
}

void AfisareGraf(GRAF_N D){
    int i,j;
    for(i=1; i<=D.nV; i++){
        for(j=1; j<=D.nV; j++)
            cout<<D.A[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    GRAF_N G,D;
    CitireGraf(G);
    Roy_Warshall(D,G);
    AfisareGraf(D);
}