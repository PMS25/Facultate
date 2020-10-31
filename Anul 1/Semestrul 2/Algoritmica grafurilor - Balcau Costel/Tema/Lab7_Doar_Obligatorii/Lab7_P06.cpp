#include <iostream>
//Determinarea matricelor gradelor de intrare, pornind de la matricea de adiacenta
using namespace std;
struct GORMA{
    int n;
    int A[100][100];
    int AGI[100][100];
}G;



void Read(){
    cout<<"Dati numarul de  noduri ale grafului: ";
    cin>>G.n;
    cout<<"Scrieti Matricea de adiacenta a grafului: "<<endl;
    for(int i=1;i<=G.n;i++)
        for(int j=1;j<=G.n;j++){
            cin>>G.A[i][j];
            G.AGI[i][j]=0;
        }

}
void Transform(){
    for(int i=1;i<=G.n;i++)
        for(int j=1;j<=G.n;j++)
            if(G.A[i][j]) G.AGI[i][j]=-G.A[i][j];
    for(int j=1;j<=G.n;j++){
        int sum=0;
        for(int i=1;i<=G.n;i++)
            sum+=G.A[i][j];
        G.AGI[j][j]=sum;
    }
}
 void Display(){
    for(int i=1;i<=G.n;i++){
        for(int j=1;j<=G.n;j++)
            cout<<G.AGI[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    Read();
    Transform();
    Display();
    return 0;
}
