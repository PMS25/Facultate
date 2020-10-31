#include <iostream>
using namespace std;
//Generarea aranjamentelor cu repetitie pentru multimi standard.
//Backtracking

void CitireDate(int &m, int &n){
    cout<<"Dati cardinalul multimii: "; cin>>m;
    cout<<"Dati lungimea aranjamentelor: "; cin>>n;
}

void PrelSol(int *c, int n){
    for(int i=1; i<=n; i++)
        cout<<c[i]<<" ";
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
    int m,n;
    CitireDate(m,n);
    Back(n,1,m,1,0);
}