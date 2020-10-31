#include <iostream>
using namespace std;
//Pentru un n naturat dat sa se determine cel mai apropiat numar prim de n.
//Dacă doua numere sunt la distanta egala de n, se vor afisa ambele numere prime.

bool EPrim(int n){
    if(n<=1)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    for(int d=3; d*d<=n; d+=2)
        if(n%d==0)
            return false;
    return true;
}

void CautarePrim(int n){
    int s=n, d=n;
    while(EPrim(s)==0)
        s--;
    while(EPrim(d)==0)
        d++;
    if(d-n < n-s)
        cout<<"Numar prim: "<<d<<endl;
    else
        if(d-n > n-s)
            cout<<"Numar prim: "<<s<<endl;
        else
            cout<<"Numare prime: "<<s<<" si "<<d<<endl;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    CautarePrim(n);
}