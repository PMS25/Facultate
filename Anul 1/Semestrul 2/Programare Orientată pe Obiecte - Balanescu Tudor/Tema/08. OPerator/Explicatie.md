# Explicaţie - Operator
## Petculescu Mihai-Silviu

- [Explicaţie - Operator](#explicaţie---operator)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [1. În programul următor, supradefiniţi operatorul `<<` astfel încat `cout<<i` să afişeze valoarea atributului `i.x`. Precizaţi şi explicaţi rezultatele afişate la executarea programului astfel obţinut.](#1-în-programul-următor-supradefiniţi-operatorul--astfel-încat-couti-să-afişeze-valoarea-atributului-ix-precizaţi-şi-explicaţi-rezultatele-afişate-la-executarea-programului-astfel-obţinut)

### 1. În programul următor, supradefiniţi operatorul `<<` astfel încat `cout<<i` să afişeze valoarea atributului `i.x`. Precizaţi şi explicaţi rezultatele afişate la executarea programului astfel obţinut.

**Rezultat**
```bash
0
2
2
0
1
```

Clasa C supraîncarcă operatorii unari de stânga, `++` şi `--`, cu diferenţa ca pentru `operator++()` returnează adresa instanţei cu referinţă `C&`, în vreme ce `operator--()` returnează doar pointerul. 

În `main()` creăm o instanţă a clasei `C` alocată variabilei `i`, apoi îi afişam valoarea, prin supraîncărcarea operatorului `<<`, care by default este 0.

Linia `cout<<++(++i)<<endl<<i<<endl;` inclementează valoarea lui i cu două unităţi, înainte de a fi accesată de operatorul `<<`, astfel la final se afişează de două ori valoarea 2.

Linia `cout<<--(--i)<<endl<<i<<endl;` are în mare, aceeaşi exect ca şi linia anterioară, cu precizările ca în cazul acesteia valoarea variabilei i descreşte. Tutuşi, la final se afişează, cum se poate observa mai sus 0 urmat cu 1, asta deoarece operatorul nu returnează variabila prin referinţă, astfel doar una dintre scăderi este înregistrată de i.

Footnote: Pentru a difereţia operatorii unari plasaţi la începutul unei variabile cu cei plasaţi la finalul aceleiaşi variabile, C++ foloseşte ca diferenţiator un parametru formal de tip `int`. Astfel funcţia `operator++()` va supraîncărca operatorul `++x`, în vreme ce `operator++(int)` va supraîncărca operatorul `x++`. Analog pentru `--`.
