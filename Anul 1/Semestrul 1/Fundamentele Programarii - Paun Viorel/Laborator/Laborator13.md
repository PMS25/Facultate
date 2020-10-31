# Laborator13

- [Laborator13](#laborator13)
    - [1. Numar vocale](#1-numar-vocale)
    - [2. Anagrame](#2-anagrame)
    - [3. Eliminare vocale](#3-eliminare-vocale)
    - [4. ReverseWords](#4-reversewords)
    - [5. Sume în matrice pătratică](#5-sume-în-matrice-pătratică)

### 1. Numar vocale

```c++
#include <iostream>
#include <string.h>
using namespace std;
/* sa se scrie o functie care determina numarul de vocale dintr un
text transmis ca parametru*/

int nr_voc(char s[]) {
    int i;
    char v[11] = "aeiouAEIOU";
    int nr = 0;
    for (i = 0; i < strlen(s); i++)
        if (strchr(v, s[i]) != 0) nr++;
    return nr;
}

int nr_voc_r(char s[]) {
    static char v[11] = "aeiouAEIOU";
    if (s[0] == 0) return 0;
    if (strchr(v, s[0]) != 0) return 1 + nr_voc_r(s + 1);
    return nr_voc_r(s + 1);
}

int main() {
    char s[100];
    cout << "s=";
    cin.getline(s, 99, '\n');
    cout << "Textul contine " << nr_voc(s) << " vocale" << endl;
    cout << "Metoda recursiva:" << nr_voc_r(s);
}
```

### 2. Anagrame

```c++
/*Sa se scrie o fct cu 2 parametrii siruri de caractere
care sa verifice daca sunt anagrame*/
#include <iostream>
#include <string.h>
using namespace std;

int anagrame1(char a[], char b[]) {
    int v[256] = {0};
    for (int i = 0; i < strlen(a); i++)
        v[a[i]]++;
    for (int i = 0; i < strlen(b); i++)
        if (v[b[i]] == 0) return 0;
        else v[b[i]]--;
    for (int i = 0; i < 256; i++)
        if (v[i] != 0) return 0;
    return 1;
}

int anagrame2(char * a, char * b) {
    int i, j;
    char * c = new char[strlen(b)];
    strcpy(c, b);
    char * p;
    for (i = 0; i < strlen(a); i++) {
        p = strchr(c, a[i]);
        if (p == 0) return 0;
        * p = c[strlen(c) - 1];
        c[strlen(c) - 1] = 0;
    }
    return c[0] == 0;
}

int main() {
    char a[100], b[100];
    cout << "a=";
    cin.getline(a, 100);
    cout << "b=";
    cin.getline(b, 100);

    cout << "anagrame1 ";
    if (anagrame1(a, b)) cout << "Sunt anagrame";
    else cout << "Nu sunt anagrame";

    cout << "anagrame2 ";
    if (anagrame2(a, b)) cout << "Sunt anagrame";
    else cout << "Nu sunt anagrame";
}
```

### 3. Eliminare vocale

```c++
#include <iostream>
#include <string.h>
using namespace std;
/// sa se elimine vocale dintr un text

//Metoda 1
void elimvoc(char s[]) {
    char v[11] = "aeiouAEIOU";
    int i;
    for (i = strlen(s) - 1; i > 0; i--)
        if (strchr(v, s[i])) strcpy(s + i, s + i + 1);

}

//Metoda 2-a
char * eliminareVocale(char * s) {
    char v[11] = "aeiouAEIOU";
    char * p;
    for (int i = 0; i < 10; i++) {
        p = strrchr(s, v[i]);
        while (p != 0) {
            strcpy(p, p + 1);
            p = strrchr(s, v[i]);
        }
    }
    return s;
}

int main() {
    char s[100];
    cout << "tastati textul:";
    cin.getline(s, 100);
    cout << "dupa eliminare vocale: " << eliminareVocale(s);
    return 0;
}
```

### 4. ReverseWords

```c++
#include <iostream>
#include <string.h>
using namespace std;
/*scrieti functia reverseWords (char s[]) care primeste ca parametru
un sir format din cuvinte separate prin cate un spatiu
si returneaza tot prin intermediul parametrului s cuvintele
in ordine inversa
ana are mere si pere
=> pere si mere are ana
*/

void reverseWords(char * s) {
    int n = strlen(s);
    char * s1 = new char[n];
    strcpy(s1, s);
    char * p;
    p = strtok(s1, " ");
    while (p != 0) {
        for (int i = strlen(p) - 1; i >= 0; i--)
            s[--n] = p[i];
        if (n > 0) s[--n] = ' ';
        p = strtok(NULL, " ");
    }
}

int main() {
    char s[100];
    cout << "tastati textul:";
    cin.getline(s, 100);
    reverseWords(s);
    cout << s << endl;
    return 0;
}
```

### 5. Sume în matrice pătratică

```c++
#include <iostream>
using namespace std;

int sumalinie(int a[10][10], int n, int l) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s = s + a[l][i];
    return s;
}

int sumacoloana(int a[10][10], int n, int k) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s = s + a[i][k];
    return s;
}

void Citire(int a[10][10], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        cout << "linia " << i << "=";
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    }
}

int main() {
    int a[10][10], n, l, k;
    cout << "n=";
    cin >> n;
    Citire(a, n);
    cout << "l,k=";
    cin >> l >> k;
    cout << "suma liniei " << l << "=" << sumalinie(a, n, l) << endl;
    cout << "suma coloana " << k << "=" << sumacoloana(a, n, k) << endl;
    return 0;
}
```

