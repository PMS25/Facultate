# Laborator8 - Temă

## Petculescu Mihai-Silviu

- [Laborator8 - Temă](#laborator8---temă)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [Exerciţiul 1.0.1](#exerciţiul-101)
    - [Exerciţiul 1.0.2](#exerciţiul-102)
    - [Exerciţiul 1.0.3](#exerciţiul-103)
    - [Exerciţiul 1.0.4](#exerciţiul-104)

### Exerciţiul 1.0.1

Folosind regula silogismului, să se verifice relaţia:
$$
((\alpha \to \beta) \and (\beta \to \gamma)) \to (\alpha \to \gamma)
$$
Folosind $RS(\theta_1,\theta_2)$, unde $\theta_1 = (\alpha \to \beta), \theta_2 = (\beta \to \gamma) \Rightarrow \theta_3 = (\alpha \to \gamma)$ şi relaţia este verificată.

### Exerciţiul 1.0.2

Folosind axiomelele, să se identifice demonstraţiile formale pentru:

a) $(\neg(\alpha \and \neg\beta) \to \beta) \to ((\neg\gamma \or \theta) \to ((\alpha \and \neg\beta) \or \beta)))$

Folosind $\overline\alpha_{1}\ = (a\rightarrow(b \rightarrow a))$, substituția $\theta =\{((\alpha \and \neg\beta) \or \beta))|a,\ (\neg\gamma \or \theta)|b\}$ și axioma $(\neg(\alpha \and \neg\beta) \to \beta) \leftrightarrow((\alpha \and \neg\beta) \or \beta)))$ rezultă cerința a)

b) $(\neg((\beta \and \alpha) \or \gamma) \to \neg(\theta \or \alpha)) \to ((\neg\theta \to \alpha) \to ((\beta \and \alpha) \or \gamma))$

Pentru cerinţa b) vom folosi $\overline\alpha_7=(((\neg a)\rightarrow(\neg b))\rightarrow (b\rightarrow a))$, substituția $\theta =\{((\beta \and \alpha) \or \gamma)|a,\ (\theta \or \alpha)|b\}$ și axioma $  (\theta \or \alpha) \leftrightarrow (\neg \theta \rightarrow \alpha )$ de unde rezultă cerinţa.

c) $\neg((\beta \or \neg\alpha) \or ((\gamma \or \neg\theta) \and \neg\theta)) \leftrightarrow ((\neg\beta \and \alpha) \and (\neg(\gamma \or \neg\theta) \or \theta))$

În cazul cerinței c) folosind relațiile $\neg (a \or b) \leftrightarrow (\neg a \and \neg b), \neg(a \and b)\leftrightarrow(\neg a \lor \neg b) $ cu substituția $\theta = \{(\beta \or  \neg \alpha) \and \gamma)|a,\ ((\gamma \or \neg\theta) \and \neg\theta))|b\}$ se va rezolva.

### Exerciţiul 1.0.3

Să se demonstreze că pentru orice $a,b \in FORM$, următoarele formule sunt teoreme.
$$
\begin{align}
1)\ &(a \and b) \to a\\
2)\ &(a \and b) \to b\\
3)\ &(a \and b) \leftrightarrow (b \and a)\\
4)\ &((a \to b) \to a) \to a\\
5)\ &(a \and b) \leftrightarrow (\neg(a \to \neg b))\\
6)\ &\neg(a \to b) \leftrightarrow (a \and \neg b)
\end{align}
$$
$$
\begin{align}
&1)\\
&\beta_1=(a\rightarrow((a \and b)\rightarrow a)\rightarrow a)=\overline \alpha_1\{a|a,((a \and b)\rightarrow a)|b\}\\
&\beta_2=((a \and b)\rightarrow a)\rightarrow(a \rightarrow a), PP\\
&\beta_3=(a \rightarrow a),\ \vdash \beta_3\\
&\beta_4=(a\and b)\rightarrow a\\
\\
&2)\\
&\beta_1=(b\rightarrow((a \and b)\rightarrow b)\rightarrow b)=\overline \alpha_1\{b|a,((a \and b)\rightarrow b)|b\}\\
&\beta_2=((a \and b)\rightarrow b)\rightarrow(b \rightarrow b), PP\\
&\beta_3=(b \rightarrow b),\ \vdash \beta_3\\
&\beta_4=(a\and b)\rightarrow b\\
\\
&3)\\
&\beta_1=(a \and b) \leftrightarrow (\neg((\neg a) \or (\neg b)))=\overline \alpha_9\\
&Dar\ (\neg((\neg a) \or (\neg b))) \leftrightarrow (b \and a),axioma\ , deci\ 3) \ teorema\\
\\
&5)\\
&\beta_1=((a\and b )\leftrightarrow(\neg((\neg a)\lor(\neg b))))=\overline\alpha_9\\
&Cu\ axioma\ (\neg((\neg a)\lor(\neg b)))\leftrightarrow(\neg(a\leftarrow \neg b)) \ teorema\ se\ demostreaza\ usor\ \\
\\
&6)\\
&Folosind\ relatiile\ (\neg(a\leftarrow  b))\leftrightarrow(\neg((\neg a)\or b)\ si (\neg((\neg a)\or b))\leftrightarrow(a\and(\neg b)) \ teorema\ este\ usor\ de\ demonstrat\ 
\end{align}
$$

### Exerciţiul 1.0.4

Să se stabilească demonstraţii formale pentru următoarele formule:
$$
\begin{align}
1)\ &\alpha_1=(a \to (b \to c)) \to (b \to (a \to c))\\
2)\ &\alpha_2=(\neg b \and a) \to ((\neg a \or b) \to c)\\
3)\ &\alpha_3=(a \to b) \to (\neg b \to \neg a)\\
4)\ &\alpha_4=(a \to \neg a) \to \neg a\\
5)\ &\alpha_5=(\neg a \to a) \to a\\
6)\ &\alpha_6=\neg(\neg a \or b) \to ((a \to \neg b) \to (\neg b \and a))
\end{align}
$$
$$
\begin{align}
&1)\\
&Fie\ H=\{a,b,(a\rightarrow(b\rightarrow c))\}, secventa\ a,,a\rightarrow (b\rightarrow c),b\rightarrow c,b,c\ este\ H-deductiva\\
&deci {a,b,(a\rightarrow(b\rightarrow c))}\vdash c, din\ teorema\ deductiei\ rezulta\\
&\vdash (a \to (b \to c)) \to (b \to (a \to c)), PP\\
\\
&2)\\
&\gamma_1=((\neg \beta)\rightarrow(\neg \alpha))\rightarrow(\alpha\rightarrow\beta)=\overline\alpha_7\{\beta|a,\alpha|b\}\\
&\gamma_2=(\neg \alpha)\rightarrow((\neg \beta)\rightarrow(\neg\alpha))\\
&\gamma_3=(\neg \alpha)\rightarrow(a\rightarrow \beta ), RS(\gamma_2,\gamma_1) cu\ substitutia\ \omega=\{\neg a \lor b|\alpha,c|\beta\}\\
\\
&3)\\
&Folosind\ a\ doua\ schema\  a\ negatiei\ de\ unde\ rezulta\ usor\ \alpha_3=(a \to b) \to (\neg b \to \neg a)\\
\\
&4)\\
&\beta_1=(((a\rightarrow\neg a)\leftrightarrow\neg a)(\neg a \rightarrow(a\rightarrow \neg a)))=\overline\alpha_5\{a\rightarrow\neg a|a,\neg a|b\}\\
&\beta_2=(\neg a \rightarrow(a\rightarrow \neg a))=\overline\alpha_1\{\neg a|a,a|b\}\\
&\beta_3=((a\rightarrow\neg a)\leftrightarrow\neg a),MP(\beta_1,\beta_2)\\
&\beta_4=((a\rightarrow\neg a)\rightarrow\neg a),EI(\beta_3,\beta_4)\\
\\
&5)\\
&Daca\ 4)\ teorema\ pentru\ a,b\in FORM, atunci\ folosind\ substitutia\ \theta=\{\neg a|a\}\ rezulta\ cerinta\ 5)\\
\\
&6)\\
&\beta_1=((a \and \neg b)\rightarrow((a \rightarrow \neg b)\rightarrow(\neg b \and a)))=\overline\alpha_1{a\and \neg b|a,a\rightarrow \neg b|b}\\
&Folosind\ axiomele\ \neg(\neg a \or b) \leftrightarrow (a \and \neg b)\ si\ (a \and \neg b) \leftrightarrow (\neg b \and a)\ rezulta\ teorema\ ceruta
\end{align}
$$


