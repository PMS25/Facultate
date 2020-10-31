#include <iostream>
using namespace std;
//Intr-o tabara, baietii sunt cazati cate 4 intr-o casuta, in ordinea sosirii. Ionel a sosit al n-lea.
//Stabiliti in a cata casuta se va afla Ionel?
//EX: n = 61 => 16. 
int NrCabana(int n, int x){ return n/x + (n%x!=0? 1:0); }

int main(){
    int n; cout<<"Dati numarul sosirii lui Ionel: "; cin>>n;
    int x; cout<<"Dati numarul de copii in cabana: "; cin>>x;
    cout<<"Cabana: "<<NrCabana(n,x)<<endl;
}