# Temă09 - Tranzacţii SQL Server, Cursoare SQL Server

## Petculescu Mihai-Silviu

- [Temă09 - Tranzacţii SQL Server, Cursoare SQL Server](#temă09---tranzacţii-sql-server-cursoare-sql-server)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
  - [Tranzacţii](#tranzacţii)
  - [Cursor](#cursor)

## Tranzacţii

1. Adaugă noi autori fără a le atribui încă cărţi.

```sql
-- Finalizata cu Succes
BEGIN TRANSACTION
	INSERT INTO Colectie.tAutori(Nume)
	VALUES ('Ruth Hogan'), ('Sandor Marai'), ('Sylvain Neuvel');
COMMIT TRANSACTION
```

**Rezultat**

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
     10|Sylvain Neuvel     |
     11|Traian Tandin      |
     12|Nicolae Margeanu   |
     13|Petre Vârlan       |
     14|Pierre Barbet      |
     15|Ruth Hogan         |
     16|Sandor Marai       |
     17|Sylvain Neuvel     |
```

2. Adăugare cărţi pentru noii autori

```sql
-- Finalizata cu Esec
BEGIN TRANSACTION
	INSERT INTO Colectie.tCarti(idAutor, Denumire, anAparitie, Editie)
	VALUES (15,'Colecţionarul de obiecte pierdute',2010,2),
		(16,'Lumânările ard până la capăt',2010,2),
		(16,'Moştenirea Esztere',2010,2),
		(17,'Giganţii adormiţi',2010,2)
ROLLBACK TRANSACTION
```

**Rezultat**

```bash
idAutor|Denumire                             |anAparitie|Editie|
-------|-------------------------------------|----------|------|
      1|Înca aud muzica noastra în gând      |      2010|     1|
      2|O zi din viata lui Ivan Denisovici   |      2011|     2|
      3|Barba albastra                       |      1980|     3|
      4|Mobius Dick                          |      1990|     2|
      5|Fjallbacka - V6 Sirena               |      2005|     1|
      5|Fjallbacka - V7 Paznicul farului     |      2008|     1|
      5|Fjallbacka - V8 Fauritoarea de îngeri|      2012|     1|
      6|Aici, acum, mereu                    |      2015|     1|
      7|Misterul lumilor uitate              |      2010|     1|
      8|Orasul de la miezul noptii           |      2015|     2|
      9|Tacerea poate fi asurzitoare         |      2000|     2|
     10|Gigantii adormiti                    |      2007|     1|
     11|Dilemele capitanului Roman           |      2007|     1|
     12|Alte aventuri ale capitanului Vigu   |      2010|     2|
     12|Romanul care ucide                   |      2010|     3|
     13|Înfrângerea lui Thanatos             |      2012|     3|
     14|Planeta vrajita                      |      2012|     2|
```

3. Înserare cărţi noi în baza de date. Tranzacţia se va efectua cu succes dacă autorul a fost deja în baza de date, altfel funcţia se va oferi să-l adauge.

```sql
BEGIN TRAN T1
	INSERT INTO Colectie.tCarti(idAutor, Denumire, anAparitie, Editie)
	VALUES (16,'Lumânările ard până la capăt',2010,2),
		(16,'Moştenirea Esztere',2010,2);
	IF NOT EXISTS (select * from Colectie.tCarti where idAutor = 16)
		BEGIN TRAN T2
		INSERT INTO Colectie.tAutori(Nume) VALUES ('Sandor Marai')
		COMMIT TRAN T2
COMMIT TRAN T1
```

**Rezultat**

```bash
idCarte|idAutor|Denumire                             |
-------|-------|-------------------------------------|
      1|      1|Înca aud muzica noastra în gând      |
      2|      2|O zi din viata lui Ivan Denisovici   |
      3|      3|Barba albastra                       |
      4|      4|Mobius Dick                          |
      5|      5|Fjallbacka - V6 Sirena               |
      6|      5|Fjallbacka - V7 Paznicul farului     |
      7|      5|Fjallbacka - V8 Fauritoarea de îngeri|
      8|      6|Aici, acum, mereu                    |
      9|      7|Misterul lumilor uitate              |
     10|      8|Orasul de la miezul noptii           |
     11|      9|Tacerea poate fi asurzitoare         |
     12|     10|Gigantii adormiti                    |
     13|     11|Dilemele capitanului Roman           |
     14|     12|Alte aventuri ale capitanului Vigu   |
     15|     12|Romanul care ucide                   |
     16|     13|Înfrângerea lui Thanatos             |
     17|     14|Planeta vrajita                      |
     22|     16|Lumânarile ard pâna la capat         |
     23|     16|Mostenirea Esztere                   |
```

## Cursor

1. Parcurgeţi tabela cu cărţi

```sql
DECLARE crs1 CURSOR FOR SELECT idCarte, Denumire FROM Colectie.tCarti
OPEN crs1
DECLARE @cod INT, @titlu NVARCHAR(50)
fetch next FROM crs1 INTO @cod, @titlu
WHILE @@fetch_status = 0 
  BEGIN
	print str(@cod) + ' - ' + @titlu
	fetch next FROM crs1 INTO @cod, @titlu
  END
CLOSE crs1
DEALLOCATE crs1
```

**Rezultat**

```bash
 1 - ?nca aud muzica noastra ?n g?nd
 2 - O zi din viata lui Ivan Denisovici
 3 - Barba albastra
 4 - Mobius Dick
 5 - Fjallbacka - V6 Sirena
 6 - Fjallbacka - V7 Paznicul farului
 7 - Fjallbacka - V8 Fauritoarea de ?ngeri
 8 - Aici, acum, mereu
 9 - Misterul lumilor uitate
10 - Orasul de la miezul noptii
11 - Tacerea poate fi asurzitoare
12 - Gigantii adormiti
13 - Dilemele capitanului Roman
14 - Alte aventuri ale capitanului Vigu
15 - Romanul care ucide
16 - ?nfr?ngerea lui Thanatos
17 - Planeta vrajita
22 - Lum?narile ard p?na la capat
23 - Mostenirea Esztere
```

2. Parcurgeţi tabela cu cărţi în ordine descrescătoare

```sql
DECLARE crs1 CURSOR SCROLL FOR SELECT idCarte, Denumire FROM Colectie.tCarti
OPEN crs1
DECLARE @cod INT, @titlu NVARCHAR(50)
fetch last FROM crs1 INTO @cod, @titlu
WHILE @@fetch_status = 0 
  BEGIN
	print str(@cod) + ' - ' + @titlu
	fetch prior FROM crs1 INTO @cod, @titlu
  END
CLOSE crs1
DEALLOCATE crs1
```

**Rezultat**

```bash
23 - Mostenirea Esztere
22 - Lum?narile ard p?na la capat
17 - Planeta vrajita
16 - ?nfr?ngerea lui Thanatos
15 - Romanul care ucide
14 - Alte aventuri ale capitanului Vigu
13 - Dilemele capitanului Roman
12 - Gigantii adormiti
11 - Tacerea poate fi asurzitoare
10 - Orasul de la miezul noptii
 9 - Misterul lumilor uitate
 8 - Aici, acum, mereu
 7 - Fjallbacka - V8 Fauritoarea de ?ngeri
 6 - Fjallbacka - V7 Paznicul farului
 5 - Fjallbacka - V6 Sirena
 4 - Mobius Dick
 3 - Barba albastra
 2 - O zi din viata lui Ivan Denisovici
 1 - ?nca aud muzica noastra ?n g?nd
```

3. Afişare autori din 2 în 2.

```sql
DECLARE crs1 cursor scroll FOR SELECT idAutor, Nume FROM Colectie.tAutori
OPEN crs1
DECLARE @cod INT, @nume NVARCHAR(50)
fetch first FROM crs1 INTO @cod, @nume
WHILE @@fetch_status = 0 
  BEGIN
	print str(@cod) + ' - ' + @nume
	fetch relative 2 FROM crs1 INTO @cod, @nume
  END
CLOSE crs1
DEALLOCATE crs1
```

**Rezultat**

```bash
 1 - Agnes Martin Lugand
 3 - Amelie Nothomb
 5 - Camilla Lackberg
 7 - Charles Berlitz
 9 - Christina Dalcher
11 - Traian Tandin
13 - Petre V?rlan
15 - Ruth Hogan
17 - Sylvain Neuvel
19 - Sandor Marai
```

