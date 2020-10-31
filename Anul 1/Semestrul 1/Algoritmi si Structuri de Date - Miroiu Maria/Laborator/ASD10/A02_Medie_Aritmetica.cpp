#include <iostream>
using namespace std;
//La un concurs de patinaj artistic se cunosc cele n note obtinte de un concurent.
//Sa se calculeze medie aritmetica, stiind ca nu se iau in considerare nota cea mai mica si cea mai mare.

int MinimV(int V[], int n){
    int minim = V[0];
    for(int i=1; i<n; i++)
        minim = (V[i]<minim ? V[i]:minim);
    return minim;
}

int MaximV(int V[], int n){
    int maxim = V[0];
    for(int i=1; i<n; i++)
        maxim = (V[i]>maxim ? V[i]:maxim);
    return maxim;
}

float MedieNote(int V[], int n){
    float s = V[0];
    for(int i=1; i<n; i++) s+=V[i];
    if(n>2)
        return (s-MinimV(V,n)-MaximV(V,n))/(n-2);
    else
        return 0;
}

void CitireDate(int *&V, int &n){
    cout<<"Dati numarul notelor: "; cin>>n;
    V = new int[n];
    cout<<"Dati notele: ";
    for(int i=0; i<n; i++) cin>>V[i];
}

int main(){
    int *V, n;
    CitireDate(V,n);
    cout<<"Media notelor: "<<MedieNote(V,n)<<endl;
    delete[] V;
}
