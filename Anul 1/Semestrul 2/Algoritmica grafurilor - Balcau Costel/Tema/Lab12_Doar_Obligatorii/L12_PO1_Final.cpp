#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 100
#define FILEIN "date.in"
#define INF 32000
//Algoritmul Ford-Fulkerson.

struct MUCHIE{
    int x,y,c;
};

struct GRAF{
    int nV, nE;
    MUCHIE M[NMAX];
};

struct RETEA{
    GRAF G;
    int s,t;
    int C[NMAX][NMAX];
}Re;

bool SEL[NMAX];
int TATA[NMAX];
int F[NMAX][NMAX];
int R[NMAX][NMAX];
int vmax, rmin;

void CitireDate(){
    ifstream f(FILEIN);
    int x,y,c,e;
    f>>Re.G.nV>>Re.G.nE;
    for(e=1; e<=Re.G.nE; e++){
        f>>x>>y>>c;
        Re.G.M[e].x = x;
        Re.G.M[e].y = y;
        Re.G.M[e].c = c;
        Re.C[x][y] = c;
    }
    f>>Re.s>>Re.t;
    f.close();
}

void CalculReziduri(){
    int i,j;
    int n = Re.G.nV;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(F[i][j] < Re.C[i][j])
                R[i][j] = Re.C[i][j] - F[i][j];
            else
                if(F[j][i]>0)
                    R[i][j] = F[j][i];
                else
                    R[i][j] = 0;
}

void DF(int i){
    int n=Re.G.nV;
    for(int j=1; j<=n; j++)
        if(R[i][j]>0 && SEL[j]==0){
            TATA[j]=i;
            SEL[j]=1;
            DF(j);
        }
}

void DetLantCR(){
    int i, j = Re.G.nV;
    while(j!=1){
        i = TATA[j];
        if(rmin > R[i][j])
            rmin = R[i][j];
        j = i;
    }
}

void MarireFlux(){
    int i, j = Re.G.nV;
    while(j!=1){
        i = TATA[j];
        if(Re.C[i][j]>F[i][j])
            F[i][j] += rmin;
        else
            F[j][i] -= rmin;
        j=i;
    }
}

void FordFulkerson(){
    int i,j;
    int n = Re.G.nV;

    //Initializare flux
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            F[i][j]=0;

    vmax = 0;

    do{
        CalculReziduri();
        
        SEL[1]=1;
        for(i=2; i<=n; i++)
            SEL[i]=0;
        TATA[1]=0;
        
        DF(1);
        if(SEL[n]==1){
            rmin=INF;
            DetLantCR();
            MarireFlux();
            vmax += rmin;
        }

    }while(SEL[n]==1);
}

void AfisareDate(){
    int i,j, n = Re.G.nV;
    cout<<"S: "<<Re.s<<" ;; T: "<<Re.t<<endl;
    cout<<"Matrice de Adiacenta: "<<endl;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            cout<<F[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"Lista de muchii: "<<endl;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(F[i][j])
                cout<<i<<" "<<j<<" "<<F[i][j]<<"/"<<Re.C[i][j]<<endl;
    cout<<endl<<"Vmax: "<<vmax<<endl;
}

int main(){
    CitireDate();
    FordFulkerson();
    AfisareDate();
}