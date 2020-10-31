 # Laborator05

- [Laborator05](#laborator05)
    - [1. Cmmdc Cmmmc](#1-cmmdc-cmmmc)
    - [2. Descompunere Fibonacci](#2-descompunere-fibonacci)
    - [3. Descompunerea in factori primi](#3-descompunerea-in-factori-primi)

### 1. Cmmdc Cmmmc

```c++
#include <iostream>
/* 36 24 */
using namespace std;

int cmmdc1(int a, int b) {
    int m = (a < b) ? a : b;
    for (int d = m; d >= 1; d--)
        if (a % d == 0 && b % d == 0) return d;

}

int cmmdc2(int a, int b) {
    int d = (a < b) ? a : b;
    for (;; d--)
        if (a % d == 0 && b % d == 0) return d;
}

int cmmdc3(int a, int b) {
    while (a != b) {
        if (b > a) b = b - a;
        else a = a - b;
    }
    return a;
}

int cmmdc4(int a, int b) {
    while (a != b)(b > a) ? b = b - a : a = a - b;
    return a;
}

int cmmdc(int a, int b) {//Algoritmul lui Euclin
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int cmmmc(int a, int b) {
    return a * b / cmmdc(a, b);
}

int cmmdc(int a[], int n) {
    int d = a[0];
    for (int i = 1; i < n; i++)
        d = cmmdc(d, a[i]);
    return d;

}

int cmmmc(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++)
        m = cmmmc(m, a[i]);
    return m;
}

int main() {
    cout << "cmmdc(72,30)=" << cmmdc(72, 30) << endl;
    cout << "cmmmc(72,30)=" << cmmmc(72, 30) << endl;
    int x[100], n;
    cout << "n="; cin >> n;
    cout << "Tastati " << n << " nr naturale strict pozitive: ";
    for (int i = 0; i < n; i++) cin >> x[i];
    cout << "cmmdc(x,n)=" << cmmdc(x, n) << endl;
    cout << "cmmmc(x,n)=" << cmmmc(x, n) << endl;
    return 0;
}
```

### 2. Descompunere Fibonacci

```c++
#include <iostream>
 ///sa se descompuna un nr nat n in suma de nr fibonacci distincte
/// nr sunt 1,1,2,3,5,8,13,21,34,55,89,144
/// 100=89+8+3
using namespace std;

int maxFib(int n) {
    int f1, f2, f;
    f1 = 0;
    f2 = 1;
    f = 1;
    while (f <= n) {
        f1 = f2;
        f2 = f;
        f = f1 + f2;
    }
    return f2;
}

void descompunere(int n) {
    cout << n << "=";
    int f;
    while (n > 0) {
        f = maxFib(n);
        cout << f << "+";
        n -= f;
    }
    cout << "\b ";
}

int main() {
    descompunere(950);
    return 0;
}
```

### 3. Descompunerea in factori primi

```c++
#include <iostream>
using namespace std;
// descompunerea unui numar natural n > 1 in factori primi

void Descompunere(int n) {
    int d = 2, p;
    while (n > 1) {
        p = 0;
        while (n % d == 0) {
            p++;
            n /= d;
        }
        if (p > 0) cout << d << "^" << p << "*";
        d++;
    }
    cout << "\b ";
}

void Descompunere_optimizata(int n) {
    int d = 2, p = 0;
    while (n % 2 == 0) {
        p++;
        n /= 2;
    }
    if (p > 0) cout << d << "^" << p << "*";
    d = 3;

    while (d * d <= n) {
        p = 0;
        while (n % d == 0) {
            p++;
            n /= d;
        }
        if (p > 0) cout << d << "^" << p << "*";
        d += 2;
    }
    if (n > 1) cout << n << "^1 ";
    cout << "\b ";
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    Descompunere(n);
    cout << endl;
    Descompunere_optimizata(n);
    return 0;
}
```

