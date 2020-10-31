#include <iostream>
using namespace std;
//Sa se descrie un algoritm pentru a calcula reuniunea a doua intervale deschise.
//EX: (1,2) si (3,4) => (1,2) U (3,4) ; (1,4) si (2,5) => (1,5) ; (1,4) si (2,3) => (1,4)

struct interval{ int a,b; };
bool SeIntersecteaza(interval p, interval q){ return p.b>q.a; }

int main(){
    interval p; cout<<"Dati primul interval: "; cin>>p.a>>p.b;
    interval q; cout<<"Dati al doilea interval: "; cin>>q.a>>q.b;
    if(SeIntersecteaza(p,q))
        cout<<"Reuniune: "<<"("<<p.a<<","<<q.b<<")"<<endl;
    else
        cout<<"Reuniune: "<<"("<<p.a<<","<<p.b<<") U ("<<q.a<<","<<q.b<<")"<<endl;
}