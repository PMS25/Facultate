#include <iostream>
using namespace std;
//Sa se decrie un algoritm pentru a afisa toate numerele prime de 3 cifre.

bool EPrim(int x){
    if(x<=1)
        return false;
    if(x==2)
        return true;
    if(x%2==0)
        return false;
    for(int d=3; d*d<=x; d+=2)
        if(x%d==0)
            return false;
    return true;
}

int main(){
    cout<<"Nr prime (100-1000): ";
    for(int i=101; i<1000; i++)
        if(EPrim(i))
            cout<<i<<" ";
    cout<<endl;
}