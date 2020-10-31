# Temă08 - Crearea funcţiilor şi procedurilor stocate

## Petculescu Mihai-Silviu

- [Temă08 - Crearea funcţiilor şi procedurilor stocate](#temă08---crearea-funcţiilor-şi-procedurilor-stocate)
	- [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)

1. Scrieţi o funcţie care să afişeze media anilor cărţilor din baza de date

```sql
CREATE FUNCTION anAVG() RETURNS INT AS
BEGIN
	DECLARE @x INT
	SELECT @x=AVG(anAparitie) FROM Colectie.tCarti;
	RETURN @x;
END

print dbo.anAVG();
```

**Rezultat**

```bash
2006
```

2. Scrieţi o funcţie care afişează numărul cărţilor publicate mai recent decât o anumită dată.

```sql
CREATE FUNCTION Carti_Recente(@an_dat INT) RETURNS INT AS
BEGIN
	DECLARE @x int
	SELECT @x = COUNT(*) FROM Colectie.tCarti WHERE anAparitie >= @an_dat
	return @x
END

BEGIN
print 'Carti aparute dupa 2000: '+ str(dbo.Carti_Recente(2000))
print 'Carti aparute dupa 2010: '+ str(dbo.Carti_Recente(2010))
END
```

**Rezultat**

```bash
Carti aparute dupa 2000:         15
Carti aparute dupa 2010:         10
```

3. Creaţi o procedură care afişează lista cărţilor.

```sql
CREATE PROCEDURE Colectie.Afisare_Carti @Titlu VARCHAR(50)='' AS 
BEGIN
	SET @Titlu = '%' + @Titlu + '%'
	SELECT idCarte AS 'ID', Denumire AS 'Titlu' From Colectie.tCarti AS C Where LOWER(C.Denumire) LIKE @Titlu
END

EXECUTE Colectie.Afisare_Carti
```

- `EXECUTE Colectie.Afisare_Carti`

**Rezultat**

```bash
ID|Titlu                                |
--|-------------------------------------|
 1|Înca aud muzica noastra în gând      |
 2|O zi din viata lui Ivan Denisovici   |
 3|Barba albastra                       |
 4|Mobius Dick                          |
 5|Fjallbacka - V6 Sirena               |
 6|Fjallbacka - V7 Paznicul farului     |
 7|Fjallbacka - V8 Fauritoarea de îngeri|
 8|Aici, acum, mereu                    |
 9|Misterul lumilor uitate              |
10|Orasul de la miezul noptii           |
11|Tacerea poate fi asurzitoare         |
12|Gigantii adormiti                    |
13|Dilemele capitanului Roman           |
14|Alte aventuri ale capitanului Vigu   |
15|Romanul care ucide                   |
16|Înfrângerea lui Thanatos             |
17|Planeta vrajita                      |
```

- `EXECUTE Colectie.Afisare_Carti 'aici'`

**Rezultat**

```bash
ID|Titlu            |
--|-----------------|
 8|Aici, acum, mereu|
```

4. Ştergere funcţii şi proceduri

```sql
DROP PROCEDURE Colectie.Afisare_Carti
DROP FUNCTION Carti_Recente
```

