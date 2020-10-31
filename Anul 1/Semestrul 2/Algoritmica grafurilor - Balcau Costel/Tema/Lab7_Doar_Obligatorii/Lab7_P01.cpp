#include <iostream>
#include <fstream>
using namespace std;
//Verificarea daca un graf dat este sau nu un arbore.

struct GORMA{ int n, A[100][100]; };
int VIZ[100];

void CitireGORMA(GORMA &G){
    cin>>G.n;
    for(int i=1; i<=G.n; i++)
        for(int j=1; j<=G.n; j++)
            cin>>G.A[i][j];
}
int Nrmuchii(GORMA & G){
    int sem=1,k=0;
    for(int i=1;i<=G.n-1;i++)
        for(int j=i+1;j<=G.n;j++)
            if(G.A[i][j]!=G.A[j][i]){
                sem=0;break;
            }
    if(sem==0){
            cout<<"GO cu ";
         for(int i=1;i<=G.n;i++)
            for(int j=1;j<=G.n;j++)
                if(G.A[i][j]) k++;
        return k;
    }
    cout<<"GN cu ";
    for(int i=1;i<=G.n-1;i++)
        for(int j=i+1;j<=G.n;j++)
            if(G.A[i][j]) k++;
    return k;
}
void ParcurgereLatime(GORMA G, int nodS){
    int c[100], cs=1, cf=1;
    c[1]=nodS; VIZ[nodS]=1;
    while(cs<=cf){
        for(int nod=1; nod<=G.n; nod++)
            if((G.A[nod][c[cs]]==1 || G.A[c[cs]][nod]==1 ) && VIZ[nod]==0){
                c[++cf]=nod;
                VIZ[nod]=1;
            }
        cs++;
    }
}

int EsteConex(GORMA G){
    ParcurgereLatime(G,1);
    for(int i=1; i<=G.n; i++)
        if(VIZ[i]==0)
            return 0;
    return 1;
}

int main(){
    GORMA G;
    CitireGORMA(G);
    int m=Nrmuchii(G);
     cout<<m<<" muchii"<<endl;
    cout<<"Graful orientat "<<((EsteConex(G) &&  m==G.n-1)? "este":"nu este")<<" arbore."<<endl;
}
