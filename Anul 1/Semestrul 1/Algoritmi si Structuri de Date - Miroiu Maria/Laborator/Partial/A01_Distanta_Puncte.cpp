#include <iostream>
#include <cmath>
using namespace std;
//Sa se descrie un algoritm pentru determinarea distantei dintre doua puncte din plan
//d = sqrt( (a.x-b.x)^2 + (a.y-b.y)^2 )
//EX: pentru a=(1,6) si b=(4,2) => d=5

struct punct{ float x,y; };

float DistantaPuncte(punct a, punct b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
    punct a; cout<<"Dati primul punct: "; cin>>a.x>>a.y;
    punct b; cout<<"Dati al doilea punct: "; cin>>b.x>>b.y;
    cout<<"Distanta: "<<DistantaPuncte(a,b)<<endl;
}