# Laborator09

## Metode de sortare a elementelor dintr-o listă de numere reale

[TOC]

### 1. Metoda Bubble Sort

Sortarea presupune realizarea de interschimbări a elementelor din listă până la ordinea de sortare.

**Program Prolog**:

```apl
domains
  lista=real*
predicates
  bsort(lista,lista)
  schimba(lista,lista)
clauses
  bsort(L,LS):- schimba(L,L1), bsort(L1,LS),!.
  bsort(L,L).
  schimba([X,Y|T], [Y,X|T]):- X>Y.
  schimba([Y|T], [Y|T1]):- schimba(T,T1).
```

**SWI-Prolog**:

```apl

```

**Execuție**:

```apl
?- bsort([10,-1,7,8], Lista_sortata).
Lista_sortata = [-1,7,8,10]
```

### 2. Sortare prin inserție

Sortarea se bazează pe inserarea clauselor din listă pe poziția de sortare

**Program Prolog**:

```apl
domains
  lista=real*
predicates
  insertsort(lista,lista)
  insert(real,lista,lista)
clauses
  insertsort([],[]).
  insertsort([H|T],LS):- insertsort(T,LST), insert(H,LST,LS).
  insert(H,[Y|T],[Y|T1]):- H>Y, insert(H,T,T1),!.
```

**SWI-Prolog**:

```apl

```

**Execuție**:

```apl
?- insertsort([10,-1,7,8], Lista_sortata).
Lista_sortata = [-1,7,8,10]
```

### 3. Metoda QuickSort

- Se împarte lista iniţială în funcţie de primul element în două liste $\large \to$ O listă cu valori mai mici decât primul element, respectiv o listă cu valori mai mari decât primul element.
- Se sortează fiecare listă de la primul pas.
- Concatenarea rezultatelor listelor sortate cu includerea primului element.

**Program Prolog**:

```apl
domains
predicates
clauses
  qsort([],[]).
  qsort([H|T],LS):- split(H,T,L1,L2), qsort(L1,LS1), qsort(L2,LS2), concatenare(LS1,[H|LS2],LS).
  split(K,[],[],[]).
  split(K,[H|T],[H|T1],L2):- H<K, split(K,T,T1,L2),!.
  split(K,[H|T],L1,[H|T2]):- split(K,T,L1,T2).
  concatenare([],L2,L2).
  concatenare([H|T],L2,[H|TR]):- concatenare(T,L2,TR).
```

**SWI-Prolog**:

```apl

```

**Execuție**:

```apl
?- qsort([20,-4,10,7], Lista_sortara).
Lista_sortata = [-4,7,10,20]
```

### 4. Utilizarea metodelor de sortare

Să se determine lista sumelor elementelor de pe fiecare linie dintr-o matrice şi să se sorteze lista rezultat.

Fie matricea:
$$
\large
A =
\begin{pmatrix}
a_{11}\ a_{12}\ ...\ a_{1n}\\
a_{21}\ a_{22}\ ...\ a_{2n}\\
...\\
a_{n1}\ a_{n2}\ ...\ a_{nn}\\
\end{pmatrix}
\begin{matrix}
\to SL_{1}\\
\to SL_{2}\\
...\\
\to SL{n}
\end{matrix}
\Rightarrow\\

\large
LR = [SL_{1}, SL_{2}, ..., SL_{n}],\ (a_{ij})_{1 \le i \le n \\ 1 \le j \le n} \in \R,\ n,m \in \N^{*} \\

\large
sortare(LR)\  prin\ bsort/insertsort/qsort
$$
**Program Prolog**:

```apl
domains
  lista=real*
  matrice=lista*
predicates
  sumaL(lista,real)
  sumaM(matrice,lista)
  sort_linie_matrice(matrice,lista)
  insertsort(lista,lista)
  insert(real,lista,lista)
clauses
  sumaL([],0).
  sumaL([H|T],S):- sumaL(T,S1), S is S1+H.
  sumaM([],[]).
  sumaM([HM|TM],[SL1|TSL]):- sumaL(HM,SL1), sumaM(MM,TSL).
  sort_linie_matrice(M,LS):- sumaM(M,Rez), insertsort(Rez, LS).
  * sortare prin insertie
```

**SWI-Prolog**:

```apl

```

**Execuție**:

```apl

```

## Imagini

