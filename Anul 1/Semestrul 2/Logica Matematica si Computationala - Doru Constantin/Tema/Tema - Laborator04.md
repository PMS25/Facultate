# Laborator4 - Temă

## Petculescu Mihai-Silviu

- [Laborator4 - Temă](#laborator4---temă)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [Exerciţiul 1.0.1. Se consideră următoarele clauze](#exerciţiul-101-se-consideră-următoarele-clauze)
    - [Exerciţiul 1.0.2. Aplicând procedura *DemRez*, demonstraţi că următoarea reprezentare clauzală este invalidabilă:](#exerciţiul-102-aplicând-procedura-demrez-demonstraţi-că-următoarea-reprezentare-clauzală-este-invalidabilă)
    - [Exerciţiul 1.0.3. Aplicaţi algoritmul *DemRez* următoarei reprezentări clauzale:](#exerciţiul-103-aplicaţi-algoritmul-demrez-următoarei-reprezentări-clauzale)

### Exerciţiul 1.0.1. Se consideră următoarele clauze

$$
\begin{align}
C1 &: \neg a \or q \\
C2 &: \neg b \or c \or \neg a \\
C3 &: q \or b \or c \\
C4 &: d \or q \or \neg b
\end{align}
$$

**Determinaţi următoarele rezolvente:**
R1: $rez_{a}(C_1,C_2)$

$R1=\{q\lor \neg b\lor c\}$

R2: $rez_{\neg a}(R_1,C_1)$

$R2=\emptyset,\ clauzele\ R1 \ si\ C1\ nu\ sunt\ \neg a\ rezolubile$

R3: $rez_{b}(C_2,C_4)$

$R3=\emptyset,\ clauzele\ C2\ si\ C4\ nu\ sunt\ b\ rezolubile $

R4: $rez_{q}(R_2,C_4)$

$R4=\emptyset,\ clauzele\ C2\ si\ C4\ nu\ sunt\ q\ rezolubile $

R5: $rez_{q}(C_1,C_3)$

$R5=\emptyset,\ clauzele\ C1\ si\ C3\ nu\ sunt\ q\ rezolubile $

R6: $rez_{b}(R_5,R_3)$

$R6=\emptyset,\ clauzele\ R5\ si\ R3\ nu\ sunt\ b\ rezolubile $

R7: $rez_{q}(R_6,C_1)$

$R7=\emptyset,\ clauzele\ R6\ si\ C1\ nu\ sunt\ q\ rezolubile $

### Exerciţiul 1.0.2. Aplicând procedura *DemRez*, demonstraţi că următoarea reprezentare clauzală este invalidabilă:

$$
S = \{p \or q \or r, \neg p \or r, \neg q, \neg r\}
$$

$$
\begin{align}
Initializare:\ &\gamma \leftarrow \{p \or q \or r, \neg p \or r, \neg q, \neg r\};\ sw \leftarrow false
\\Iteratia \ 1:\ &\lambda = \neg q \ clauza \ unitara
\\ &\gamma \leftarrow NEG_{\neg q}(\gamma)=\{\neg p \lor r, \neg r,p \lor r\}
\\Iteratia \ 2 :\ &\lambda =\neg r\ clauza \ unitara
\\ &\gamma \leftarrow NEG_{\neg r}(\gamma)=\{\neg p ,p \}
\\Iteratia \ 3 :\ &\lambda=p \ clauza \ unitara 
\\ &\gamma \leftarrow NEG_{p}(\gamma)=\{\square \}
\\Iteratia \ 4 :\ &\square \in \gamma \Rightarrow \ write "invalidabila",sw\leftarrow true 
\\&\Rightarrow STOP
\end{align}
$$



### Exerciţiul 1.0.3. Aplicaţi algoritmul *DemRez* următoarei reprezentări clauzale:

$$
S = \{p \or q, \neg q \or r, \neg p \or q, \neg r\}
$$

$$
\begin{align}
Initializare:\ &\gamma \leftarrow \{p \or q, \neg q \or r, \neg p \or q, \neg r\};\ sw \leftarrow false
\\Iteratia \ 1 :\ &\lambda = \neg r \ clauza\ unitara 
\\ &\gamma \leftarrow NEG_{\neg r}(\gamma)=\{p \lor q, \neg p \lor q,\neg q\}
\\Iteratia \ 2:\ &\lambda=\neg q \ clauza \ unitara 
\\ &\gamma \leftarrow NEG_{\neg q}(\gamma)=\{p, \neg p \}
\\Iteratia \ 3 :\ &\lambda=p \ clauza \ unitara 
\\ &\gamma \leftarrow NEG_{p}(\gamma)=\{\square \}
\\Iteratia \ 4 :\ &\square \in \gamma \Rightarrow \ write "invalidabila",sw\leftarrow true 
\\&\Rightarrow STOP
\end{align}
$$


