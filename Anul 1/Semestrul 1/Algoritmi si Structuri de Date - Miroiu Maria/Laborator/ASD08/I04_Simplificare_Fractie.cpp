#include <iostream>
using namespace std;
//Aducerea unei fractii la forma ireductibila (simplificarea fractiei).

int Cmmdc(int a, int b){
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main(){
    int a,b; cout<<"Dati fractia: "; cin>>a>>b;
    cout<<"SImplificare: "<<a/Cmmdc(a,b)<<"/"<<b/Cmmdc(a,b)<<endl;
}