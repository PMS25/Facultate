#include <iostream>
using namespace std;
//Ciurul lui Eratostene (folosind vectori)
int *C, n;

void GenerareCiur(){
    C[0] = 1;
    C[1] = 1;
    for(int i=4; i<=n; i+=2)
        C[i] = 1;
    for(int i=3; i<=n; i+=2)
        if(C[i]==0)
            for(int j=i*3; j<=n; j+=i)
                C[j] = 1;
}

void AfisareCiur(){
    cout<<"Sirul lui Eratostene 0-"<<n<<": ";
    for(int i=0; i<n; i++)
        cout<<!C[i]<<" ";
    cout<<endl;
}

void AfisarePrime(){
    cout<<"Numere prime: ";
    for(int i=0; i<n; i++)
        if(!C[i])
            cout<<i<<" ";
    cout<<endl;
}

int main(){
    cout<<"Dati pragul pana la care se genereaza sirul: "; cin>>n;
    C = new int[n+1];
    GenerareCiur();
    AfisareCiur();
    AfisarePrime();
    delete[] C;
}