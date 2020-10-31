#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define NMAX 100
#define FILEIN "date.in"
#define LIM 32000
//Algoritmul Roy-Floyd.

struct MUCHIE{ int x,y,c; };

struct GRAF{
    int nV, nE;
    MUCHIE M[NMAX];
};

struct RETEA{
    GRAF G;
    int C[NMAX][NMAX];
}Re;

int C1[NMAX][NMAX];

void RoyFloyd(){
    int i,j,k;
    int n = Re.G.nV;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            C1[i][j] = Re.C[i][j];
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(C1[i][k] + C1[k][j] < C1[i][j])
                    C1[i][j] = C1[i][k] + C1[k][j];
}

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

void Afisare(){
    int i,j, n=Re.G.nV;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            if(i==j)
                cout<<setw(3)<<"0";
            else
                if(Re.C[i][j] > LIM)
                    cout<<setw(3)<<"-1";
                else
                    if(Re.C[i][j] == 0)
                        cout<<setw(3)<<"oo";
                    else
                        cout<<setw(3)<<Re.C[i][j];
        cout<<endl;
    }
}

int main(){
    CitireDate();
    RoyFloyd();
    Afisare();
}
