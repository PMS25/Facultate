# Laborator 2 - Temă

## Petculescu Mihai-Silviu

- [Laborator 2 - Temă](#laborator-2---temă)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [Exerciţiul 1.0.1.](#exerciţiul-101)
    - [Exerciţiul 1.0.2.](#exerciţiul-102)

### Exerciţiul 1.0.1.

Să se calculeze mulţimile $\alpha_{\lambda}^{+}$, $\alpha_{\lambda}^{-}$, $\alpha_{\lambda}^{0}$, $POS_{\lambda}(\alpha)$, $NEG_{\lambda}(\alpha)$ pentru următoarele reprezentări clauzele:

a) $S(\alpha) = \{ a \lor b \lor \neg c, \neg b \lor d \lor \neg a, a \lor c \lor \neg b, \neg a \lor \neg c \lor b \}$ şi $\lambda_{1}=a$, respectiv $\lambda_{2}=\neg d$.

Pentru $\lambda=a$
$$
\alpha_{\lambda}^{+} = \{a \lor b \lor \neg c, a \lor c \lor \neg b \}\\
\alpha_{\lambda}^{-} = \{\neg b \lor d \lor \neg a, \neg a \lor \neg c \lor b \}\\
\alpha_{\lambda}^{0} = \{\square\}\\
\begin{align}
POS_{\lambda}(\alpha) &= \{\square\} \cup \{b \lor \neg c, c \lor \neg b \}\\
  &= \{\square, b \lor \neg c, c \lor \neg b \}\\
NEG_{\lambda}(\alpha) &= \{\square\} \cup \{\neg b \lor d, \neg c \lor b \}\\
  &= \{\square, \neg b \lor d, \neg c \lor b \}
\end{align}
$$
Pentru $\lambda=\neg d$
$$
\alpha_{\lambda}^{+} = \{\square\}\\
\alpha_{\lambda}^{-} = \{\neg b \lor d \lor \neg a\}\\
\alpha_{\lambda}^{0} = \{a \lor b \lor \neg c, a \lor c \lor \neg b, \neg a \lor \neg c \lor b\}\\
\begin{align}
POS_{\lambda}(\alpha) &= \{a \lor b \lor \neg c, a \lor c \lor \neg b, \neg a \lor \neg c \lor b\} \cup \{\square\}\\
  &= \{a \lor b \lor \neg c, a \lor c \lor \neg b, \neg a \lor \neg c \lor b, \square\}\\
NEG_{\lambda}(\alpha) &= \{a \lor b \lor \neg c, a \lor c \lor \neg b, \neg a \lor \neg c \lor b\} \cup \{\neg b \lor \neg a\}\\
  &= \{a \lor b \lor \neg c, a \lor c \lor \neg b, \neg a \lor \neg c \lor b, \neg b \lor \neg a\}
\end{align}
$$
b) $S(\alpha)=\{\neg a \lor b \lor c, \neg b \lor d \lor \neg e \lor a, \neg a \lor \neg c \lor d \lor e, b \lor c \lor a \lor e \}$ şi $\lambda_{1}=\neg b$, respectiv $\lambda_{2}=\neg e$.

Pentru $\lambda=\neg b$
$$
\alpha_{\lambda}^{+} = \{\neg b \lor d \lor \neg e \lor a\}\\
\alpha_{\lambda}^{-} = \{\neg a \lor b \lor c, b \lor c \lor a \lor e\}\\
\alpha_{\lambda}^{0} = \{\neg a \lor \neg c \lor d \lor e\}\\
\begin{align}
POS_{\lambda}(\alpha) &= \{\neg a \lor \neg c \lor d \lor e\} \cup \{d \lor \neg e \lor a\}\\
  &= \{\neg a \lor \neg c \lor d \lor e, d \lor \neg e \lor a\}\\
NEG_{\lambda}(\alpha) &= \{\neg a \lor \neg c \lor d \lor e\} \cup \{\neg a \lor c, c \lor a \lor e\}\\
  &= \{\neg a \lor \neg c \lor d \lor e, \neg a \lor c, c \lor a \lor e\}\\
\end{align}
$$
Pentru $\lambda=\neg e$
$$
\alpha_{\lambda}^{+} = \{\neg b \lor d \lor \neg e \lor a\}\\
\alpha_{\lambda}^{-} = \{\neg a \lor \neg c \lor d \lor e, b \lor c \lor a \lor e\}\\
\alpha_{\lambda}^{0} = \{\neg a \lor b \lor c\}\\
\begin{align}
POS_{\lambda}(\alpha) &= \{\neg a \lor b \lor c\} \cup \{\neg b \lor d \lor a\}\\
  &= \{\neg a \lor b \lor c, \neg b \lor d \lor a\}\\
NEG_{\lambda}(\alpha) &= \{\neg a \lor b \lor c\} \cup \{\neg a \lor \neg c \lor d, b \lor c \lor a\}\\
  &= \{\neg a \lor b \lor c, \neg a \lor \neg c \lor d, b \lor c \lor a\}\\
\end{align}
$$


### Exerciţiul 1.0.2.

Să se calculeze mulţimile $\alpha_{\lambda}^{+}$, $\alpha_{\lambda}^{-}$, $\alpha_{\lambda}^{0}$, $POS_{\lambda}(\alpha)$, $NEG_{\lambda}(\alpha)$ pentru:

a) $S(\alpha) = \{\beta \lor \omega \lor \neg \theta, \neg \omega \lor \gamma \lor \neg \beta, \beta \lor \theta \lor \neg \omega, \neg \beta \lor \neg \theta \lor \omega \}$ şi $\lambda_{1}=\beta$, respectiv $\lambda_{2}=\neg \gamma$.

Pentru $\lambda=\beta$
$$
\alpha_{\lambda}^{+} = \{\beta \lor \omega \lor \neg\theta, \beta \lor \theta \lor \neg\omega\}\\
\alpha_{\lambda}^{-} = \{\neg\omega \lor \gamma \lor \neg\beta, \neg\beta \lor \neg\theta \lor \omega\}\\
\alpha_{\lambda}^{0} = \{\square\}\\
\begin{align}
POS_{\lambda}(\alpha) &= \{\square\} \cup \{\omega \lor \neg\theta, \theta \lor \neg\omega\}\\
  &= \{\square, \omega \lor \neg\theta, \theta \lor \neg\omega\}\\
NEG_{\lambda}(\alpha) &= \{\square\} \cup \{\neg\omega \lor \gamma, \neg\theta \lor \omega\}\\
  &= \{\square, \neg\omega \lor \gamma, \neg\theta \lor \omega\}\\
\end{align}
$$
Pentru $\lambda=\neg \gamma$
$$
\alpha_{\lambda}^{+} = \{\square\}\\
\alpha_{\lambda}^{-} = \{\neg\omega \lor \gamma \lor \neg\beta\}\\
\alpha_{\lambda}^{0} = \{\beta \lor \omega \lor \neg\theta, \beta \lor \theta \lor \neg\omega, \neg\beta \lor \neg\theta \lor \omega\}\\
\begin{align}
POS_{\lambda}(\alpha) &= \{\beta \lor \omega \lor \neg\theta, \beta \lor \theta \lor \neg\omega, \neg\beta \lor \neg\theta \lor \omega\} \cup \{\square\}\\
  &= \{\beta \lor \omega \lor \neg\theta, \beta \lor \theta \lor \neg\omega, \neg\beta \lor \neg\theta \lor \omega,\square\}\\
NEG_{\lambda}(\alpha) &= \{\beta \lor \omega \lor \neg\theta, \beta \lor \theta \lor \neg\omega, \neg\beta \lor \neg\theta \lor \omega\} \cup \{\neg\omega \lor \neg\beta\}\\
  &= \{\beta \lor \omega \lor \neg\theta, \beta \lor \theta \lor \neg\omega, \neg\beta \lor \neg\theta \lor \omega, \neg\omega \lor \neg\beta\}\\
\end{align}
$$
b) $S(\alpha) = \{\neg\gamma \lor \theta \lor \psi, \neg\theta \lor \beta \lor \neg\delta \lor \gamma, \neg\gamma \lor \neg\psi \lor \beta \lor \delta, \theta \lor \psi \lor \gamma \lor \delta \}$ şi $\lambda_{1}=\neg\theta$, respectiv $\lambda_{2}=\neg\delta$.

Pentru $\lambda=\neg\theta$
$$
\alpha_{\lambda}^{+} = \{\neg\theta \lor \beta \lor \neg\delta \lor \gamma\}\\
\alpha_{\lambda}^{-} = \{\neg\gamma \lor \theta \lor \psi, \theta \lor \psi \lor \gamma \lor \delta\}\\
\alpha_{\lambda}^{0} = \{\neg\gamma \lor \neg\psi \lor \beta \lor \delta\}\\
\begin{align}
POS_{\lambda}(\alpha) &= \{\neg\gamma \lor \neg\psi \lor \beta \lor \delta\} \cup \{\beta \lor \neg\delta \lor \gamma\}\\
  &= \{\neg\gamma \lor \neg\psi \lor \beta \lor \delta,\beta \lor \neg\delta \lor \gamma\}\\
NEG_{\lambda}(\alpha) &= \{\neg\gamma \lor \neg\psi \lor \beta \lor \delta\} \cup \{\neg\gamma \lor \psi,\psi \lor \gamma \lor \delta\}\\
  &= \{\neg\gamma \lor \neg\psi \lor \beta \lor \delta,\neg\gamma \lor \psi,\psi \lor \gamma \lor \delta\}\\
\end{align}
$$
Pentru $\lambda=\neg\delta$
$$
\alpha_{\lambda}^{+} = \{\neg\theta \lor \beta \lor \neg\delta \lor \gamma\}\\
\alpha_{\lambda}^{-} = \{\neg\gamma \lor \neg\psi \lor \beta \lor \delta,\theta \lor \psi \lor \gamma \lor \delta\}\\
\alpha_{\lambda}^{0} = \{\neg\gamma \lor \theta \lor \psi\}\\
\begin{align}
POS_{\lambda}(\alpha) &= \{\neg\gamma \lor \theta \lor \psi\} \cup \{\neg\theta \lor \beta \lor \gamma\}\\
  &= \{\neg\gamma \lor \theta \lor \psi,\neg\theta \lor \beta \lor \gamma\}\\
NEG_{\lambda}(\alpha) &= \{\neg\gamma \lor \theta \lor \psi\} \cup \{\neg\gamma \lor \neg\psi \lor \beta,\theta \lor \psi \lor \gamma\}\\
  &= \{\neg\gamma \lor \theta \lor \psi,\neg\gamma \lor \neg\psi \lor \beta,\theta \lor \psi \lor \gamma\}\\
\end{align}
$$

