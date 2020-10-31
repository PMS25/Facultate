#include <iostream>
using namespace std;
//Se dau trei numere x, y, z. Sa se descrie un algoritm pentru a scadea z din cel mai mare dintre x si y. 

int main(){
    int x,y,z; cout<<"Dati numerele: "; cin>>x>>y>>z;
    cout<<"Maximul minus al treilea: "<<max(x,y)-z<<endl;
}