# Laborator03

- [Laborator03](#laborator03)
    - [1. Funcţii utilizator](#1-funcţii-utilizator)
    - [2. cdab](#2-cdab)
    - [3. Nr. zerouri](#3-nr-zerouri)
    - [4. Cifre lipsă](#4-cifre-lipsă)

### 1. Funcţii utilizator 

```c++
#include <iostream>
using namespace std;

int sumaCifre(int n) {
    int s;
    s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int nrCifrePare(int n) {
    int p, c;
    if (n == 0) return 1;
    p = 0;
    while (n) {
        c = n % 10;
        if (c % 2 == 0) p++;
        n /= 10;

    }
    return p;
}

int main() {
    int a;
    cout << "a= ";
    cin >> a;
    cout << "suma cifrelor numarului " << a << " este " << sumaCifre(a) << endl;
    cout << a << " are " << nrCifrePare(a) << " cifre pare " << endl;
    return 0;
}
```

### 2. cdab

```c++
#include <iostream>
/*
se da un numar de forma abcd. Sa se elaboreze o functie care returneaza cdab.
7135=> 3571
*/
using namespace std;

int cdab(int abcd) {
    return abcd % 100 * 100 + abcd / 100;
}

int main() {
    int a;
    cout << "a=";
    cin >> a;
    if (a >= 1000 && a <= 9999) cout << cdab(a) << endl;
    else cout << "numarul nu este strict din 4 cifre";
    return 0;
}
```

### 3. Nr. zerouri

```c++
#include <iostream>
/*se da un sir de n numere naturale >=1
sa se determine numarul de zerouri in care se termina produsul lor
15,20,25,30,48
*/
using namespace std;

int exponent(int n, int d) {
    int p;
    p = 0;
    while (n % d == 0) {
        p = p + 1;
        n = n / d;
    }
    return p;
}

int main() {
    int a;
    int n;
    cout << " n=";
    cin >> n;
    int p2, p5;
    int i;
    p2 = 0;
    p5 = 0;
    i = 1;
    while (i <= n) {
        cout << "a" << i << "=";
        cin >> a;
        p2 = p2 + exponent(a, 2);
        p5 = p5 + exponent(a, 5);
        i = i + 1;
    }
    int nrz;
    if (p2 < p5) nrz = p2;
    else nrz = p5;
    cout << "produsul numerelor se termina in " << nrz << " zerouri";
    return 0;
}
```

### 4. Cifre lipsă

```c++
#include <iostream>
/*
se dau n numere naturale. sa se determine cifrele
care nu apar in scrierea numerelor
1246 654 315

   0 1 2 3 4 5 6 7 8 9
v: 0 1 1 1 1 1 1 0 0 0
*/
using namespace std;

int v[10];
void setareCifre(int a) {
    int c;
    if (a == 0) {
        v[0] = 1;
        return;
    }
    while (a > 0) {
        c = a % 10;
        v[c] = 1;
        a = a / 10;
    }
}

int main() {
    int a, n, i;
    cout << "dati numarul de numere:";
    cin >> n;
    i = 1;
    while (i <= n) {
        cout << "a" << i << "=";
        cin >> a;
        setareCifre(a);
        i = i + 1;
    }
    cout << "cifrele care nu apar in sir sunt:";
    i = 0;
    while (i <= 9) {
        if (v[i] == 0) cout << i << ", ";
        i = i + 1;
    }
    cout << "\b\b.";
    return 0;
}
```

