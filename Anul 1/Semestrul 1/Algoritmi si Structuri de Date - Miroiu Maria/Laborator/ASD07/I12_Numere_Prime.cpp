#include <iostream>
using namespace std;
//Determinati cate numere prime sunt mai mici sau egale decat n.
//EX: pentru n=6 sunt 3 numere prime (2, 3 şi 5).

bool EPrim(int x){
    if(x<=1)
        return false;
    if(x==2)
        return true;
    if(x%2==0)
        return false;
    for(int i=3; i*i<x; i+=2)
        if(x%i==0)
            return false;
    return true;
}

int NrPrimeMaiMiciCaN(int n){
    int k=0;
    if(2<=n)
        k++;
    for(int i=3; i<=n; i+=2)
        k+=(EPrim(i) ? 1:0);
    return k;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Numarul nr prime mai mici ca "<<n<<": "<<NrPrimeMaiMiciCaN(n)<<endl;
}