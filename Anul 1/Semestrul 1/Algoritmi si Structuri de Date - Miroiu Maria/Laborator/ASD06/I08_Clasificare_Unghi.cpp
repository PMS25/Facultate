#include <iostream>
using namespace std;
//Clasificati un unghi dat (in grade) ca obtuz(>90), ascutit(<90) sau drept.
//EX: x=30 => unghi ascutit ; x=120 => unghi obtuz

string TipUnghi(float x){
    if(x==90) return "drept";
    else if(x<90) return "ascutit";
    else return "obtuz";
}

int main(){
    float x; cout<<"Dati unghiul: "; cin>>x;
    cout<<"Tip unghi: "<<TipUnghi(x)<<endl;
}