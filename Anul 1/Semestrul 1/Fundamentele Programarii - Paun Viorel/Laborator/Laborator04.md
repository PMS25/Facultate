# Laborator04

- [Laborator04](#laborator04)
    - [1. Nr prim](#1-nr-prim)
    - [2. Goldbach](#2-goldbach)
    - [3. Nr prim cu invers prim](#3-nr-prim-cu-invers-prim)

### 1. Nr prim

```c++
#include <iostream>
//Sa se verifice daca un numar n este prim
using namespace std;

int prim(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    int d = 3;
    while (d * d <= n) {
        if (n % d == 0) return 0;
        d += 2;
    }
    return 1;
}

int main(){
    int n;
    cout << "n= ";
    cin >> n;
    if (prim(n)) cout << n << " Este prim!";
    else cout << n << " Nu este prim!";
    return 0;
}
```

### 2. Goldbach

```c++
#include <iostream>
//orice numar par mai mare decat 2,se poate descompune in suma de 2 numere prime
using namespace std;

int prim(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    int d = 3;
    while (d * d <= n) {
        if (n % d == 0) return 0;
        d += 2;
    }
    return 1;
}

void Goldbach(int n) {
    if (n == 4) {
        cout << 4 << "=" << 2 << "+" << 2 << endl;
        return;
    }
    int m = 3;
    while (m <= n / 2) {
        if (prim(m) && prim(n - m)) cout << n << "=" << m << "+" << n - m << endl;
        m += 2;
    }
}

int main() {
    int n;
    cout << "n=";
    cin >> n;
    if (n % 2 != 0) cout << "n nu este par" << endl;
    else Goldbach(n);
    return 0;
}
```

### 3. Nr prim cu invers prim

```c++
#include<iostream>
#include<cmath>
/*
Sa se afiseze toate nr prime de patru cifre 
care au inversul tot nr prim
*/
using namespace std;

int prim(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    int d = 3;
    int r = sqrt(n);
    while (d <= r) {
        if (n % d == 0) return 0;
        d += 2;
    }
    return 1;
}

int invers(int n) {
    /*
     n= 738
     m=0
     c=n%10=8
     m=m*10+c=8
     n=n/10=73
     c=n%10=3
     m=m*10+c=83
     n=n/10=7
     c=n%10=7
     m=m*10+c=830+7=837
     n=n/10=0
     return m;
     */
    int m, c;
    m = 0;
    while (n > 0) {
        c = n % 10;
        n = n / 10;
        m = m * 10 + c;
    }
    return m;
}

int main() {
    int n;
    n = 1000;
    while (n < 9999) {
        if (prim(n) && prim(invers(n)))
            cout << n << "   ";
        n++;
    }
    return 0;
}
```

