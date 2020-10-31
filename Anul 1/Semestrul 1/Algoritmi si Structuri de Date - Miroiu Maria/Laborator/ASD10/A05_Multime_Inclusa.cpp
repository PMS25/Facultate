#include <iostream>
using namespace std;
//Stabiliti daca multimea A este inclusa in multimea B.

bool EInclusa(int A[], int nA, int B[], int nB){
    if(nA>nB)
        return false;
    else{
        bool *S = new bool [nB];
        for(int i=0; i<nB; i++)
            S[i] = false;
        for(int i=0; i<nA; i++)
            for(int j=0; j<nB; j++)
                if(A[i] == B[j])
                    if(S[j] && j==nB-1)
                        return false;
                    else{
                        S[j] = true;
                        break;
                    }
        delete[] S;
        return true;
    }
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
    cout<<"Multimea A "<<(EInclusa(A,nA,B,nB) ? "":"nu ")<<"este inclusa in B"<<endl;
    delete[] A; delete[] B;
}
