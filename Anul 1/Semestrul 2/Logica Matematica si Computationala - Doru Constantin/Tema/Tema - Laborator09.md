# Laborator09 - Temă 

## Petculescu Mihai-Silviu

- [Laborator09 - Temă](#laborator09---temă)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [Exerciţiul 1.0.1](#exerciţiul-101)
    - [Ecerciţiul 1.0.2](#ecerciţiul-102)
    - [Exerciţiul 1.0.3](#exerciţiul-103)
    - [Exerciţiul 1.0.4](#exerciţiul-104)

### Exerciţiul 1.0.1

Să se aducă la forma normală conjunctivă şi la forma normală disjunctivă şi să se rezolve problema deciziei pentru următoarele formule:

1. $ (x \or\neg y) \to (t \to\neg x) \to (\neg y \to\neg t)$

$$
\neg(\neg(x \or\neg y) \or (\neg t \or\neg x)) \or (\neg\neg y \or\neg t)\\
( (x \or \neg y) \and (t \and x) ) \or (y \or \neg t)
$$

**DNF**
$$
(x \and t) \or (\neg y \or t \or x) \or (y \or \neg t)\\
x \and t
$$
**CNF**
$$
(t \and (x \or \neg y)) \and (x \and (x \or \neg y)) \or (y \or \neg t)\\
((y \or \neg t) \or (t \and (x \or \neg y))) \and ( (y \or \neg t) \or (x \and (x \or \neg y))))\\
(y \or \neg t \or t) \and (y \or \neg t \or x \or \neg y) \and (y \or \neg t \or x) \and (y \or \neg t \or x \or \neg y)\\
y \or \neg t \or x
$$

2. $(a \to b) \to (\neg (c \or a) \to b)$

$$
\neg (\neg a \or b) \or (\neg\neg (c \or a) \or b)\\
(a \and \neg b) \or (a \or b \or c)\\
$$

**DNF**
$$
((a \and \neg b) \or a) \or ((a \and \neg b) \or b) \or ((a \and \neg b) \or c)\\
(a \and (a \or b)) \or ((a \or b) \and (\neg b \or b)) \or ((a \or c) \and (\neg b \or c))\\
(a \and (a \or b)) \or (a \or b) \or ((a \or c) \and (\neg b \or c))
$$
**CNF**
$$
( a \or (a \or b \or c) ) \and ( b \or (a \or b \or c) )\\
a \or b \or c
$$


3. $ ((\neg x \to y) \to x ) \to (\neg x \to (y \and \neg x))$

$$
\neg(\neg(\neg\neg x \or y) \or x ) \or (\neg\neg x \or (y \and \neg x))\\
((x \or y) \and \neg x ) \or (x \or (y \and \neg x))\\
$$

DNF
$$
(x \and \neg x) \or (y \and \neg x) \or (x \and y) \or (x \and \neg x)\\
(y \and \neg x) \or (x \and y)
$$
CNF
$$
(\neg x \or x \or y \and \neg x) \and (x \or y \or x \or y \and \neg x)\\
\neg x \or x \or y\\
T
$$

### Ecerciţiul 1.0.2

Să se arate că $ \vdash (a \and b) \to (b \and a)$.

Folosind rezultatul prezentat în curs, 1.2.2, confom căreia pentru orice $\alpha \in FORM, \vdash (\alpha \to \alpha)$ şi echivalenţa $\alpha \and \beta \leftrightarrow \beta \and \alpha$ obţinem concluzia.

### Exerciţiul 1.0.3

Să se arate că $(x \or y) \to (\neg z \to t), \neg(z \and t) \to (\neg x \and p), \vdash((x \or y) \to (\neg x \and p))$

Pentru demonstrarea relaţiei vom porni de la regula silogismului (RS) $\{(\alpha \to \beta), (\beta \to \gamma)\} \vdash (\alpha \to \gamma)$ în care aplicăm substituţia $\sigma = \{x \or y|\alpha, \neg z \to t|\beta, \neg x \and p|\gamma\}$ şi echivalenţa $\neg z \to t \leftrightarrow \neg(z \and t)$.

### Exerciţiul 1.0.4

Să se arate că $(a \to b), \neg(a \to b) \vdash (c)$

Pentru demonstrarea relaţiei, aplicăm următoarea axiome, la care, în final, aplicăm substituţia $\sigma = \{a \to b|a, c|b\}$
$$
\begin{align}
&1. \neg a  && ipoteza\\
&2. (\neg a) \to ((\neg b) \to (\neg a)) && \overline{\alpha_1}\\
&3. (\neg b) \to (\neg a) && \frac{1}{2}\ MP\\
&4. a && ipoteza\\
&5. a \to ((\neg b) \to a) && \overline{\alpha_1}\\
&6. (\neg b) \to a && \frac{4}{5}\ MP\\
&7. (\neg b \to \neg a) \to ((\neg b \to a) \to b) && \overline{\alpha_3}\\
&8. (\neg b \to a) \to b && \frac{3}{7}\ MP\\
&9. b && \frac{6}{8}\ MP
\end{align}
$$


