# Laborator 01

## Petculescu Mihai-Silviu

[TOC] 

### Comenzi în R

```R
# Operatii aritmetice
> 5 - 1 + 10 - 7 * 10 / 2
[1] -21

# Functii matematice
> exp(-2.19)
[1] 0.1119167
> sin(2 * pi / 3)
[1] 0.8660254

# Constanta matematica
> pi
[1] 3.141593

# Variabile
> a = (1 + sqrt(5) / 2) / 2
> a
[1] 1.059017
> asq = sqrt(a)
> asq
[1] 1.029086

# Listare variabile
> ls()
[1] "a"   "asq"
> ls.str()
a :  num 1.06
asq :  num 1.03

# Eliminare variabile din memorie
> rm(list = ls())
> a
Error: object 'a' not found

# Cautare obiecte / functii din sesiunea curenta
> apropos("mean") # contine <mean>
[1] ".colMeans"     ".rowMeans"     "colMeans"      "kmeans"       
[5] "mean"          "mean.Date"     "mean.default"  "mean.difftime"
[9] "mean.POSIXct"  "mean.POSIXlt"  "rowMeans"      "weighted.mean"

> apropos("^mean") # incepe cu <mean>
[1] "mean"          "mean.Date"     "mean.default"  "mean.difftime"
[5] "mean.POSIXct"  "mean.POSIXlt" 

> apropos("mean", mode = "functions") # functiile ce contin <mean>
character(0)

# Alte functii
> help.start() # Manual de utilizare
> help("nume") [sau] ?nume # Documentatia privind functia <nume>
> example("nume") # Exemple de utilizare a functiei <nume>
> data() # Listare setari pentru pachetele incarcate
> vignette() # Listare toate vinietele disponibile
> vignette("nume") # Afisare vinietele corespunzatoare topicului <nume>
```

