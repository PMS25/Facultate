#include <iostream>
#include <string.h>
using namespace std;
//Sa se inlocuiasca literele cu cifre in scaderea urmatoare:
//a b c b e –
//  e d a b
//----------
//  e b c e

int X[20], nr;
char a[20], b[20], c[20];

void GenerareNumere(int &na, int &nb, int &nc){
    for(int i=0; i<strlen(a); i++)
        na=na*10 + X[a[i]-'a'+1];
    for(int i=0; i<strlen(b); i++)
        nb=nb*10 + X[b[i]-'a'+1];
    for(int i=0; i<strlen(c); i++)
        nc=nc*10 + X[c[i]-'a'+1];
}

void Afisare(){
    for(int i=0; i<nr; i++)
        cout<<char(i+'a')<<" ";
    cout<<endl;
    for(int i=1; i<=nr; i++)
        cout<<X[i]<<" ";
    cout<<endl;
    for(int i=0; i<nr; i++)
        cout<<"==";
    cout<<endl;
}

void PrelSol(){
    int na=0, nb=0, nc=0;
    GenerareNumere(na,nb,nc);
    if(na-nb==nc)
        Afisare();
}

bool Valid(int k){
    if(X[a[0]-'a'+1]==0 || X[b[0]-'a'+1]==0 || X[c[0]-'a'+1]==0)
        return false;
    return true;
}

// Backtracking
void Back(int n, int min, int max, int pas, int fi){
    int k;
    for(k=1; k<=n; k++)
        X[k] = fi;
    k = 1;
    while(k>0)
        if(k==n+1){
            PrelSol();
            k--;
        }else
            if(X[k] <= max - pas){
                X[k] += pas;
                if(Valid(k))
                    k++;
            }else{
                X[k] = fi;
                k--;
            }
}

int NrVariabile(char a[], char b[], char c[]){
    char k = 'a';
    for(int i=0; i<strlen(a); i++)
        k = (a[i]>k ? a[i]:k);
    for(int i=0; i<strlen(b); i++)
        k = (b[i]>k ? b[i]:k);
    for(int i=0; i<strlen(c); i++)
        k = (c[i]>k ? c[i]:k);
    return k-'a'+1;
}

void LoadDefault(){
    strcpy(a,"abcbe");
    strcpy(b,"edab");
    strcpy(c,"ebce");
}

void CitireDate(){
    cout<<"Dati primul termen al scaderii: "; cin.get(a,20); cin.get();
    cout<<"Dati al doilea termen al scaderii: "; cin.get(b,20); cin.get();
    cout<<"Dati rezultatul scaderii: "; cin.get(c,20); cin.get();
}

int main(){
    int o; cout<<"Doriti sa folositi valorile default (1/0): "; cin>>o;
    if(o==1) LoadDefault();
    else CitireDate();
    nr = NrVariabile(a,b,c);
    cout<<"Solutii: "<<endl;
    Back(nr,0,9,1,-1);
}