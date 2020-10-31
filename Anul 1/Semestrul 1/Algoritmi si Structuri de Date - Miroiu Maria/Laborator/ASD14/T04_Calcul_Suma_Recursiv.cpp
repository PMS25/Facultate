#include <iostream>
using namespace std;
// Determinati o functie recursiva pentru calculul sumei Sn = 1 + 3 + 5 + ...+ (2n-1), n>=1.

int Suma(int n){
    if(n==0)
        return 0;
    else
        return Suma(n-1) + 2*n-1;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Suma: "<<Suma(n)<<endl;
}