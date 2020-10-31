#include <iostream>
using namespace std;
#define NMAX 50

// --- Initializare ---
void Initializare(int x[], int &v){
    v = 0;
}

// --- Inserare ---
void Inserare(int x[], int &v, int a){
    if(v < NMAX)
        x[v++] = a;
    else cout<<"Spatiu indisponibil."<<endl;
}

// --- Stergere ---
void Stergere(int x[], int &v){
    if(v > 0)
        v--;
    else cout<<"Stiva vida."<<endl;
}

// --- Extragere ---
int Extrage(int x[], int &v){
    if(v > 0){
        int a = x[v-1];
        Stergere(x,v);
        return a;
    }else{
        cout<<"Stiva vida."<<endl;
        return 0;
    }
}

// --- Afisare ---
void Afisare(int x[], int v){
    for(int i=v-1; i>=0; i--)
        cout<<x[i]<<" ";
    cout<<endl;
}

// --- Meniu ---
int CitireElement(){
    int a; cout<<"Dati elementul: "; cin>>a; return a;
}

int Options(){
    cout<<endl;
    cout<<"Optiuni:"<<endl;
    cout<<"1. Adauga element."<<endl;
    cout<<"2. Elimina element."<<endl;
    cout<<"3. Extragere element."<<endl;
    cout<<"4. Afisare stiva."<<endl;
    cout<<"0. Iesire."<<endl;
    int opt; cout<<endl<<"Dati optiunea: "; cin>>opt;
    cout<<endl;
    return opt;
}

void Menu(int x[], int &v){
    int opt;
    do{
        opt = Options();
        switch (opt){
            case 0: break;
            case 1: Inserare(x,v,CitireElement()); break;
            case 2: Stergere(x,v); break;
            case 3: cout<<Extrage(x,v)<<endl; break;
            case 4: Afisare(x,v); break;
        }
    }while(opt != 0);
}

int main(){
    int x[NMAX], V;
    Menu(x,V);
}