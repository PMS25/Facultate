#include <iostream>
using namespace std;
//Descrieti un algoritm recursiv pentru determinarea numarului lui Fibonacci de ordin n.

int Fibonacci(int n){
    if(n==0 || n==1)
        return 1;
    return Fibonacci(n-2)+Fibonacci(n-1);
}

int main(){
    int n; cout<<"Dati ordinul: "; cin>>n;
    cout<<"Fibonacci: "<<Fibonacci(n)<<endl;
}