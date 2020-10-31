#include <iostream>
using namespace std;
//Descrieti un algoritm prin care sa stabiliti daca un numar dat este palindrom.
//EX: 237732 e palindrom ; 65756 e palindrom ; 123 nu e palindrom

int Invers(int n){
    int in=n%10;
    while(n/=10)
        in=in*10+n%10;
    return in;
}

bool EPalindrom(int n){
    return n == Invers(n);
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Numarul "<<(EPalindrom(n) ? "":"nu ")<<"e palindrom."<<endl;

}