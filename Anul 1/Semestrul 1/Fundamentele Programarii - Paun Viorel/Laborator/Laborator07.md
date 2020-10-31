# Laborator07

- [Laborator07](#laborator07)
    - [1. x1^n+x2^n](#1-x1nx2n)
    - [2. Problema numarului majoritar](#2-problema-numarului-majoritar)
    - [3. Operatii cu matrice](#3-operatii-cu-matrice)

### 1. x1^n+x2^n

```c++
#include <iostream>
using namespace std;

int suma(int n, int s, int p) {
    int S, S1, S0;
    if (n == 0) return 2;
    if (n == 1) return s;
    S0 = 2; S1 = s;
    for (int i = 2; i <= n; i++) {
        S = s * S1 - p * S0;
        S0 = S1;
        S1 = S;
    }
    return S;
}

int main() {
    int s, p, n;
    cout << "n = "; cin >> n;
    cout << "s = "; cin >> s;
    cout << "p = "; cin >> p;
    cout << suma(n, s, p);
}
```

### 2. Problema numarului majoritar

```c++
/* Se un vector cu n nr intregi,
un nr din vector este majoritar
daca apare de mai mult de n/2 ori */
#include <iostream>
#include <fstream>
using namespace std;

int majoritar(int a[], int n, int & m) {
    int nr, i, j;
    for (i = 0; i <= n / 2; i++) {
        m = a[i];
        nr = 1;
        for (j = i + 1; j < n; j++)
            if (a[j] == m) nr++;
        if (nr > n / 2)
            return 1;
    }
    return 0;
}

int majoritarOptim(int a[], int n, int & m) {
    int i, nr;
    nr = 0;
    for (i = 0; i < n; i++)
        if (nr == 0) {
            m = a[i];
            nr = 1;
        }
    else if (a[i] == m) nr++;
    else nr--;
    if (nr > 0) {
        nr = 0;
        for (i = 0; i < n; i++)
            if (a[i] == m) nr++;
    }
    return nr > n / 2;
}

int main() {
    int a[1000], n, i, m;
    ifstream f("date.in");
    f >> n;
    for (i = 0; i < n; i++)
        f >> a[i];
    int raspuns = majoritarOptim(a, n, m);
    if (raspuns == 1) cout << "Numarul majoritar este: " << m;
    else cout << "Nu exista numar majoritar ";
    return 0;
}
```

### 3. Operatii cu matrice

```c++
#include <iostream>
#include <fstream>
#include <iomanip> // pentru setw();
using namespace std;
ifstream in ("date.in");

void citire(int a[10][10], int & n) {
    in >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            in >> a[i][j];
}

void afisare(int a[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(6) << a[i][j];
        cout << endl;
    }
}

void suma(int a[][10], int b[][10], int c[][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void produs(int a[][10], int b[][10], int c[][10], int n) {
    int s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            s = 0;
            for (int k = 0; k < n; k++)
                s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
}

int main() {
    int a[10][10], b[10][10], c[10][10], n;
    citire(a, n);
    citire(b, n);
    cout << "A: " << endl; afisare(a, n);
    cout << "B: " << endl; afisare(b, n);
    suma(a, b, c, n);
    cout << "suma= " << endl; afisare(c, n);
    produs(a, b, c, n); cout << "produs= " << endl;
    afisare(c, n);
}
```

