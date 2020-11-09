# Laborator04

## Petculescu Mihai-Silviu

[TOC]

## Aplicații

### Aplicaţia 1.

Să se calculeze $n!$. $n! = 1 \cdot 2 \cdot 3 \cdot ... \cdot n = (n-1)! \cdot n$, $0! = 1$.

**SWI-Prolog**:

 ```apl
factorial(0,1).
factorial(N,R):- N1 is N-1, factorial(N1, R1), R is R1*N.
 ```

**Execuţie**:

```apl
?- factorial(5,Rez).
Rez = 120.
```

### Aplicația 2.

Fie șirul $a(n) = 2*a(n-1) + 1$, $a(0) = -2$

**SWI-Prolog**:

 ```apl
sir(0,-2).
sir(N,R):- N1 is N-1, sir(N1,R1), R is 2*R1+1.
 ```

**Execuţie**:

```apl
?- sir(7,Rez).
Rez = -129.
```

### Aplicația 3.

Șirul lui Fibonacci $F(n) = F(n-1) + F(n-2)$, $F(0) = 0$, $F(1) = 1$

**SWI-Prolog**:

```apl
fibonacci(0,0).
fibonacci(1,1).
fibonacci(N,R):- N1 is N-1, N2 is N-2, fibonacci(N1,R1), fibonacci(N2,R2), R is R1+R2.
```

**Execuţie**:

```apl
?- fibonacci(10, Rez).
55.
```

### Aplicația 4.

Fie șirul: $2 \cdot f(n+1) = 3 \cdot f(n) + f(n+2),\ f(0) = -1,\ f(1) = 2$, $f(n+2) = 2 \cdot f(n+1) - 3 \cdot f(n)$

**Rezolvare**:

Rescriem formula de mai sus astfel:
$$
n := n+2 \to f(n) = 2 \cdot f(n-1) - 3 \cdot f(n-2)
$$
**SWI-Prolog**:

```apl
f(0,-1).
f(1,2).
f(N,R):- N1 is N-1, N2 is N-2, f(N1,R1), f(N2,R2), R is 2*R1-3*R2.
```

**Execuție**:

```apl
?- f(7,Rez).
Rez = -4.
```

### Aplicația 5.

`Cmmdc(X,Y)` și `Cmmmc(X,Y)` pentru două numere întregi `X,Y`.

**Observație**: $(X,Y) = (Y, X\ mod\ Y)$, $[X,Y]*(X,Y)=X*Y \to$ $[X,Y] = X*Y / (X,Y)$

**SWI-Prolog**:

```apl
/* Cmmdc */
cmmdc(X,0,X).
cmmdc(X,Y,D):- Z is X mod Y, cmmdc(Y,Z,D).

/* Cmmmc */
cmmmc(X,Y,D):- cmmdc(X,Y,Z), D is (X*Y)/Z.
```

**Execuție**:

```apl
?- cmmdc(180,45,Rez).
Rez = 45.
?- cmmmc(20,45,Rez).
Rez = 180.
```

### Aplicația 6.

Să se calculeze `cmmdc3(X,Y,Z,R)` și `cmmmc3(X,Y,Z,R)` pentru trei numere întregi `X,Y,Z`.

**Observație**: $(X,Y,Z) = ((X,Y),\ Z),\ [X,Y,Z] = [[X,Y],\ Z]$

**SWI-Prolog**:

```APL
/* Cmmdc */
cmmdc(X,0,X).
cmmdc(X,Y,D):- Z is X mod Y, cmmdc(Y,Z,D).
cmmdc3(X,Y,Z,D):- cmmdc(X,Y,R1), cmmdc(R1,Z,D).

/* Cmmmc */
cmmmc(X,Y,D):- cmmdc(X,Y,Z), D is (X*Y)/Z.
cmmmc3(X,Y,Z,D):- cmmmc(X,Y,R1), cmmmc(R1,Z,D).
```

**Execuție**:

```apl
?- cmmdc3(30,45,60,Rez).
Rez = 15.
?- cmmmc3(30,45,60,Rez).
Rez = 180.
```

### Aplicația 7.

Să se calculeze valoarea expresiei:
$$
E(a,b,c) = cmmmc3(a,b,c) + cmmdc3(a,b,c) - cmmmc(b,c)
$$
**SWI-Prolog**:

```apl
/* Cmmdc */
cmmdc(X,0,X).
cmmdc(X,Y,D):- Z is X mod Y, cmmdc(Y,Z,D).
cmmdc3(X,Y,Z,D):- cmmdc(X,Y,R1), cmmdc(R1,Z,D).

/* Cmmmc */
cmmmc(X,Y,D):- cmmdc(X,Y,Z), D is (X*Y)/Z.
cmmmc3(X,Y,Z,D):- cmmmc(X,Y,R1), cmmmc(R1,Z,D).

expresie(A,B,C,Rez):- cmmmc3(A,B,C,R1), cmmdc3(A,B,C,R2), cmmmc(B,C,R3), Rez is R1+R2-R3.
```

**Execuție**:

```apl
?- expresie(5,10,20,Rez).
Rez = 5.
```

### Aplicația 8.

Să se calculeze `maxim3(a,b,c)`.

**SWI-Prolog**:

```apl
maxim(A,B,A):- A>B, !.
maxim(_,B,B).
maxim3(A,B,C,Rez):- maxim(A,B,R1), maxim(R1,C,Rez).
```

**Execuție**:

```apl
?- maxim3(3,-5,8,Rez).
Rez = 8.
```

### Aplicația 9.

Să se calculeze valoarea expresiei:
$$
\begin{align*}
E2(a,b,c,d) =\ & maxim3(a,b,c) - minim3(b,c,d) + cmmdc(max(a,b), min(c,d))\\
&- cmmdc(maxim3(b,c,d),a) + maxim4(a,b,c,d)
\end{align*}
$$
**SWI-Prolog**:

```apl
/* Maxim */
maxim(A,B,A):- A>B, !.
maxim(_,B,B).
maxim3(A,B,C,Rez):- maxim(A,B,R1), maxim(R1,C,Rez).
maxim4(A,B,C,D,Rez):- maxim(A,B,R1), maxim(C,D,R2), maxim(R1,R2,Rez).

/* Minim */
minim(A,B,A):- A<B, !.
minim(_,B,B).
minim3(A,B,C,Rez):- minim(A,B,R1), minim(R1,C,Rez).
minim4(A,B,C,D,Rez):- minim(A,B,R1), minim(C,D,R2), minim(R1,R2,Rez).

/* Cmmdc */
cmmdc(X,0,X).
cmmdc(X,Y,D):- Z is X mod Y, cmmdc(Y,Z,D).

/* Cmmmc */
cmmmc(X,Y,D):- cmmdc(X,Y,Z), D is (X*Y)/Z.

/* Aplicatia 9 */
expresie_e2(A,B,C,D,Rez):-
maxim3(A,B,C,R1),
minim3(B,C,D,R2),
maxim(A,B,R31), minim(C,D,R32), cmmdc(R31,R32,R3),
maxim3(B,C,D,R41), cmmdc(R41,A,R4),
maxim4(A,B,C,D,R5),
Rez is R1-R2+R3-R4+R5.
```

**Execuție**:

```apl
?- expresie_e2(4,8,5,12,Rez).
Rez = 12.
```

## Temă

### Tema 1.

Să se calculeze valoarea șirului: $2\cdot b(n)=b(n+1)-b(n+2)$, cu $b(0)=-1$, $b(1) = 2$.

**Rezolvare**:

Rescriem formula de mai sus astfel:
$$
b(n+2)= b(n+1) - 2 \cdot b(n) \\
n := n+2 \to b(n) = b(n-1) - 2 \cdot b(n-2)
$$
**SWI-Prolog**:

```apl
expresie_b(0,-1).
expresie_b(1,2).
expresie_b(N,Rez):- N1 is N-1, N2 is N-2, expresie_b(N1,R1), expresie_b(N2,R2), Rez is R1-2*R2. 
```

**Execuție**:

```apl
/* Expresie b */
?- expresie_b(2,Rez).
Rez = 4.
?- expresie_b(3,Rez).
Rez = 0.
?- expresie_b(4,Rez).
Rez = -8.
```

### Temă 2.

Să se calculeze valoarea expresiei $E1(N) = b(N) + c(N)$, unde șirul $b(n)$ este definit la 1), iar șirul $c$ se definește prin $c(n) = 3 \cdot c(n-1) - c(n-2)$, cu $c(0)=1$,  $c(1)=-1$.

**SWI-Prolog**:

```apl
/* Tema 1 */
expresie_b(0,-1).
expresie_b(1,2).
expresie_b(N,Rez):- N1 is N-1, N2 is N-2, expresie_b(N1,R1), expresie_b(N2,R2), Rez is R1-2*R2.

/* Tema 2 */
expresie_c(0,1).
expresie_c(1,-1).
expresie_c(N,Rez):- N1 is N-1, N2 is N-2, expresie_c(N1,R1), expresie_c(N2,R2), Rez is 3*R1-R2.

expresie_e1(N,Rez):- N1 is N, expresie_b(N1,R1), N2 is N, expresie_c(N2,R2), Rez is R1+R2.
```

**Execuție**:

```apl
/* Expresie c */
?- expresie_c(2,Rez).
Rez = -4.
?- expresie_c(3,Rez).
Rez = -11.
?- expresie_c(4,Rez).
Rez = -29.

/* Expresie E1 */
?- expresie_e1(2,Rez).
Rez = 0.
?- expresie_e1(3,Rez).
Rez = -11.
?- expresie_e1(4,Rez).
Rez = -37.
```

### Temă 3.

Să se calculeze valoarea expresiei: 
$$
E2(x,y,z,t) = (x,y,z,t) + [(x,y),[z,t]] - [[x,y,z],(y,z,t)]
$$
**SWI-Prolog**:

```apl
/* Cmmdc */
cmmdc(X,0,X).
cmmdc(X,Y,D):- Z is X mod Y, cmmdc(Y,Z,D).
cmmdc3(X,Y,Z,D):- cmmdc(X,Y,R1), cmmdc(R1,Z,D).
cmmdc4(X,Y,Z,T,D):- cmmdc(X,Y,R1), cmmdc(Z,T,R2), cmmdc(R1,R2,D).

/* Cmmmc */
cmmmc(X,Y,D):- cmmdc(X,Y,Z), D is (X*Y)/Z.
cmmmc3(X,Y,Z,D):- cmmmc(X,Y,R1), cmmmc(R1,Z,D).
cmmmc4(X,Y,Z,T,D):- cmmmc(X,Y,R1), cmmmc(Z,T,R2), cmmmc(R1,R2,D).

/* Expresie E2 */
expresie_e2(X,Y,Z,T,Rez):- 
cmmdc4(X,Y,Z,T,D1),
cmmdc(X,Y,D21), cmmmc(Z,T,D22), cmmmc(D21,D22,D2),
cmmmc3(X,Y,Z,D31), cmmdc3(Y,Z,T,D32), cmmmc(D31,D32,D3),
Rez is D1+D2-D3.
```

**Execuție**:

```apl
?- expresie_e2(3,8,14,5,Rez).
Rez = -97.
```

### Temă 4.

Să se calculeze valoarea expresiei:
$$
E3(x,y,z,t) = maxim4(\ (x,y,z,t),\ [(x,y),[z,t]],\ [[x,y,z],(y,z,t)],\ (x,y,t)\ ) + \\
minim4(\ [x,y,z,t],\ ((x,y),[z,t]),\ ([x,y,z],(y,z,t)),\ [x,y,t]\ )
$$
**SWI-Prolog**:

```apl
/* Maxim */
maxim(A,B,A):- A>B, !.
maxim(_,B,B).
maxim4(A,B,C,D,Rez):- maxim(A,B,R1), maxim(C,D,R2), maxim(R1,R2,Rez).

/* Minim */
minim(A,B,A):- A<B, !.
minim(_,B,B).
minim4(A,B,C,D,Rez):- minim(A,B,R1), minim(C,D,R2), minim(R1,R2,Rez).

/* Cmmdc */
cmmdc(X,0,X).
cmmdc(X,Y,D):- Z is X mod Y, cmmdc(Y,Z,D).
cmmdc3(X,Y,Z,D):- cmmdc(X,Y,R1), cmmdc(R1,Z,D).
cmmdc4(X,Y,Z,T,D):- cmmdc(X,Y,R1), cmmdc(Z,T,R2), cmmdc(R1,R2,D).

/* Cmmmc */
cmmmc(X,Y,D):- cmmdc(X,Y,Z), D is (X*Y)/Z.
cmmmc3(X,Y,Z,D):- cmmmc(X,Y,R1), cmmmc(R1,Z,D).
cmmmc4(X,Y,Z,T,D):- cmmmc(X,Y,R1), cmmmc(Z,T,R2), cmmmc(R1,R2,D).

/* Expresie E3 */
expresie_e3(X,Y,Z,T,Rez):- 

/* Primul termen */
cmmdc4(X,Y,Z,T,D1),
cmmdc(X,Y,D21), cmmmc(Z,T,D22), cmmmc(D21,D22,D2),
cmmmc3(X,Y,Z,D31), cmmdc3(Y,Z,T,D32), cmmmc(D31,D32,D3), 
cmmdc3(X,Y,T,D4),
maxim4(D1,D2,D3,D4,R1),

/* Al doilea termen */
cmmmc4(X,Y,Z,T,M1),
cmmdc(X,Y,M21), cmmmc(Z,T,M22), cmmdc(M21,M22,M2),
cmmmc3(X,Y,Z,M31), cmmdc3(Y,Z,T,M32), cmmdc(M31,M32,M3), 
cmmmc3(X,Y,T,M4),
minim4(M1,M2,M3,M4,R2),

/* Rezultat */
Rez is R1+R2.
```

**Execuție**:

```apl
?- expresie_e3(5,12,10,15,Rez).
Rez = 61.
```

