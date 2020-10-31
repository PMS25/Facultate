# Temă06 - Manipularea datelor

## Petculescu Mihai-Silviu

- [Temă06 - Manipularea datelor](#temă06---manipularea-datelor)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
  - [Insert](#insert)
  - [Select Into](#select-into)
  - [Update](#update)
  - [Truncate](#truncate)
  - [Delete](#delete)

## Insert

```sql
-- Inserare noi Autori
INSERT INTO Colectie.tAutori(Nume)
VALUES ('Sylvain Neuvel'), --10
	('Traian Tandin'), --11
	('Nicolae Mărgeanu'), --12
	('Petre Vârlan'), --13
	('Pierre Barbet'); --14

-- Inserare noi Carti
INSERT INTO Colectie.tCarti(idAutor, Denumire, anAparitie, Editie)
VALUES
(10, 'Giganţii adormiţi', 2007, 1), --12
(11, 'Dilemele căpitanului Roman', 2007, 1), --13
(12, 'Alte aventuri ale căpitanului Vigu', 2010, 2), --14
(12, 'Romanul care ucide', 2010, 1), --15
(13, 'Înfrângerea lui Thanatos', 2012, 1), --16
(14, 'Planeta vrăjită', 2012, 2); --17

-- inserare noi Formate
INSERT INTO Colectie.tFormat(Extensie) VALUES ('pdf')

-- Inserare noi Fisiere
INSERT INTO Colectie.tFisiere(idCarte, idFormat, Denumire, nrPagini)
VALUES
(12,2,'Sylvain Neuvel - Giganţii adormiţi 1.0 10 {SF}.rtf',400),
(12,1,'Sylvain Neuvel - Giganţii adormiţi 1.0 {SF}.docx',405),
(13,2,'Traian Tandin - Dilemele căpitanului Roman 2.0 10 {Poliţistă}.rtf',330),
(13,1,'Traian Tandin - Dilemele căpitanului Roman 2.0 {Poliţistă}.docx',340),
(14,2,'Nicolae Mărgeanu - Alte aventuri ale căpitanului Vigu 1.0 10 {Poliţistă}.rtf',350),
(14,1,'Nicolae Mărgeanu - Alte aventuri ale căpitanului Vigu 1.0 {Poliţistă}.docx',355),
(15,2,'Nicolae Mărgeanu - Romanul care ucide 1.0 10 {Poliţistă}.rtf',360),
(15,1,'Nicolae Mărgeanu - Romanul care ucide 1.0 {Poliţistă}.docx',360),
(16,1,'Petre Vârlan - Înfrângerea lui Thanatos 1.0 {Poliţistă}.docx',340),
(16,3,'Petre Vârlan - Înfrângerea lui Thanatos 1.0 10 {Poliţistă}.pdf',345),
(17,1,'Pierre Barbet - Planeta vrăjită 1.1 {SF}.docx',365),
(17,3,'Pierre Barbet - Planeta vrăjită 1.1 10 {SF}.pdf',365);
```

## Select Into

```sql
SELECT idFormat, nrPagini
INTO Colectie.tStatisticiPagini
FROM Colectie.tFisiere
```

**Rezultat**

```bash
idFormat|nrPagini|
--------|--------|
       2|     500|
       1|     520|
       2|     380|
       1|     410|
       2|     450|
       1|     470|
       2|     610|
       1|     590|
       2|     280|
       1|     300|
       1|     330|
       2|     170|
       1|     210|
       2|     250|
       1|     260|
       1|     570|
       2|     230|
       1|     245|
       2|     278|
       1|     302|
       2|     400|
       1|     405|
       2|     330|
       1|     340|
       2|     350|
       1|     355|
       2|     360|
       1|     360|
       1|     340|
       3|     345|
       1|     365|
       3|     365|
```

## Update

```sql
-- Update Editie Carti
UPDATE Colectie.tCarti SET Editie = 3 WHERE idCarte = 15 OR idAutor = 13

-- Update Data Modificare Fisier in Host
UPDATE Colectie.tHost SET dataModificare = '2020-05-24' WHERE idFisier < 5
```

## Truncate

```sql
-- Golire tabela tStatisticiPagini
TRUNCATE TABLE Colectie.tStatisticiPagini
```

## Delete

```sql
-- Stergere Carti de pe Host mai vechi de '2020-04-10'
DELETE Colectie.tHost WHERE dataModificare < '2020-04-10'

-- Stergere tabel tStatisticiPagini
DELETE Colectie.tStatisticiPagini
DROP TABLE Colectie.tStatisticiPagini; 
```

