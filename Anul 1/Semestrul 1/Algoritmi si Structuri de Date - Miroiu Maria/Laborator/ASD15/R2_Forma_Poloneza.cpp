#include <iostream>
#include <cstring>
using namespace std;
#define NMAX 30

char s[NMAX];
char stiva[NMAX]; int varf;
char fp[NMAX]; int n=-1; 

int Prioritate(char c){
    switch(c){
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(':
        case ')': return 0;
        default: return -1;
    }
}

void Convertire(){
    for(int i=0; i<strlen(s); i++)
        switch (s[i]){
        case '(':
            stiva[++varf]='(';
            break;
        case ')': 
            while(stiva[varf]!='(')
                fp[++n] = stiva[varf--];
            varf--; break;
        case '+':
        case '-':
        case '*':
        case '/':
            while(Prioritate(stiva[varf]) >= Prioritate(s[i]))
                fp[++n] = stiva[varf--];
            stiva[++varf] = s[i];
            break;
        default:
            fp[++n] = s[i];
        }
}

void Citire(){
    cout<<"Dati ecuatia: ";
    cin.get(s,NMAX); cin.get();
    int l = strlen(s);
    for(int i=l; i>0; i--)
        s[i] = s[i-1];
    s[0] = '(';
    s[l+1] = ')';
    cout<<s<<endl;
}

int main(){
    Citire();
    Convertire();
    cout<<"Forma poloneza: "<<fp<<endl;
}