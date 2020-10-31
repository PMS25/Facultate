#include <iostream>
using namespace std;
#define NMAX 50

// --- Inserare ---
void Inserare(int x[], int &n, int a, int k){
    if(n==NMAX)
        cout<<"Spatiu indisponibil."<<endl;
    else if(k<0 || k>n)
        cout<<"Pozitie indisponibila."<<endl;
    else{
        for(int i=++n; i>k; i--)
            x[i] = x[i-1];
        x[k] = a;
    }
}

void InserareInceput(int x[], int &n, int a){
    Inserare(x,n,a,0);
}

void InserareSfarsit(int x[], int &n, int a){
    Inserare(x,n,a,n);
}

// --- Stergere ---
void Stergere(int x[], int &n, int k){
    if(n==0)
        cout<<"Lista visa."<<endl;
    else if(k<0 || k>n)
        cout<<"Pozitie indisponibila."<<endl;
    else{
        for(int i=k+1; i<n; i++)
            x[i-1] = x[i];
        n--;
    }
}

void StergereInceput(int x[], int &n){
    Stergere(x,n,0);
}

void StergereSfarsit(int x[], int &n){
    Stergere(x,n,n);
}

// --- Extragere ---
int Extragere(int x[], int n, int k){
    if(k<0 || k>n){
        cout<<"Pozitie indisponibila."<<endl;
        return 0;
    }else{
        int a = x[k];
        Stergere(x,n,k);
        return a;
    }
}

// --- Afisare ---
void Afisare(int x[], int n){
    for(int i=0; i<n; i++)
        cout<<x[i]<<" ";
    cout<<endl;
}

// --- Meniu ---
int CitireElement(){
    int a; cout<<"Dati elementul: "; cin>>a; return a;
}

int CitirePozitie(){
    int k; cout<<"Dati pozitia: "; cin>>k; return k;
}

int Options(){
    cout<<"Optiuni:"<<endl;
    cout<<"1. Adauga element la inceputul listei."<<endl;
    cout<<"2. Adauga element la finalul listei."<<endl;
    cout<<"3. Adauga element pe o pozitie data din lista."<<endl;
    cout<<"4. Elimina element de la inceputul listei."<<endl;
    cout<<"5. Elimina element de la finalul listei."<<endl;
    cout<<"6. Elimina element de pe o pozitie data din lista."<<endl;
    cout<<"7. Extragere element de pe o pozitie data din lista."<<endl;
    cout<<"8. Afisare lista."<<endl;
    cout<<"0. Iesire."<<endl<<endl;
    int opt; cout<<"Dati optiunea: "; cin>>opt;
    cout<<endl;
    return opt;
}

void Menu(int x[], int &n){
    int opt;
    do{
        opt = Options();
        switch (opt){
            case 0: break;
            case 1: InserareInceput(x,n,CitireElement()); break;
            case 2: InserareSfarsit(x,n,CitireElement()); break;
            case 3: Inserare(x,n,CitireElement(),CitirePozitie()); break;
            case 4: StergereInceput(x,n); break;
            case 5: StergereSfarsit(x,n); break;
            case 6: Stergere(x,n,CitirePozitie()); break;
            case 7: cout<<Extragere(x,n,CitirePozitie())<<endl; break;
            case 8: Afisare(x,n); break;
        }
    }while(opt != 0);
}

int main(){
    int x[NMAX], N=0;
    Menu(x,N);
}