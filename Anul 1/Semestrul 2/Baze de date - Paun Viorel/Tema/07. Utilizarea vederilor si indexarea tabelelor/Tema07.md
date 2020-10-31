# Temă07 - Utilizarea vederilor şi indexarea tabelelor

## Petculescu Mihai-Silviu

- [Temă07 - Utilizarea vederilor şi indexarea tabelelor](#temă07---utilizarea-vederilor-şi-indexarea-tabelelor)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
  - [Vederi](#vederi)
  - [Indexi](#indexi)

## Vederi

1. Creaţi o vedere care conţine toţi autorii şi operele scrise de aceştia

```sql
CREATE VIEW Colectie.vTitluri AS
SELECT Nume, Denumire
FROM Colectie.tAutori AS A INNER JOIN Colectie.tCarti AS C
ON A.idAutor = C.idAutor 
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
Sylvain Neuvel     |Gigantii adormiti                    |
Traian Tandin      |Dilemele capitanului Roman           |
Nicolae Margeanu   |Alte aventuri ale capitanului Vigu   |
Nicolae Margeanu   |Romanul care ucide                   |
Petre Vârlan       |Înfrângerea lui Thanatos             |
Pierre Barbet      |Planeta vrajita                      |
```

2. Redenumiţi titlul cărţii 'V19 Barba albastra'

```sql
UPDATE Colectie.vTitluri
SET Denumire = 'Barba albastra' WHERE Nume = 'Amelie Nothomb'
```

**Rezultat**

```bash
Nume               |Denumire                             |
-------------------|-------------------------------------|
Agnes Martin Lugand|Înca aud muzica noastra în gând      |
Alexandr Soljenitîn|O zi din viata lui Ivan Denisovici   |
Amelie Nothomb     |Barba albastra                       |
Andrew Crumey      |Mobius Dick                          |
Camilla Lackberg   |Fjallbacka - V6 Sirena               |
Camilla Lackberg   |Fjallbacka - V7 Paznicul farului     |
Camilla Lackberg   |Fjallbacka - V8 Fauritoarea de îngeri|
Catherine Isaac    |Aici, acum, mereu                    |
Charles Berlitz    |Misterul lumilor uitate              |
Charlie Jane Anders|Orasul de la miezul noptii           |
Christina Dalcher  |Tacerea poate fi asurzitoare         |
Sylvain Neuvel     |Gigantii adormiti                    |
Traian Tandin      |Dilemele capitanului Roman           |
Nicolae Margeanu   |Alte aventuri ale capitanului Vigu   |
Nicolae Margeanu   |Romanul care ucide                   |
Petre Vârlan       |Înfrângerea lui Thanatos             |
Pierre Barbet      |Planeta vrajita                      |
```

3. Ştergeţi cărţile lui 'Camilla Lackberg'.

```sql
DELETE FROM Colectie.vTitluri WHERE Nume='Camilla Lackberg'
```

**Rezultat**

```bash
Nume               |Denumire                             |
-------------------|-------------------------------------|
Agnes Martin Lugand|Înca aud muzica noastra în gând      |
Alexandr Soljenitîn|O zi din viata lui Ivan Denisovici   |
Amelie Nothomb     |Barba albastra                       |
Andrew Crumey      |Mobius Dick                          |
Catherine Isaac    |Aici, acum, mereu                    |
Charles Berlitz    |Misterul lumilor uitate              |
Charlie Jane Anders|Orasul de la miezul noptii           |
Christina Dalcher  |Tacerea poate fi asurzitoare         |
Sylvain Neuvel     |Gigantii adormiti                    |
Traian Tandin      |Dilemele capitanului Roman           |
Nicolae Margeanu   |Alte aventuri ale capitanului Vigu   |
Nicolae Margeanu   |Romanul care ucide                   |
Petre Vârlan       |Înfrângerea lui Thanatos             |
Pierre Barbet      |Planeta vrajita                      |
```

4. Ştergere vedere

```sql
DROP VIEW Colectie.vTitluri
```

## Indexi

- Creare Index

```sql
-- Insexare Titlu Carti
CREATE INDEX IX_Titlu_Carti ON Colectie.tCarti(Denumire)

-- Insexare Nume Autori
CREATE INDEX IX_Nume_Autori ON Colectie.tAutori(Nume)
```

- Interogări

1. Selectaţi toate cărţile care fac parte din seria 'Fjallbacka'

```sql
SELECT * FROM Colectie.tCarti WHERE Denumire LIKE 'Fjallbacka%'
```

**Rezultat**

```bash
idCarte|idAutor|Denumire                   |anAparitie|Editie|
--|--|-------------------------------------|----------|------|
 5| 5|Fjallbacka - V6 Sirena               |      2005|     1|
 6| 5|Fjallbacka - V7 Paznicul farului     |      2008|     1|
 7| 5|Fjallbacka - V8 Fauritoarea de îngeri|      2012|     1| 
```

2. Selectaţi toate cărţile care conţin în titlu cuvântul 'oras'

```sql
SELECT * FROM Colectie.tCarti WHERE LOWER(Denumire) LIKE '%oras%'
```

**Rezultat**

```bash
idCarte|idAutor|Denumire                  |anAparitie|Editie|
-------|-------|--------------------------|----------|------|
     10|      8|Orasul de la miezul noptii|      2015|     2|
```

3. Selectaţi toţi autoriii al cărol nume în baza de date începe cu litera 'c'

```sql
SELECT * FROM Colectie.tAutori WHERE lower(Nume) LIKE 'c%'
```

**Rezultat**

```bash
idAutor|Nume               |
-------|-------------------|
      5|Camilla Lackberg   |
      6|Catherine Isaac    |
      7|Charles Berlitz    |
      8|Charlie Jane Anders|
      9|Christina Dalcher  |
```

- Ştergere indexi

```sql
DROP INDEX Colectie.tCarti.IX_Titlu_Carti
DROP INDEX Colectie.tAutori.IX_Nume_Autori
```

