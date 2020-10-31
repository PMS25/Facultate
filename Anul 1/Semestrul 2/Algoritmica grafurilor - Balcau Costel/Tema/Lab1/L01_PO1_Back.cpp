#include <iostream>
using namespace std;
//Generarea produsului cartezian pentru multimi standard.
//Backtracking

void CitireDate(int *&m, int &n){
    cout<<"Dati numarul multimilor: "; cin>>n;
    m = new int[n+1];
    for(int i=1; i<=n; i++){
        cout<<"Card(A"<<i<<") = ";
        cin>>m[i];
    }
}

void PrelSol(int *c, int n){
    for(int i=1; i<=n; i++)
        cout<<c[i]<<" ";
    cout<<endl;
}

inline bool Valid(int k){ return true; }

void Back(int n, int min, int *m, int pas, int fi){
    int *c = new int[n+1], k;
	for(k=1; k<=n; k++) c[k]=fi;
	k=1;
	while(k>0)
		if(k==n+1){
			PrelSol(c,n);
			k--;
		}else
			if(c[k]<m[k]){
				c[k]+=pas;
				if(Valid(k))
					k++;
			}else
				c[k--]=fi;
    delete[] c;
}

int main(){
    int *m,n;
    CitireDate(m,n);
    Back(n,1,m,1,0);
}