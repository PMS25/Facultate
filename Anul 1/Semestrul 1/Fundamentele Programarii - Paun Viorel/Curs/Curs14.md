# Curs14

- [Curs14](#curs14)
    - [Generare submulţimi](#generare-submulţimi)

### Generare submulţimi

```c++
#include <iostream>
using namespace std;

void generare(int a[], int n, int & ig) {
    int i;
    if (ig == 0) {
        for (i = 0; i < n; i++) a[i] = 0;
        ig = 1;
        return;
    } else
        for (i = n - 1; i >= 0; i--)
            if (a[i] == 0) {
                a[i] = 1;
                return;
            }
    else a[i] = 0;
    ig = 0;

}

void afis(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void subm(int a[], int n) {
    cout << "{";
    for (int i = 0; i < n; i++)
        if (a[i] == 1) cout << i + 1 << " ";
    cout << "}" << endl;
}

void gen(int v[], int n, int p) {
    for (int i = 0; i < n; i++)
        v[n - i - 1] = (p & (1 << i)) != 0;
}

int main() {
    cout << "Metoda 1" << endl;
    int a[10], n = 4, ig;
    ig = 0;
    generare(a, n, ig);
    while (ig == 1) {
        subm(a, n);
        generare(a, n, ig);
    }
    cout << "Metoda 2" << endl;
    int nrs = 1 << n;
    int p;
    for (p = 0; p < nrs; p++) {
        gen(a, n, p);
        ///afis(a,n);
        subm(a, n);
    }
    return 0;
}
```
