# Laborator01

1. Se consideră următoarea bază de cunoștințe cu informații privind anumite firme și produsele distribuite.
- Magic srl vinde calculatoareși accesorii.
- Alfa sa vinde televizoareși calculatoare
- Beta sa vinde accesorii.

```
CERINTE
A. Vinde AlfaSA calculatoare?
B. Vinde BetaSA televizoare?
C. Ce vinde MagicSRL?
D. Cine vinde calculatoare?
E. Vinde AlfaSA ceva?
F. Vinde cineva accesorii?
G. Cine vinde la fel ca BetaSA un anumit produs?
H. Cine vinde ce?
I. Vinde cineva ceva?
```

**Rezolvare**

```apl
# [laborator01].
vinde(magicsrl,calculatoare).
vinde(magicsrl,accesorii).
vinde(alfasa,calculatoare).
vinde(alfasa,televizoare).
vinde(betasa,accesorii).
```

```apl
# A. Vinde AlfaSA calculatoare?
?- vinde(alfasa,calculatoare).
true.
```

```apl
# B. Vinde BetaSA televizoare?
?- vinde(betasa,televizoare).
false.
```

```apl
# C. Ce vinde MagicSRL?
?- vinde(magicsrl,X).
X = calculatoare ;
X = accesorii.
```

```apl
# D. Cine vinde calculatoare?
?- vinde(Y,calculatoare).
Y = magicsrl ;
Y = alfasa.
```

```apl
# E. Vinde AlfaSA ceva?
?- vinde(alfasa,_).
true.
```

```apl
# F. Vinde cineva accesorii?
?- vinde(_, accesorii).
true.
```

```apl
# G. Cine vinde la fel ca BetaSA un anumit produs?
?- vinde(betasa,X), vinde(Y,X), Y='betasa'.
X = accesorii,
Y = betasa.
```

```apl
# H. Cine vinde ce?
?- vinde(X,Y).
X = magicsrl,
Y = calculatoare ;
X = magicsrl,
Y = accesorii ;
X = alfasa,
Y = calculatoare ;
X = alfasa,
Y = televizoare ;
X = betasa,
Y = accesorii.
```

```apl
# I. Vinde cineva ceva?
?- vinde(_,_).
true.
```

