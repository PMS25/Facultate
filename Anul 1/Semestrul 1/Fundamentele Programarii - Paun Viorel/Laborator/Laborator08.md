# Laborator08

- [Laborator08](#laborator08)
    - [Varianta1](#varianta1)
    - [Varianta2](#varianta2)

### Varianta1

```c++
#include <iostream>
using namespace std;

int maxDim = 100;
void citire(int * & a, int & n) {
    a = new int[maxDim];
    cout << "Dimensiunea multimii: ";
    cin >> n;
    cout << "Tastati " << n << " elemente: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void afisare(int * a, int n) {
    cout << "{";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "}";
}

void intersectie(int * a, int m, int * b, int n, int * & c, int & p) {
    p = 0;
    c = new int[maxDim];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i] == b[j]) {
                c[p++] = a[i];
                break;
            }
}

void reuniune(int * a, int m, int * b, int n, int * & c, int & p) {
    c = new int[maxDim];
    for (int i = 0; i < m; i++)
        c[i] = a[i];
    p = m;
    int ok;
    for (int j = 0; j < n; j++) {
        ok = 0;
        for (int i = 0; i < m; i++)
            if (b[j] == a[i]) {
                ok = 1;
                break;
            }
        if (!ok)
            c[p++] = b[j];
    }
}

void diferenta(int * a, int m, int * b, int n, int * & c, int & p) {
    c = new int[maxDim];
    int ok;
    p = 0;
    for (int i = 0; i < m; i++) {
        ok = 0;
        for (int j = 0; j < n; j++)
            if (a[i] == b[j]) {
                ok = 1;
                break;
            }
        if (!ok) c[p++] = a[i];
    }
}

void eliminareDubluri(int * a, int & m) {
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            if (a[i] == a[j]) a[j--] = a[--m];
}

int main() {
    int * a = 0, * b = 0, * c = 0, m, n, p;
    cout<<"Multimea A: "<<endl; citire(a,m);
    eliminareDubluri(a, m);
    afisare(a, m);
    cout<<endl<<"Multimea B: "<<endl; citire(b,n); afisare(b,n);
    cout << endl;
    
    intersectie(a, m, b, n, c, p);
    afisare(a, m); cout << "*";
    afisare(b, n); cout << "=";
    afisare(c, p); cout << endl;
    delete[] c;
    
    reuniune(a, m, b, n, c, p);
    afisare(a, m); cout << "U";
    afisare(b, n); cout << "=";
    afisare(c, p); cout << endl;
    delete[] c;
    
    diferenta(a, m, b, n, c, p);
    afisare(a, m); cout << "-";
    afisare(b, n); cout << "=";
    afisare(c, p);
    delete c;
    return 0;
}
```

### Varianta2

```c++
#include <iostream>
using namespace std;

int maxDim = 100;
void citire(int * & a, int & n) {
    a = new int[maxDim];
    cout << "Dimensiunea multimii: ";
    cin >> n;
    cout << "Tastati " << n << " elemente: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void afisare(int * a, int n) {
    cout << "{";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "}";
}

void eliminareDubluri(int * a, int & m) {
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            if (a[i] == a[j]) a[j--] = a[--m];
}

int apartine(int x, int * a, int n) {
    for (int i = 0; i < n; i++)
        if (x == a[i]) return 1;
    return 0;
}

inline void adauga(int x, int * a, int & n) {
    a[n++] = x;
}

void intersectie(int * a, int m, int * b, int n, int * & c, int & p) {
    c = new int[maxDim];
    p = 0;
    for (int i = 0; i < m; i++)
        if (apartine(a[i], b, n)) adauga(a[i], c, p);
}

void reuniune(int * a, int m, int * b, int n, int * & c, int & p) {
    c = new int[maxDim];
    for (int i = 0; i < m; i++)
        adauga(a[i], c, p);
    for (int i = 0; i < n; i++)
        if (!apartine(b[i], a, m)) adauga(b[i], c, p);
}

void diferenta(int * a, int m, int * b, int n, int * & c, int & p) {
    c = new int[maxDim];
    for (int i = 0; i < m; i++)
        if (!apartine(a[i], b, n)) adauga(a[i], c, p);
}

inline int vida(int * a, int m) {
    return m == 0;
}

inline int plina(int * a, int m) {
    return m == maxDim;
}

int main() {
    int * a = 0, * b = 0, * c = 0, m, n, p;
    cout<<"Multimea A: "<<endl; citire(a,m);
    eliminareDubluri(a, m);
    afisare(a, m);
    cout<<endl<<"Multimea B: "<<endl; citire(b,n); afisare(b,n);
    cout << endl;
    
    intersectie(a, m, b, n, c, p);
    afisare(a, m); cout << "*";
    afisare(b, n); cout << "=";
    afisare(c, p); cout << endl;
    delete[] c;
    
    reuniune(a, m, b, n, c, p);
    afisare(a, m); cout << "U";
    afisare(b, n); cout << "=";
    afisare(c, p); cout << endl;
    delete[] c;
    
    diferenta(a, m, b, n, c, p);
    afisare(a, m); cout << "-";
    afisare(b, n); cout << "=";
    afisare(c, p);
    delete c;
    return 0;
}
```

