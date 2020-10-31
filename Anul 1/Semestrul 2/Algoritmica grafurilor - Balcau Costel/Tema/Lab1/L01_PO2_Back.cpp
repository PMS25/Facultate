#include <iostream>
using namespace std;
//Generarea produsului cartezian pentru multimi oarecare.
//Backtracking

struct multime{
    int n;
    string *s;
};

void CitireDate(multime *&m, int &n){
    cout<<"Dati numarul multimilor: "; cin>>n;
    m = new multime[n+1];
    for(int i=1; i<=n; i++){
        cout<<"Card(A"<<i<<") = "; cin>>m[i].n;
        m[i].s = new string[m[i].n+1];
        cout<<"Elementele: ";
        for(int j=1; j<=m[i].n; j++)
            cin>>m[i].s[j];
    }
}

void PrelSol(int *c, multime *m, int n){
    for(int i=1; i<=n; i++)
        cout<<m[i].s[c[i]]<<" ";
    cout<<endl;
}

inline bool Valid(int k){ return true; }

void Back(int n, int min, multime *m, int pas, int fi){
    int *c = new int[n+1], k;
	for(k=1; k<=n; k++) c[k]=fi;
	k=1;
	while(k>0)
		if(k==n+1){
			PrelSol(c,m,n);
			k--;
		}else
			if(c[k]<m[k].n){
				c[k]+=pas;
				if(Valid(k))
					k++;
			}else
				c[k--]=fi;
    delete[] c;
}

int main(){
    multime *m; int n;
    CitireDate(m,n);
    Back(n,1,m,1,0);
}