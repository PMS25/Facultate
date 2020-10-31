#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int A[20], B[20], X[20], nA, nB;
ofstream g;

// Afisare Date
void Afisare(bool monotonie, bool consola){
    if(consola)
        cout<<"Functii strict "<<(monotonie ? "":"des")<<"crescatoare"<<endl;
    else{
        g.open("output.txt");
        g<<"Functii strict "<<(monotonie ? "":"des")<<"crescatoare"<<endl;
    }
}

void PrelSol(bool consola){
    if(consola){
        for(int i=1; i<=nA; i++)
            cout<<setw(2)<<A[i]<<" ";
        cout<<endl;
        for(int i=1; i<=nA; i++)
            cout<<setw(2)<<B[X[i]]<<" ";
        cout<<endl;
        for(int i=1; i<=nA; i++)
            cout<<"===";
        cout<<endl;
    }else{
        for(int i=1; i<=nA; i++)
            g<<setw(2)<<A[i]<<" ";
        g<<endl;
        for(int i=1; i<=nA; i++)
            g<<setw(2)<<B[X[i]]<<" ";
        g<<endl;
        for(int i=1; i<=nA; i++)
            g<<"===";
        g<<endl;
    }
}

// Validare
bool Valid(int k, bool monotonie){
    if(monotonie)
        return X[k-1]<X[k];
    else{
        if(k==1)
            return true;
        return X[k-1]>X[k];
    }
}

// Backtracking
void Back(int n, int min, int max, int pas, int fi, bool monotonie, bool afisare){
    int k;
    for(k=1; k<=n; k++)
        X[k] = fi;
    k = 1;
    while(k>0)
        if(k==n+1){
            PrelSol(afisare);
            k--;
        }else
            if(X[k] <= max - pas){
                X[k] += pas;
                if(Valid(k, monotonie))
                    k++;
            }else{
                X[k] = fi;
                k--;
            }
}

// Citire Date
void CitireDateFisier(bool generare){
    ifstream f("input.txt");
    if(generare){
        f>>nA>>nB;
        for(int i=1; i<=nA; i++)
            A[i]=B[i]=i;
        for(int i=nA+1; i<=nB; i++)
            B[i]=i;
    }else{
        f>>nA; for(int i=1; i<=nA; i++) f>>A[i];
        f>>nB; for(int i=1; i<=nB; i++) f>>B[i];
    }
}

void CitireDateConsola(bool generare){
    if(generare){
        cout<<"Dati cardinalul lui A: "; cin>>nA;
        cout<<"Dati cardinalul lui B: "; cin>>nB;
        for(int i=1; i<=nA; i++)
            A[i]=B[i]=i;
        for(int i=nA+1; i<=nB; i++)
            B[i]=i;
    }else{
        cout<<"Dati cardinalul lui A si elementele multimii: "; cin>>nA;
        for(int i=1; i<=nA; i++) cin>>A[i];
        cout<<"Dati cardinalul lui B si elementele multimii: "; cin>>nB;
        for(int i=1; i<=nB; i++) cin>>B[i];
    }
}

void ChangeOption(char &o, char def, char alt){
    string input, aux;
    getline(cin,input);
    if(!input.empty()){
        istringstream stream(input);
        stream>>aux;
    }
    o = (tolower(aux[0]) == alt ? alt:def);
}

void Citire(bool &crescator, bool &afisare){
    char citire, scriere, tip, elemente;
    cout<<"Sursa citire consola/fisier (c/f --default c): "; ChangeOption(citire,'c','f');
    cout<<"Sursa afisare consola/fisier (c/f --default c): "; ChangeOption(scriere,'c','f');
    cout<<"Tip functie crescatoare/descrescatoare (c/d --default c): "; ChangeOption(tip,'c','d');
    cout<<"Se dau elementele sirurilor yes/no (y/n --default n): "; ChangeOption(elemente,'n','y');
    if(citire=='c')
        CitireDateConsola(elemente=='n');
    else
        CitireDateFisier(elemente=='n');
    crescator = (tip == 'c');
    afisare = (scriere == 'c');
}

int main(){
    bool monotonie, afisare;
    Citire(monotonie, afisare);
    Afisare(monotonie, afisare);
    Back(nA,1,nB,1,0, monotonie, afisare);
}