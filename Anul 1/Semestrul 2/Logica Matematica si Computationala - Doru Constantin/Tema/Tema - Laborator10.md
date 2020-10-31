# Laborator10 - Temă

## Petculescu Mihai-Silviu

- [Laborator10 - Temă](#laborator10---temă)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [Exerciţiul 1.0.1](#exerciţiul-101)
    - [Exerciţiul 1.0.2](#exerciţiul-102)

### Exerciţiul 1.0.1

Să se determine forma normal conjunctivă (CNF) şi să se aplice algoritmul Davis-Putnam pentru formula
$$
\alpha = (\neg(a \and b)) \leftrightarrow (\neg c \to d)
$$
**CNF**:
$$
\begin{align}
T1:& (\neg(a \and b) \to (\neg c \to d)) \and ((\neg c \to d) \to \neg(a \and b))\\
T2:& (\neg\neg(a \and b) \or (\neg\neg c \or d)) \and (\neg(\neg\neg c \or d) \or \neg(a \and b))\\
T4:& ((a \and b) \or (c \or d)) \and (\neg(c \or d) \or \neg(a \and b))\\
T3:& ((a \and b) \or c \or d) \and ((\neg c \and \neg d) \or \neg a \or \neg b)\\
T5:& (a \or c \or d) \and (b \or c \or d) \and (\neg a \or \neg b \or \neg c) \and (\neg a \or \neg b \or \neg d)\\
\end{align}
$$
**Davis-Putnam**:
$$
\begin{align}
Initializari:&\ \gamma \leftarrow \{a \or c \or d, b \or c \or d, \neg a \or \neg b \or \neg c, \neg a \or \neg b \or \neg d\}\\
&sw \leftarrow false;\ T \leftarrow \O\\
Iteratia\ 1:&\ Nu\ exista\ clauza\ unitara\ si\ nici\ literal\ pur\\
&\ Alegem\ \lambda = a\ literal\\
&\ \gamma \leftarrow NEG_{a}(\gamma) = \{b \or c \or d, \neg b \or \neg c, \neg b \or \neg d\}\\
&\ T \leftarrow POS_{a}(\gamma) = \{b \or c \or d, c \or d\}\\
Iteratia\ 2:&\ Nu\ exista\ clauza\ unitara\ si\ nici\ literal\ pur\\
&\ Alegem\ \lambda = b\ literal\\
&\ \gamma \leftarrow NEG_{b}(\gamma) = \{\neg c, \neg d\}\\
&\ T \leftarrow POS_{b}(\gamma) = \{c \or d\}\\
Iteratia\ 3:&\ \lambda = \neg c\ clauza\ unitara\\
&\ \gamma \leftarrow NEG_{\neg c}(\gamma) = \{\neg d\}\\
Iteratia\ 4:&\ \lambda = \neg d\ clauza\ unitara\\
&\ \gamma \leftarrow NEG_{\neg d}(\gamma) = \O\\
Iteratia\ 5:&\ \gamma = \O \Rightarrow write('Validabila'), sw \leftarrow true \\
&\ \Rightarrow STOP
\end{align}
$$

### Exerciţiul 1.0.2

Să se determine forma normal conjunctivă (CNF) şi să se aplice algoritmul bazat pe rezoluţie pentru formula
$$
\alpha = (\neg(a \or b)) \leftrightarrow (\neg a \or c)
$$
**CNF**:
$$
\begin{align}
T1:& (\neg(a \or b) \to (\neg a \or c)) \and ((\neg a \or c) \to \neg(a \or b))\\
T2:& (\neg\neg(a \or b) \or (\neg a \or c)) \and (\neg(\neg a \or c) \or \neg(a \or b))\\
T3:& (\neg\neg(a \or b) \or (\neg a \or c)) \and ((a \and \neg c) \or (\neg a \and \neg b))\\
T4:& (a \or b \or \neg a \or c) \and ((a \and \neg c) \or (\neg a \and \neg b))\\
T5:& (b \or c) \and (a \or \neg b) \and (\neg c \or \neg a) \and (\neg c \or \neg b)
\end{align}
$$
**Algoritmul bazat pe rezoluţie**:
$$
\begin{align}
Initializare:&\ \gamma \leftarrow \{b \or c, a \or \neg b, \neg c \or \neg a, \neg c \or \neg b\}\\
Iteratia\ 1:&\ Nu\ exista\ clauze\ unitare\ si\ nici\ literali\ puri\\
&\ Alegem\ \lambda = b\ literal\\
&\ \gamma \leftarrow REZ_{b}(\gamma) = \{\neg c \or \neg a, a \or c, \neg c \or c\} \\
&\ Eliminam\ tautologiile\\
&\ \gamma \leftarrow \{\neg c \or \neg a, a \or c\} \\
Iteratia\ 2:&\ Nu\ exista\ clauze\ unitare\ si\ nici\ literali\ puri\\
&\ Alegem\ \lambda = a\ literal\\
&\ \gamma \leftarrow REZ_{a}(\gamma) = \{\neg c \or c\} \\
&\ Eliminam\ tautologiile\\
&\ \gamma \leftarrow \O \\
Iteratia\ 3:&\ \lambda = \O \Rightarrow write('Validabila'), sw \leftarrow true\\
&\ \Rightarrow STOP
\end{align}
$$



