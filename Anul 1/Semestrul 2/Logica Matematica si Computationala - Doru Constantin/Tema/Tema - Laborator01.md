# Laborator 1 - Temă

## Petculescu Mihai-Silviu

- [Laborator 1 - Temă](#laborator-1---temă)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [Exerciţiu 1.2.1. Să se stabilească forma CNF pentru expresiile logice:](#exerciţiu-121-să-se-stabilească-forma-cnf-pentru-expresiile-logice)
    - [Exerciţiu 1.2.2. Reduceţi la CNF următoarele formule:](#exerciţiu-122-reduceţi-la-cnf-următoarele-formule)

### Exerciţiu 1.2.1. Să se stabilească forma CNF pentru expresiile logice:

1. $ (a \to b) \to c $
   
   $$
   \neg(a \to b) \or c \\
\neg(\neg a \or b) \or c \\
(a \and \neg b) \or c \\
(a \or c) \and (\neg b \or c)
   $$

2. $ (a \to b) \or (b \to a) $
   
   $$
   \neg a \or b \or \neg b \or a\\
   \square
   $$
   
3. $ \neg a \to (a \to b) $
   
   $$
   a \or (a \to b) \\
a \or \neg a \or b \\
   b
   $$
4. $ (a \to (b \to c)) \to (a \to (c \to b)) $
   $$
   (\neg a \or (\neg b \or c)) \to (\neg a \or (\neg c \or b)) \\
\neg (\neg a \or (\neg b \or c)) \or (\neg a \or (\neg c \or b)) \\
(a \and b \and \neg c) \or (\neg a \or \neg c \or b) \\
(a \or \neg a \or \neg c \or b) \and (b \or \neg a \or \neg c \or b) \and (\neg c \or \neg a \or \neg c \or b)\\
(\neg c \or b) \and (\neg a \or \neg c) \and (\neg a \or b)
   $$
5. $ (a \to b) \to ((b \to c) \to (a \to c)) $
   
   $$
   (\neg a \or b) \to (\neg (\neg b \or c) \or (\neg a \or c)) \\
\neg (\neg a \or b) \or (\neg (\neg b \or c) \or (\neg a \or c)) \\
(a \and \neg b) \or (b \and \neg c) \or (\neg a \or c) \\
(a \and \neg b) \or ((b \or \neg a \or c) \and (\neg c \or \neg a \or c)) \\
(a \and \neg b) \or ((b \or \neg a \or c) \and \neg a) \\
(a \or ((b \or \neg a \or c) \and \neg a)) \and (\neg b \or ((b \or \neg a \or c) \and \neg a))\\
   (a \or b \or \neg a \or c) \and (a \or \neg a) \and (\neg b \or b \or \neg a \or c) \and (\neg b \or \neg a))\\
   (b \or c) \and (\neg a \or c) \and (\neg b \or \neg a)
   $$
### Exerciţiu 1.2.2. Reduceţi la CNF următoarele formule:

1. $ p \to (q \and r)$
   $$
   \neg p \or (q \and r) \\
(\neg p \or q) \and (\neg p \or r)
   $$
   
2. $ (p \or q) \to r $
   
   $$
   \neg (p \or q) \or r \\
(\neg p \and \neg q) \or r \\
   (\neg p \or r) \and (\neg q \or r)
   $$
   
3. $ \neg(\neg p \or q) \or (r \to \neg s) $
   
   $$
   \neg (\neg p \or q) \or (\neg r \or \neg s) \\
(p \and \neg q) \or (\neg r \or \neg s) \\
(p \or \neg r \or \neg s) \and (\neg q \or \neg r \or \neg s)
   $$
   
4. $ \neg(p \to (q \to r)) \to ((p \to q) \to (p \to r)) $
   

$$
(\neg p \or (\neg q \or r)) \or (\neg (\neg p \or q) \or (\neg p \or r)) \\
(\neg p \or \neg q \or r) \or ((p \and \neg q) \or (\neg p \or r))\\
(\neg p \or \neg q \or r) \or (p \and \neg q)\\
(p \or \neg p \or \neg q \or r) \and (\neg q \or \neg p \or \neg q \or r)\\
(\neg q \or r) \and (\neg p \or \neg q \or r)\\
$$

5. $ \neg(((a \to b) \to a) \to a) $
   
$$
\neg(\neg(\neg(\neg a \or b) \or a) \or a) \\
\neg(\neg(a \and \neg b) \or a) \\
\neg(\neg a \or b \or a) \\
\neg b
$$
6. $ \neg(a \or (a \to b)) $
   
$$
\neg(a \or \neg a \or b) \\
\neg b
$$
7. $ ((x \to y) \to (z \to \neg x)) \to (\neg y \to \neg z)$
$$
((\neg x \or y) \to (\neg z \or \neg x)) \to (y \or \neg z) \\
\neg(\neg(\neg x \or y) \or (\neg z \or \neg x)) \or (y \or \neg z) \\
\neg((x \and \neg y) \or (\neg z \or \neg x)) \or (y \or \neg z) \\
((\neg x \or y) \and z \and x) \or (y \or \neg z) \\
(\neg x \and z \and x) \or (y \and z \and x) \or (y \or \neg z) \\
(y \and z \and x) \or (y \or \neg z) \\
(y \or \neg z) \and y \and (x \or y \or \neg z)
$$

