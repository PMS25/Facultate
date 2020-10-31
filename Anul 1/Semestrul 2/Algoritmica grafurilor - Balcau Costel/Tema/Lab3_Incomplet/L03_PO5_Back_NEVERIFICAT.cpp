#include <iostream>
using namespace std;
//Generarea partitiilor multimii {1, 2, ..., n} cu k parti.

void CitireDate(int &n, int &k){
    cout<<"Dati dimensiunea multimii: "; cin>>n;
    cout<<"Dati nr de parti: "; cin>>k;
}

void PrelSol(int *c, int lungime_c, int nr_parti){
    for(int i=1; i<=nr_parti; i++){
        cout<<"{";
        for(int j=1; j<=lungime_c; j++)
            if(c[j] == i)
                cout<<j<<", ";
        cout<<"\b\b}, ";
    }
    cout<<"\b\b \n";
    for(int i=1; i<=lungime_c; i++)
        cout<<c[i]<<" ";
    cout<<endl<<"==="<<endl;
}

bool Valid(int *c, int pozitie, int lungime_c, int nr_parti){
    if(pozitie == lungime_c){
        bool sem;
        for(int pk=1; pk<=nr_parti; pk++){
            sem = false;
            for(int i=1; i<=nr_parti; i++)
                sem = (c[i] == pk ? true:sem);
            if(sem == false)
                return sem;
        }
        if(sem)
            PrelSol(c,lungime_c,nr_parti);
    }
    return true;
}

void Back(int n, int min, int max, int pas, int fi){
    int *c = new int[n+1], k;
    for(k=1; k<=n; k++)
        c[k] = fi;
    k = 1;
    while(k>0)
        if(k == n+1)
            k--;
        else
            if(c[k]<= max - pas){
                c[k] += pas;
                if(Valid(c,k,n,max));
                    k++;
            }else
                c[k--] = fi;
    delete[] c;
}

int main(){
    int n,k;
    CitireDate(n,k);
    Back(n,1,k,1,0);
}