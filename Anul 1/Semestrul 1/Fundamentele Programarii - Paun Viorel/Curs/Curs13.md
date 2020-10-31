# Curs13

- [Curs13](#curs13)
    - [1. Cel mai lung subşir crescator](#1-cel-mai-lung-subşir-crescator)
    - [2. Drum de lungime maximă](#2-drum-de-lungime-maximă)

### 1. Cel mai lung subşir crescator

```c++
#include <iostream>
#include<fstream>
/*
Determinarea celui mai lung subşir crescător
Fie a1,a2,...,an un şir  de numere.
Să se găsească cel mai lung subşir ai1, ai2, ..., aik al şirului dat cu propietatea că ai1 <= ai2 <=....<= aik 
şi  i1< i2 < ... < ik. 
Rezolvare.
Fie L[p]=lungimea celui mai lung subşir crescător al şirului dat având ca prim termen pe ap,
p=n,n-1,...,1.
Au loc relaţiile:
		L[n]=1
		L[p]=1 dacă ap > ak oricare ar fi k > p,k <= n sau
		L[p]=max{ 1+L[k] | k=p+1,...,n şi ap <= ak }
Soluţia se construieşte în vectorul x astfel:
Pentru p=n,n-1,...,1 luăm 
	x[p]=-1 dacă L[p]=1 sau x[p] = k dacă L[p]=1+L[k].
	x[p]=-1 are semnificaţia că elementul ap nu mai are succesor în subşirul crescător,
    iar x[p]=k are semnificaţia că succesorul elementului ap este ak.
De asemenea fie 
		Lmax= max{ L[1],...,L[n] } = L[pmax]
Obs. In program indicii sunt numerotati incepand cu zero
*/
using namespace std;

int n, a[1000], x[1000], Lmax = 0, pmax;
void subsir(int a[], int n, int x[]) {
    int L[1000];
    int i, j;
    for (i = n - 1; i >= 0; i--) {
        L[i] = 1;
        x[i] = -1;
        for (j = i + 1; j < n; j++)
            if (a[i] <= a[j] && L[i] <= L[j]) {
                L[i] = L[j] + 1;
                x[i] = j;
                if (L[i] > Lmax) {
                    Lmax = L[i];
                    pmax = i;
                }
            }
    }
}

void AfisareSol(int a[], int x[]) {
    int p = pmax;
    while (p != -1) {
        cout << a[p] << " ";
        p = x[p];
    }
}

int main() {
    ifstream f("date.in");
    f >> n;
    int i;
    for (i = 0; i < n; i++) f >> a[i];
    for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    subsir(a, n, x);
    AfisareSol(a, x);
    return 0;
}
```

### 2. Drum de lungime maximă

```c++
#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;
/*
Se consideră un triunghi de numere care are pe prima linie un număr,
pe a doua linie două numere, pe a treia linie trei numere etc., 
triunghiul având în total N linii (1 ≤ N ≤ 1000).
 Scrieţi un program care să calculeze cea mai mare dintre sumele numerelor 
ce apar pe drumurile ce pleacă din vârf şi ajung la bază, 
astfel încât în fiecare drum succesorul unui număr se află pe rândul de mai jos dedesubt
 sau pe diagonală la dreapta. 
*/

int ** a, ** d, * s, n;
void alocare(int n) {
    a = new int * [n];
    d = new int * [n];
    s = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[i + 1];
        d[i] = new int[i + 1];
    }
}

void citire(ifstream & f, int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j <= i; j++) {
            f >> a[i][j];
            d[i][j] = 0;
        }
}

void afisare(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++)
            cout << setw(6) << a[i][j];
        cout << endl;
    }
}

int sol(int n) {
    int i, j;
    for (i = 0; i < n; i++)
        s[i] = a[n - 1][i];
    for (i = n - 2; i >= 0; i--)
        for (j = 0; j <= i; j++)
            if (s[j] > s[j + 1]) {
                s[j] += a[i][j];
                d[i][j] = j;
            }
    else {
        s[j] = s[j + 1] + a[i][j];
        d[i][j] = j + 1;
    }
    return s[0];
}

void drum(int n) {
    int i, j = 0;
    for (i = 0; i < n; i++) {
        cout << a[i][j] << " ";
        j = d[i][j];
    }
}

int main() {
    ifstream f("date.in");
    f >> n;
    alocare(n);
    citire(f, n);
    afisare(n);
    cout << sol(n) << endl;
    drum(n);
    return 0;
}
```
