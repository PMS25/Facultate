# Laborator10

- [Laborator10](#laborator10)
    - [1. Fracţii](#1-fracţii)
    - [2. Problema de decupare](#2-problema-de-decupare)

### 1. Fracţii

```c++
#include <iostream>
/*
Definiti structura fractie si
functii de lucru cu fractii.
Calculati suma 1/(1*2)+1/(2*3)+...1/(n*(n+1))
direct si prin formula matematica.
Comparati rezultatele
*/
using namespace std;

struct fractie {
    long long p; //numaratorul
    long long q; // numitorul
};

void afisare(fractie f) {
    cout << f.p << "/" << f.q;
}

long long cmmdc(long long a, long long b) {
    if (b == 0) return a;
    return cmmdc(b, a % b);
}

void normalizare(fractie & f) {
    long long d = cmmdc(f.p, f.q);
    f.p /= d;
    f.q /= d;
    if (f.q < 0) {
        f.p = -f.p;
        f.q = -f.q;
    }
}

fractie sum(fractie f1, fractie f2) {
    fractie f;
    f.p = f1.p * f2.q + f2.p * f1.q;
    f.q = f1.q * f2.q;
    normalizare(f);
    return f;
}

fractie dif(fractie f1, fractie f2) {
    fractie f;
    f.p = f1.p * f2.q - f2.p * f1.q;
    f.q = f1.q * f2.q;
    normalizare(f);
    return f;
}

fractie sum(long long n, fractie f) {
    fractie f1;
    f1.p = n * f.q + f.p;
    f1.q = f.q;
    normalizare(f1);
    return f1;
}

fractie sum(fractie f, long long n) {
    return sum(n, f);
}

fractie fr(long long p, long long q) {
    fractie f = {p,q};
    return f;
}

fractie sol(int n) {
    fractie f = {0,1};
    for (int i = 1; i <= n; i++) {
        f = sum(f, fr(1, i * (i + 1)));
    }
    return f;
}

int main() {
    fractie f1 = {21,-35}, f2 = {4,3}, f;
    normalizare(f1);
    
    f = sum(f1, f2);
    afisare(f1); cout << "+";
    afisare(f2); cout << "=";
    afisare(f); cout << endl;
    
    f = dif(f1, f2);
    afisare(f1); cout << "-";
    afisare(f2); cout << "=";
    afisare(f); cout << endl;
    
    f = sum(f1, 5);
    afisare(f1); cout << "+5=";
    afisare(f); cout << endl;
    
    int n; cout << "n="; cin >> n;
    f = sol(n);
    cout << "Suma ceruta este:";
    afisare(f);
    return 0;
}
```

### 2. Problema de decupare

```c++
using namespace std;#include <iostream>
#include <fstream>
ifstream in ("date.in");
/*
O placa dreptunghiulara(tabla) de lungime l si latime h,
este intepata in n puncte de coordonate cunosute.
Sa se decupeze o placa dreptunghiulara negaurita
(cu laturile paralele cu axele)
de arie maxima
*/

int n, * a, * b, l, h, aMax = 0, xf, yf, lf, hf;
void citire() {
    in >> l >> h; in >> n;
    a = new int[n];
    b = new int[n];
    for (int i = 0; i < n; i++)
        in >> a[i] >> b[i];
}

int index_intepatura(int x, int y, int l, int h) {
    for (int i = 0; i < n; i++) {
        if (a[i] > x && a[i] < x + l && b[i] > y && b[i] < y + h) return i;
    }
    return -1;
}

void divimp(int x, int y, int l, int h) {
    int i = index_intepatura(x, y, l, h);
    if (i == -1) {
        if (l * h > aMax) {
            aMax = l * h;
            xf = x;
            yf = y;
            lf = l;
            hf = h;
        }
    } else {
        divimp(x, y, a[i] - x, h);
        divimp(a[i], y, l - a[i] + x, h);
        divimp(x, y, l, b[i] - y);
        divimp(x, b[i], l, h - b[i] + y);
    }
}

int main() {
    citire();
    cout << "l=" << l << " h=" << h << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << b[i] << endl;
    }
    divimp(0, 0, l, h);
    cout << "Aria maxima este; " << aMax << endl;
    cout << "X final =" << xf << " Y final =" << yf <<
        " L final =" << lf << " H final=" << hf << endl;
}
```

