#include <iostream>
#include <cmath>
using namespace std;
//Determinati daca un numar natural este patrat perfect sau nu.
bool EPPerfect(int x){ return sqrt(x)*sqrt(x)==x; }

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Numarul "<<n<<(EPPerfect(n)? "":" nu ")<<" este patrat perfect."<<endl;
}