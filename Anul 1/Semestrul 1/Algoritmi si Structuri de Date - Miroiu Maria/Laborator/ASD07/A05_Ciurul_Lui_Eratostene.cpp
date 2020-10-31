#include <iostream>
using namespace std;
//Determinare Ciurul lui Eratostene

bool V[32000];

void Afisare(int n, int p){
    cout<<"Pasul "<<p<<":"<<endl;
    for(int i=0; i<=n; i++)
        if(!V[i])
            cout<<i<<" ";
    cout<<endl;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    V[0] = true; V[1]=true;
    for(int d=2; d*d<=n; (d==2 ? d++:d+=2)){
        if(!V[d]){
            for(int q=2*d; q<=n; q+=d)
                V[q]=true;
            Afisare(n, d);
        }
    }
}