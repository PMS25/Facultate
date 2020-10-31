# Laborator6 - Temă

## Petculescu Mihai-Silviu

- [Laborator6 - Temă](#laborator6---temă)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [Exerciţiu 1.0.1. Să se construiască arborii semantici pentru următoarele formule:](#exerciţiu-101-să-se-construiască-arborii-semantici-pentru-următoarele-formule)

### Exerciţiu 1.0.1. Să se construiască arborii semantici pentru următoarele formule:

1) $(a \and b) \leftrightarrow (a \to (a \to \neg b))$

```mermaid
graph TD
  r("(a ∧ b) ↔ (a → (a → ¬b))")
  n1("{(a ∧ b) → (a → (a → ¬b)), (a → (a → ¬b)) → (a ∧ b)}")
  n2("{(a ∧ b) → (a → (a → ¬b)), ¬(a → (a → ¬b))}")
  n3("{(a ∧ b) → (a → (a → ¬b)), a ∧ b}")
  n4("{(a ∧ b) → (a → (a → ¬b)), a, ¬(a → ¬b))}")
  n5("{(a ∧ b) → (a → (a → ¬b)), a, b}")
  n6("{(a ∧ b) → (a → (a → ¬b)), a, ¬¬b)}")
  n7("{(a ∧ b) → (a → (a → ¬b)), a, b}")
  n8("{¬(a ∧ b), a, b}")
  n9("{a → (a → ¬b), a, b}")
  n10("{¬a, a, b}")
  n11("{a, b, ¬b}")
  n12("{¬a, a, b}")
  n13("{a → ¬b, a, b}")
  n14("{¬a, a, b}")
  n15("{¬b, a, b}")
  n16("{¬(a ∧ b), a, b}")
  n17("{a → (a → ¬b), a, b}")
  n18("{¬a, a, b}")
  n19("{a, b, ¬b}")
  n20("{¬a, a, b}")
  n21("{a → ¬b, a, b}")
  n22("{¬a, a, b}")
  n23("{¬b, a, b}")
  r --> n1
  n1 --> n2 --> n4 --> n6 --> n7
  n1 --> n3 --> n5
  n7 --> n8
  n7 --> n9
  n8 --> n10 --> x1("X")
  n8 --> n11 --> x2("X")
  n9 --> n12 --> x3("X")
  n9 --> n13
  n13 --> n14 --> x4("X")
  n13 --> n15 --> x5("X")
  n5 --> n16
  n5 --> n17
  n16 --> n18 --> x6("X")
  n16 --> n19 --> x7("X")
  n17 --> n20 --> x8("X")
  n17 --> n21
  n21 --> n22 --> x9("X")
  n21 --> n23 --> x10("X")
```

2) $(\neg b \to (\neg a \to b) \leftrightarrow b)$

```mermaid
graph TD
  r("(¬b → (¬a → b)) ↔ b")
  n1("{(¬b → (¬a → b)) → b, b → (¬b → (¬a → b))}")
  n2("{¬(¬b → (¬a → b)), b → (¬b → (¬a → b))}")
  n3("{b, b → (¬b → (¬a → b))}")
  n4("{¬b, ¬(¬a → b), b → (¬b → (¬a → b))}")
  n5("{¬b, ¬a, b → (¬b → (¬a → b))}")
  n6("{¬b, ¬a}")
  n7("{¬b, ¬a, ¬b → (¬a → b}")
  n8("{¬b, ¬a, ¬¬b}")
  n9("{¬b, ¬a, ¬a → b}")
  n10("{¬b, ¬a, b}")
  n11("{¬b, ¬a, ¬¬a}")
  n12("{¬b, ¬a, b}")
  n13("{¬b, ¬a, a}")
  n14("{b, ¬b}")
  n15("{b, ¬b → (¬a → b)}")
  n16("{b, ¬¬b}")
  n17("{b, ¬a → b}")
  n18("{b}")
  n19("{b, ¬¬a}")
  n20("{b}")
  n21("{b, a}")
  r --> n1
  n1 --> n2 --> n4 --> n5
  n1 --> n3
  n5 --> n6 --> o1("O")
  n5 --> n7
  n7 --> n8 --> n10 --> x1("X")
  n7 --> n9
  n9 --> n11 --> n13 --> x2("X")
  n9 --> n12 --> x3("X")
  n3 --> n14 --> x4("X")
  n3 --> n15
  n15 --> n16 --> n18 --> o2("O")
  n15 --> n17
  n17 --> n19 --> n21 --> o3("O")
  n17 --> n20 --> o4("O")
```

3) $a \to (b \to (a \or \neg b))$

```mermaid
graph TD
  r("a → (b → (a ∨ ¬b))")
  n1("{¬a}")
  n2("{b → (a ∨ ¬b)}")
  n3("{¬b}")
  n4("{a ∨ ¬b}")
  n5("{a}")
  n6("{¬b}")
  r --> n1 --> o1("O")
  r --> n2
  n2 --> n3 --> o2("O")
  n2 --> n4
  n4 --> n5 --> o3("O")
  n4 --> n6 --> o4("O")
```

4) $(\neg a \to \neg b) \to \neg (a \to b)$

```mermaid
graph TD
  r("(¬a → ¬b) → ¬(a → b)")
  n1("{¬(¬a → ¬b)}")
  n2("{¬(a → b)}")
  n3("{¬a, ¬¬b}")
  n4("{¬a, b}")
  n5("{a, ¬b)}")
  r --> n1 --> n3 --> n4 --> o1("O")
  r --> n2 --> n5 --> o2("O")
```

5) $(\neg b \to a) \to (\neg a \to c)$

```mermaid
graph TD
  r("(¬b → a) → (¬a → c)")
  n1("{¬(¬b → a)}")
  n2("{¬a → c}")
  n3("{¬b, ¬a}")
  n4("{¬¬a}")
  n5("{c}")
  n6("{a}")
  r --> n1 --> n3 --> o1("O")
  r --> n2
  n2 --> n4 --> n6 --> o2("O")
  n2 --> n5 --> o3("O")
```

6) $(a \or b) \to ((a \or b) \to (\neg b \to a))$

```mermaid
graph TD
  r("(a ∨ b) → ((a ∨ b) → (¬b → a))")
  n1("{¬(a ∨ b)}")
  n2("{(a ∨ b) → (¬b → a)}")
  n3("{¬(a ∨ b)}")
  n4("{¬b → a}")
  n5("{¬a, ¬b}")
  n6("{¬a, ¬b}")
  n7("{¬¬b}")
  n8("{a}")
  n9("{b}")
  r --> n1 --> n5 --> o1("O")
  r --> n2
  n2 --> n3 --> n6 --> o2("O")
  n2 --> n4
  n4 --> n7 --> n9 --> o3("O")
  n4 --> n8 --> o4("O")
  
```

7) $(b \to \neg a) \to ((\neg a \or \neg b) \to b)$

```mermaid
graph TD
  r("(b → ¬a) → ((¬a ∨ ¬b) → b)")
  n1("{¬(b → ¬a)}")
  n2("{(¬a ∨ ¬b) → b}")
  n3("{b, ¬¬a}")
  n4("{b, a}")
  n5("{¬(¬a ∨ ¬b)}")
  n6("{b}")
  n7("{¬¬a, ¬¬b}")
  n8("{a, b}")
  r --> n1 --> n3 --> n4 --> o1("O")
  r --> n2
  n2 --> n5 --> n7 --> n8 --> o2("O")
  n2 --> n6 --> o3("O")
```

8) $\neg(\neg(a \or \neg b) \and \neg (a \or b))$

```mermaid
graph TD
  r("¬(¬(a ∨ ¬b) ∧ ¬(a ∨ b))")
  n1("{¬¬(a ∨ ¬b)}")
  n2("{¬¬(a ∨ b)}")
  n3("{a ∨ ¬b}")
  n4("{a ∨ b}")
  n5("{a}")
  n6("{¬b}")
  n7("{a}")
  n8("{b}")
  r --> n1 --> n3
  r --> n2 --> n4
  n3 --> n5 --> o1("O")
  n3 --> n6 --> o2("O")
  n4 --> n7 --> o3("O")
  n4 --> n8 --> o4("O")
```

9) $(p \or (q \and \neg p)) \and (\neg p \or q \or \neg p)$

```mermaid
graph TD
  r("(p ∨ (q ∧ ¬p)) ∧ (¬p ∨ q ∨ ¬p)")
  n1("{p ∨ (q ∧ ¬p), ¬p ∨ q ∨ ¬p}")
  n2("{p, ¬p ∨ q ∨ ¬p}")
  n3("{q ∧ ¬p, ¬p ∨ q ∨ ¬p}")
  n4("{p, ¬p}")
  n5("{p, q ∨ ¬p}")
  n6("{p, q}")
  n7("{p, ¬p}")
  n8("{q, ¬p, ¬p ∨ q ∨ ¬p}")
  n9("{q, ¬p}")
  n10("{q, ¬p, q ∨ ¬p}")
  n11("{q, ¬p}")
  n12("{q, ¬p}")
  r --> n1
  n1 --> n2
  n1 --> n3 --> n8
  n2 --> n4 --> x1("X")
  n2 --> n5
  n5 --> n6 --> o1("O")
  n5 --> n7 --> x2("X")
  n8 --> n9 --> o2("O")
  n8 --> n10
  n10 --> n11 --> o3("O")
  n10 --> n12 --> o4("O")
```

10) $(a \and \neg b) \or (a \to b)$

```mermaid
graph TD
  r("(a ∧ ¬b) ∨ (a → b)")
  n1("{a ∧ ¬b}")
  n2("{a → b}")
  n3("{a, ¬b}")
  n4("{¬a}")
  n5("{b}")
  r --> n1 --> n3 --> o1("O")
  r --> n2
  n2 --> n4 --> o2("O")
  n2 --> n5 --> o3("O")
```

