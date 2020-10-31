#include <iostream>
#include <math.h>
//Determinarea matricei de admitanta
//Vom folosi matricea de incidenta a grafului dat sau alta varianta ar fi folosirea matricei de adiacenta si verificarea daca graful este O sau N
struct GORMA
{
    int AI[100][100];
    int n;
    int m;
    int AA[100][100];
} G;
using namespace std;
void Read()
{
    cout<<"Numarul de noduri al grafului: ";
    cin>>G.n;
    cout<<"Numarul de muchii al grafului dat: ";
    cin>>G.m;
    for(int i=1; i<=G.n; i++)
        for(int j=1; j<=G.m; j++)
            cin>>G.AI[i][j];
}
void Transform()
{
    for(int i=1; i<=G.n; i++)
        for(int j=1; j<=G.n; j++)
            G.AA[i][j]=0;
    for(int j=1; j<=G.m; j++)
    {
        int x=0,y=0;
        for(int i=1; i<=G.n; i++)
        {
            if(G.AI[i][j]!=0)
                if(x==0)
                {
                    x=i;
                }
                else if(y==0)
                {
                    y=i;
                    break;
                }
        }
        if(x && y)
        {
            cout<<x<<" "<<y<<endl;
            G.AA[x][y]-=1;
            G.AA[y][x]-=1;
        }
    }
    for(int i=1; i<=G.n; i++)
    {
        int sum=0;
        for(int j=1; j<=G.n; j++)
            sum+=G.AA[i][j];
        G.AA[i][i]=sum*(-1);
    }
}
void DisplayGMADM()
{
    for(int i=1; i<=G.n; i++)
    {
        for(int j=1; j<=G.n; j++)
            cout<<G.AA[i][j]<<" ";
        cout<<endl;
    }
}
using namespace std;

int main()
{
    Read();
    Transform();
    DisplayGMADM();
    return 0;
}
