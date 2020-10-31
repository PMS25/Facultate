# Explicaţie - Non-synchronized Threads
## Petculescu Mihai-Silviu

- [Explicaţie - Non-synchronized Threads](#explicaţie---non-synchronized-threads)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [1. Se obţine acelaşi rezultat la fiecare executare? Explicaţi.](#1-se-obţine-acelaşi-rezultat-la-fiecare-executare-explicaţi)
    - [2. Care este rolul instructiunii `while(t1.isAlive() || t2.isAlive()){}`](#2-care-este-rolul-instructiunii-whilet1isalive--t2isalive)

### 1. Se obţine acelaşi rezultat la fiecare executare? Explicaţi.

**Rezultat**
```bash
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111112222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
```
**Sau 100 de 1 urmaţi de 100 de 2**

În teorie şi în mare parte din cazurile practice se va obţine acelaşi rezultat, dar nu este garantat. Această execuţie are la bază două variabile, prima reprezentând timpul pe procesor disponibil la rurarea programului, iar a doua reprezentând intervalul de timp dintre execuţia primului thread şi execuţia celui de-al doilea şi asumbţia că operaţia pe care pe care o au de implementat se încadrează în acel interval de timp.

Ţinând cont de natura sarcinii, afişarea pe consolă a unei valori de 100 de ori, este suficient de probabil ca thredul `t1` să termine înaintea thredului `t2` în situaţiile în care timpul pe procesor este suficient pentru operaţiunea indicată, iar, în caz contral, se vor produce intercalări între cele două threduri la afişare. Dacă, să zicem, creşţem numarul de afişări de la 100 la 10000, cel din urmă comportament devine cel mai probabil.

### 2. Care este rolul instructiunii `while(t1.isAlive() || t2.isAlive()){}`

Deoarece sarcina programului a fost delegată de la thredul principal (cel de pe care se execută funcţia `main()`) la unele auxiliare, există întotdeauna riscul ca acesta să se finalizeze înainte ca thredurile adiacent adăugate să-şi finalizeze operaţiunea, rezultând de la lipsă unor porţiuni de informaţie axişată, la zone de memorie rămase alocate chiar şi după finalizarea programului iniţial (sarcină de care poate sau nu să aibă grijă JVM-ul, dar în acest caz ne-am raporta la o proastă implementare a codului - căci să fim raţionali, nu este de datoria sistemului să cureţe zone de momerie adiţionale, după ce, în prealabil, a eliminat spaţiul alocat programului care le-a generat în primul rând).

Linia `while(t1.isAlive() || t2.isAlive()){}` se asigură că funcţia `main()` este activă pe durata operaţiunii, astfel fiind disponibilă pentru a prelua informaţia procesată de threduri.
