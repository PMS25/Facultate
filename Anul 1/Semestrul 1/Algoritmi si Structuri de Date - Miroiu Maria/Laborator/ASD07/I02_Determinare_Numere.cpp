#include <iostream>
using namespace std;
//Determinati toate numerele de forma a23a care se impart exact la 6.
//Solutie: 2232, 8238

bool EDivizibil(int n, int d){ return n%d==0; }

int main(){
    cout<<"Nr generate: ";
    for(int i=1; i<10; i++)
        if(EDivizibil(i*1000+230+i,6))
            cout<<i*1000+230+i<<" ";
    cout<<endl;
}