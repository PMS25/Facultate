#include <iostream>
using namespace std;
//Descrieti un algoritm ce stabileste daca un numar intreg n≥1 dat este deficient sau abundent.
//deficitar <=> suma divizorilor proprii+1 < n ; abundent <=> suma divizorilor proprii + 1 > n
//EX: n=12 este abundent (1+2+3+4+6=16>12), n=14 este deficient (1+2+7<14)
//perfect <=> n = suma divizorilor proprii + 1

int SumaDivizoriProprii(int n){
    int s=0;
    for(int i=2; i<=n/2; i++)
        s+=(n%i==0 ? i:0);
    return s;
}

int main(){
    int n; cout<<"Dati numarul: "; cin>>n;
    int s = SumaDivizoriProprii(n)+1;
    cout<<"Numarul "<<n<<" este "<<(s<n ? "deficitar":(s>n ? "abundent":"perfect"))<<endl;
}