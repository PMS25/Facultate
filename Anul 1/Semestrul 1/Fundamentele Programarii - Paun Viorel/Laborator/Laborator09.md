# Laborator09

- [Laborator09](#laborator09)
    - [1. Recursivitate](#1-recursivitate)
    - [2. Recursivitate](#2-recursivitate)

### 1. Recursivitate 

```c++
#include <iostream>
using namespace std;

unsigned int sumaCifre(unsigned int n) {
    if (n < 10) return n;
    return n % 10 + sumaCifre(n / 10);

}
unsigned sumaCifreImpare(unsigned n) {
    if (n == 0) return 0;
    return (n % 2 == 1) ? n % 10 + sumaCifreImpare(n / 10) : sumaCifreImpare(n / 10);
}

unsigned sumaPrimelorDouaCifre(unsigned n) {
    if (n < 100) return n % 10 + n / 10;
    return sumaPrimelorDouaCifre(n / 10);
}

unsigned cifraMinima(unsigned n) {
    if (n < 10) return n;
    unsigned m = cifraMinima(n / 10);
    return (n % 10 < m) ? n % 10 : m;
}

int cifraMaxima(int n) {
    if (n < 10) return n;
    int m = cifraMaxima(n / 10);
    return m > n % 10 ? m : n % 10;
}

int eliminareCifra(int n, int c) { //42526
    if (n == 0) return 0;
    if (n % 10 == c) return eliminareCifra(n / 10, c);
    return n % 10 + 10 * eliminareCifra(n / 10, c);
}

unsigned Invers(unsigned n, unsigned x = 0) {// x parametru cu valoare implicita
    if (n == 0) return x;
    return Invers(n / 10, x * 10 + n % 10);
}

void Invers2(unsigned n, unsigned & x) {
    if (n == 0) return;
    x = x * 10 + n % 10;
    Invers2(n / 10, x);
}

int main() {
    int n;
    cout << "n=";
    cin >> n;
    cout << sumaCifre(n); cout << endl;
    cout << sumaCifreImpare(n); cout << endl;
    cout << sumaPrimelorDouaCifre(n); cout << endl;
    cout << cifraMinima(n); cout << endl;
    cout << eliminareCifra(n, cifraMinima(n)) << endl;
    cout << Invers(n, 0) << endl;
    cout << Invers(n);
    unsigned m = 0;
    Invers2(n, m);
    cout << endl;
    cout << m;
    return 0;
}
```

### 2. Recursivitate

```c++
#include <iostream>
using namespace std;

unsigned cmmdc(unsigned a, unsigned b) {
    if (a == b) return a;
    if (a > b) return cmmdc(a - b, b);
    return cmmdc(a, b - a);
}

unsigned euclid(unsigned a, unsigned b) {
    if (a % b == 0) return b;
    return euclid(b, a % b);
}

long long ackerman(long long m, long long n) {
    if (m == 0) return n + 1;
    if (n == 0) return ackerman(m - 1, 1);
    return ackerman(m - 1, ackerman(m, n - 1));
}

int main() {
    int a, b;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    cout << cmmdc((unsigned) a, (unsigned) b); cout << endl;
    cout << euclid(a, b); cout << endl;
    cout << ackerman(a, b);
    return 0;
}
```

