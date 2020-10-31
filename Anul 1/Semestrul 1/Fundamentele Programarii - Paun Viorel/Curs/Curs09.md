# Curs09

- [Curs09](#curs09)
    - [1. Căutare binară](#1-căutare-binară)
    - [2. Problema fotografiei](#2-problema-fotografiei)
    - [3. Problema de decupare](#3-problema-de-decupare)

### 1. Căutare binară

```c++
#include <iostream>
using namespace std;
/*
Sa se determine pozitia unui numar intreg x 
intr-un vector de numere intregi a, ordonat crescator
*/

int cautareBinara(int a[], int s, int d, int x) {
    int m;
    while (s <= d) {
        m = (s + d) / 2;
        if (x == a[m]) return m;
        if (x < a[m]) d = m - 1;
        else s = m + 1;
    }
    return -1;
}

int cautareBinaraREC(int a[], int s, int d, int x) {
    if (s > d) return -1;
    int m = (s + d) / 2;
    if (x == a[m]) return m;
    if (x < a[m]) return cautareBinaraREC(a, s, m - 1, x);
    return cautareBinaraREC(a, m + 1, d, x);
}

int main() {
    int a[]={4,6,8,9,14,16,20,25,37,42,56};
    int n = sizeof(a) / sizeof(int);
    cout << "n=" << n << endl;
    int x; cout << "x="; cin >> x;
    
    int p = cautareBinara(a, 0, n - 1, x);
    if (p >= 0)
        cout << "poz lui a=" << p << endl;
    else
        cout << "a nu se gaseste in sir" << endl;

    p = cautareBinaraREC(a, 0, n - 1, x);
    if (p >= 0)
        cout << "poz lui a=" << p << endl;
    else
        cout << "a nu se gaseste in sir" << endl;
    return 0;
}
```

### 2. Problema fotografiei

```c++
#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
/*
Se consideră fotografia alb-negru a unor obiecte, 
reprezentată sub forma unui tablou bidimensional cu n linii şi n coloane, 
cu elementele în mulţimea {0,1}. 
Elementele egale cu 1 corespund poziţiilor ce aparţin obiectelor. 
Să se scrie un program pentru a determina câte obiecte sunt fotografiate 
şi din câte elemente de "1" este compus fiecare obiect.
*/

int a[25][25], n;
int generare() {
    srand(time(0));
    int k;
    k = rand() % (n * n);
    while (k > 0) {
        a[1 + rand() % n][1 + rand() % n] = 1;
        k--;
    }
}

void afisare() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int fig(int i, int j) {
    if (a[i][j] == 1) {
        a[i][j] = -1;
        return 1 + fig(i - 1, j - 1) + fig(i - 1, j) + fig(i - 1, j + 1) +
            fig(i, j - 1) + fig(i, j + 1) +
            fig(i + 1, j - 1) + fig(i + 1, j) + fig(i + 1, j + 1);
    }
    return 0;
}

int figNR(int i, int j) {
    int * x = new int[n * n], * y = new int[n * n];
    int k = 0, nr = 0;
    x[k] = i;
    y[k] = j;
    a[i][j] = -1;
    while (k >= 0) {
        i = x[k];
        j = x[k];
        nr++;
        k--;
        if (a[i - 1][j - 1] == 1) {
            k++;
            x[k] = i - 1;
            y[k] = j - 1;
            a[i - 1][j - 1] = -1;
        }
        if (a[i - 1][j] == 1) {
            k++;
            x[k] = i - 1;
            y[k] = j;
            a[i - 1][j] = -1;
        }
        if (a[i - 1][j + 1] == 1) {
            k++;
            x[k] = i - 1;
            y[k] = j + 1;
            a[i - 1][j + 1] = -1;
        }
        if (a[i][j - 1] == 1) {
            k++;
            x[k] = i;
            y[k] = j - 1;
            a[i][j - 1] = -1;
        }
        if (a[i][j + 1] == 1) {
            k++;
            x[k] = i;
            y[k] = j + 1;
            a[i][j + 1] = -1;
        }
        if (a[i + 1][j - 1] == 1) {
            k++;
            x[k] = i + 1;
            y[k] = j - 1;
            a[i + 1][j - 1] = -1;
        }
        if (a[i + 1][j] == 1) {
            k++;
            x[k] = i + 1;
            y[k] = j;
            a[i + 1][j] = -1;
        }
        if (a[i + 1][j + 1] == 1) {
            k++;
            x[k] = i + 1;
            y[k] = j + 1;
            a[i + 1][j + 1] = -1;
        }
    }
    return nr;
}

int main() {
    n = 6;
    generare();
    afisare();

    int i, j, nrOb = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) {
                nrOb++;
                cout << "obiectul " << nrOb << " are " << fig(i, j) << " elem 1" << endl;
            }
    cout << "Metoda a II-a" << endl;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] *= -1;

    nrOb = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) {
                nrOb++;
                cout << "obiectul " << nrOb << " are " << fig(i, j) << " elem 1" << endl;
            }
    return 0;
}
```

### 3. Problema de decupare

O suprafaţă pătrată cu lungimea laturii n=2 k este divizată ca o tablă de şah în pătrate unitare. Unul din aceste pătrate unitare este acoperit. Să se arate cum se poate acoperi suprafaţa ramasă cu plăci de forma constând din trei pătrate unitare.

|   X   |  X   |
| :---: | :--: |
| **X** |      |

**Soluţie**
Se împarte suprafaţa pătrată în patru pătrate egale, formându-se patru suprafeţe pătrate cu lungimea laturii 2k-1. Una dintre suprafeţe are un pătrat unitar acoperit(marcat cu x). Acoperim cu o placă ca mai jos:

|      |      |      |       |       |      |       |      |
| ---- | ---- | ---- | ----- | ----- | ---- | ----- | ---- |
|      |      |      |       |       |      | **X** |      |
|      |      |      |       |       |      |       |      |
|      |      |      | **X** |       |      |       |      |
|      |      |      | **X** | **X** |      |       |      |
|      |      |      |       |       |      |       |      |
|      |      |      |       |       |      |       |      |
|      |      |      |       |       |      |       |      |

Fiecare din cele 4 suprafeţe este acum în condiţiile problemei, deci pentru fiecare suprafaţă se repetă procedeul descris(cât timp n>1).

```c++
#include<iostream>
#include<iomanip>
using namespace std;

int a[64][64];
int ex(int i, int j, int n) {//exista patratel acoperti
    int l, k;
    for (l = i; l < i + n; l++)
        for (k = j; k < j + n; k++)
            if (a[l][k] != 0) return 1;
    return 0;
}

void divimp(int i, int j, int n) {
    static int p = 1;
    if (n == 1) return;
    p++;
    int m = n / 2;
    if (ex(i, j, m)) {
        a[i + m][j + m - 1] = p;
        a[i + m][j + m] = p;
        a[i + m - 1][j + m] = p;
    } else if (ex(i, j + m, m)) {
        a[i + m - 1][j + m - 1] = p;
        a[i + m][j + m - 1] = p;
        a[i + m][j + m] = p;
    } else if (ex(i + m, j, m)) {
        a[i + m - 1][j + m - 1] = p;
        a[i + m - 1][j + m] = p;
        a[i + m][j + m] = p;
    } else if (ex(i + m, j + m, m)) {
        a[i + m - 1][j + m - 1] = p;
        a[i + m - 1][j + m] = p;
        a[i + m][j + m - 1] = p;
    }
    divimp(i, j, m);
    divimp(i, j + m, m);
    divimp(i + m, j, m);
    divimp(i + m, j + m, m);
}

int main() {
    int n = 8;
    a[3][5] = 1;
    divimp(0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    return 0;
}
```

