# Laborator02

```c++
//Suma a doua unghiuri exprimate in grade, minute si secunde
#include <iostream>
using namespace std;
/*
40g 50m 25s+
70g 20m 35s
-------------
111g 11m 0s
*/

int main() {
    int g1, m1, s1;
    int g2, m2, s2;
    int g, m, s;
    int t;
    cout << "U1(g,m,s)=";
    cin >> g1 >> m1 >> s1;
    cout << "U2(g,m,s)=";
    cin >> g2 >> m2 >> s2;
    s = s1 + s2;
    if (s >= 60) {
        s = s - 60;
        t = 1;
    } else t = 0;
    m = m1 + m2 + t;
    if (m >= 60) {
        m = m - 60;
        t = 1;
    } else t = 0;
    g = g1 + g2 + t;
    if (g >= 360) g = g - 360;
    cout << g1 << "g " << m1 << "m " << s1 << "s +" <<
        g2 << "g " << m2 << "m " << s2 << "s =" <<
        g << "g " << m << "m " << s << "s ";
    return 0;
}

// Varianta a II-a
#include <iostream>
using namespace std;

int main() {
    int g1, m1, s1;
    int g2, m2, s2;
    int g, m, s;
    int t;
    cout << "U1(g,m,s)=";
    cin >> g1 >> m1 >> s1;
    cout << "U2(g,m,s)=";
    cin >> g2 >> m2 >> s2;
    /*
    45g 50m 10s+340g 40m 20s=
    */
    s = s1 + s2;
    t = s / 60;
    s = s % 60;
    m = m1 + m2 + t;
    t = m / 60;
    m = m % 60;
    g = g1 + g2 + t;
    g = g % 360;
    cout << g1 << "g " << m1 << "m " << s1 << "s +" <<
        g2 << "g " << m2 << "m " << s2 << "s =" <<
        g << "g " << m << "m " << s << "s ";
    return 0;
}

//Suma cifrelor unui numar natural
#include <iostream>
using namespace std;
/*
n=237
s=0
c=n%10=7
s=s+c=7
n=n/10=23
c=n%10=3
s=s+c=10
n=n%10=2
c=n%10=2
s=s+c=12
n=n/10=0
*/

int main() {
    int n, aux, s, c;
    cout << "Introduceti numarul n: ";
    cin >> n;
    aux = n;
    s = 0;
    while (aux > 0) {
        c = aux % 10;
        s = s + c;
        aux = aux / 10;
    }
    cout << "Suma cifrelor numarului " << n << " este: " << s;
    return 0;
}

/*program care verifica daca cifrele unui nr
sunt in ordine crescatoare (nu strict crescatoare)
*/
#include <iostream>
using namespace std;
/*
n=235568
8>=6>=5>=5>=3>=2
Ok=1
n=25649
9>=4>=6(F)
ok=0
*/

int main() {
    int n, ok, c1, c2, aux;
    cout << "n=";
    cin >> n;
    aux = n;
    c2 = 10;
    ok = 1;
    while (aux > 0) {
        c1 = aux % 10;
        if (c1 > c2) {
            ok = 0;
            break;
        }
        c2 = c1;
        aux = aux / 10;
    }
    if (ok) {
        cout << "Este in ordine crescatoare" << endl;
    } else cout << "Nu este in ordine crescatoare";
    return 0;
}

/*
Fie n un nr natural.
Sa se determine k altfel incat k!=1*2*...*k sa fie cel mai apropiat de n
*/
#include <iostream>
/*
n=80
k=1,p=1
k=2,p=p*2=2
k=3=>p=p*3=6
k=4,p=p*4=24
k=5,p=p*5=120>=n
pa=p/k=24
Comparam pe n-pa cu p-n
*/
using namespace std;

int main() {
    int n, k, p, pa;
    cout << "n=";
    cin >> n;
    k = 1;
    p = 1;
    while (p < n){
        k++;
        p = p * k;
    }
    pa = p / k;
    if (n - pa <= p - n) k--;
    cout << "k=" << k;
    return 0;
}
```

