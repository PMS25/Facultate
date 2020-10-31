# Laborator3 - Temă

## Petculescu Mihai-Silviu

- [Laborator3 - Temă](#laborator3---temă)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [Exerciţiul 1.0.1. Să se aplice algoritmul Davis-Putnam următoarelor formule (se determină iniţial CNF):](#exerciţiul-101-să-se-aplice-algoritmul-davis-putnam-următoarelor-formule-se-determină-iniţial-cnf)
    - [Exerciţiul 1.0.2. Aplicând algoritmul lui Davis-Putnam, demonstraţi că următoarea formulă este validabilă:](#exerciţiul-102-aplicând-algoritmul-lui-davis-putnam-demonstraţi-că-următoarea-formulă-este-validabilă)

### Exerciţiul 1.0.1. Să se aplice algoritmul Davis-Putnam următoarelor formule (se determină iniţial CNF):

1) $(\neg p \or q) \and (\neg p) \and p$
$$
S(\alpha)=\{k1=\neg p \or q,k2=\neg p,k3=p\}\\
\begin{align}
Initializare:\ &\gamma \leftarrow \{\neg p \or q,\neg p,p\};\ sw \leftarrow false;\ T \leftarrow \O \\
Iteratia\ 1:\ &\lambda = p\ clauza\ unitara\\
&\gamma \leftarrow NEG_p(\gamma)=\{q,\square\}\\
Iteratia\ 2:\ &\square \in \gamma\ si\ T=\O \Rightarrow write('invalidalibila'),\ sw\leftarrow true\\
&\Rightarrow STOP
\end{align}
$$
2) $(p \or q) \and (r \or q) \and (\neg r) \and (\neg q)$
$$
S(\alpha)=\{k1=p \or q,k2=r \or q,k3=\neg r,k4=\neg q\}\\
\begin{align}
Initializare:\ &\gamma \leftarrow \{p \or q,r \or q,\neg r,\neg q\};\ sw \leftarrow false;\ T \leftarrow \O \\
Iteratia\ 1:\ &\lambda = \neg q\ clauza\ unitara\\
&\gamma \leftarrow NEG_{\neg q}(\gamma)=\{p,r,\neg r\}\\
Iteratia\ 2:\ &\lambda = \neg r\ clauza\ unitara\\
&\gamma \leftarrow NEG_{\neg r}(\gamma)=\{p,\square\}\\
Iteratia\ 3:\ &\square \in \gamma\ si\ T=\O \Rightarrow write('invalidalibila'),\ sw\leftarrow true\\
&\Rightarrow STOP
\end{align}
$$
3) $p \and q \and r$
$$
S(\alpha)=\{k1=p,k2=q,k3=r\}\\
\begin{align}
Initializare:\ &\gamma \leftarrow \{p,q,r\};\ sw \leftarrow false;\ T \leftarrow \O \\
Iteratia\ 1:\ &\lambda = p\ clauza\ unitara\\
&\gamma \leftarrow NEG_p(\gamma)=\{q,r\}\\
Iteratia\ 2:\ &\lambda = q\ clauza\ unitara\\
&\gamma \leftarrow NEG_q(\gamma)=\{r\}\\
Iteratia\ 3:\ &\lambda = r\ clauza\ unitara\\
&\gamma \leftarrow NEG_r(\gamma)=\emptyset\\
Iteratia\ 4:\ &\gamma=\emptyset  \Rightarrow write('validalibila'),\ sw\leftarrow true\\
&\Rightarrow STOP
\end{align}
$$
4) $(p \or q) \and (\neg p \or q) \and r$
$$
S(\alpha)=\{k1=p \or q,k2=\neg p \or q,k3=r\}\\
\begin{align}
Initializare:\ &\gamma \leftarrow \{p \or q,\neg p \or q,r\};\ sw \leftarrow false;\ T \leftarrow \O \\
Iteratia\ 1:\ &\lambda = r\ clauza\ unitara\\
&\gamma \leftarrow NEG_r(\gamma)=\{p \or q,\neg p \or q\}\\
Iteratia\ 2:\ &\lambda = q\ literar\ pur\\
&\gamma \leftarrow NEG_q(\gamma)=\emptyset\\
Iteratia\ 3:\ &\gamma=\emptyset \Rightarrow write('validalibila'),\ sw\leftarrow true\\
&\Rightarrow STOP
\end{align}
$$
5) $(p \or q) \and (\neg q)$
$$
S(\alpha)=\{k1=p \or q,k2=\neg q\}\\
\begin{align}
Initializare:\ &\gamma \leftarrow \{p \or q,\neg q\};\ sw \leftarrow false;\ T \leftarrow \O \\
Iteratia\ 1:\ &\lambda = \neg q\ clauza\ unitara\\
&\gamma \leftarrow NEG_{\neg q}(\gamma)=\{p\}\\
Iteratia\ 2:\ &\lambda = p\ clauza\ unitara\\
&\gamma \leftarrow NEG_{p}(\gamma)=\emptyset\\
Iteratia\ 3:\ &\gamma=\emptyset \Rightarrow write('validalibila'),\ sw\leftarrow true\\
&\Rightarrow STOP
\end{align}
$$
6) $(p \or q) \and (\neg p \or q) \and (\neg r \or \neg q) \and (r \or \neg q)$
$$
S(\alpha)=\{k1=p \or q,k2=\neg p \or q,k3=\neg r \or \neg q, k4=r \or \neg q\}\\
\begin{align}
Initializare:\ &\gamma \leftarrow \{p \or q,\neg p \or q,\neg r \or \neg q,r \or \neg q\};\ sw \leftarrow false;\ T \leftarrow \O \\
Iteratia\ 1:\ &Nu\ exista\ literar\ pur\ sau \ clauza\ unitara\\
&\ alegem \lambda=q\ literar\\
&\gamma \leftarrow NEG_q(\gamma)=\{\neg r, r\}\\
&\ T \leftarrow POS_q(\gamma)=\{p,\neg p\}\\
Iteratia\ 2:\ &\lambda=r\ clauza\ unitara\\
&\gamma \leftarrow NEG_q(\gamma)=\{\square\}\\
Iteratia\ 3:\ &\square \in \gamma,T \leftarrow POS_q(\gamma)=\{p,\neg p\}\\
&\gamma \leftarrow  T =\{p,\neg p\}\\
&\ T =\emptyset\\
Iteratia\ 4:\ &\lambda=p\ clauza\ unitara\\
&\gamma \leftarrow NEG_q(\gamma)=\{\square\}\\
Iteratia\ 5:\ &\square \in \gamma,T =\emptyset \Rightarrow write\ 'invalidabila',sw\leftarrow rue\\
&\Rightarrow STOP
\end{align}
$$


### Exerciţiul 1.0.2. Aplicând algoritmul lui Davis-Putnam, demonstraţi că următoarea formulă este validabilă:

$$
(((q \to p) \and (p \to q)) \to (\neg q \and \neg r)) \or (((r \to p) \and (q \to s)) \to ((p \to r) \to (r \and s)))
$$

**Determinare CNF**:
$$
\begin{align}
T2:\ &(\neg((\neg q \or p) \and (\neg p \or q)) \or (\neg q \and \neg r)) \or (\neg ((\neg r \or p) \and (\neg q \or s)) \or (\neg (\neg p \or r) \or (r \and s))) \\
T3:\ &(q \and\neg p) \or (p \and\neg q) \or (\neg q \and \neg r) \or (r \and\neg p) \or (\neg q \and s) \or (p \and\neg r) \or (r \and s)
\end{align}
$$
**Mapă Karnaugh**:

| rs\qp  |  00  |  01  |  10  |  11  |
| :----: | :--: | :--: | :--: | :--: |
| **00** |  1   |  1   |  1   |  1   |
| **01** |  1   |  1   |  1   |  1   |
| **10** |  1   |  1   |  1   |  0   |
| **11** |  1   |  1   |  1   |  1   |

**CNF**: $ \neg q \or p \or \neg r \or \neg s $

**Aplicăm algoritmul *Davis-Putnam***:
$$
S(\alpha)=\{k1= \neg q \or p \or \neg r \or \neg s \}\\
\begin{align}
Initializare:\ &\gamma \leftarrow \{ \neg q \or p \or \neg r \or \neg s \};\ sw \leftarrow false;\ T \leftarrow\O \\
Iteratia\ 1:\ &\lambda = \neg q\ literal\ pur\\
&\gamma \leftarrow NEG_{\neg q}(\gamma)=\O\\
Iteratia\ 2:\ &\gamma = \O \Rightarrow write('Validabila'),\ sw\leftarrow true\\
&\Rightarrow STOP
\end{align}
$$


