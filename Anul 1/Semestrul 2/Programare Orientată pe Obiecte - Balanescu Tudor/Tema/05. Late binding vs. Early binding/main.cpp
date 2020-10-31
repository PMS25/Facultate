#include <iostream>
using namespace std;

class A{
    public:
        void st(){cout<<" A::st()"<<endl;}
        virtual void vrt(){cout<<" A::vrt()"<<endl;}
        void stafis(){cout<<" A::stafis()"<<endl; st(); vrt(); }
        virtual void vrtafis(){cout<<" A::vrtafis()"<<endl; st(); vrt();}
};

class B : public A{
    public:
        int st(){cout<<" B::st()"<<endl; return 1;}
        void stafis(){cout<<" B::stafis()"<<endl; st(); vrt(); }
        virtual void vrtafis(){cout<<" B::vrtafis()"<<endl; st(); vrt();}
};


int main(){
    A *p; p=new B();
    p->st();
    p->vrt();
    p->stafis();
    p->vrtafis();
}