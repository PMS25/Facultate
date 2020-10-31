1. Care dintre următoarele funcții sunt asimpotic pozitive?

$$
\begin{align*}
a)\ &\ f_1(n) = \sqrt{\frac{n-7}{10n - n^2}} \\
b)\ &\ f_2(n) = \frac{n^2 - 1}{sin(\frac{n \cdot \pi}{2})} \\
c)\ &\ f_3(n) = \frac{2 + \sqrt{n^2 - 16} - n}{ln(n^2 - 10n + 25)} \\
d)\ &\ f_4(n) = (100 - n!) \cdot 2^{50 - n} \\
\end{align*}
$$

**Rezolvare:**

a) Funcția $f_1 : D \to \R$, $f_1(n) = \sqrt{\frac{n-7}{10n - n^2}}$, unde $D = \{n\in\R\ |\ n>7\ si\ n<10 \}$, nu este aimptotic pozitivă deoarece nu există $A$ (finită) astfel încât $D = N \setminus A$.

b) Funcția $f_2 : D \to \R$, $f_2(n) = \frac{n^2 - 1}{sin(\frac{n \cdot \pi}{2})}$, unde $D = N$, nu este asimpotic pozitivă deoarece nu există $A$ (finită) astfel încât $D = N \setminus A$.

c) Funcția $f_3 : D \to \R$, $f_3(n) = \frac{2 + \sqrt{n^2 - 16} - n}{ln(n^2 - 10n + 25)}$, unde $D = \{n \in \N \ |\ n \ge 7\}$, este asimptotic pozitivă, deoarece $D = N \setminus A$ cu $A = \{0,1,2,3,4,5,6\}$ (mulțime finită) și $f_3(n) > 0,\ \forall\ n \ge 7$.

d) Funcția $f : D \to \R$, $f_4(n) = (100 - n!) \cdot 2^{50 - n}$, unde $D = N$, nu este aimptotic pozitivă deoarece nu există $A$ (finită) astfel încât $D = N \setminus A$.

2. Demonstrați că:

$$
\begin{align*}
a)\ &\ n \cdot lnn = O(n^2) \\
a)\ &\ n \sqrt{n} = \Omega(n \cdot lnn) \\
a)\ &\ n! = \Omega(e^n) \\
a)\ &\ n! = O(n^n) \\
\end{align*}
$$

**Rezolvare:**

a) Întrucât $lim_{n \to \infty} \frac{n \cdot ln n}{n^2} = lim_{n \to \infty} \frac{ln n}{n} = 0$ ($n$ tinde mai rapid la $\infty$) și $0 \in [0, + \infty)$ $\implies n \cdot lnn = O(n^2)$

b) Deoarece $lim_{n \to \infty} \frac{n \cdot \sqrt{n}}{n \cdot lnn} = lim_{n \to \infty} \frac{\sqrt{n}}{lnn} = \infty$ ($\sqrt{n}$ tinde mai rapid la $\infty$) și $\infty \in (0, +\infty]$ $\implies n \sqrt{n} = \Omega(n \cdot lnn)$.

c) Deoarece $lim_{n \to \infty} \frac{n!}{e^n} = \infty$ ($n!$ tinde mai rapid la $\infty$) și $\infty \in (0, +\infty]$ $\implies n! = \Omega(e^n)$.

d) Întrucât $lim_{n \to \infty} \frac{n!}{n^n} = 0$ ($n!$ tinde mai rapid la $\infty$) și $0 \in [0, +\infty)$ $\implies n! = O(n^n)$.