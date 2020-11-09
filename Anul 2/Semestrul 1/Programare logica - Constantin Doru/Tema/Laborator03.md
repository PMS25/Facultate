# Laborator03

## Petculescu Mihai-Silviu

[TOC]

## Aplicaţii

### Aplicaţia 6.

Să se determine valoarea expresiei $E(x,y) = f(x,y) + 3 \cdot g(x,y)$, unde $f(x,y) = x + y - 2$, dacă $x>-1$, $y < 1$ și  $f(x,y) = x - y$, în rest, iar $g(x,y) = x^2 - y^2$.

**SWI-Prolog**:

```apl
f(X,Y,F):- X>(-1), Y<1, F is X+Y-2, !.
f(X,Y,F):- F is X-Y.
g(X,Y,R):- R is X*X-Y*Y.
expresie(X,Y,R):- f(X,Y,R1), g(X,Y,R2), R is R1+3*R2.
```

**Execuţie**:

```apl
?- expresie(3,-2,Rez).
Rez = 14.
```

### Aplicaţia 7.

Să se determine `CMMDC` și `CMMMC` pentru două numere întregi.

**Observație**:
$$
\begin{align*}
& (X,Y) = (Y, X\ mod\ Y);\\
& (X,Y) \cdot [X,Y] = X \cdot Y\\
& [X,Y] = (X \cdot Y) / (X,Y)
\end{align*}
$$

**SWI-Prolog**:

```apl
cmmdc(X,Y,Y):- mod(X,Y) =:= 0, !.
cmmdc(X,Y,D):- R is X mod Y, cmmdc(Y,R,D).
cmmmc(X,Y,M):- cmmdc(X,Y,D), M is (X*Y)/D.
```

**Execuţie**:

```apl
?- cmmdc(30, 15, D)
15.
?- cmmmc(30, 15, M).
30.
```


### Aplicaţia 8.

Să se determine valoarea expresiei $E(a,b,c) = (a,c)-[a,b]+(b,c)$.

**SWI-Prolog**:

```apl
/* Cmmdc */
cmmdc(X,0,X).
cmmdc(X,Y,D):- Z is X mod Y, cmmdc(Y,Z,D).

/* Cmmmc */
cmmmc(X,Y,M):- cmmdc(X,Y,D), M is (X*Y)/D.

expresie_e1(A,B,C,Rez):- cmmdc(A,C,R1), cmmmc(A,B,R2), cmmdc(B,C,R3), Rez is R1-R2+R3.
```

**Execuţie**:

```apl
?- expresie_e1(20, 15, 25, Rez).
Rez = -50.
```

### Aplicaţia 9.

Să se determine valoarea expresiei $E(a,b,c) = max((a,c),[a,b],(b,c))$, unde $a,b,c$ sunt numere întregi.

**SWI-Prolog**:

```apl
/* Maxim */
maxim(A,B,A):- A>=B, !.
maxim(_,B,B).
maxim3(A,B,C,Max3):- maxim(A,B,R), maxim(R,C,Max3).

/* Cmmdc */
cmmdc(X,0,X).
cmmdc(X,Y,D):- Z is X mod Y, cmmdc(Y,Z,D).

/* Cmmmc */
cmmmc(X,Y,M):- cmmdc(X,Y,D), M is (X*Y)/D.

expresie_e2(A,B,C,Rez):- cmmdc(A,C,R1), cmmmc(A,B,R2), cmmdc(B,C,R3), maxim3(R1,R2,R3,Rez).
```

**Execuţie**:

```apl
?- expresie_e2(20,15,25,Rez).
Rez = 60.
```

### Aplicaţia 10.

Să se determine `CMMDC` și `CMMMC` pentru 3 numere întregi.

**Observaţie**: $(X,Y,Z) = ((X,Y),\ Z)$, $[X,Y,Z] = [[X,Y],\ Z]$.

**SWI-Prolog**:

```apl
/* Cmmdc */
cmmdc(X,0,X).
cmmdc(X,Y,D):- Z is X mod Y, cmmdc(Y,Z,D).
cmmdc3(X,Y,Z,D3):- cmmdc(X,Y,R), cmmdc(R,Z,D3).

/* Cmmmc */
cmmmc(X,Y,M):- cmmdc(X,Y,D), M is (X*Y)/D.
cmmmc3(X,Y,Z,M3):- cmmmc(X,Y,R), cmmmc(R,Z,M3).
```

**Execuţie**:

```apl
?- cmmdc3(30, 15, 25, D)
D = 5.
?- cmmmc3(30, 15, 25, M)
M = 150.
```

