# Laborator07

 ## Aplicaţii Prolog

[TOC]

### 1. Reuniunea a două mulţimi de valori reale reprezentate prin liste.

$$
\large
\begin{align*}
&A \or B = \{x|\ x \in A\ sau\ x \in B\} \\
&L_1 \or L_2 = \{H_i|\ H_i \in L_1\ sau\ H_i \in L_2\}
\end{align*}
$$

**Exemplu**:
$$
\large
L_1 = [2,10,17],\ L_2 = [-1,8,10,20] \Rightarrow LR = [\overline{2,17},-1,8,10,20]
$$
**Program Prolog**:

```apl
domains
  lista=real*
predicates
  member(real,lista)
  reuniune(lista,lista,lista)
clauses
  member(X,[X|T]):-!.
  member(X,[Y|T]):- member(X,T).
  reuniune([],L2,L2).
  reuniune([H1|T1],L2,[H1|TR]):- not(member(H1|L2)), reuniune(T1,L2,TR),!.
  reuniune([H1|T1],L2,R):- reuniune(T1,L2,R).
```

**SWI-Prolog**:

```apl
!!! probleme la member
```

**Execuţie**:

```apl
?- reuniune([2,10,17,21],[-1,8,10,20,25],Rezultat_reuniune).
Rezultat_reuniune = [2,17,21,-1,8,10,20,25].
```

### 2.Intersecţia a două mulţimi de valori reale reprezentate prin liste.

$$
\large
\begin{align*}
&A \and B = \{x|\ x \in A\ si\ x \in B\} \\
&L_1 \and L_2 = \{H_i|\ H_i \in L_1\ si\ H_i \in L_2\}
\end{align*}
$$

**Exemplu**:
$$
\large
L_1 = [2,10,17],\ L_2 = [-1,10,8,17] \Rightarrow LR = [10,17]
$$
**Program Prolog**:

```apl

```

**SWI-Prolog**:

```apl

```

**Execuţie**:

```apl
!!!
?- reuniune([2,10,17,21],[-1,8,10,20,25],Rezultat_reuniune).
Rezultat_reuniune = [2,17,21,-1,8,10,20,25].
```

### 3. Maximul a $\large n$ valori reale, $\large n \in \N^*$

$$
\large
\begin{align*}
&L = [H_1, \overline{H_2,...,H_n}],\ H_i \in R,\ i=\overline{1..n}\\
&L = [H|T]
\end{align*}
$$

```apl
domains
  lista=real*
predicates
  maxim(real,real,real)
  maximL(lista,real)
clauses
  maxim(A,B,A):- A>B,!.
  maxim(A,B,B).
  maximL([H],H).
  maximL([H|L],MaxL):- maximL(T,MaxT), maxim(H,MaxT,MaxL).
```

Executie

```apl
maximL([8,12,-17,24,-1,18], Max_lista).
Max_lista = 24.
```

### 4. Minimul a n valori reale, n \in N* (Tema)

### 5. Concatenarea (alipire) a n liste de valori reale, n \in N*


$$
L_1 = [H_i^1]_{i = \overline{1..n1}} \\
L_2 = [H_i^2]_{i = \overline{1..n2}} \\
...\\
L_N = [H_i^N]_{i = \overline{1..n_n}} \\
$$
unde
$$
H_i^j \in R reprezinta\ el\ cu\ nr\ i\ din\ lista\ nr\ j\ (1 <= i <= n_j,\ 1<=j<=N)\\
n_j \in N^* - reprezinta\ nr\ de\ el\ din\ lista\ j,\ j = \overline{1..N}
$$
LR = L1 * L2 ... Lj ... Ln

lista_de_liste (matrice) = lista* [HM|TM]

```apl
domains
  lista=real*
  matrice=lista*
predicates
  concatenare(lista,lista,lista)
  concatenareN(matrice,lista)
clauses
  concatenare([],L2,L2).
  concatenare([H|T],L2,[H|TR]):- concatenare(T,L2,TR).
```

