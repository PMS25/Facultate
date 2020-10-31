#include <iostream>
using namespace std;
//In cate zerouri se termina un numar natural dat?
//Exemplu: n = 617300 are 2 zerouri la final, iar n = 6151 are 0 zerouri la final.

int NrZeroFinal(int n){
    int k=0;
    while(n%10==0){
        k++;
        n/=10;
    }
    return k;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    cout<<"Numar zerouri final: "<<NrZeroFinal(n)<<endl;
}