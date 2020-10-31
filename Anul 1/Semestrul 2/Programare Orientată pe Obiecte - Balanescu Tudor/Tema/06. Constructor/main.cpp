#include <iostream>
using namespace std;

class Person{
    public:
        Person(int a){
            age=a;
            cout<<age<<endl;
        }
    int age;
};

int main(){
    Person p(20);
    cout<<p.age<<endl;
}