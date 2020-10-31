#include <iostream>
using namespace std;
//Un lift pentru copii accepta o greutate de maxim 100kg.
//Citind de la tastatura greutatile a doi copii, determinati daca ”pot intra ambii copii” sau “pot intra pe rând”.
//EX: 87 50 => intra pe rand ; 45 52 => pot intra ambii copii

int main(){
    float l; cout<<"Dati capacitate lift: "; cin>>l;
    float c1,c2; cout<<"Dati greutate copii: "; cin>>c1>>c2;
    if(l-c1-c2>0)
        cout<<"Copii pot intra impreuna."<<endl;
    else
        cout<<"Copii pot intra pe rand."<<endl;
}