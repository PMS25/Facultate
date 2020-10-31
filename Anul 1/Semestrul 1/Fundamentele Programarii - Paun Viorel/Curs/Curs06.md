# Curs06

- [Curs06](#curs06)
    - [Problema celor 4 triunghiuri](#problema-celor-4-triunghiuri)

### Problema celor 4 triunghiuri

O matrice pătratică este împărţită de cele două diagonale în patru triunghiuri. Să se determine suma elementelor din cele patru triunghiuri. Elementele de pe diagonale fac parte din triunghiurile respective.

```c++
#include<iostream.h>

long sumaTrSus(long a[20][20], int n) {
    long S = 0;
    int p, q, k;
    p = 0;
    q = n - 1;
    while (p <= q) {
        for (k = p; k <= q; k++)
            S += a[p][k];
        p++;
        q--;
    }
    return S;
}

long sumaTrJos(long a[20][20], int n) {
    long S = 0;
    int p, q, k;
    p = 0;
    q = n - 1;
    while (p <= q) {
        for (k = p; k <= q; k++)
            S += a[q][k];
        p++;
        q--;
    }
    return S;
}

long sumaTrStanga(long a[20][20], int n) {
    long S = 0;
    int p, q, k;
    p = 0;
    q = n - 1;
    while (p <= q) {
        for (k = p; k <= q; k++)
            S += a[k][p];
        p++;
        q--;
    }
    return S;
}

long sumaTrDreapta(long a[20][20], int n) {
    long S = 0;
    int p, q, k;
    p = 0;
    q = n - 1;
    while (p <= q) {
        for (k = p; k <= q; k++)
            S += a[k][q];
        p++;
        q--;
    }
    return S;
}

void main() {
    long a[20][20]={{1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}};
    cout << sumaTrSus(a, 5) << endl;
    cout << sumaTrStanga(a, 5) << endl;
    cout << sumaTrJos(a, 5) << endl;
    cout << sumaTrDreapta(a, 5) << endl;
}
```
