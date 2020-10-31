#include <iostream>
#include <fstream>
using namespace std;

struct GraphMA{ int n,m,*V,**A; }G;
bool *VIZ; int *TATA;
ifstream f("graph.in");

void Initialization(){
    int i,j;
    G.A = new int*[G.n+1];
    G.V = new int[G.n+1];
    VIZ = new bool[G.n+1];
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

int main(){
    ReadGraph();
    int x; cout<<"Dati nodul: "; cin>>x;
    int p = PozitieNod(x);
    if(p==0)
        cout<<"Nod invalid"<<endl;
    else{
        cout<<"DF("<<x<<") : ";
        DF_Recursiv(p);
        cout<<endl;
    }
}