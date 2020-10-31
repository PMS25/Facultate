#include <iostream>
using namespace std;
//Generarea submultimilor unei multimi standard.
//Backtracking

void CitireDate(int &m){
    cout<<"Dati cardinalul multimii: "; cin>>m;
}

void PrelSol(int *c, int n){
    for(int i=1; i<=n; i++)
        if(c[i]==1)
            cout<<i<<" ";
    cout<<endl;
}

inline bool Valid(int k){ return true; }

void Back(int n, int min, int max, int pas, int fi){
    int *c = new int[n+1], k;
	for(k=1; k<=n; k++) c[k]=fi;
	k=1;
	while(k>0)
		if(k==n+1){
			PrelSol(c,n);
			k--;
		}else
			if(c[k]<max){
				c[k]+=pas;
				if(Valid(k))
					k++;
			}else
				c[k--]=fi;
    delete[] c;
}

int main(){
    int m;
    CitireDate(m);
    Back(m,1,2,1,0);
}