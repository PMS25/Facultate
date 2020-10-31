#include <iostream>
using namespace std;
//Ionel spune parintilor doar notele mai mari sau egale cu 7. Intr-o zi el a luat 3 note.
//Cititi-le de la tastatura si afisati acele note pe care le va comuniva si parintilor
//EX: 8, 7, 5 => 8, 7

void Citire(int *&v, int &n, int &k){
    cout<<"Dati numarul de note: "; cin>>n;
    cout<<"Dati notele: ";
    v = new int[n];
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<<"Dati pragul notelor: "; cin>>k;
}

void Afisare(int *v, int n, int k){
    cout<<"Note optime: ";
    for(int i=0; i<n; i++)
        if(v[i]>=k)
            cout<<v[i]<<" ";
    cout<<endl;
}

int main(){
    int *v, n, k;
    Citire(v,n,k);
    Afisare(v,n,k);
    delete[] v;
}