# Laborator06

- [Laborator06](#laborator06)
    - [1. Generare siruri](#1-generare-siruri)
    - [2. Generare matrice](#2-generare-matrice)
    - [3. Generare matrice](#3-generare-matrice)
    - [4. Eliminare nr prime din vector](#4-eliminare-nr-prime-din-vector)

### 1. Generare siruri

```c++
#include <iostream>
using namespace std;
/* sa se genereze primii n termeni ai sirului
a) 1,1,2,1,2,3,1,2,3,4,1,2,3,4,5...
b) 1,2,1,1,2,3,4,3,2,1,1,2,3,4,5,6,5,4,3,2,1...
*/

void a(int n) {
    int nr, i, k;
    k = 1;
    nr = 0;
    while (1) {
        for (i = 1; i <= k; i++) {
            cout << i << ",";
            nr++;
            if (nr == n) {
                cout << "\b ";
                return;
            }
        }
        k++;
    }
}

void b(int n) {
    int nr, i, k;
    nr = 0; k = 2;
    while (1) {
        for (i = 1; i <= k; i++) {
            cout << i << ",";
            nr++;
            if (nr == n) {
                cout << "\b ";
                return;
            }
        }
        for (i = k - 1; i >= 1; i--) {
            cout << i << ",";
            nr++;
            if (nr == n) {
                cout << "\b ";
                return;
            }
        }
        k += 2;
    }
}

int main(){
    cout << "a:"; a(30); cout << endl;
    cout << "b:"; b(30);
    return 0;
}
```

### 2. Generare matrice

```c++
#include <iostream>
/*sa se genereze matricea cu n linii si n coloane astfel incat
aij=i, daca i >j
aij=j , daca i<j
aij=0, daca i=j
*/
using namespace std;

void generare(int a[20][20], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            if (i > j) a[i][j] = i;
            else if (j > i) a[i][j] = j;
        else a[i][j] = 0;
    }
}

void afisare(int a[20][20], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int x[20][20], n;
    cout << "n="; cin >> n;
    generare(x, n);
    afisare(x, n);
    return 0;
}
```

### 3. Generare matrice

```c++
#include <iostream>
#include <iomanip> ///pentru setw
using namespace std;
/*Sa se genereze o matrice patratica cf urmatorului exemplu
  1  2  3  4  5
 16 17 18 19  6
 15 24 25 20  7
 14 23 22 21  8
 13 12 11 10  9
*/

void generare(int a[20][20], int n) {
    int i, p = 0, q = n - 1, k = 1;
    while (p <= q) {
        for (i = p; i <= q; i++) a[p][i] = k++;
        for (i = p + 1; i <= q; i++) a[i][q] = k++;
        for (i = q - 1; i >= p; i--) a[q][i] = k++;
        for (i = q - 1; i > p; i--) a[i][p] = k++;
        p++;
        q--;
    }
}

void afisare(int a[20][20], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

int main() {
    int x[20][20], n;
    cout << "n=";
    cin >> n;
    generare(x, n);
    afisare(x, n);
    return 0;
}
```

### 4. Eliminare nr prime din vector 

```c++
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
//Se da un sir de nr naturale >=1. Sa se elimine din sir numerele prime.

int prim(int n) {
    int d;
    if (n == 1) return 1;
    for (d = 2; d * d <= n; d++)
        if (n % d == 0) return 0;
    return 1;
}

int main() {
    int i, k = 0;
    int v[100], n;
    f >> n;
    for (i = 0; i < n; i++)
        f >> v[i];
    for (i = 0; i < n; i++) {
        if (prim(v[i]) == 0) {
            v[k] = v[i];
            k++;
        }
    }
    n = k;
    for (i = 0; i < n; i++)
        cout << v[i] << ",";
    return 0;
}
```

