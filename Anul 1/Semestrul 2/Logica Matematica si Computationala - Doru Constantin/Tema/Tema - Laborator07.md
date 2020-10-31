# Laborator7 - Temă

## Petculescu Mihai-Silviu

- [Laborator7 - Temă](#laborator7---temă)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [Exerciţiul 1.0.1.](#exerciţiul-101)
    - [Exerciţiul 1.0.2](#exerciţiul-102)
    - [Exerciţiul 1.0.3](#exerciţiul-103)

### Exerciţiul 1.0.1. 

Folosind axiomele, să se identifice demonstraţii formale pentru:
$$
(\neg(\alpha \and \neg\beta) \to \beta) \to ((\neg\gamma \or \theta) \to ((\alpha \and \neg\beta) \or \beta))
$$
Folosind $\overline{\alpha_1} = a \to (b \to a)$, substitutia $\sigma=\{((\alpha \and \neg\beta) \or \beta)|a, (\neg\gamma \or \theta)|b\}$ şi relaţia $((\alpha \and \neg\beta) \or \beta) \leftrightarrow (\neg(\alpha \and \neg\beta) \to \beta)$ obţinem $\overline{\alpha_1}\sigma = (\neg(\alpha \and \neg\beta) \to \beta) \to ((\neg\gamma \or \theta) \to ((\alpha \and \neg\beta) \or \beta))$

### Exerciţiul 1.0.2

Folosind axiomele, să se identifice demonstraţii formale pentru:
$$
(\neg((\beta \and \alpha) \or \gamma) \to \neg(\theta \or \alpha)) \to ((\neg\theta \to \alpha) \to ((\beta \and \alpha) \or \gamma))
$$
Pentru demonstrarea relaţiei vom folosi axioma $\overline{\alpha_7} = (\neg a \to \neg b) \to (b \to a)$, substitutia $\sigma=\{((\beta \and \alpha) \or \gamma)|a, (\theta \or \alpha)|b\}$ şi relaţia $(\neg\alpha \to \beta) \leftrightarrow (\alpha \or \beta)$. 

### Exerciţiul 1.0.3

Folosind axiomele, să se identifice demonstraţii formale pentru:
$$
\neg((\beta \or \neg\alpha) \or ((\gamma \or \neg\theta) \and \neg\theta)) \leftrightarrow ((\neg\beta \and \alpha) \and (\neg(\gamma \or \neg\theta) \or \theta))
$$
Plecând de la relaţiile $\neg (a \or b) \leftrightarrow (\neg a \and \neg b)$ şi $\neg (a \and b) \leftrightarrow (\neg a \or \neg b)$, cu $a,b \in V$ şi aplicând substituţia $\sigma=\{(\beta \and \neg\alpha)|a, ((\gamma \or \neg\theta) \and \neg\theta)|b\}$ formulelor prezentate obtinem cu uşurinţă formula dată.
