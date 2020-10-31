#include <iostream>
using namespace std;
//Generare patrate perfecte mai mici ca un n dat.

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Patrate perfecte: ";
    for(int i=1; i*i<=n; i++)
        cout<<i*i<<", ";
    cout<<"\b\b."<<endl;
}