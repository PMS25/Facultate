#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//Determinarea matricei de incidenta a unui graf orientat dat.

struct GraphMA{ int n,m,**A; };
ifstream f("graf.txt");

void Initialization(GraphMA &G){
    int i,j;
    G.A = new int* [G.n+1];
    for(i=1; i<=G.n; i++)
        G.A[i] = new int[G.m+1];
    for(i=1; i<=G.n; i++)
        for(j=1; j<=G.m; j++)
            G.A[i][j] = 0;
}

void ReadGraph(GraphMA &G){
    int a,b,i;
    f>>G.n>>G.m;
    Initialization(G);
    for(i=1; i<=G.m; i++){
        f>>a>>b;
        G.A[a][i]=1;
        G.A[b][i]=-1;
    }
}

void DisplayMA(GraphMA G){
    cout<<"Matrice de adiacenta: "<<endl;
    for(int i=1; i<=G.n; i++){
        for(int j=1; j<=G.m; j++)
            cout<<setw(2)<<G.A[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void CleanMemory(GraphMA &G){
    for(int i=1; i<=G.n; i++)
        delete[] G.A[i];
    delete[] G.A;
}

int main(){
    GraphMA G;
    ReadGraph(G);
    DisplayMA(G);
    f.close();
}