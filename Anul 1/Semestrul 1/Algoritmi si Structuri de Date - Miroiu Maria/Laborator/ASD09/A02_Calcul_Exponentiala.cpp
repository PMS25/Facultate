#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double Exponentiala(int n, double E){
    double result = 1, old, x=1, k=1;
    while(abs(result-old) > E){
        x*=n;
        x/=k++;
        old = result;
        result = result + x;
    }
    return result;
}

int main(){
    double E; cout<<"Dati precizia (Epsilon) (subunitar): "; cin>>E;
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Exponentiala: "<<setprecision(15)<<Exponentiala(n,E)<<endl;
}