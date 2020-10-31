#include <iostream>
using namespace std;
//La un concurs se dau ca premii primilor 100 de concurenti, tricouri de culoare alba, rosie, albastra si neagra (25 de fiecare culoare).
//Sa se descrie un algoritm prin care sa se stabileasca ce culoare va avea tricoul pe care-l va primi?
//EX: x=38 => “tricou roşu”

string Optiune(int x){
    if(x<=25) return "Tricou alb.";
    if(x<=50) return "Tricou rosu.";
    if(x<=75) return "Tricou albastru.";
    if(x<=100) return "Tricou negru.";
    return "Nimic. Mult noroc data viitoare.";
}

int main(){
    int x; cout<<"Dati pozitia: "; cin>>x;
    cout<<Optiune(x)<<endl;
}