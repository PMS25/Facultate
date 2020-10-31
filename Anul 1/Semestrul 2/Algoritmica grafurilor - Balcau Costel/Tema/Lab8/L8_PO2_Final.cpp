#include <iostream>
#include <fstream>
#include <limits>
#define NMAX 100
#define FILEIN "date.in"
using namespace std;
//Algoritmul lui Prim

struct GRAF{
    int nV; // n - nr de noduri
    int nE; // m - nr de muchii
    int C[NMAX][NMAX];
}G;

void CitireDate(GRAF &G){
    ifstream f(FILEIN);
    f>>G.nV>>G.nE;
    int i,j,k;
    for(i=1; i<=G.nV; i++)
        for(j=1; j<=G.nV; j++)
            if(i==j)
                G.C[i][j] = 0;
            else
                G.C[i][j] = numeric_limits<int>::max();
    for(k=1; k<=G.nE; k++){
        f>>i>>j;
        f>>G.C[i][j];
        G.C[j][i] = G.C[i][j];
    }
    f.close();
}

void Prim(GRAF G){
    int S[G.nV+1], TATA[G.nV+1], T[G.nV+1];
    int i,l,x,y,cost,minim;

    S[1] = 1;
    cost = 0;

    for(i=2; i<=G.nV; i++){
        S[i] = 0;
        T[i] = G.C[i][1];
        TATA[i] = 1;
    }

    cout<<"Muchii:"<<endl;
    for(l=1; l<G.nV; l++){
        minim=numeric_limits<int>::max();
        for(i=2; i<=G.nV; i++)
            if(S[i]==0 && T[i]<minim){
                minim = T[i];
                y = i;
            }
        S[y] = 1;
        x = TATA[y];
        cost += G.C[x][y];

        cout<<x<<" "<<y<<" "<<G.C[x][y]<<endl;

        for(i=2; i<=G.nV; i++)
            if(S[i]==0 && T[i] > G.C[i][y]){
                T[i] = G.C[i][y];
                TATA[i] = y;
            }
    }
    cout<<"Cost: "<<cost<<endl;
}

int main(){
    CitireDate(G);
    Prim(G);
}