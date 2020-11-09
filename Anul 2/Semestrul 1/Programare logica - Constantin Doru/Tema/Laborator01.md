# Laborator01

## Petculescu Mihai-Silviu

[TOC]

## Aplicaţia 1.

Se consideră următoarea bază de cunoştinţe cu informaţii privind anumite firme şi produsele distribuite.

- Magic srl vinde calculatoare şi accesorii.
- Alfa sa vinde televizoare şi calculatoare
- Beta sa vinde accesorii.

### Cerinţe

### SWI-Prolog

```apl
vinde(magicsrl,calculatoare).
vinde(magicsrl,accesorii).
vinde(alfasa,calculatoare).
vinde(alfasa,televizoare).
vinde(betasa,accesorii).
```

### A. Vinde AlfaSA calculatoare?

```apl
?- vinde(alfasa,calculatoare).
true.
```

### B. Vinde BetaSA televizoare?

```apl
?- vinde(betasa,televizoare).
false.
```

### C. Ce vinde MagicSRL?

```apl
?- vinde(magicsrl,X).
X = calculatoare ;
X = accesorii.
```

### D. Cine vinde calculatoare?

```apl
?- vinde(Y,calculatoare).
Y = magicsrl ;
Y = alfasa.
```

### E. Vinde AlfaSA ceva?

```apl
?- vinde(alfasa,_).
true.
```

### F. Vinde cineva accesorii?

```apl
?- vinde(_, accesorii).
true.
```

### G. Cine vinde la fel ca BetaSA un anumit produs?

```apl
?- vinde(betasa,X), vinde(Y,X), Y='betasa'.
X = accesorii,
Y = betasa.
```

### H. Cine vinde ce?

```apl
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

### I. Vinde cineva ceva?

```apl
?- vinde(_,_).
true.
```

## Aplicaţia 2.

Se consideră următoarea bază de cunoştinţe cu informaţii privind anumite persoane şi produsele distribuite.

- Alex vinde trandafiri, lalele şi crizanteme.
- Ana vinde lalele şi crini.
- Andu vinde lalele şi nuci.

### Cerinţe

### SWI-Prolog

```apl
vinde(alex, trandafiri).
vinde(alex, lalele).
vinde(alex, crizanteme).
vinde(ana, lalele).
vinde(ana, crini).
vinde(andu, lalele).
vinde(andu, nuci).
```

### 1. Vinde Andrei lalele?

```apl
?- vinde(andrei,lalele).
false.
```

### 2. Cine vinde crizanteme?

```apl
?- vinde(X,crizanteme).
X = alex.
```

### 3. Ce vinde Ana?

```apl
?- vinde(ana,Y).
Y = lalele;
Y = crini.
```

