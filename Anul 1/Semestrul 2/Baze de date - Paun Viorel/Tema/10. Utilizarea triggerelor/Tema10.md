# Temă10 - Utilizarea triggerelor

## Petculescu Mihai-Silviu

- [Temă10 - Utilizarea triggerelor](#temă10---utilizarea-triggerelor)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)

Validare ISBN10 in tabela tCarti

```sql
-- Creare Functie de validare ISBN10
CREATE function Colectie.ValidareISBN10(@ISBN CHAR(10)) returns INT AS
BEGIN
	DECLARE @S int
    DECLARE @I int
    DECLARE @P int
    SET @S=0
    SET @I=1
    SET @P=10
    WHILE @I<=10
    	BEGIN
        	IF SUBSTRING(@ISBN,@I,1) not between '0' and '9' RETURN 0
            SET @S = @S + convert(int,SUBSTRING(@ISBN,@I,1)) * @P
            SET @I = @I + 1
            SET @P = @P - 1
        END
	DECLARE @C int
    SET @C = @S % 11
    IF NOT @C = convert(int,SUBSTRING(@ISBN,1,1))
    	RETURN 0
    RETURN 1
END

-- Creare Coloana ISBN10
ALTER TABLE Colectie.tCarti ADD ISBN10 char(10)

-- Creare Trigger pentru validare ISBN10
CREATE TRIGGER TRG_Valid_ISBN10 ON Colectie.tCarti for insert, update AS
BEGIN
	DECLARE @n int = @@ROWCOUNT
    if not update(ISBN10) RETURN
    if @n > 1
    begin
    	print 'Aceasta varianta de trigger nu permite modificari in mai multe randuri'
        ROLLBACK TRANSACTION
        print 'Actualizarea tabelului a fost anulata'
        RETURN
    end
    
    DECLARE @ISBN char(10)
    SELECT @ISBN = ISBN10 from inserted
    if Colectie.ValidareISBN10(@ISBN) = 0
    	begin
        	print 'EROARE ISBN ' + @ISBN
        	ROLLBACK
            print 'Actualizarea tabelului a fost anulata'
        end
END
```

Utilizare

```sql
INSERT INTO Colectie.tCarti(idAutor, Denumire, ISBN10)
VALUES (15, 'Colecţionarul de obiecte pierdute', '0716703441')
```

**Rezultat**

```bash
EROARE ISBN 0716703441
Actualizarea tabelului a fost anulata
```

Pentru ISBN10 = 0716703440

**Rezultat**

```bash
idAutor|Denumire                             |ISBN10    |
-------|-------------------------------------|----------|
      1|Înca aud muzica noastra în gând      |          |
      2|O zi din viata lui Ivan Denisovici   |          |
      3|Barba albastra                       |          |
      4|Mobius Dick                          |          |
      5|Fjallbacka - V6 Sirena               |          |
      5|Fjallbacka - V7 Paznicul farului     |          |
      5|Fjallbacka - V8 Fauritoarea de îngeri|          |
      6|Aici, acum, mereu                    |          |
      7|Misterul lumilor uitate              |          |
      8|Orasul de la miezul noptii           |          |
      9|Tacerea poate fi asurzitoare         |          |
     10|Gigantii adormiti                    |          |
     11|Dilemele capitanului Roman           |          |
     12|Alte aventuri ale capitanului Vigu   |          |
     12|Romanul care ucide                   |          |
     13|Înfrângerea lui Thanatos             |          |
     14|Planeta vrajita                      |          |
     16|Lumânarile ard pâna la capat         |          |
     16|Mostenirea Esztere                   |          |
     15|Colectionarul de obiecte pierdute    |0716703440|
```

