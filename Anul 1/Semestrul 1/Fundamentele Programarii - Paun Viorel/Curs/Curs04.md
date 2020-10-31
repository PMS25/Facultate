# Curs04

- [Curs04](#curs04)
    - [Inversarea elementelor unui vector de numere intregi](#inversarea-elementelor-unui-vector-de-numere-intregi)

### Inversarea elementelor unui vector de numere intregi

```c++
#include <iostream>

using namespace std;

int main() {
    int x[100], n;
    int i, j;
    cout << "n=";
    cin >> n;
    cout << "tastati " << n << " nr intregi:";
    for (i = 0; i < n; i++) cin >> x[i];

    /* // varianta cu while
     i=0;
     j=n-1;
     while(i<j)
     {
         int aux=x[i];
         x[i]=x[j];
         x[j]=aux;
         i++;
         j--;
     }
     */

    // varianta cu for
    for (i = 0, j = n - 1; i < j; i++, j--) {
        int aux = x[i];
        x[i] = x[j];
        x[j] = aux;
    }
    cout << "vectorul inversat:";
    for (i = 0; i < n; i++) cout << x[i] << " ";
    return 0;
}
```
