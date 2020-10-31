#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

class Persoana{
    protected:
        char *nume;
    public:
        Persoana(char *m){
            nume=new char [strlen(m)+1];
            strcpy(nume,m);
        }
        Persoana operator =(const Persoana& p){
            if(strcmp(nume,p.nume) != 0){
                delete[] nume;
                nume = new char(strlen(p.nume));
                strcpy(nume,p.nume);
            }
            return *this;
        }
        char* getNume(){
            return nume;
        }
};

int main(){
    Persoana p("Andrei"), q("Sara"), r("Mircea");
    cout<<"p: "<<p.getNume()<<endl;
    cout<<"q: "<<q.getNume()<<endl;
    cout<<"r: "<<r.getNume()<<endl;
    p = p;
    cout<<"p: "<<p.getNume()<<endl;
    p = q = r;
    cout<<"p: "<<p.getNume()<<endl;
}