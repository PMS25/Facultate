#include <iostream>
#include <fstream>
using namespace std;
//Determinarea matricei de adiacenta(MA), listelor de adiacenta(LA), gradelor de intrare, iesire si totale ale nodurilor unui graf orientat dat.

struct GraphMA{ int n,m,**A; };
ifstream f("graf.txt");

void Initialization(GraphMA &G){
    int i,j;
    G.A = new int* [G.n+1];
    for(i=1; i<=G.n; i++)
        G.A[i] = new int[G.n+1];
    for(i=1; i<=G.n; i++)
        for(j=1; j<=G.n; j++)
            G.A[i][j] = 0;
}

void ReadGraph(GraphMA &G){
    int a,b,i;
    f>>G.n>>G.m;
    Initialization(G);
    for(i=1; i<=G.m; i++){
        f>>a>>b;
        G.A[a][b] = 1;
    }
}

void CleanMemory(GraphMA &G){
    for(int i=1; i<=G.n; i++)
        delete[] G.A[i];
    delete[] G.A;
}

void DisplayMA(GraphMA G){
    cout<<"Matrice de adiacenta: "<<endl;
    for(int i=1; i<=G.n; i++){
        for(int j=1; j<=G.n; j++)
            cout<<G.A[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void DisplayLA(GraphMA G){
    cout<<"Lista de adiacenta:";
    for(int i=1; i<=G.n; i++){
        cout<<"L("<<i<<") : ";
        for(int j=1; j<=G.n; j++)
            if(G.A[i][j])
                cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void DisplayDegree(GraphMA G){
    int i,j,k,kk;
    cout<<"Grad noduri:"<<endl;
    for(i=1; i<=G.n; i++){
        kk=0;
        cout<<"Grad("<<i<<") : ";
        k=0; for(j=1; j<=G.n; j++) k+=(G.A[j][i] ? 1:0);
        kk+=k; cout<<"I = "<<k<<" ; ";
        k=0; for(j=1; j<=G.n; j++) k+=(G.A[i][j] ? 1:0);
        kk+=k; cout<<"E = "<<k<<" ; ";
        cout<<"T = "<<kk<<endl;
    }
    cout<<endl;
}

void Display(GraphMA G){
    DisplayMA(G);
    DisplayLA(G);
    DisplayDegree(G);
}

int main(){
    GraphMA G;
    ReadGraph(G);
    Display(G);
    CleanMemory(G);
    f.close();
}