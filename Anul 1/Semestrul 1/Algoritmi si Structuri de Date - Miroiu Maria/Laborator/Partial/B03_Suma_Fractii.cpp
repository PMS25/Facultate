#include <iostream>
using namespace std;
//Sa se descrie un algoritm pentru a aduna doua fractii si aducerea rezultatului forma ireductibila.
//EX: 1/6 + 2/15 = 3/10

struct fractie{ int a,b; };

int Cmmdc(int a, int b){
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int Cmmmc(int a, int b){
    return a*b/Cmmdc(a,b);
}

void SumaFractii(fractie x, fractie y, fractie &z){
    int m = Cmmmc(x.b,y.b);
    z.a = x.a * m/x.b + y.a + m/y.b;
    z.b = m;
    int d = Cmmdc(z.a,z.b);
    z.a = z.a/d;
    z.b = z.b/d;
}

int main(){
    fractie x; cout<<"Dati prima fractie: "; cin>>x.a>>x.b;
    fractie y; cout<<"Dati a doua fractie: "; cin>>y.a>>y.b;
    fractie z; SumaFractii(x,y,z);
    cout<<"Suma fractii: "<<z.a<<" "<<z.b<<endl;
}