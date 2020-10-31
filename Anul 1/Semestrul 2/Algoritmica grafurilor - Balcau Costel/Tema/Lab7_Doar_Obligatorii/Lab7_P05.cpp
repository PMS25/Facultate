#include <iostream>
//Numarul arborilor partiali ai unui graf
//Pornind de la matricea de adiacenta, excluzand buclele se va creea matricea de admitanta al carui determinant va fi calculat
struct GORMA{int MA[100][100];int n; int AA[100][100];}G;
int B[100][100],mx=1;
using namespace std;
void Read(){
    cout<<"Dati numarul de  noduri ale grafului: ";
    cin>>G.n;
    cout<<"Scrieti Matricea de adiacenta a grafului: "<<endl;
    for(int i=1;i<=G.n;i++)
        for(int j=1;j<=G.n;j++)
            cin>>G.MA[i][j];
}
int  Check(){
    for(int i=1;i<=G.n-1;i++)
        for(int j=i+1;j<=G.n;j++)
            if(G.MA[i][j]!=G.MA[j][i])
                return 1;
    return 0;
}
void TransformGO(){
    for(int i=1;i<=G.n;i++)
        for(int j=1;j<=G.n;j++)
            G.AA[i][j]=0;
    for(int i=1;i<=G.n;i++)
        for(int j=1;j<=G.n;j++)
            while(G.MA[i][j]){
                G.AA[i][j]-=1;
                G.AA[j][i]-=1;
                G.MA[i][j]--;
            }
    for(int i=1;i<=G.n;i++){
            int sum=0;
        for(int j=1;j<=G.n;j++)
            sum+=G.AA[i][j];
        G.AA[i][i]=sum*(-1);
    }
}

void TransformGN(){
    for(int i=1;i<=G.n;i++)
        for(int j=1;j<=G.n;j++)
            G.AA[i][j]=0;
    for(int i=1;i<=G.n-1;i++)
        for(int j=i+1;j<=G.n;j++)
            while(G.MA[i][j]){
                G.AA[i][j]-=1;
                G.AA[j][i]-=1;
                G.MA[i][j]--;
            }
    for(int i=1;i<=G.n;i++){
            int sum=0;
        for(int j=1;j<=G.n;j++)
            sum+=G.AA[i][j];
        G.AA[i][i]=sum*(-1);
    }
}
int Det2( int s, int f){
    int x=G.AA[s][s]*G.AA[f][f]-G.AA[s][f]*G.AA[f][s];
    cout<<"("<<s<<","<<f<<","<<x<<")"<<endl;
    return x;
}
double DetR(int cn,int B[100][100],int S)
{
    int i;
    if(S==cn-1) return Det2(S,cn);
     for(int i=S;i<=cn;i++)
        for(int j=S+1;j<=cn;j++)
            B[i][j]-=B[1][j];
    if(B[S][S]==0){
        for(i=S;i<=cn;i++)
            if(B[1][i]!=0){
                for(int j=S;j<=cn;j++)
                    B[j][S]+=B[i][j];
                break;
            }
        if(i>cn) return 0;
    }

    double x=1;
    for(i=S;i<=cn;i++)
        for(int j=S+1;j<=cn;j++ ){
            B[i][j]*=B[S][j]/B[S][S];
            x*=B[S][j]/B[S][S];
        }
    for(int i=S;i<=cn;i++)
        for(int j=S+1;j<=cn;j++)
            B[i][j]-=B[1][j];

    return B[S][S]*x*DetR(cn,B,S+1);
}
int NrArbP(){
    for(int i=2;i<=G.n;i++)
        if(G.AA[i][i]>G.AA[mx][mx])
            mx=i;
    int cn=G.n-1;
    int B[100][100];
    for(int i=1;i<=G.n;i++)
        for(int j=1;j<=G.n;j++)
           if(i>=mx){
                if(j>=mx)B[i][j]=G.AA[i+1][j+1];
                else B[i][j]=G.AA[i+1][j];
           }else if(j>=mx) B[i][j]=G.AA[i][j+1];
    cout<<"b:"<<endl;
     for(int i=1;i<=cn;i++){
        for(int j=1;j<=cn;j++)
            cout<<B[i][j]<<" ";
        cout<<endl;
     }
    return DetR(cn,B,1);

}
void DisplayMAD(){
    for(int i=1;i<=G.n;i++){
        for(int j=1;j<=G.n;j++)
            cout<<G.AA[i][j]<<" ";
        cout<<endl;
    }

}
int main()
{
    Read();
    if(Check())
        TransformGO();
    else
        TransformGN();
    DisplayMAD();
    cout<<"Numarul de arbori este: "<<NrArbP()<<endl;
    cout<<"se scoat linia si coloana "<<mx<<endl;
    return 0;
}
