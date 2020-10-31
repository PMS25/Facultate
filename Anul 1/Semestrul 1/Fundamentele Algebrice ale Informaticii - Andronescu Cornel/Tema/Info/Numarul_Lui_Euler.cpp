#include <iostream>
using namespace std;

bool EPrim(int n){
    if(n==0 || n==1)
        return false;
    if(n%2==0 && n!=2)
        return false;
    for(int d=3; d*d<=n; d+=2)
        if(n%d==0)
            return false;
    return true;
}

int Euler(int n){
    int aux;
    float p = n;
    while(n%2==0) n/=2;
    p *= (n==p ? 1:1/2.0);
    for(int d=3; d<=n; d+=2)
        if(EPrim(d)){
            aux = n;
            while(n%d==0)
                n/=d;
            if(aux!=n)
                p *= 1-1.0/d;
        }
    return p;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Indicatorul lui Euler: "<<Euler(n)<<endl;
}