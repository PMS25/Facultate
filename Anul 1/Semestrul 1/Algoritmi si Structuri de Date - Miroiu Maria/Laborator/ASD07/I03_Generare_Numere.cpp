#include <iostream>
using namespace std;
//Afisati toate numerele dintre 100 si 599 ce au cifrele in ordine crescatoare si suma cifrelor 18.
//Solutie: 189, ..., 567.

bool CifreCrescatoare(int n){
    int u = n%10;
    while(n/=10)
        if(n%10>u)
            return false;
        else
            u = n%10;
    return true;
}

int SumaCifre(int n){
    int s=n%10;
    while(n/=10)
        s+=n%10;
    return s;
}

int main(){
    cout<<"Solutie: ";
    for(int i=100; i<600; i++)
        if(SumaCifre(i)==18 && CifreCrescatoare(i))
            cout<<i<<" ";
}