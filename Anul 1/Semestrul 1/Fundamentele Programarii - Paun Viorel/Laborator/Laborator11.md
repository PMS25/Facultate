 # Laborator11

### Secvenţa de sumă maximă

```c++
#include <iostream>
using namespace std;
//Se da un vector cu n elemente nr intregi.
//Determinati o secventa de nr
//consecutive (ca pozitie in vector) de suma maxima

int SumMax(int a[], int n, int & p, int & u) {
    int i, s, smax = a[0];
    s = a[0];
    p = 0;
    u = 0;
    int i0 = 0;
    for (i = 1; i < n; i++) {
        if (s <= 0) {
            s = 0;
            i0 = i;
        }
        s += a[i];
        if (s >= smax) {
            smax = s;
            p = i0;
            u = i;
        }
    }
    return smax;
}

int main() {
    int a[8] = {-2, -1, 3, 3, -1, 2, -6, -5}, n = 8, p, u;
    int S = SumMax(a, n, p, u);
    cout << S << " p=" << p << " u=" << u << endl;
    return 0;
}
```

