# Curs08

- [Curs08](#curs08)
    - [Rezolvarea unui sistem triunghiular](#rezolvarea-unui-sistem-triunghiular)

### Rezolvarea unui sistem triunghiular

```c++
#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int n;
float ** a, * b, * x;

void citire() {
    ifstream f("date.in");
    f >> n;
    a = new float * [n];
    for (int i = 0; i < n; i++)
        a[i] = new float[i + 1];
    b = new float[n];
    x = new float[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            f >> a[i][j];
        f >> b[i];
    }
    f.close();
}

void solutie() {
    int i, j;
    float S;
    for (i = 0; i < n; i++) {
        S = 0;
        for (j = 0; j < i; j++)
            S += a[i][j] * x[j];
        x[i] = (b[i] - S) / a[i][i];
    }
}

void afisare() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++)
            cout << setw(6) << a[i][j];
        cout << endl;
    }
    for (i = 0; i < n; i++)
        cout << setw(6) << b[i];
}

int main() {
    citire();
    afisare();
    solutie();
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << "=" << x[i] << endl;
    return 0;
}
```
