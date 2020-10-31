#include <iostream>
#include <sstream>
#include <string>
using namespace std;

double Calculate(long k, int n){
    double d = 1;
    k++;
    while(--k)
        d*=n;
    return d;
}

void Result(string opt, int n){
    long k = n*n;
    if(opt[0] == 'b')
        k = (n*n+n)/2;
    else if(opt[0] == 'c')
        k = n*n - 2*n + 2;
    else if(opt[0] == 'd')
        k = (n*n - n + 2)/2;
    cout<<"Rezultat: "<<Calculate(k,n)<<endl;
}

void Start(){
    cout<<"Afisare numarul: "<<endl;
    cout<<"a) Legilor de compozitie"<<endl;
    cout<<"b) Legilor de compozitie comutative"<<endl;
    cout<<"c) Legilor de compozitie cu element neutru"<<endl;
    cout<<"d) Legilor de compozitie comutative si cu element neutru"<<endl;
    cout<<"Dati optiune (--default a): ";
    string opt, aux; getline(cin,opt);
    istringstream stream(opt); stream>>aux;
    if(tolower(aux[0])=='b' || tolower(aux[0])=='c' || tolower(aux[0])=='d')
        opt = aux;
    else
        opt= "a";
    int n; cout<<"Dati n: "; cin>>n;
    Result(opt,n);
}

int main(){
    Start();
}