# Temă03  -  Selectarea datelor din mai multe tabele

## Petculescu Mihai-Silviu

- [Temă03  -  Selectarea datelor din mai multe tabele](#temă03---selectarea-datelor-din-mai-multe-tabele)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)

1. Afişare Nume Autor + Denumire Carte

```sql
-- Afisare Nume Autor + Denumire Carte
SELECT Nume, Denumire
FROM Colectie.tAutori as A RIGHT JOIN Colectie.tCarti as B
ON A.idAutor = B.idAutor 
```

**Rezultat**

```bash
Nume               |Denumire                             |
-------------------|-------------------------------------|
Agnes Martin Lugand|Înca aud muzica noastra în gând      |
Alexandr Soljenitîn|O zi din viata lui Ivan Denisovici   |
Amelie Nothomb     |V19 Barba albastra                   |
Andrew Crumey      |Mobius Dick                          |
Camilla Lackberg   |Fjallbacka - V6 Sirena               |
Camilla Lackberg   |Fjallbacka - V7 Paznicul farului     |
Camilla Lackberg   |Fjallbacka - V8 Fauritoarea de îngeri|
Catherine Isaac    |Aici, acum, mereu                    |
Charles Berlitz    |Misterul lumilor uitate              |
Charlie Jane Anders|Orasul de la miezul noptii           |
Christina Dalcher  |Tacerea poate fi asurzitoare         |
```

2. Afişare idHost + Denumire_Fişier

```sql
SELECT idHost as [ID], Denumire as [File]
FROM Colectie.tHost AS A LEFT JOIN Colectie.tFisiere as B
ON A.idFisier = B.idFisier 
```

**Rezultat**

```bash
ID        |File                                                                            |
----------|--------------------------------------------------------------------------------|
28151eohux|Alexandr Soljenitîn - O zi din viata lui Ivan Denisovici 1.0 {Literatura}.docx  |
29q2ygf3e6|Andrew Crumey - Mobius Dick 1.0 10 {Literatura}.rtf                             |
2hfvz9ad86|Andrew Crumey - Mobius Dick 1.0 {Literatura}.docx                               |
3f964odvw6|Christina Dalcher - Tacerea poate fi asurzitoare 1.0 10 {SF}.rtf                |
4ky6orfjah|Christina Dalcher - Tacerea poate fi asurzitoare 1.0 {SF}.docx                  |
7akrk0ert0|Camilla Lackberg - Fjallbacka - V8 Fauritoarea de îngeri 1.1 10 {Politista}.rtf |
7b0l1wpllj|Agnes Martin Lugand - Înca aud muzica noastra în gând 1.0 {Dragoste}.docx       |
7hgfjqvqsu|Camilla Lackberg - Fjallbacka - V6 Sirena 1.1 {Politista}.docx                  |
9mfzaonrek|Catherine Isaac - Aici, acum, mereu 1.0 {Literatura}.docx                       |
arxkjc2rnq|Camilla Lackberg - Fjallbacka - V8 Fauritoarea de îngeri 1.1 {Politista}.docx   |
bn9gzc2yyd|Camilla Lackberg - Fjallbacka - V7 Paznicul farului 1.1 {Politista}.docx        |
gahj8wt25l|Catherine Isaac - Aici, acum, mereu 1.0 10 {Literatura}.rtf                     |
ktt0swufn1|Alexandr Soljenitîn - O zi din viata lui Ivan Denisovici 1.0 10 {Literatura}.rtf|
q3xchig4u9|Charles Berlitz - Misterul lumilor uitate 1.0 ^{Mister si Stiinta}.docx         |
quq91yv0ty|Camilla Lackberg - Fjallbacka - V6 Sirena 1.1 10 {Politista}.rtf                |
tczrxs6vno|Amelie Nothomb - V19 Barba albastra 1.0 10 {Thriller}.rtf                       |
u5e8eh4k3z|Charlie Jane Anders - Orasul de la miezul noptii 1.0 {SF}.docx                  |
xx25soydmq|Amelie Nothomb - V19 Barba albastra 1.0 {Thriller}.docx                         |
xztgtmla34|Charlie Jane Anders - Orasul de la miezul noptii 1.0 10 {SF}.rtf                |
z2xsl23jd3|Agnes Martin Lugand - Înca aud muzica noastra în gând 1.0 10 {Dragoste}.rtf     |
```

3. Afişare ultimele cărţi actualizare

```sql
SELECT DISTINCT C.Denumire AS [Carte], H.dataModificare AS [Data]
FROM Colectie.tCarti AS C
INNER JOIN Colectie.tFisiere AS F ON C.idCarte  = F.idCarte 
INNER JOIN Colectie.tHost AS H ON F.idFisier = H.idFisier 
ORDER BY H.dataModificare DESC
```

**Rezultat**

```bash
Carte                                |Data               |
-------------------------------------|-------------------|
Orasul de la miezul noptii           |2020-05-04 00:00:00|
Tacerea poate fi asurzitoare         |2020-05-04 00:00:00|
Aici, acum, mereu                    |2020-04-29 00:00:00|
Misterul lumilor uitate              |2020-04-29 00:00:00|
Aici, acum, mereu                    |2020-04-28 00:00:00|
Fjallbacka - V8 Fauritoarea de îngeri|2020-04-28 00:00:00|
Fjallbacka - V7 Paznicul farului     |2020-04-26 00:00:00|
Fjallbacka - V6 Sirena               |2020-04-25 00:00:00|
Fjallbacka - V6 Sirena               |2020-04-21 00:00:00|
Mobius Dick                          |2020-04-20 00:00:00|
V19 Barba albastra                   |2020-04-17 00:00:00|
Înca aud muzica noastra în gând      |2020-04-16 00:00:00|
O zi din viata lui Ivan Denisovici   |2020-04-16 00:00:00|
Înca aud muzica noastra în gând      |2020-04-15 00:00:00|
```