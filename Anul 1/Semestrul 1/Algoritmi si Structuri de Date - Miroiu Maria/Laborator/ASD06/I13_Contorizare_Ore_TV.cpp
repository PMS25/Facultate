#include <iostream>
using namespace std;
//Ionel are voie sa se uite la TV 20 de ore pe saptamana.
//Se introduc numarul de ore cand el se uita la TV pe fiecare zi din saptamana. Sa se verifice dacă va fi pedepsit sau nu.
//EX: 3 4 2 2 5 6 1 => va fi pedepsit.

int SumaVector(int a[], int n){
    int s=a[0];
    for(int i=1; i<n; i++) s+=a[i];
    return s;
}

int main(){
    int a[7]; cout<<"Dati ore pe saptamana: ";
    for(int i=0; i<7; i++)
        cin>>a[i];
    if(SumaVector(a,7)>20)
        cout<<"Trebuie pedepsit."<<endl;
    else
        cout<<"A scapat saptamana asta."<<endl;
}