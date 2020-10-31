# Curs10

- [Curs10](#curs10)
    - [1. Calculul ariei unui poligon cu n laturi](#1-calculul-ariei-unui-poligon-cu-n-laturi)
    - [2. Structuri liniare de tip stivă](#2-structuri-liniare-de-tip-stivă)
    - [3. Structuri de tip coada](#3-structuri-de-tip-coada)

### 1. Calculul ariei unui poligon cu n laturi

Calculul ariei unui poligon cu n laturi, n>=3, când se cunosc coordonatele rectangulare ale vârfurilor poligonului (xi,yi), i=1,2,...,n utilizând formula: A=| (x1+x2)(y1-y2)+(x2+x3)(y2-y3)+...+(xn+x1)(yn-y1) |/2, şi determinarea coordonatelor centrului de greutate al poligonului.

```c++
#include <iostream>

#include<cmath>

using namespace std;
struct punct {
    double x;
    double y;
};

double arie(punct P[], int n) {
    double S = (P[n - 1].x - P[0].x) * (P[n - 1].y + P[0].y);
    for (int i = 0; i < n - 1; i++)
        S += (P[i].x - P[i + 1].x) * (P[i].y + P[i + 1].y);
    return abs(S) / 2;
}

punct centruDeGreutate(punct P[], int n) {
    punct G = {0,0};
    for (int i = 0; i < n; i++) {
        G.x += P[i].x;
        G.y += P[i].y;
    }
    G.x /= n;
    G.y /= n;
    return G;
}

int main() {
    punct P[3]={{10,10},{37,10},{10,51}};
    cout << "aria=" << arie(P, 3);
    punct G = centruDeGreutate(P, 3);
    cout << "   G(" << G.x << "," << G.y << ")";
    return 0;
}
```

### 2. Structuri liniare de tip stivă

```c++
#include <iostream>
using namespace std;
/*
Structuri liliare de tip lista
*/

struct nod {
    int inf;
    nod * leg;
};

void inserare(nod * & cap, int x) {
    nod * p = new nod;
    p -> inf = x;
    p -> leg = cap;
    cap = p;
}

int extragere(nod * & cap) {
    int x = ( * cap).inf;
    nod * p = cap;
    cap = cap -> leg;
    delete p;
    return x;
}

void listare(nod * cap) {
    while (cap != 0) {
        cout << cap -> inf << " ";
        cap = cap -> leg;
    }
}

int main() {
    nod * S = 0;
    int op, x;
    do {
        cout << " 1- inserare" << endl;
        cout << " 2- extragere" << endl;
        cout << " 3- listare" << endl;
        cout << " 9- iesire" << endl;
        cout << "Tastati optiunea";
        cin >> op;
        switch (op) {
        case 1:
            cout << " informatia=";
            cin >> x;
            inserare(S, x);
            break;
        case 2:
            if (S != 0)
                cout << " am extras inf:" <<
                extragere(S) << endl;
            else cout << "Stiva vida" << endl;
            break;
        case 3:
            listare(S);
            cout << endl;
            break;

        case 9:
            return 0;
        }
    }while (1);
    return 0;
}
```

### 3. Structuri de tip coada

```c++
#include <iostream>
using namespace std;
/*
Definirea structurilor utilizator de tip coada
*/

struct nod {
    int inf;
    nod * leg;
};

void inserare(nod * & prim, nod * & ultim, int x) {
    if (prim == 0) {
        prim = ultim = new nod;
    } else
        ultim = ultim -> leg = new nod;
    ultim -> inf = x;
    ultim -> leg = 0;
}

int extragere(nod * & prim) {
    nod * p = prim;
    int x = prim -> inf;
    prim = prim -> leg;
    delete p;
    return x;
}

void listare(nod * prim) {
    while (prim != 0) {
        cout << prim -> inf << " ";
        prim = prim -> leg;
    }
}

int main() {
    nod * prim = 0, * ultim;
    int op, x;
    while (1) {
        cout << " 1- inserare" << endl;
        cout << " 2- extragere" << endl;
        cout << " 3- listare" << endl;
        cout << " 9- iesire" << endl;
        cout << "Tastati optiunea";
        cin >> op;
        switch (op) {
        case 1:
            cout << " informatia=";
            cin >> x;
            inserare(prim, ultim, x);
            break;
        case 2:
            if (prim != 0)
                cout << " am extras inf:" <<
                extragere(prim) << endl;
            else cout << "coada vida" << endl;

            break;
        case 3:
            listare(prim);
            cout << endl;
            break;

        case 9:
            return 0;
        }
    }
}
```