# Temă04 - Subinterogări 

## Petculescu Mihai-Silviu

- [Temă04 - Subinterogări](#temă04---subinterogări)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)

1. Selectează numărul de cărţi ale autorului cu id-ul 5

```sql
SELECT COUNT(idCarte) AS 'Numar de carti' FROM Colectie.tCarti WHERE idAutor = 5
```

**Rezultat**

```bash
Numar de carti|
--------------|
             3|
```

2. Selectează numărul mediu de pagini al cărtilor disponibile

```sql
SELECT AVG(nrPagini) as 'Nr mediu de pagini' FROM Colectie.tFisiere
```

**Rezultat**

```bash
Nr mediu de pagini|
------------------|
               367|
```

3. Deteminaţi numărul mediu al reviziilor (ediţiilor) la care se află cărţile

```sql
SELECT AVG(Editie) as 'Editie' FROM Colectie.tCarti
```

**Rezultat**

```bash
Editie|
------|
     1|
```

4. Determinaţi numărul de pagini minime pentru fiecare carte în parte

```sql
SELECT C.idCarte AS 'ID', C.idAutor AS 'ID Autor', C.Denumire AS 'Nume', F.nrPagini AS 'Numar Pagini' FROM Colectie.tCarti AS C INNER JOIN Colectie.tFisiere AS F ON C.idCarte = F.idCarte
WHERE nrPagini = (SELECT MIN(nrPagini) AS Pagini FROM Colectie.tFisiere WHERE idCarte = C.idCarte)
```

**Rezultat**

```bash
ID|ID Autor|Nume                                 |Numar Pagini|
--|--------|-------------------------------------|------------|
 1|       1|Înca aud muzica noastra în gând      |         500|
 2|       2|O zi din viata lui Ivan Denisovici   |         380|
 3|       3|V19 Barba albastra                   |         450|
 4|       4|Mobius Dick                          |         590|
 5|       5|Fjallbacka - V6 Sirena               |         280|
 6|       5|Fjallbacka - V7 Paznicul farului     |         330|
 7|       5|Fjallbacka - V8 Fauritoarea de îngeri|         170|
 8|       6|Aici, acum, mereu                    |         250|
 9|       7|Misterul lumilor uitate              |         570|
10|       8|Orasul de la miezul noptii           |         230|
11|       9|Tacerea poate fi asurzitoare         |         278|
```