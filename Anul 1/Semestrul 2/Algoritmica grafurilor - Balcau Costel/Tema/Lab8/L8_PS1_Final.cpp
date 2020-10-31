#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 100
#define FILEIN "test.in"
#define FILEOUT "test.out"
//Generarea tuturor arborilor partiali de cost minim ai unui graf ponderat conex dat.

struct MUCHIE{
    int x,y,c;
};

struct GRAF{
    int nV, nE;
    MUCHIE M[NMAX];
}G;

int X[NMAX], nrsol;

ofstream g(FILEOUT);

bool Valid(GRAF G, int k, int aminim){
    if(k<G.nV-1)
        return false;
    else{
        int cost=0;
        for(int i=1; i<=k; i++)
            cost += G.M[X[i]].c;
        return cost == aminim;
    }
}

void Afisare(GRAF G, int k){
    nrsol++;
    g<<"Solutie "<<nrsol<<":"<<endl;
    for(int i=1; i<=k; i++)
        g<<G.M[X[i]].x<<" "<<G.M[X[i]].y<<" "<<G.M[X[i]].c<<endl;
    g<<endl;
}

void Back(GRAF &G, int k, int minim){
    for(int i=X[k-1]+1; i<=G.nE; i++){
        X[k] = i;
        if(Valid(G,k,minim))
            Afisare(G,k);
        Back(G,k+1,minim);
    }
}

void CitireDate(GRAF &G){
    ifstream f(FILEIN);
    f>>G.nV>>G.nE;
    for(int i=1; i<=G.nE; i++)
        f>>G.M[i].x>>G.M[i].y>>G.M[i].c;
    f.close();
}

void Sortare_Pondere(GRAF &G){
    int i,j;
    for(i=1; i<G.nE; i++)
        for(j=i+1; j<=G.nE; j++)
            if(G.M[i].c > G.M[j].c)
                swap(G.M[i], G.M[j]);
}

int Kruskal(GRAF &G){
    Sortare_Pondere(G);
    int i,k;

    //Initializare
    bool S[G.nE+1]; int CC[G.nV+1];
    for(i=1; i<=G.nE; i++) S[i]=0;
    for(i=1; i<=G.nV; i++) CC[i]=i;

    int aux, cost=0, poz=0;
    int x, y, c;

    for(int l=1; l<G.nV; l++){
        k = poz;
        do{
            k++;
            x = G.M[k].x;
            y = G.M[k].y;
            c = G.M[k].c;
        }while(CC[x]==CC[y]);

        S[k] = 1;
        cost = cost + c;
        poz = k;
        aux = CC[y];

        for(i=1; i<=G.nV; i++)
            if(CC[i]==aux)
                CC[i] = CC[x];
    }

    return cost;
}

int main(){
    CitireDate(G);
    int cost = Kruskal(G);
    g<<"Cost: "<<cost<<endl<<endl;
    Back(G,1,cost);
    g.close();
}