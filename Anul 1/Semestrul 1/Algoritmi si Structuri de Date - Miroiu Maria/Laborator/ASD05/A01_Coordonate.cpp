#include <iostream>
#include <cmath>
using namespace std;
//Determinati distanta dintre doua puncte de pe Pamant, date prin coordonatele geografice exprimate in grade zecimale.
//Latitudine [-90, 90] – la 00 este Ecuatorul si Longitudine [-180, 180])
//EX: coordonatele Universitatii din Pitesti sunt (44.854735, 24.881994),
//    coordonatele Universitatii Bucuresti sunt (44.435695,  26.101216).
//    Rezultat: 118km
//Se va folosi algoritmul lui Haversine.

struct coordonata{ double lat,lng; };

double Delta(double lat1, double lat2){ return (lat1 - lat2)*M_PI/180; }

double Distanta(coordonata c1, coordonata c2){
    const int R = 6371;
    double D_lat = Delta(c1.lat,c2.lat), D_long = Delta(c1.lng,c2.lng);
    double A = pow(sin(D_lat/2),2) + cos(c1.lat) * cos(c1.lng) * pow(sin(D_long/2),2);
    double C = 2 * tan(sqrt(A)/sqrt(1-A));
    return R*C;
}

void Citire(coordonata &c1, coordonata &c2){
    cout<<"Dati prima coordonata (lat/long): "; cin>>c1.lat>>c1.lng;
    cout<<"Dati a doua coordonata (lat/long): "; cin>>c2.lat>>c2.lng;
}

int main(){
    coordonata c1, c2;
    Citire(c1,c2);
    cout<<"Distanta: "<<Distanta(c1,c2)<<" km"<<endl;
}