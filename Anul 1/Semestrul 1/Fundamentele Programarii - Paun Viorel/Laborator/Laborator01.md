# Laborator01

```c++
//Sa se citeasca de la tastatura doua numere si sa se afiseze suma lor
#include <iostream>
using namespace std;

int main() {
    int a, b, s;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    s = a + b;
    cout << a << "+" << b << "=" << s << endl;

    if (a > b) cout << "max(" << a << "," << b << ")=" << a << endl;
    else cout << "max(" << a << "," << b << ")=" << b << endl;

    return 0;
}

// -----------------------------------------------------------------
// -Se citesc 3 nr intregi de la tastatura. Sa se determine maximul lor
#include <iostream>
using namespace std;

int main() {
    int a, b, c, max;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "c=";
    cin >> c;
    if (a > b) max = a;
    else max = b;
    if (c > max) max = c;
    cout << "max(" << a << "," << b << "," << c << ")=" << max << endl;
    return 0;
}

//----------------------------------------------------------
//ordonarea crescatoare a 3 nr
#include <iostream>
using namespace std;

int main() {
    int a, b, c, aux;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "c=";
    cin >> c;
    if (a > b) {
        aux = a;
        a = b;
        b = aux;
    }
    if (a > c) {
        aux = a;
        a = c;
        c = aux;
    }
    if (b > c) {
        aux = b;
        b = c;
        c = aux;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}

//-------------------------------------------------------------------
//se dau 5 note, nota minima si nota maxima se exclud. Sa se calculeze media  celorlalte 3.
#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3, n4, n5, max, min;
    float m;
    cout << "Tastati cele 5 note:";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    min = n1;
    if (n2 < min) min = n2;
    if (n3 < min) min = n3;
    if (n4 < min) min = n4;
    if (n5 < min) min = n5;
    max = n1;
    if (n2 > max) max = n2;
    if (n3 > max) max = n3;
    if (n4 > max) max = n4;
    if (n5 > max) max = n5;
    m = (n1 + n2 + n3 + n4 + n5 - min - max) / 3.0;
    cout << "Media=" << m << endl;
    return 0;
}
```

