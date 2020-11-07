# Laborator01 - Tema

2. Se consideră următoarea bază de cunoștințe cu informații privind anumite persoane și produsele distribuite.
   - Alex vinde trandafiri, lalele și crizanteme.
   - Ana vinde lalele și crini.
   - Andu vinde lalele și nuci.

```
CERINŢE
1. Vinde Andrei lalele?
2. Cine vinde crizanteme?
3. Ce vinde Ana? 
```

**Rezolvare**

```apl
# [tema01]
vinde(alex, trandafiri).
vinde(alex, lalele).
vinde(alex, crizanteme).
vinde(ana, lalele).
vinde(ana, crini).
vinde(andu, lalele).
vinde(andu, nuci).
```

```apl
# 1. Vinde Andrei lalele?
?- vinde(andrei,lalele).
false.
```

```apl
# 2. Cine vinde crizanteme?
?- vinde(X,crizanteme).
X = alex.
```

```apl
# 3. Ce vinde Ana?
?- vinde(ana,Y).
Y = lalele;
Y = crini.
```

