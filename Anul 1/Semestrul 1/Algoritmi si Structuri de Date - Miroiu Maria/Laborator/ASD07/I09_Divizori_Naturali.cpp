#include <iostream>
using namespace std;
//Sa se descrie un algoritm pentru a afisa divizorii primi ai unui numar natural dat.

void DivizoriPrimi(int n){
    cout<<"Divizorii primi: ";
    for(int i=2; i<=n/2; i++)
        if(n%i==0)
            cout<<i<<" ";
    cout<<endl;
}


int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    DivizoriPrimi(n);
}