#include <iostream>
using namespace std;
//Generarea aranjamentelor pentru multimi oarecare.
//Backtracking

struct multime{
    int n;
    string *s;
};

void CitireDate(multime &m, int &n){
    cout<<"Dati cardinalul multimii: "; cin>>m.n;
    m.s = new string[m.n+1];
    cout<<"Elementele: ";
    for(int i=1; i<=m.n; i++)
        cin>>m.s[i];
    cout<<"Dati lungimea cuvintelor: "; cin>>n;
}

void PrelSol(int *c, int n, multime m){
    for(int i=1; i<=n; i++)
        cout<<m.s[c[i]]<<" ";
    cout<<endl;
}

bool Valid(int *c, int k){
    for(int i=1; i<k; i++)
        if(c[i]==c[k])
            return false;
    return true;
}

void Back(int n, int min, int max, int pas, int fi, multime m){
    int *c = new int[n+1], k;
    for(k=1; k<=n; k++)
        c[k]=fi;
    k=1;
    while(k>0)
        if(k==n+1){
            PrelSol(c,n,m);
            k--;
        }else
            if(c[k]<max){
                c[k]++;
                if(Valid(c,k))
                    k++;
            }else
                c[k--]=fi;
    delete[] c;
}

int main(){
    multime m; int n;
    CitireDate(m,n);
    Back(n,1,m.n,1,0,m);
}