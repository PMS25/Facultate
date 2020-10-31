#include <iostream>
using namespace std;
//Sa se exprime o suma de bani citita de la tastatura in numar minim de bancnote in valoarea de 1,5,10,50,100,200,500 lei.
//EX: 932 lei = 1 bancnota de 500 lei + 2 bancnote de 200 lei + 3 bancnote de 10 lei +  2 bancnote de 1 leu

int bancnote[7] = {1,5,10,50,100,200,500};

void Afisare(int n){
    cout<<n<<" lei = ";
    for(int i=6; i>=0; i--){
        int s = n/bancnote[i];
        n%=bancnote[i];
        if(s){
            cout<<s<<(s==1 ? " bancnota":" bancnote")<<" de ";
            cout<<bancnote[i]<<(i==0?"leu":"lei")<<" + ";
        }
    }
    cout<<"\b\b \n";
}

int main(){
    int n; cout<<"Dati valoarea: "; cin>>n;
    Afisare(n);
}