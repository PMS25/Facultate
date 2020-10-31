#include <iostream>
using namespace std;
//Scrieti algoritmi pentru intersectia, reuniunea si diferenta a doua multimi.

void Afisare(int V[], int n){
    for(int i=0; i<n; i++)
        cout<<V[i]<<" ";
    cout<<endl;
}

void Intersectie(int A[], int nA, int B[], int nB){
    int *S = new int [min(nA,nB)], n=0;
    for(int i=0; i<nA; i++)
        for(int j=0; j<nB; j++)
            if(A[i] == B[j])
                S[n++] = A[i];
    Afisare(S,n);
}

void Reuniune(int A[], int nA, int B[], int nB){
    int *S = new int [nA+nB], n=0;
    bool aux;
    for(int i=0; i<nA; i++)
        S[n++] = A[i];
    for(int j=0; j<nB; j++){
        aux = true;
        for(int i=0; i<nA; i++)
            if(B[j] == A[i]){
                aux = false;
                break;
            }
        if(aux)
            S[n++]=B[j];
    }
    Afisare(S,n);
}

void Diferenta(int A[], int nA, int B[], int nB){
    int *S = new int [max(nA,nB)], n=0;
    bool aux;
    for(int i=0; i<nA; i++){
        aux = true;
        for(int j=0; j<nB; j++)
            if(A[i] == B[j]){
                aux = false;
                break;
            }
        if(aux)
            S[n++]=A[i];
    }
    Afisare(S,n);
}

void CitireDate(int *&A, int &nA, int *&B, int &nB){
    cout<<"Dati numarul de elemente A: "; cin>>nA;
    A = new int[nA];
    cout<<"Dati elementele multimii A: ";
    for(int i=0; i<nA; i++) cin>>A[i];
    cout<<"Dati numarul de elemente B: "; cin>>nB;
    B = new int[nB];
    cout<<"Dati elementele multimii B: ";
    for(int i=0; i<nB; i++) cin>>B[i];
}

int main(){
    int *A, *B, nA, nB;
    CitireDate(A,nA,B,nB);
    cout<<"Intersectie A∩B: "; Intersectie(A,nA,B,nB);
    cout<<"Reuniunea AUB: "; Reuniune(A,nA,B,nB);
    cout<<"Diferenta A\\B: "; Diferenta(A,nA,B,nB);
    cout<<"Diferenta B\\A: "; Diferenta(B,nB,A,nA);
    delete[] A; delete[] B;
}
