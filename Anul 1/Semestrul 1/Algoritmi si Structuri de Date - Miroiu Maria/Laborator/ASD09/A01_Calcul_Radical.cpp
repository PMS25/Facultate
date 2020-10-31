#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double Radical(int n, double E){
    double result = 1, old=0;
    while(abs(result-old) > E){
        old = result;
        result = (result + n/result) /2;
    }
    return result;
}

int main(){
    double E; cout<<"Dati precizia (Epsilon) (subunitar): "; cin>>E;
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Radical: "<<setprecision(15)<<Radical(n,E)<<endl;
}