#include <iostream>
#include <cmath>
using namespace std;
//Convertor grade <-> radiani
//Formula: grade/180 = radiani/PI
//EX: x=0(grade) => x=0(radiani) ; x=180(grade) => x=3.14(radiani)

float Grade2Radiani(float x){ return x/180*M_PI; }
float Radiani2Grade(float x){ return x/M_PI*180; }

int main(){
    float x; cout<<"Dati valoarea: "; cin>>x;
    cout<<"Radiani -> Grade : "<<Radiani2Grade(x)<<endl;
    cout<<"Grade -> Radiani : "<<Grade2Radiani(x)<<endl;
}