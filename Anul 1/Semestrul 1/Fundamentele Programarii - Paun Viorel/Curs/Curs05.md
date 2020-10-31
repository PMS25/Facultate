# Curs05

- [Curs05](#curs05)
    - [1. Variabile automatice şi statice](#1-variabile-automatice-şi-statice)
    - [2. Instrucţiunea `vidă` (copiere şir de caractere)](#2-instrucţiunea-vidă-copiere-şir-de-caractere)
    - [3. Instrucţiunea `switch`](#3-instrucţiunea-switch)
    - [4. Instrucţiunea `goto`](#4-instrucţiunea-goto)

### 1. Variabile automatice şi statice

```c++
#include <iostream>
using namespace std;

int incrementare() {
    int a = 10;
    static int b = 100;
    a++;
    b++;
    cout << "a=" << a << "  b=" << b << endl;
}

int main() {
    incrementare();
    incrementare();
    incrementare();

    return 0;
}
```

### 2. Instrucţiunea `vidă` (copiere şir de caractere)

```c++
#include <iostream>
using namespace std;

void strcpy(char s1[], char s2[]){ //Copiaza sirul s2 in s1
    int i = 0;
    while (s1[i] = s2[i++]);
}

int main() {
    char a[100], b[100];
    cout << "a=";
    cin.getline(a, 99, '\n');
    strcpy(b, a);
    cout << "b=" << b << endl;
    return 0;
}
```

### 3. Instrucţiunea `switch`

```c++
#include <iostream>
#include <cstring> //<string.h>
using namespace std;

int main() {
    char s[1000];
    cout << "tastati sirul de caractere:";
    cin.getline(s, 999, '\n');
    int na, ne, ni, no, nu, altele, i;
    na = ne = ni = no = nu = altele = 0;
    for (i = 0; i < strlen(s); i++)
        switch (tolower(s[i])) {
        case 'a':
            na++; break;
        case 'e':
            ne++; break;
        case 'i':
            ni++; break;
        case 'o':
            no++; break;
        case 'u':
            nu++; break;
        default:
            altele++;
        }
    cout << " a->" << na << " e->" << ne << " i->" << ni <<
        " o->" << no << " u->" << nu << " altele->" << altele << endl;
    return 0;
}
```

### 4. Instrucţiunea `goto`

```c++
#include <iostream>
#include<fstream>
#include<cmath>
#include<stdlib.h>
using namespace std;

int main() {
    ifstream f("date.in");
    int a[10][10], m, n, i, j;
    float r;
    f >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            f >> a[i][j];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
            r = sqrt(a[i][j]);
            if (r == (int) r) goto afisare;
        }
    i = -1;
    afisare: if (i >= 0) cout << "i=" << i << " j=" << j << endl;
        else cout << "matricea nu contine patrate perfecte";
    return 0;
}
```
