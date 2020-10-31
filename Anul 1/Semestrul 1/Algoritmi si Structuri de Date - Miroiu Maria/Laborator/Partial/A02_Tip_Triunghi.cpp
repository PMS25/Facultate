#include <iostream>
using namespace std;
//Sa se descrie un algoritm pentru a determina daca un triunghi este isoscel, cunoscand valorile unghiurilor. 
//EX: A=70, B=40 şi C=70 triunghiul este isoscel, iar pentru A=40, B=80 si C=60 triunghiul nu este isoscel.

bool EIsoscel(int A, int B, int C){
    return (A==B || A==C || B==C);
}

int main(){
    int A,B,C; cout<<"Dati unghiurile: "; cin>>A>>B>>C;
    cout<<"Triunghiul "<<(EIsoscel(A,B,C) ? "":"nu ")<<"este isoscel."<<endl;
}