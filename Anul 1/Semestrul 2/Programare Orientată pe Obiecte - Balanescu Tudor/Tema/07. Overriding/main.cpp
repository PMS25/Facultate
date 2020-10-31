#include <iostream>
using namespace std;

class A{
    public:
        virtual void v(){
            cout<<"A::v()"<<endl;
            s(); w();
        }
    protected:
        void s(){cout<<"A::s()"<<endl;}
        virtual void w(){cout<<"A::w()"<<endl;}
};      

class B : public A{
    public:
        virtual void v(){
            cout<<"B::v()"<<endl;
            s();w();
        }
    protected:
        virtual void w(){cout<<"B::w()"<<endl;}
};

int main(){
    cout<<"Start"<<endl;
    A *a; B *b;
    b=new B();
    a=b;
    a->v();
    a=(A*)b;
    a->v();
    ((A)(*b)).v();
} 