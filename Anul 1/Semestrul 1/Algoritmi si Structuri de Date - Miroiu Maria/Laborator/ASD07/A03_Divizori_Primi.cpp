#include <iostream>
using namespace std;
//Determinare divizori primi ai unui numar natural dat.

bool EPrim(int n){
    if(n==0 || n==1)
        return false;
    for(int d=2; d*d<=n; (d==2 ? d++: d+=2))
        if(n%d==0)
            return false;
    return true;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Solutie: ";
    for(int d=2; d<=n; (d==2 ? d++: d+=2))
        if(EPrim(d) && n%d == 0){
            cout<<d<<" ";
            while(n%d==0)
                n/=d;
        }
    cout<<endl;
}