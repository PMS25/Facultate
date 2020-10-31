#include <iostream>
using namespace std;
//Generarea partitiilor lui n cu k termeni.
//Backtracking

void CitireDate(int &n, int &k){
    cout<<"Dati numarul: "; cin>>n;
    cout<<"Dati nr de termeni: "; cin>>k;
}

void PrelSol(int *c, int k, int n){
    cout<<n<<" = ";
    for(int i=1; i<=k; i++)
        cout<<c[i]<<" + ";
    cout<<"\b\b \n";
}

inline bool Valid(int *c, int k, int n, int nr){
    int s = 0;
    for(int i=1; i<=n; i++)
        s+=c[i];
    if(k==n)
        return s==nr && c[k]>=c[k-1];
    return c[k]>=c[k-1];
}

void Back(int n, int min, int max, int pas, int fi){
    int *c = new int[n+1], k;
    for(k=1; k<=n; k++)
        c[k] = fi;
    k = 1;
    while(k>0)
        if(k==n+1){
            PrelSol(c,n,max);
            k--;
        }else
            if(c[k]<max){
                c[k] += pas;
                if(Valid(c,k,n,max))
                    k++;
            }else
                c[k--] = fi; 

    delete[] c;
}

int main(){
    int n,k;
    CitireDate(n,k);
    for(int i=1; i<=k; i++)
        Back(i,1,n,1,0);
}