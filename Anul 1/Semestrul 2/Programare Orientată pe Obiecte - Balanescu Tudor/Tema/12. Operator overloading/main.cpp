#include <iostream>
using namespace std;

class Person{
    public:
        Person(char* name):name(name){}
        Person operator+(Person p){
            cout<<name<<" s-a intalnit cu "<<p.name<<endl;
            return Person(name);
        }
        Person operator*(Person p){
            cout<<name<<" s-a intalnit cu "<<p.name<<endl;
            return p;
        }
    private:
        char* name;
};

int main(){
    cout<<"Operator Overloading"<<endl;
    Person p("Andrei"), q("Sara"), r("Tudor");
    //Operator+
    p+q; cout<<endl;
    p+q+r; cout<<endl;
    //Operator*
    p*q*r;
}
