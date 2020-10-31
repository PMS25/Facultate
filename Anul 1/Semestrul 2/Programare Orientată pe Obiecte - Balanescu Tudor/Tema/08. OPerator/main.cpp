#include <iostream>
using namespace std;

class C{
    public:
        C(int i=0){x=i;}
        C& operator++(){++x; return *this;}
        C  operator--(){x--; return *this;}
        int getX() const{ return x; }
    private:
        int x;
};

ostream& operator<<(ostream& stream, const C& obj){
    stream<<obj.getX();
    return stream;
}

int main(){
    C i;
    cout<<i<<endl;
    cout<<++(++i)<<endl<<i<<endl;
    cout<<--(--i)<<endl<<i<<endl;
}