#include <iostream>
using namespace std;
//Se considera o matrice patrata de ordin n (un fel de tabla de sah) cu elemente ce au valori {0, 1, 2}.
//Unde este 0 nu este nicio piesa, unde este 1 sunt piesele adversarului, iar unde este 2 (unica) este piesa proprie.
//Piesa proprie numita "turo-rege" poate ataca doar vecinii aflati in casuta alaturată in N, S, E, V (numai departe de o casuta).
//Sa se descrie un algoritm pentru determinarea pozitiilor pe care piesa proprie le poate ataca.

struct pozitie{ int a,b; };

pozitie PozitieRege(int **a, int n){
    pozitie p;
    p.a=-1; p.b=-1;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(a[i][j]==2){
                p.a = i; p.b = j;
                return p;
            }
    return p;
}

void Posibilitati(int **a, int n, pozitie p){
    cout<<"Solutii: ";
    bool aux = true;
    if(p.a-1>=0 && a[p.a-1][p.b]==1){ //Nord
        cout<<"["<<p.a-1<<","<<p.b<<"] ; ";
        aux = false;
    }
    if(p.a+1<n && a[p.a+1][p.b]==1){ //Sud
        cout<<"["<<p.a+1<<","<<p.b<<"] ; ";
        aux = false;
    }
    if(p.b+1<n && a[p.a][p.b+1]==1){ //Est
        cout<<"["<<p.a<<","<<p.b+1<<"] ; ";
        aux = false;
    }
    if(p.b-1>=0 && a[p.a][p.b-1]==1){ //Vest
        cout<<"["<<p.a<<","<<p.b-1<<"] ; ";
        aux = false;
    }
    if(aux)
        cout<<"Niciuna."<<endl;
    else
        cout<<"\b\b \n";
}

void AlocareM(int **&a, int n){
    a = new int*[n];
    for(int i=0; i<n; i++)
        a[i] = new int[n];
}

void CitireM(int **&a, int &n){
    cout<<"Dati numarul de linii: "; cin>>n;
    cout<<"Dati elementele: "<<endl;
    AlocareM(a,n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
}

void DeleteM(int **a, int n){
    for(int i=0; i<n; i++)
        delete[] a[i];
    delete[] a;
}

int main(){
    int **a,n;
    CitireM(a,n);
    Posibilitati(a,n,PozitieRege(a,n));
    DeleteM(a,n);
}