
// Verificarea daca un graf orientat dat este sau nu o arborescenta
//Un graf orientat dat este arborescenta daca este quasi-tare conex si are m=n-i muchii
#include <iostream>
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

void DF(int x){
    Viz[x]=1;
    for(int y=1;y<=G.n;y++)
        if(G.A[x][y]>=1 && Viz[y]==0){
            TATA[y]=x;
            DF(y);
        }
}

int Test(){
    int k=0;
    for(int i=1;i<=G.n;i++)
        if(TATA[i]==0) k++;
    if(k==1)
        return 1;
    return 0;
}
int Nrmuchii(){
    int k=0;
for(int i=1;i<=G.n;i++)
    for(int j=1;j<=G.n;j++)
        if(G.A[i][j]) k++;
    return k;
}
int main()
{
    Read();
     int sem=0;
    for(int i=G.n;i>0;i--){
        for(int j=1;j<=G.n;j++){TATA[j]=0;Viz[j]=0;}
        DF(i);
        for(int j=1;j<=G.n;j++)
        cout<<j<<"("<<TATA[j]<<")"<<" ";
        cout<<endl;
        if(Test()==1){sem=1;break;}

    }
    cout<<"Graful dat "<<((sem==1 && Nrmuchii()==G.n-1)?"este ":"nu este ")<<"arborescenta"<<endl;

    return 0;
}
