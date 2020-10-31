#include <iostream>
//verificare  arbore
using namespace std;
struct GORMA{
    int n;
    int A[100][100];
}G;
int CC[100],nrc=0,Viz[100],TATA[100];


void Read(){
    cout<<"Dati numarul de  noduri ale grafului: ";
    cin>>G.n;
    cout<<"Scrieti Matricea de adiacenta a grafului: "<<endl;
    for(int i=1;i<=G.n;i++)
        for(int j=1;j<=G.n;j++)
            cin>>G.A[i][j];
}
void Viziteaza(int x){
    CC[x]=nrc;

}

void DF(int x){
    Viziteaza(x);
    Viz[x]=1;
    for(int y=1;y<=G.n;y++)
        if(G.A[x][y]>=1 && Viz[y]==0){
            TATA[y]=x;
            DF(y);
        }
}
int ComponenteConexe()
{
    for(int i=1;i<=G.n;i++) CC[i]=0;
    for(int i=1;i<=G.n;i++)
        if(CC[i]==0)
        {
            nrc++;
            DF(i);
        }
    return nrc;
}
int Nrmuchii(){
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
int main()
{
    Read();
    int m=Nrmuchii();
    cout<<m<<" muchii."<<endl;
    cout<<"Graful dat "<<((ComponenteConexe()==1 && m==G.n-1)?"este ":"nu este ")<<"arbore"<<endl;
    for(int i=1;i<=G.n;i++)
        cout<<i<<"("<<TATA[i]<<")"<<" ";
    return 0;
}
