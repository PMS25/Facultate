#include <iostream>
#include <fstream>
using namespace std;
//Parcurgerea BF a unui graf dat.
//BF - Parcurgerea pe nivele (breath first)

struct GraphMA{ int n,m,*V,**A; }G;
bool *VIZ; int *TATA, *URM;
ifstream f("graph.in");

void Initialization(){
    int i,j;
    G.A = new int*[G.n+1];
    G.V = new int[G.n+1];
    VIZ = new bool[G.n+1];
    URM = new int[G.n+1];
    TATA = new int[G.n+1];
    for(i=1; i<=G.n; i++)
        G.A[i] = new int[G.n+1];
    for(i=1; i<=G.n; i++)
        for(j=1; j<=G.n; j++)
            G.A[i][j] = 0;
}

void ReadGraph(){
    int i,a,b;
    f>>G.n>>G.m;
    Initialization();
    for(i=1; i<=G.n; i++)
        f>>G.V[i];
    for(i=1; i<=G.m; i++){
        f>>a>>b;
        G.A[a][b] = G.A[b][a] = 1;
    } 
}

void Viziteaza(int x){
    cout<<G.V[x]<<" ";
}

int PozitieNod(int x){
    for(int i=1; i<=G.n; i++)
        if(G.V[i] == x)
            return i;
    return 0;
}

void DF_Recursiv(int x){
    Viziteaza(x);
    VIZ[x] = true;
    for(int y=1; y<=G.n; y++)
        if(G.A[x][y]>=1 && VIZ[y]==0){
            TATA[y] = x;
            DF_Recursiv(y);
        }
}

void BF(int x){
    int i,j,varf,coada,*S = new int[G.n+1];
    Viziteaza(x);
    VIZ[x] = true;
    TATA[x] = 0;
    varf = 1;
    coada = 1;
    S[coada] = x;
    while(varf<=coada){
        i = S[varf], j = URM[i] + 1;
        while(G.A[i][j]==0 && j<=G.n) j++;
        if(j>G.n)
            varf++;
        else{
            URM[i] = j;
            if(VIZ[j]==0){
                Viziteaza(j);
                VIZ[j]=1;
                TATA[j]=i;
                S[++coada]=j;
            }
        }
    }
}

int main(){
    ReadGraph();
    int x; cout<<"Dati nodul: "; cin>>x;
    int p = PozitieNod(x);
    if(p==0)
        cout<<"Nod invalid"<<endl;
    else{
        cout<<"BF("<<x<<") : "; BF(p); cout<<endl;
    }
}
