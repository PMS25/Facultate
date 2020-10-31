#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define NMAX 100
#define FILEIN "date.in"
#define LIM 32000
//Algoritmul Dijkstra.

struct MUCHIE{ int x,y,c; };

struct GRAF{
    int nV, nE;
    MUCHIE M[NMAX];
};

struct RETEA{
    GRAF G;
    int C[NMAX][NMAX];
}Re;

void CitireDate(){
    ifstream f(FILEIN);
    f>>Re.G.nV>>Re.G.nE;
    int x,y,c,e;
    for(e=1; e<=Re.G.nE; e++){
        f>>x>>y>>c;
        Re.G.M[e].x = x;
        Re.G.M[e].y = y;
        Re.G.M[e].c = c;
        Re.C[x][y] = c;
    }
    f.close();
}

int S[NMAX], T[NMAX], TATA[NMAX];

void Dijkstra(int s){
    int i,x,minim;
    int n = Re.G.nV;

    for(i=1; i<=n; i++){
        S[i]=0;
        T[i]=LIM;
        TATA[i]=LIM;
    }

    T[s]=0;
    TATA[s]=0;

    do{
        minim=LIM;
        for(i=1; i<=n; i++)
            if(S[i]==0 && T[i]<minim){
                minim=T[i];
                x=i;
            }
        
        if(minim<LIM){
            S[x]=1;
            for(i=1; i<=n; i++)
                if(S[i]==0 && Re.C[x][i]<LIM)
                    if(T[i]>T[x]+Re.C[x][i]){
                        T[i]=T[x]+Re.C[x][i];
                        TATA[i]=x;
                    }
            cout<<T[x]<<" "<<x<<endl;
        }
    }while(minim<LIM);
}

void Start(){
    int i,b,n = Re.G.nV;
    for(i=1; i<=n; i++)
        for(b=1; b<=n; b++)
            if(Re.C[i][b]==0 && b!=i)
                Re.C[i][b]=LIM;
    Dijkstra(1);
}

int main(){
    CitireDate();
    Start();
}