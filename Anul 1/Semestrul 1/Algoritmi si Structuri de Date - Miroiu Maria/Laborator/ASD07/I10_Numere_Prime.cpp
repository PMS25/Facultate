#include <iostream>
using namespace std;
//Determinati toate numerele prime de 3 cifre, care citite invers sunt tot numere prime.

bool EPrim(int x){
    if(x<=1)
        return false;
    if(x==2)
        return true;
    if(x%2==0)
        return false;
    for(int i=3; i*i<x; i+=2)
        if(x%i==0)
            return false;
    return true;
}

int Invers(int x){
    int nr = x%10;
    while(x/=10)
        nr=nr*10+x%10;
    return nr;
}

int main(){
    cout<<"Numere prime: ";
    for(int i=100; i<=999; i++)
        if(EPrim(i) && EPrim(Invers(i)))
            cout<<i<<" ";
    cout<<endl;
}