# Laborator02

## Petculescu Mihai-Silviu

[TOC]

## Aplicaţia 1.

Se consideră următoarea bază de cunoştinţe cu informaţii privind anumite firme şi produsele distribuite.

- Magic srl vinde calculatoare şi accesorii.
- Alfa sa vinde televizoareşi calculatoare
- Beta sa vinde accesorii.

### Cerinţe

### SWI-Prolog

```apl
vinde(magicsrl,calculatoare).
vinde(magicsrl,accesorii).
vinde(alfasa,calculatoare).
vinde(alfasa,televizoare).
vinde(betasa,accesorii).
```

### A. Vinde AlfaSA calculatoare?

```apl
?- vinde(alfasa,calculatoare).
true.
```

### B. Vinde BetaSA televizoare?

```apl
?- vinde(betasa,televizoare).
false.
```

### C. Ce vinde MagicSRL?

```apl
?- vinde(magicsrl,X).
X = calculatoare ;
X = accesorii.
```

### D. Cine vinde calculatoare?

```apl
?- vinde(Y,calculatoare).
Y = magicsrl ;
Y = alfasa.
```

### E. Vinde AlfaSA ceva?

```apl
?- vinde(alfasa,_).
true.
```

### F. Vinde cineva accesorii?

```apl
?- vinde(_, accesorii).
true.
```

### G. Cine vinde la fel ca BetaSA un anumit produs?

```apl
?- vinde(betasa,X), vinde(Y,X), Y='betasa'.
X = accesorii,
Y = betasa.
```

### H. Cine vinde ce?

```apl
?- vinde(X,Y).
X = magicsrl,
Y = calculatoare ;
X = magicsrl,
Y = accesorii ;
X = alfasa,
Y = calculatoare ;
X = alfasa,
Y = televizoare ;
X = betasa,
Y = accesorii.
```

### I. Vinde cineva ceva?

```apl
?- vinde(_,_).
true.
```


## Aplicaţia 2.

Se consideră următoarea bază de cunoştinţe cu informaţii privind anumite persoane şi produsele distribuite.

- Alex vinde trandafiri, lalele şi crizanteme.
- Ana vinde lalele şi crini.
- Andu vinde lalele şi nuci.

### Cerinţe

### SWI-Prolog

```apl
vinde(alex, trandafiri).
vinde(alex, lalele).
vinde(alex, crizanteme).
vinde(ana, lalele).
vinde(ana, crini).
vinde(andu, lalele).
vinde(andu, nuci).
floare(X):- not(X = 'nuci').
```

### 1. Vinde Andrei lalele?

```apl
?- vinde(andrei,lalele).
false.
```

### 2. Cine vinde crizanteme?

```apl
?- vinde(X,crizanteme).
X = alex.
```

### 3. Ce vinde Ana?

```apl
?- vinde(ana,Y).
Y = lalele;
Y = crini.
```

### 4. Vinde cineva crini?

```apl
?- vinde(_,crini).
true.
```

### 5. Vinde Andu ceva?

```apl
?- vinde(andu,_).
true.
```

### 6. Cine vinde la fel ca Alex un anumit produs?

```apl
?- vinde(alex,X), vinde(Y,X), Y\='alex'.
X = lalele,
Y = ana ;
X = lalele,
Y = andu ;
false.
```

### 7. Ce vinde Andu şi nu este floare?

```apl
?- vinde(andu,Y), not(floare(Y)).
Y = nuci.
```


## Prelucrări Aritmetice 

### Aplicaţia 1.

Să se calculeze media aritmetică a două valori reale.

**SWI-Prolog**:

```apl
media_aritmetica(A,B,M_aritmetica):- M_aritmetica is (A+B)/2.
```

**Execuţie**:

```apl
?- media_aritmetica(40, 34, Media).
Media = 37.
```

### Aplicaţia 1'.

Să se calculeze media aritmetică a două valori reale, respectiv, media armonica.

**SWI-Prolog**:

```apl
media_aritmetica(A,B,M_aritmetica):- M_aritmetica is (A+B)/2.
media_armonica(A,B,M_armonica):- A \= 0, B \= 0, M_armonica is 2/(1/A + 1/B).
```

**Execuţie**:

```apl
?- media_aritmetica(40, 34, Media).
Media = 37.
?- media_armonica(40, 34, M).
M = 36.75675675675676.
```

### Aplicaţia 2.

Să se determine maximul/minimul a două valori reale.

**SWI-Prolog**:

```apl
maxim(A,B,A):- A>=B.
maxim(A,B,B):- A<B.
minim(A,B,B):- A>=B.
minim(A,B,A):- A<B.
```

**Execuţie**:

```apl
?- maxim(40, 34, Max).
Max = 40 .
?- minim(40, 34, Min).
Min = 34 .
?- minim(21, -4, Min).
Min = -4 .
```

### Aplicaţia 3.

Să se determine maximul/minimul a trei valori reale.

**SWI-Prolog**:

```apl
/* Aplicatia 2 */
maxim(A,B,A):- A>=B.
maxim(A,B,B):- A<B.
minim(A,B,B):- A>=B.
minim(A,B,A):- A<B.
/* Aplicatia 3 */
maxim3(A,B,C,Max3):- maxim(A,B,R), maxim(R,C,Max3).
minim3(A,B,C,Min3):- minim(A,B,R), minim(R,C,Min3).
```

**Execuţie**:

```apl
?- maxim3(40, 34, 12, Max).
Max = 40 .
?- minim3(21, -4, 2, Min).
Min = -4 .
```

### Aplicaţia 4.

Să se determine maximul/minimul a două valori reale. **V2 - Prin utilizarea operatorului `CUT !`**

**Observaţie**: Operatorul `CUT !` are rolul de a exclude anumite ramuri de căutare în spaţiul soluţilor în cadrul procesului de backtracking recursiv.

**SWI-Prolog**:

```apl
maxim(A, B, A):- A>=B, !.
maxim(A, B, B).
minim(A, B, B):- A>=B, !.
minim(A, B, A).
```

**Execuţie**:

```apl
?- maxim(40, 34, Max).
Max = 40 .
?- minim(21, -4, Min).
Min = -4 .
```

### Aplicaţia 5.

Să se determine valoarea funcţiei:
$$
\begin{align*}
& f(x,y) = x+y-2,\ daca\ x>-1,\ y<1\\
& f(x,y) = x-y,\ in\ rest
\end{align*}
$$
**SWI-Prolog**:

```apl
functie_f(X,Y,Rez):- X>(-1), Y<1, Rez is X+Y-2, !.
functie_f(X,Y,Rez):- Rez is X-Y.
```

**Execuţie**:

```apl
/* x>-1 & y<1 */
?- functie_f(4,-7,Rez).
Rez = -5.
/* x<-1 & y<1 */
?- functie_f(-3,-7,Rez).
Rez = 4.
/* x>-1 & y>1 */
?- functie_f(1,10,Rez).
Rez = -9.
```

