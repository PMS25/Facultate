#include <iostream>
using namespace std;
//Generarea compunerilor lui n cu m termeni.
//Backtracking

void CitireDate(int &n, int &m){
    cout<<"Dati numarul: "; cin>>n;
    cout<<"Dati nr de termeni: "; cin>>m;
}

void PrelSol(int *c, int m, int n){
    cout<<n<<" = ";
    for(int i=1; i<=m; i++)
        cout<<c[i]<<" + ";
    cout<<"\b\b \n";
}

inline bool Valid(int *c, int m, int n){
    int s = 0;
    for(int i=1; i<=m; i++){
        if(c[i]<0) return s <= n;
        s += c[i];
    }
    if(s == n)
        PrelSol(c,m,n);
    return s <= n;
}

void Back(int n, int min, int max, int pas, int fi){
    int *c = new int[n+1], k;
    for(k=1; k<=n; k++)
        c[k] = fi;
    k = 1;
    while(k>0)
        if(k==n+1){
            // PrelSol(c,n,max);
            k--;
        }else
            if(c[k]<max){
                c[k] += pas;
                if(Valid(c,n,max))
                    k++;
            }else
                c[k--] = fi; 

    delete[] c;
}

int main(){
    int n,m;
    CitireDate(n,m);
    Back(m,0,n,1,-1);
}