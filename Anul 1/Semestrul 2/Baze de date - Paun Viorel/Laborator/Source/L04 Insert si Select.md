# L04 Insert si Select 

```sql
--Activam baza de date 
use bdFacultati

--Sa se insereze date in tabelul Scoala.tFacultati
insert into Scoala.tFacultati (CodFac,Denumire) values
  ('FSEFI','Facultatea de Stiinte, Ed. Fizica si Informatica'),
  ('FECC','Facultatea de Electronica, Comunicatii si Calculatoare'),
  ('FSED','Facultatea de Stiinte Economice si Drept'),
  ('FTLIA','Facultatea de Teologie, Litere, Istorie si Arte'),
  ('FMT', 'Facultatea de Mecanica si Tehnologie'),
  ('FSESSP','Facultatea de Stiinte ale Ed., Stiinte Sociale si Psihologice'),
  ('DPPD','Departamentul de Perfectionare a Cadrelor Didactice') 

/*
Am obtinut mesajul:
Msg 8152, Level 16, State 14, Line 1
String or binary data would be truncated.
The statement has been terminated.
*/
--Sa se modifice dimensiunea coloanei denumire de la 50 la 80 caractere
alter table Scoala.tFacultati
alter column denumire varchar(80) not null

/* Sa se reexecute comanda insert
Am obtinut mesajul: (7 row(s) affected)
ceea ce inseamna ca insert-urile au fost efectuate
*/
--Sa se afiseze continutul tabelului  Scoala.tFacultati
select * from Scoala.tFacultati

/*
codFac   denumire	                                                  adresa
DPPD     Departamentul de Perfectionare a Cadrelor Didactice	        NULL
FECC     Facultatea de Electronica, Comunicatii si Calculatoare	        NULL
FMT      Facultatea de Mecanica si Tehnologie	                        NULL
FSED     Facultatea de Stiinte Economice si Drept	                    NULL
FSEFI    Facultatea de Stiinte, Ed. Fizica si Informatica	            NULL
FSESSP   Facultatea de Stiinte ale Ed., Stiinte Sociale si Psihologice	NULL
FTLIA    Facultatea de Teologie, Litere, Istorie si Arte	            NULL
*/

/* Observatie:
   Tabelele tFacultati,tDepartamente,tSpecializari etc. sunt create in schema Scoala si de aceea in comenzile insert si select anterioara am prefixat denumirea tabelului cu denumirea schemei.
   Daca acest lucru il consideram un neajuns, il putem elimina prin crearea sinonimelor
 */
-- Sa se creeze sinonime pentru tabelele schemei Scoala
  
create synonym   tFacultati for Scoala.tFacultati
create synonym   tDepartamente for Scoala.tDepartamente
create synonym   tSpecializari for Scoala.tSpecializari
create synonym   tProfesori for Scoala.tProfesori
create synonym   tStudenti for Scoala.tStudenti
create synonym   tCursuri for Scoala.tCursuri
create synonym   tNote for Scoala.tNote
create synonym   tCursProfesor for Scoala.tCursProfesor

/* Acum putem referi tabelele fie utilizand sintaxa <denumure schema>.<denumire tabel> ca in insert-ul de mai sus, fie folosind synonym-ele lor.
  Obs. Un sinonim nu trebuie neaparat  sa aiba aceeasi denumire cu a tabelului
*/ 

insert into tDepartamente(CodDep, Denumire, CodFac)
values ('DMI','Mate-Info','FSEFI'),
       ('DS','Stiinte','FSEFI'),
       ('DEFS','Ed. Fiz si Sport','FSEFI'),
	   ('DAMK','As. Medicala si Kineto','FSEFI')
	   
insert into tSpecializari(CodSpec, Denumire, CodDep)
values ('Info', 'Informatica','DMI'),
       ('Mate', 'Matematica', 'DMI'),
	   ('Sport','Sport si Performanta', 'DEFS'),
	   ('EF', 'Educatie Fizica', 'DEFS'),
	   ('CM', 'Chimie Medicala', 'DS'),
	   ('Bio','Biologie', 'DS'),
	   ('AM','Asistenta Medicala','DAMK'),
	   ('KT','Kinetoterapie','DAMK') 

insert into scoala.tProfesori(CodProf, Nume,  GradDidactic, CodDep)
values ('P1','POPESCU',null,'DMI'),
       ('P2','TEODORESCU',null,'DMI'),
	   ('P3','CONSTANTINESCU',null,'DMI'),
	   ('P4', 'MARINESCU',null,'DEFS'),
	   ('P5', 'IONESCU',null,'DS'),
	   ('P6', 'RADULESCU',null, 'DAMK')

insert into tStudenti(CodStud,Nume,CodJud,Localitate,CodSpec,AnStudiu,CNP)
values 
  ('S01', 'Florin', 'AG', 'Pitesti','Info','1','1990514123456'),
  ('S02', 'Mihai', 'AG', 'Costesti', 'Info','1','1991130123456'),
  ('S03','Alexandra', 'AG', 'Pitesti', 'Info','2','2980117123456'),
  ('S04','Andreea','AG','Stefanesti','Info','2','2980824123456'),
  ('S11','Flavius','AG','Mioveni','Mate','1','1990413123456'),
  ('S12', 'Marian','AG','Pitesti','Mate','2','1980919123456'),
  ('S13','Adrian','AG','Costesti','Mate','1','1990718123456'),
  ('S21','Raul','AG','Pitesti','Bio','1','1991228123456'),
  ('S22','Corina','AG','Stefanesti','Bio','1','2991121123456'),
  ('S31','Maria','AG','Pitesti','AM','1','2990426123456')   

insert into tCursuri
values ('AG', 'Algoritmica Grafurilor','B',5),
	   ('BD', 'Baze de Date','B', 6),
	   ('OOP', 'Programare Orientata Pe Obiecte','B',6),
	   ('GC', 'Geometrie Computationala','B', 5),
	   ('LMC', 'Logica Matematica Si Computationala','B', 6),
	   ('EN', 'Limba Engleza','B', 4),
	   ('EF', 'Educatie Fizica', 'B',2),
	   ('PED', 'Pedagogie','F',4)

-- INTEROGARI  SIMPLE--
select * from tStudenti
/*
codStud	  nume			CNP		  codSpec anStudiu	codJud	localitate	    dataNasterii
S01      Florin		1990514123456	Info     1		  AG      Pitesti	  1999-05-14 00:00:00
S02      Mihai		1991130123456	Info     1		  AG      Costesti	  1999-11-30 00:00:00
S03      Alexandra	2980117123456	Info     2		  AG      Pitesti	  1998-01-17 00:00:00
S04      Andreea	2980824123456	Info     2		  AG      Stefanesti  1998-08-24 00:00:00
S11      Flavius	1990413123456	Mate     1		  AG      Mioveni	  1999-04-13 00:00:00
S12      Marian		1980919123456	Mate     2		  AG      Pitesti	  1998-09-19 00:00:00
S13      Adrian		1990718123456	Mate     1		  AG      Costesti	  1999-07-18 00:00:00
S21      Raul		1991228123456	Bio      1		  AG      Pitesti	  1999-12-28 00:00:00
S22      Corina		2991121123456	Bio      1		  AG      Stefanesti  1999-11-21 00:00:00
S31      Maria		2990426123456	AM       1		  AG      Pitesti	  1999-04-26 00:00:00
*/

select * from tStudenti where CodSpec='info'
/*
codStud	 nume	      CNP	   codSpec	anStudiu  codJud   localitate	   dataNasterii
S01     Florin	  1990514123456	 Info      	1		AG     Pitesti		1999-05-14 00:00:00
S02     Mihai	  1991130123456	 Info      	1		AG     Costesti		1999-11-30 00:00:00
S03     Alexandra 2980117123456	 Info      	2		AG     Pitesti		1998-01-17 00:00:00
S04     Andreea	  2980824123456	 Info      	2		AG     Stefanesti	1998-08-24 00:00:00
*/

select codStud,nume,dataNasterii from tStudenti
/*
S01     Florin		1999-05-14 00:00:00
S02     Mihai		1999-11-30 00:00:00
S03     Alexandra	1998-01-17 00:00:00
S04     Andreea		1998-08-24 00:00:00
S11     Flavius		1999-04-13 00:00:00
S12     Marian		1998-09-19 00:00:00
S13     Adrian		1999-07-18 00:00:00
S21     Raul		1999-12-28 00:00:00
S22     Corina		1999-11-21 00:00:00
S31     Maria		1999-04-26 00:00:00
*/

select codStud,nume,dataNasterii from tStudenti order by dataNasterii
/*
S03     Alexandra	1998-01-17 00:00:00
S04     Andreea		1998-08-24 00:00:00
S12     Marian		1998-09-19 00:00:00
S11     Flavius		1999-04-13 00:00:00
S31     Maria		1999-04-26 00:00:00
S01     Florin		1999-05-14 00:00:00
S13     Adrian		1999-07-18 00:00:00
S22     Corina		1999-11-21 00:00:00
S02     Mihai		1999-11-30 00:00:00
S21     Raul		1999-12-28 00:00:00
*/

select codStud,nume,dataNasterii from tStudenti order by dataNasterii desc
/*
S21    Raul			1999-12-28 00:00:00
S02    Mihai		1999-11-30 00:00:00
S22    Corina		1999-11-21 00:00:00
S13    Adrian		1999-07-18 00:00:00
S01    Florin		1999-05-14 00:00:00
S31    Maria		1999-04-26 00:00:00
S11    Flavius		1999-04-13 00:00:00
S12    Marian		1998-09-19 00:00:00
S04    Andreea		1998-08-24 00:00:00
S03    Alexandra	1998-01-17 00:00:00
*/

-- Sa se afiseze studentii nascuti in luna urmatoare --
select CodStud, Nume, DataNasterii
	FROM tStudenti
	WHERE month(DataNasterii) = Month(GetDate())+1
/*
S11       	Flavius	1999-04-13 00:00:00
S31       	Maria	1999-04-26 00:00:00
*/

-- Sa se afiseze studentii al carui nume incepe cu litera 'F' --
select CodStud, Nume FROM tStudenti WHERE Nume like 'F%'
/*
S01       	Florin
S11       	Flavius
*/

-- Sa se afiseze studentii al carui nume incepe cu litera 'A' sau 'F' --
select CodStud, Nume FROM tStudenti WHERE Nume like '[AF]%'
/*
CodStud	    Nume
S01       	Florin
S03       	Alexandra
S04       	Andreea
S11       	Flavius
S13       	Adrian
*/

-- Sa se afiseze studentii al carui nume nu incepe cu litera 'A' sau 'F' --
select CodStud, Nume FROM tStudenti WHERE Nume like '[^AF]%'
/*
CodStud	    Nume
S02       	Mihai
S12       	Marian
S21       	Raul
S22       	Corina
S31       	Maria
*/

-- Sa se afiseze studentii al carui nume are pe pozitia a doua litera 'O' --
select CodStud, Nume FROM tStudenti WHERE Nume like '_O%'
/*
CodStud	   Nume
S22       Corina
*/

-- Sa se afiseze studentii al carui nume are pe pozitia a patra litera 'I' --
select CodStud, Nume FROM tStudenti WHERE Nume like '___I%'
/*
CodStud	   Nume
S12       Marian
S13       Adrian
S22       Corina
S31       Maria
*/

-- Sa se afiseze studentii al carui nume contine subsirul 'IA' --
select CodStud, Nume FROM tStudenti	WHERE Nume like '%IA%'
/*
CodStud	   Nume
S12       Marian
S13       Adrian
S31       Maria
*/

-- Sa se afiseze studentii al carui nume incepe cu litera 'C' si se termina cu litera 'A' --
select CodStud, Nume FROM tStudenti	WHERE Nume like 'C%A'
/*
CodStud	   Nume
S22       Corina
*/

-- Sa se afiseze studentii al carui nume incepe cu una din literele : "A,B,C,D,E,F" --
select CodStud, Nume FROM tStudenti	WHERE Nume like '[A-F]%'
/*
CodStud	     Nume
S01       	Florin
S03       	Alexandra
S04       	Andreea
S11       	Flavius
S13       	Adrian
S22       	Corina
*/

-- Sa se afiseze studentii nascuti in 1999
select CodStud, Nume, DataNasterii
	FROM tStudenti
	WHERE year(DataNasterii) = 1999

--Sa se afiseze numarul de studenti
select count(*) as [Nr studenti] FROM tStudenti

--Sa se afiseze numarul de studenti la nivel de locatitate
select Localitate, count(CodStud) AS [Nr. Studenti]
	 FROM tStudenti
	 GROUP BY Localitate

/*
 Sa se afiseze numarul de studenti la nivel de locatitate  in ordinea descrescatoare a nr. de studenti
*/
select Localitate, count(CodStud) AS [Nr. Studenti]
	 FROM tStudenti
	 GROUP BY Localitate
	 ORDER BY [Nr. Studenti] desc

/*
Sa se afiseze primele doua localitati(inregistrari) cu cei mai multi studenti
*/
select top 2 Localitate, count(CodStud) AS [Nr. Studenti]
	 FROM tStudenti
	 GROUP BY Localitate
	 ORDER BY [Nr. Studenti] desc
/*
Localitate	Nr. Studenti
Pitesti	      5
Costesti	  2
*/

/*
Sa se afiseze primele doua localitati cu cei mai multi studenti.
Observati rolul lui < with ties>
*/
select TOP 2 with ties Localitate, count(CodStud) AS [Nr. Studenti]
	 FROM tStudenti
	 GROUP BY Localitate
	 ORDER BY [Nr. Studenti] DESC 
	 
/*
Localitate	Nr. Studenti
Pitesti     	5
Stefanesti      2
Costesti	    2
*/

-- Sa se afiseze specializarile cu cel mult 2 studenti --
select Localitate, count(CodStud) AS [Nr. Studenti]
	 FROM tStudenti
	 GROUP BY Localitate
	 HAVING count(CodStud) < 3
/*
Localitate	Nr. Studenti
Costesti	  2
Mioveni	      1
Stefanesti	  2
*/ 

/* Sa se afiseze numarul de studenti din localitatile din localitatile Pitesti si Mioveni in ordinea descrescatoare a nr de stud
*/
select Localitate, count(CodStud) as [NumarStudenti]
	from tStudenti
	where Localitate = 'Pitesti' or Localitate = 'Mioveni'
	group by Localitate
	order by Localitate desc
/*
Localitate	NumarStudenti
Pitesti	        5
Mioveni	        1
*/
 
--Sa se afiseze CodStud, Nume si CodSpec
select CodStud, Nume, CodSpec from tStudenti
/*
CodStud	   Nume     CodSpec
S01       Florin	 Info
S02       Mihai	     Info
S03       Alexandra	 Info
S04       Andreea	 Info
S11       Flavius	 Mate
S12       Marian	 Mate
S13       Adrian	 Mate
S21       Raul	     Bio
S22       Corina	 Bio
S31       Maria	      AM
*/

--Sa se afiseze studentii care nu sunt la Info
select CodStud, Nume, CodSpec
	from tStudenti 
	where CodSpec != 'Info'

/*
CodStud	  Nume	   CodSpec
S11      Flavius    Mate
S12      Marian	    Mate
S13      Adrian	    Mate
S21      Raul	    Bio
S22      Corina	    Bio
S31      Maria	    AM
*/

--Sa se afiseze numarul de studenti la nivel de specializare
select count(CodStud) as [Numar Studenti] ,CodSpec
	from tStudenti
	group by CodSpec
/*
Numar Studenti	CodSpec
1	  AM
2	  Bio
4	  Info
3	  Mate
*/

--Sa se afiseze specializarile cu cel putin 2 studenti
select CodSpec, count(CodStud) as [NumarStudenti]
	from tStudenti
	group by CodSpec
 	having count(CodStud) >= 2
/*
CodSpec	NumarStudenti
Bio       	2
Info      	4
Mate      	3
*/
```

