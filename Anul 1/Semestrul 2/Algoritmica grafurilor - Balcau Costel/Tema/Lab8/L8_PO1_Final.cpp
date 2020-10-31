#include <iostream>
#include <fstream>
#define NMAX 100
#define FILEIN "date.in"
using namespace std;
//Algoritmul lui Kruskal

struct GRAF{
    int nV; // n - nr de noduri
    int nE; // m - nr de muchii
    int P[4][NMAX];
    bool S[NMAX];
    int CC[NMAX];
}G;

void CitireDate(GRAF &G){
    ifstream f(FILEIN);
    f>>G.nV>>G.nE;
    for(int k=1; k<=G.nE; k++)
        f>>G.P[1][k]>>G.P[2][k]>>G.P[3][k];
    f.close();
}

void AfisareDate(GRAF G, int cost){
    cout<<"Munchii:"<<endl;
    for(int i=1; i<=G.nE; i++)
        if(G.S[i])
            cout<<G.P[1][i]<<" "<<G.P[2][i]<<" "<<G.P[3][i]<<endl;
    cout<<"Cost: "<<cost<<endl;
}

void Sortare_Pondere(GRAF &G){
    int i,j;
    for(i=1; i<G.nE; i++)
        for(j=i+1; j<=G.nE; j++)
            if(G.P[3][i] > G.P[3][j]){
                swap(G.P[1][i], G.P[1][j]);
                swap(G.P[2][i], G.P[2][j]);
                swap(G.P[3][i], G.P[3][j]);
            }
}

void Kruskal(GRAF &G){
    Sortare_Pondere(G);
    int i,k;

    //Initializare
    for(i=1; i<=G.nE; i++) G.S[i]=0;
    for(i=1; i<=G.nV; i++) G.CC[i]=i;

    int aux, cost=0, poz=0;
    int x, y, c;

    for(int l=1; l<G.nV; l++){
        k = poz;
        do{
            k++;
            x = G.P[1][k];
            y = G.P[2][k];
            c = G.P[3][k];
        }while(G.CC[x]==G.CC[y]);

        G.S[k] = 1;
        cost = cost + c;
        poz = k;
        aux = G.CC[y];

        for(i=1; i<=G.nV; i++)
            if(G.CC[i]==aux)
                G.CC[i] = G.CC[x];
    }

    AfisareDate(G,cost);
}

int main(){
    CitireDate(G);
    Kruskal(G);
}