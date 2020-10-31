# Temă02 - Insert şi Select 

## Petculescu Mihai-Silviu

- [Temă02 - Insert şi Select](#temă02---insert-şi-select)
	- [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
	- [Date de intrare](#date-de-intrare)
	- [Insert](#insert)
	- [Select](#select)

## Date de intrare

```bash
Agnes Martin Lugand - Încă aud muzica noastră în gând 1.0 10 {Dragoste}.rtf
Agnes Martin Lugand - Încă aud muzica noastră în gând 1.0 {Dragoste}.docx
Alexandr Soljeniţîn - O zi din viaţa lui Ivan Denisovici 1.0 10 {Literatură}.rtf
Alexandr Soljeniţîn - O zi din viaţa lui Ivan Denisovici 1.0 {Literatură}.docx
Amelie Nothomb - V19 Barbă albastră 1.0 10 {Thriller}.rtf
Amelie Nothomb - V19 Barbă albastră 1.0 {Thriller}.docx
Andrew Crumey - Mobius Dick 1.0 10 {Literatură}.rtf
Andrew Crumey - Mobius Dick 1.0 {Literatură}.docx
Camilla Lackberg - Fjallbacka - V6 Sirena 1.1 10 {Poliţistă}.rtf
Camilla Lackberg - Fjallbacka - V6 Sirena 1.1 {Poliţistă}.docx
Camilla Lackberg - Fjallbacka - V7 Paznicul farului 1.1 {Poliţistă}.docx
Camilla Lackberg - Fjallbacka - V8 Făuritoarea de îngeri 1.1 10 {Poliţistă}.rtf
Camilla Lackberg - Fjallbacka - V8 Făuritoarea de îngeri 1.1 {Poliţistă}.docx
Catherine Isaac - Aici, acum, mereu 1.0 10 {Literatură}.rtf
Catherine Isaac - Aici, acum, mereu 1.0 {Literatură}.docx
Charles Berlitz - Misterul lumilor uitate 1.0 ^{Mister şi Ştiinţă}.docx
Charlie Jane Anders - Oraşul de la miezul nopţii 1.0 10 {SF}.rtf
Charlie Jane Anders - Oraşul de la miezul nopţii 1.0 {SF}.docx
Christina Dalcher - Tăcerea poate fi asurzitoare 1.0 10 {SF}.rtf
Christina Dalcher - Tăcerea poate fi asurzitoare 1.0 {SF}.docx
```

## Insert

```sql
-- Inserare in tFormat
INSERT INTO Colectie.tFormat (Extensie) VALUES ('docx'),('rtf');

-- Inserare in tAutori
INSERT INTO Colectie.tAutori (Nume)
VALUES ('Agnes Martin Lugand'),
	('Alexandr Soljeniţîn'),
	('Amelie Nothomb'),
	('Andrew Crumey'),
	('Camilla Lackberg'),
	('Catherine Isaac'),
	('Charles Berlitz'),
	('Charlie Jane Anders'),
	('Christina Dalcher');
	
-- Inserare in tCarti
INSERT INTO Colectie.tCarti (idAutor, Denumire, anAparitie, Editie)
VALUES (1,'Încă aud muzica noastră în gând',2010,1),
	(2,'O zi din viaţa lui Ivan Denisovici',2011,2),
	(3,'V19 Barbă albastră',1980,3),
	(4,'Mobius Dick',1990,2),
	(5,'Fjallbacka - V6 Sirena',2005,1),
	(5,'Fjallbacka - V7 Paznicul farului',2008,1),
	(5,'Fjallbacka - V8 Făuritoarea de îngeri',2012,1),
	(6,'Aici, acum, mereu',2015,1),
	(7,'Misterul lumilor uitate',2010,1),
	(8,'Oraşul de la miezul nopţii',2015,2),
	(9,'Tăcerea poate fi asurzitoare',2000,2);
	
-- Inserare in tFisiere
INSERT INTO Colectie.tFisiere (idCarte, idFormat, Denumire, nrPagini)
VALUES 
(1,2,'Agnes Martin Lugand - Încă aud muzica noastră în gând 1.0 10 {Dragoste}.rtf',500),
(1,1,'Agnes Martin Lugand - Încă aud muzica noastră în gând 1.0 {Dragoste}.docx',520),
(2,2,'Alexandr Soljeniţîn - O zi din viaţa lui Ivan Denisovici 1.0 10 {Literatură}.rtf',380),
(2,1,'Alexandr Soljeniţîn - O zi din viaţa lui Ivan Denisovici 1.0 {Literatură}.docx',410),
(3,2,'Amelie Nothomb - V19 Barbă albastră 1.0 10 {Thriller}.rtf',450),
(3,1,'Amelie Nothomb - V19 Barbă albastră 1.0 {Thriller}.docx',470),
(4,2,'Andrew Crumey - Mobius Dick 1.0 10 {Literatură}.rtf',610),
(4,1,'Andrew Crumey - Mobius Dick 1.0 {Literatură}.docx',590),
(5,2,'Camilla Lackberg - Fjallbacka - V6 Sirena 1.1 10 {Poliţistă}.rtf',280),
(5,1,'Camilla Lackberg - Fjallbacka - V6 Sirena 1.1 {Poliţistă}.docx',300),
(6,1,'Camilla Lackberg - Fjallbacka - V7 Paznicul farului 1.1 {Poliţistă}.docx',330),
(7,2,'Camilla Lackberg - Fjallbacka - V8 Făuritoarea de îngeri 1.1 10 {Poliţistă}.rtf',170),
(7,1,'Camilla Lackberg - Fjallbacka - V8 Făuritoarea de îngeri 1.1 {Poliţistă}.docx',210),
(8,2,'Catherine Isaac - Aici, acum, mereu 1.0 10 {Literatură}.rtf',250),
(8,1,'Catherine Isaac - Aici, acum, mereu 1.0 {Literatură}.docx',260),
(9,1,'Charles Berlitz - Misterul lumilor uitate 1.0 ^{Mister şi Ştiinţă}.docx',570),
(10,2,'Charlie Jane Anders - Oraşul de la miezul nopţii 1.0 10 {SF}.rtf',230),
(10,1,'Charlie Jane Anders - Oraşul de la miezul nopţii 1.0 {SF}.docx',245),
(11,2,'Christina Dalcher - Tăcerea poate fi asurzitoare 1.0 10 {SF}.rtf',278),
(11,1,'Christina Dalcher - Tăcerea poate fi asurzitoare 1.0 {SF}.docx',302);

-- Inserare in tHost
INSERT INTO Colectie.tHost (idHost, idFisier,dataModificare)
VALUES ('z2xsl23jd3',1,'2020-04-15'),
	('7b0l1wpllj',2,'2020-04-16'),
	('ktt0swufn1',3,'2020-04-16'),
	('28151eohux',4,'2020-04-16'),
	('tczrxs6vno',5,'2020-04-17'),
	('xx25soydmq',6,'2020-04-17'),
	('29q2ygf3e6',7,'2020-04-20'),
	('2hfvz9ad86',8,'2020-04-20'),
	('quq91yv0ty',9,'2020-04-21'),
	('7hgfjqvqsu',10,'2020-04-25'),
	('bn9gzc2yyd',11,'2020-04-26'),
	('7akrk0ert0',12,'2020-04-28'),
	('arxkjc2rnq',13,'2020-04-28'),
	('gahj8wt25l',14,'2020-04-28'),
	('9mfzaonrek',15,'2020-04-29'),
	('q3xchig4u9',16,'2020-04-29'),
	('xztgtmla34',17,'2020-05-04'),
	('u5e8eh4k3z',18,'2020-05-04'),
	('3f964odvw6',19,'2020-05-04'),
	('4ky6orfjah',20,'2020-05-04');
```

## Select

**tAutori**

```bash
idAutor|Nume               |
-------|-------------------|
      1|Agnes Martin Lugand|
      2|Alexandr Soljenitîn|
      3|Amelie Nothomb     |
      4|Andrew Crumey      |
      5|Camilla Lackberg   |
      6|Catherine Isaac    |
      7|Charles Berlitz    |
      8|Charlie Jane Anders|
      9|Christina Dalcher  |
```

**tFormat**

```bash
idFormat|Extensie|
--------|--------|
       1|docx    |
       2|rtf     |
```

**tCarti**

```sql
SELECT * FROM Colectie.tCarti
```

**Rezultat**

```bash
idCarte|idAutor|Denumire                             |anAparitie|Editie|
-------|-------|-------------------------------------|----------|------|
      1|      1|Înca aud muzica noastra în gând      |      2010|     1|
      2|      2|O zi din viata lui Ivan Denisovici   |      2011|     2|
      3|      3|V19 Barba albastra                   |      1980|     3|
      4|      4|Mobius Dick                          |      1990|     2|
      5|      5|Fjallbacka - V6 Sirena               |      2005|     1|
      6|      5|Fjallbacka - V7 Paznicul farului     |      2008|     1|
      7|      5|Fjallbacka - V8 Fauritoarea de îngeri|      2012|     1|
      8|      6|Aici, acum, mereu                    |      2015|     1|
      9|      7|Misterul lumilor uitate              |      2010|     1|
     10|      8|Orasul de la miezul noptii           |      2015|     2|
     11|      9|Tacerea poate fi asurzitoare         |      2000|     2|
```

**tFisiere**

```sql
SELECT * FROM Colectie.tFisiere
```

**Rezultat**

```bash
idFisier|idCarte|idFormat|Denumire                                                        |nrPagini|
--|---|--|--------------------------------------------------------------------------------|--------|
 2|  1| 1|Agnes Martin Lugand - Înca aud muzica noastra în gând 1.0 {Dragoste}.docx       | 520|
 1|  1| 2|Agnes Martin Lugand - Înca aud muzica noastra în gând 1.0 10 {Dragoste}.rtf     | 500|
 3|  2| 2|Alexandr Soljenitîn - O zi din viata lui Ivan Denisovici 1.0 10 {Literatura}.rtf| 380|
 4|  2| 1|Alexandr Soljenitîn - O zi din viata lui Ivan Denisovici 1.0 {Literatura}.docx  | 410|
 5|  3| 2|Amelie Nothomb - V19 Barba albastra 1.0 10 {Thriller}.rtf                       | 450|
 6|  3| 1|Amelie Nothomb - V19 Barba albastra 1.0 {Thriller}.docx                         | 470|
 7|  4| 2|Andrew Crumey - Mobius Dick 1.0 10 {Literatura}.rtf                             | 610|
 8|  4| 1|Andrew Crumey - Mobius Dick 1.0 {Literatura}.docx                               | 590|
 9|  5| 2|Camilla Lackberg - Fjallbacka - V6 Sirena 1.1 10 {Politista}.rtf                | 280|
10|  5| 1|Camilla Lackberg - Fjallbacka - V6 Sirena 1.1 {Politista}.docx                  | 300|
11|  6| 1|Camilla Lackberg - Fjallbacka - V7 Paznicul farului 1.1 {Politista}.docx        | 330|
12|  7| 2|Camilla Lackberg - Fjallbacka - V8 Fauritoarea de îngeri 1.1 10 {Politista}.rtf | 170|
13|  7| 1|Camilla Lackberg - Fjallbacka - V8 Fauritoarea de îngeri 1.1 {Politista}.docx   | 210|
14|  8| 2|Catherine Isaac - Aici, acum, mereu 1.0 10 {Literatura}.rtf                     | 250|
15|  8| 1|Catherine Isaac - Aici, acum, mereu 1.0 {Literatura}.docx                       | 260|
16|  9| 1|Charles Berlitz - Misterul lumilor uitate 1.0 ^{Mister si Stiinta}.docx         | 570|
17| 10| 2|Charlie Jane Anders - Orasul de la miezul noptii 1.0 10 {SF}.rtf                | 230|
18| 10| 1|Charlie Jane Anders - Orasul de la miezul noptii 1.0 {SF}.docx                  | 245|
19| 11| 2|Christina Dalcher - Tacerea poate fi asurzitoare 1.0 10 {SF}.rtf                | 278|
20| 11| 1|Christina Dalcher - Tacerea poate fi asurzitoare 1.0 {SF}.docx                  | 302|
```

**tHost**

```sql
SELECT * FROM Colectie.tHost
```

**Rezultat**

```bash
idHost    |idFisier|dataModificare     |
----------|--------|-------------------|
28151eohux|       4|2020-04-16 00:00:00|
29q2ygf3e6|       7|2020-04-20 00:00:00|
2hfvz9ad86|       8|2020-04-20 00:00:00|
3f964odvw6|      19|2020-05-04 00:00:00|
4ky6orfjah|      20|2020-05-04 00:00:00|
7akrk0ert0|      12|2020-04-28 00:00:00|
7b0l1wpllj|       2|2020-04-16 00:00:00|
7hgfjqvqsu|      10|2020-04-25 00:00:00|
9mfzaonrek|      15|2020-04-29 00:00:00|
arxkjc2rnq|      13|2020-04-28 00:00:00|
bn9gzc2yyd|      11|2020-04-26 00:00:00|
gahj8wt25l|      14|2020-04-28 00:00:00|
ktt0swufn1|       3|2020-04-16 00:00:00|
q3xchig4u9|      16|2020-04-29 00:00:00|
quq91yv0ty|       9|2020-04-21 00:00:00|
tczrxs6vno|       5|2020-04-17 00:00:00|
u5e8eh4k3z|      18|2020-05-04 00:00:00|
xx25soydmq|       6|2020-04-17 00:00:00|
xztgtmla34|      17|2020-05-04 00:00:00|
z2xsl23jd3|       1|2020-04-15 00:00:00|
```