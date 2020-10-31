#include <iostream>
using namespace std;
//Descrieti un algoritm pentru determinarea sumei cifrelor pare si produsul cifrelor impare ale unui numar natural.
//Daca nu exista cifre pare se va afisa 0, iar daca nu exista cifre impare se va afisa 1

int SumaCifre(int n, bool paritate){
    int s=((n%10)%2==paritate ? n%10:0);
    while(n/=10)
        s+=((n%10)%2==paritate ? n%10:0);
    return s;
}

int ProdusCifre(int n, bool paritate){
    int p=((n%10)%2==paritate ? n%10:1);
    while(n/=10)
        p*=((n%10)%2==paritate ? n%10:1);
    return p;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    int s = SumaCifre(n,0), p = ProdusCifre(n,1);
    cout<<"Suma cifre pare: "<<s<<endl;
    cout<<"Produs cifre impare: "<<p<<endl;
}