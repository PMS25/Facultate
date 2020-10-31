#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 100
#define FILEIN "in.txt"
//Verificarea conditiilor suficiente de hamiltoneitate pentru un graf neorientat dat.
//cl(G) = Khvatal, Chvatal, Bondy, Posa, Ore, Dirac

struct GRAF{
    int nV, nE;
    int A[NMAX][NMAX];
}G;

void CitireDate(GRAF &G){
    ifstream f(FILEIN);
    f>>G.nV>>G.nE;
    int i,j,k;
    for(k=1; k<=G.nE; k++){
        f>>i>>j;
        G.A[i][j]++;
        G.A[j][i]++;
        G.A[i][G.nV+1]++;
        G.A[j][G.nV+1]++;
    }
    f.close();
}

int Inchidere(GRAF G){
    int i,j,V[50];
    for(i=1; i<=G.nV; i++)
        V[i]=G.A[i][G.nV+1];

    for(i=1; i<G.nV; i++)
        for(j=i+1; j<=G.nV; j++)
            if(G.A[i][j]!=1 && V[i]+V[j]>=G.nV){
                G.A[i][j]=1;
                G.A[j][i]=1;
                V[i]++;
                V[j]++;
                i=j=1;
            }

    for(i=1,j=0; i<=G.nV; i++)
        j+=V[i];

    return j/2;
}

int Khvatal(GRAF G, int V[]){
    int i,j;
    for(i=G.nV; i>=G.nV/2; i--)
        if(!(V[i]>i || V[G.nV-i]>=G.nV-i))
            return 0;
    return 1;
}

int Bondy(GRAF G, int V[]){
    int i,j;
    for(i=1; i<=G.nV; i++)
        for(j=i+1; j<=G.nV; j++)
            if(!(V[i]>i || V[j]>j || i==j || V[i]+V[j]>=G.nV))
                return 0;
    return 1;
}

int Posa(GRAF G, int V[]){
    int i,j;
    for(i=1; i<(G.nV-1)/2;i++)
        if(V[i]<i)
            return 0;
    if(V[i]<i && i==(G.nV-1)/2 && G.nV%2)
        return 0;
    return 1;
}

int Ore(GRAF G, int V[]){
    int i,j;
    for(i=1; i<=G.nV; i++)
        for(j=i+1; j<=G.nV; j++)
            if(V[i]+V[j]<G.nV && G.A[i][j]!=1)
                return 0;
    return 1;
}

int Dirac(GRAF G, int V[]){
    int i,j;
    for(i=1; i<=G.nV; i++)
        if(V[i]<G.nV/2)
            return 0;
    return 1;
}

void Validare(GRAF G){
    int i,j;
    int V[NMAX];

    for(i=1; i<=G.nV; i++)
        V[i]=G.A[i][G.nV+1];

    for(i=1; i<G.nV; i++)
        for(j=i+1; j<=G.nV; j++)
            if(V[i]>V[j])
                swap(V[i],V[j]);

    cout<<"Inchidere: ";
    cout<<(Inchidere(G)==(G.nV*(G.nV-1))/2 ? "E":"Nu e")<<" hemiltonian"<<endl;

    cout<<"Khvatal: ";
    cout<<(Khvatal(G,V) ? "E":"Nu e")<<" hemiltonian"<<endl;

    cout<<"Bondy: ";
    cout<<(Bondy(G,V) ? "E":"Nu e")<<" hemiltonian"<<endl;

    cout<<"Posa: ";
    cout<<(Posa(G,V) ? "E":"Nu e")<<" hemiltonian"<<endl;
    
    cout<<"Ore: ";
    cout<<(Ore(G,V) ? "E":"Nu e")<<" hemiltonian"<<endl;
    
    cout<<"Dirac: ";
    cout<<(Dirac(G,V) ? "E":"Nu e")<<" hemiltonian"<<endl;
}

int main(){
    CitireDate(G);
    Validare(G);
}
