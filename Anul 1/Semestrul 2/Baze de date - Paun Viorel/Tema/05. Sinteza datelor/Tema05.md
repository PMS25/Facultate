# Temă05 - Sinteza datelor

## Petculescu Mihai-Silviu

- [Temă05 - Sinteza datelor](#temă05---sinteza-datelor)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
  - [Union](#union)
  - [Intersect](#intersect)
  - [Except](#except)
  - [RollUp](#rollup)
  - [Cube](#cube)
  - [Pivot](#pivot)

## Union

1. Să se afişeze toţi autorii urmaţi de cărţile scrise de fiecare în parte

```sql
SELECT idAutor, Denumire FROM Colectie.tCarti 
UNION
SELECT idAutor, Nume FROM Colectie.tAutori 
```

**Rezultat**

```bash
idAutor|Denumire                             |
-------|-------------------------------------|
      1|Agnes Martin Lugand                  |
      1|Înca aud muzica noastra în gând      |
      2|Alexandr Soljenitîn                  |
      2|O zi din viata lui Ivan Denisovici   |
      3|Amelie Nothomb                       |
      3|V19 Barba albastra                   |
      4|Andrew Crumey                        |
      4|Mobius Dick                          |
      5|Camilla Lackberg                     |
      5|Fjallbacka - V6 Sirena               |
      5|Fjallbacka - V7 Paznicul farului     |
      5|Fjallbacka - V8 Fauritoarea de îngeri|
      6|Aici, acum, mereu                    |
      6|Catherine Isaac                      |
      7|Charles Berlitz                      |
      7|Misterul lumilor uitate              |
      8|Charlie Jane Anders                  |
      8|Orasul de la miezul noptii           |
      9|Christina Dalcher                    |
      9|Tacerea poate fi asurzitoare         |
```

2. Să se afişeze cărţile sortate după format

```sql
SELECT idFormat, Denumire FROM Colectie.tFisiere 
UNION
SELECT idFormat, Extensie FROM Colectie.tFormat 
```

**Rezultat**

```bash
idFormat|Denumire                                                                        |
--------|--------------------------------------------------------------------------------|
       1|Agnes Martin Lugand - Înca aud muzica noastra în gând 1.0 {Dragoste}.docx       |
       1|Alexandr Soljenitîn - O zi din viata lui Ivan Denisovici 1.0 {Literatura}.docx  |
       1|Amelie Nothomb - V19 Barba albastra 1.0 {Thriller}.docx                         |
       1|Andrew Crumey - Mobius Dick 1.0 {Literatura}.docx                               |
       1|Camilla Lackberg - Fjallbacka - V6 Sirena 1.1 {Politista}.docx                  |
       1|Camilla Lackberg - Fjallbacka - V7 Paznicul farului 1.1 {Politista}.docx        |
       1|Camilla Lackberg - Fjallbacka - V8 Fauritoarea de îngeri 1.1 {Politista}.docx   |
       1|Catherine Isaac - Aici, acum, mereu 1.0 {Literatura}.docx                       |
       1|Charles Berlitz - Misterul lumilor uitate 1.0 ^{Mister si Stiinta}.docx         |
       1|Charlie Jane Anders - Orasul de la miezul noptii 1.0 {SF}.docx                  |
       1|Christina Dalcher - Tacerea poate fi asurzitoare 1.0 {SF}.docx                  |
       1|docx                                                                            |
       2|Agnes Martin Lugand - Înca aud muzica noastra în gând 1.0 10 {Dragoste}.rtf     |
       2|Alexandr Soljenitîn - O zi din viata lui Ivan Denisovici 1.0 10 {Literatura}.rtf|
       2|Amelie Nothomb - V19 Barba albastra 1.0 10 {Thriller}.rtf                       |
       2|Andrew Crumey - Mobius Dick 1.0 10 {Literatura}.rtf                             |
       2|Camilla Lackberg - Fjallbacka - V6 Sirena 1.1 10 {Politista}.rtf                |
       2|Camilla Lackberg - Fjallbacka - V8 Fauritoarea de îngeri 1.1 10 {Politista}.rtf |
       2|Catherine Isaac - Aici, acum, mereu 1.0 10 {Literatura}.rtf                     |
       2|Charlie Jane Anders - Orasul de la miezul noptii 1.0 10 {SF}.rtf                |
       2|Christina Dalcher - Tacerea poate fi asurzitoare 1.0 10 {SF}.rtf                |
       2|rtf                                                                             |
```

## Intersect

1. Să se afişeze id-urile cărţilor ce sunt dinsponibile în toate formatele

```sql
SELECT idCarte FROM Colectie.tFisiere WHERE idFormat = 1
intersect
SELECT idCarte FROM Colectie.tFisiere WHERE idFormat = 2
```

**Rezultat**

```bash
idCarte|
-------|
      1|
      2|
      3|
      4|
      5|
      7|
      8|
     10|
     11|
```

2. Să se afişeze cărţile scrise după 2010

```sql
SELECT idCarte, Denumire, anAparitie FROM Colectie.tCarti
INTERSECT
SELECT idCarte, Denumire, anAparitie FROM Colectie.tCarti where anAparitie >= 2010
```

**Rezultat**

```bash
idCarte|Denumire                             |anAparitie|
-------|-------------------------------------|----------|
      1|Înca aud muzica noastra în gând      |      2010|
      2|O zi din viata lui Ivan Denisovici   |      2011|
      7|Fjallbacka - V8 Fauritoarea de îngeri|      2012|
      8|Aici, acum, mereu                    |      2015|
      9|Misterul lumilor uitate              |      2010|
     10|Orasul de la miezul noptii           |      2015|
```

## Except

1. Să se afişeze fişierele cu un număr consistent de pagini (>300)

```sql
SELECT idCarte, Denumire, nrPagini FROM Colectie.tFisiere
EXCEPT
SELECT idCarte, Denumire, nrPagini FROM Colectie.tFisiere WHERE nrPagini < 300
```

**Rezultat**

```bash
idCarte|Denumire                                                                        |nrPagini|
-------|--------------------------------------------------------------------------------|--------|
      1|Agnes Martin Lugand - Înca aud muzica noastra în gând 1.0 {Dragoste}.docx       |     520|
      1|Agnes Martin Lugand - Înca aud muzica noastra în gând 1.0 10 {Dragoste}.rtf     |     500|
      2|Alexandr Soljenitîn - O zi din viata lui Ivan Denisovici 1.0 {Literatura}.docx  |     410|
      2|Alexandr Soljenitîn - O zi din viata lui Ivan Denisovici 1.0 10 {Literatura}.rtf|     380|
      3|Amelie Nothomb - V19 Barba albastra 1.0 {Thriller}.docx                         |     470|
      3|Amelie Nothomb - V19 Barba albastra 1.0 10 {Thriller}.rtf                       |     450|
      4|Andrew Crumey - Mobius Dick 1.0 {Literatura}.docx                               |     590|
      4|Andrew Crumey - Mobius Dick 1.0 10 {Literatura}.rtf                             |     610|
      5|Camilla Lackberg - Fjallbacka - V6 Sirena 1.1 {Politista}.docx                  |     300|
      6|Camilla Lackberg - Fjallbacka - V7 Paznicul farului 1.1 {Politista}.docx        |     330|
      9|Charles Berlitz - Misterul lumilor uitate 1.0 ^{Mister si Stiinta}.docx         |     570|
     11|Christina Dalcher - Tacerea poate fi asurzitoare 1.0 {SF}.docx                  |     302|
```

2. Să se afişeze cărtile cu cea mai recentă corectură (ediţie > 2)

```sql
SELECT idCarte, Denumire, Editie FROM Colectie.tCarti
EXCEPT
SELECT idCarte, Denumire, Editie FROM Colectie.tCarti WHERE Editie < 2
```

**Rezultat**

```bash
idCarte|Denumire                          |Editie|
-------|----------------------------------|------|
      2|O zi din viata lui Ivan Denisovici|     2|
      3|V19 Barba albastra                |     3|
      4|Mobius Dick                       |     2|
     10|Orasul de la miezul noptii        |     2|
     11|Tacerea poate fi asurzitoare      |     2|
```

## RollUp

Să se afişeze o statistică privind anul de apariţie al cărţilor în funcţie de autor

```sql
SELECT A.idAutor, A.Nume, [Media], [Cel mai vechi], [Cel mai recent] FROM Colectie.tAutori AS A
INNER JOIN
(SELECT idAutor,
       avg(anAparitie) AS [Media],
       min(anAparitie) AS [Cel mai vechi],
       max(anAparitie) AS [Cel mai recent]
FROM Colectie.tCarti
group by idAutor with rollup) AS B ON A.idAutor = B.idAutor
```

**Rezultat**

```bash
idAutor|Nume               |Media|Cel mai vechi|Cel mai recent|
-------|-------------------|-----|-------------|--------------|
      1|Agnes Martin Lugand| 2010|         2010|          2010|
      2|Alexandr Soljenitîn| 2011|         2011|          2011|
      3|Amelie Nothomb     | 1980|         1980|          1980|
      4|Andrew Crumey      | 1990|         1990|          1990|
      5|Camilla Lackberg   | 2008|         2005|          2012|
      6|Catherine Isaac    | 2015|         2015|          2015|
      7|Charles Berlitz    | 2010|         2010|          2010|
      8|Charlie Jane Anders| 2015|         2015|          2015|
      9|Christina Dalcher  | 2000|         2000|          2000|
```

## Cube

Să se determine nivelul corecturii (ediţiei), în medie, pentru fiecare autor in parte

```sql
SELECT A.idAutor, A.Nume, [Media] FROM Colectie.tAutori AS A
INNER JOIN
(SELECT idAutor,
       avg(Editie) AS [Media]
FROM Colectie.tCarti
group by idAutor with cube) AS B ON A.idAutor = B.idAutor
```

**Rezultat**

```bash
idAutor|Nume               |Media|
-------|-------------------|-----|
      1|Agnes Martin Lugand|    1|
      2|Alexandr Soljenitîn|    2|
      3|Amelie Nothomb     |    3|
      4|Andrew Crumey      |    2|
      5|Camilla Lackberg   |    1|
      6|Catherine Isaac    |    1|
      7|Charles Berlitz    |    1|
      8|Charlie Jane Anders|    2|
      9|Christina Dalcher  |    2|
```

## Pivot

Să se afişeze, pentru fiecare carte în parte, numărul de pagini asociat fiecărui format în parte

```sql
SELECT idCarte, [1] AS [docx], [2] AS [rtf]
FROM
(SELECT idCarte, idFormat, nrPagini FROM Colectie.tFisiere) AS F
Pivot (MAX(F.nrPagini) FOR idFormat  IN  ([1],[2])) AS pvt
```

**Rezultat**

```bash
idCarte|docx|rtf|
-------|----|---|
      1| 520|500|
      2| 410|380|
      3| 470|450|
      4| 590|610|
      5| 300|280|
      6| 330|   |
      7| 210|170|
      8| 260|250|
      9| 570|   |
     10| 245|230|
     11| 302|278|
```

