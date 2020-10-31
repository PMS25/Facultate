#include <iostream>
#include <cstring>
#include <regex>
using namespace std;
//Se citeste de la tastatura un CNP (SAALLZZJJNNNC – 13 cifre).
//Determinati data nasterii si sexul persoanei (se va lua in considerare doar valorile 1 si 2)
//EX: CNP = 1980627035033 => data nasterii este 27.06.98 si este persoana de sex barbatesc
//    CNP = 2971203035033 => data nasterii este 3.12.97 si este persoana de sex femeiesc

struct data_timp{ int an,luna,zi; };

string ExtractSex(string s){
    return (s[0]=='1' ? "barbatesc":"femeiesc");
}

data_timp ExtractData(string s){
    data_timp t;
    t.an = (s[1]-'0')*10 + (s[2]-'0');
    t.luna = (s[3]-'0')*10 + (s[4]-'0');
    t.zi = (s[5]-'0')*10 + (s[6]-'0');
    return t;
}

string ExtractCNP(string s){
    regex r("[0-9]{13}");
    smatch match;
    regex_search(s, match, r);
    return match[0];  
}

void Afisare(string cnp){
    data_timp d = ExtractData(cnp);
    cout<<"Sex: "<<ExtractSex(cnp)<<endl;
    cout<<"Data nastere: "<<d.zi<<"."<<d.luna<<"."<<d.an<<endl;
}

int main(){
    char s[21]; cout<<"Dati CNP: "; cin.get(s,20);
    string cnp = ExtractCNP(string(s));
    if(cnp.length())
        Afisare(cnp);
    else
        cout<<"Nu ati introdus niciun CNP valid.";
}