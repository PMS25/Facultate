#include <iostream>
#include <cstring>
using namespace std;
//"Ma iubeste un pic, mult, cu pasiune, la nebunie, deloc, un pic, ...".
//Rupand petalele unei margarete cu x petale, sa se determine ce urmeaza la “el(ea) ma iubeste”.
//EX: x = 10 => el(ea) ma iubeste deloc. 

string optiuni[5] ={"un pic","mult","cu pasiune","la nebunie","deloc"};
string Optiune(int n){ return optiuni[(n-1)%5]; }

int main(){
    int n; cout<<"Dati numarul de petale: "; cin>>n;
    cout<<"El(Ea) ma iubeste "<<Optiune(n)<<endl;
}