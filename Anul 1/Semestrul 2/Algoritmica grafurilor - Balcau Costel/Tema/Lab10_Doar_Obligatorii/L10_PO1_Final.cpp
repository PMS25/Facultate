#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 100
#define FILEIN "date1.in"
//Determinarea inchiderii unui graf neorientat simplu dat.

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

void AfisareDate(GRAF G){
    int i,j;
    for(i=1; i<=G.nV; i++){
        for(j=1; j<=G.nV; j++)
            cout<<G.A[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void Inchidere(GRAF &G){
    int i,j;
    for(i=1; i<G.nV; i++)
        for(j=i+1; j<=G.nV; j++)
            if(G.A[i][j]!=1 && G.A[i][G.nV+1]+G.A[j][G.nV+1]>=G.nV){
                G.A[i][j]=1;
                G.A[j][i]=1;
                G.A[i][G.nV+1]++;
                G.A[j][G.nV+1]++;
                i=j=1;
            }
}

void Afisare(GRAF G){
    cout<<"Initial:"<<endl;
    AfisareDate(G);
    cout<<"Dupa inchidere:"<<endl;
    Inchidere(G);
    AfisareDate(G);
    cout<<"Muchii: "<<endl;
    for(int i=1; i<G.nV; i++)
        for(int j=i+1; j<=G.nV; j++)
            if(G.A[i][j]==1 && i!=j)
                cout<<"["<<i<<","<<j<<"]"<<endl;
}

int main(){
    CitireDate(G);
    Afisare(G);
}