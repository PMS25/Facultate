#include <iostream>
using namespace std;
//Incadrare numar intre 2 numere consecutive ale lui Fibonacci

void Fibonacci(int &a, int &b, int n){
    int c = a+b;
    while(c<=n){
        a=b;
        b=c;
        c=a+b;
    }
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    int a = 0, b = 1;
    Fibonacci(a,b,n);
    cout<<"Numarul "<<n<<" apartine intervalului ["<<b<<","<<a+b<<"]"<<endl;
}