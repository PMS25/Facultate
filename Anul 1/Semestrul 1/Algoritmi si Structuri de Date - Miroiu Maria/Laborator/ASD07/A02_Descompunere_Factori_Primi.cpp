#include <iostream>
using namespace std;
//Descompunere numar in factori primi

int main(){
    int n, p; cout<<"Dati numarul: "; cin>>n;
    cout<<"Solutie: ";
    for(int d=2; d<=n; (d==2 ? d++: d+=2)){
        p=0;
        while(n%d == 0){
            n/=d;
            p++;
        }
        if(p) cout<<d<<"^"<<p<<" * ";
    }
    cout<<"\b\b\b  \n";
}