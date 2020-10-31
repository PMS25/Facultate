# L06 Subinterogari 

```sql
use db2019Info_an1

insert into tCursuri(CodCurs,denumire,tipCurs,nrCredite)
values('ASD','Algoritmi si structuri de date','B','5'),
      ('FP','Fundamentele Programarii','B',6)

insert into tCursuri(CodCurs,denumire,tipCurs,nrCredite)
values('ASD','Algoritmi si structuri de date','B','5'),
      ('FP','Fundamentele Programarii','B',6)

insert into tNote(codCurs, codStud, nota, DataExamen)
values ('ASD', 'S01', 7, '2020/02/08'),
       ('ASD', 'S02', 9, '2020/02/08'),
	   ('ASD', 'S03', 8, '2020/02/08'),
	   ('ASD', 'S04', 5, '2020/02/08')

insert into tNote(codCurs, codStud, nota, DataExamen)
values ('FP', 'S01', 5, '2020/02/05'),
       ('FP', 'S02', 6, '2020/02/05'),
	   ('FP', 'S03', 4, '2020/02/05'),
	   ('FP', 'S04', 10, '2020/02/05'),
	   ('FP', 'S11', 8, '2020/02/05'),
	   ('FP', 'S12', 4, '2020/02/05'),
	   ('FP', 'S13', 7, '2020/02/05')

select * from tCursuri
/*
codCurs		denumire					    tipCurs	  nrCredite
AG        	Algoritmica Grafurilor			    B		  5
ASD       	Algoritmi si structuri de date		B		  5
BD        	Baze de Date					   B		 6
EF        	Educatie Fizica					   B		 2
EN        	Limba Engleza					   B		 4
FP        	Fundamentele Programarii			B		  6
GC        	Geometrie Computationala			B		  5
LMC       	Logica Matematica Si Computationala	 B		   6
OOP       	Programare Orientata Pe Obiecte		 B		   6
PED       	Pedagogie						   F		 4
*/

select * from tStudenti
/*
codStud	nume	  CNP		  codSpec anStudiu  codJud	localitate	   dataNasterii
S01     Florin	  1990514123456	Info      1	  	AG        Pitesti		1999-05-14 00:00:00
S02     Mihai     1991130123456	Info      1	  	AG        Costesti		1999-11-30 00:00:00
S03     Alexandra 2980117123456	Info      2	  	AG        Pitesti		1998-01-17 00:00:00
S04     Andreea	  2980824123456	Info      2	  	AG        Stefanesti	1998-08-24 00:00:00
S11     Flavius	  1990413123456	Mate      1	  	AG        Mioveni		1999-04-13 00:00:00
S12     Marian	  1980919123456	Mate      2	  	AG        Pitesti		1998-09-19 00:00:00
S13     Adrian	  1990718123456	Mate      1	  	AG        Costesti		1999-07-18 00:00:00
S21     Raul	  1991228123456	Bio       1	  	AG        Pitesti		1999-12-28 00:00:00
S22     Corina	  2991121123456	Bio       1	  	AG        Stefanesti	1999-11-21 00:00:00
S31     Maria	  2990426123456	AM        1	  	AG        Pitesti		1999-04-26 00:00:00
*/

select * from tNote
/*
codCurs		codStud		dataExamen			nota
ASD       	S01       	2020-02-08 00:00:00	   7
ASD       	S02       	2020-02-08 00:00:00	   9
ASD       	S03       	2020-02-08 00:00:00	   8
ASD       	S04       	2020-02-08 00:00:00	   5
FP        	S01       	2020-02-05 00:00:00	   5
FP        	S02       	2020-02-05 00:00:00	   6
FP        	S03       	2020-02-05 00:00:00	   4
FP        	S04       	2020-02-05 00:00:00	  10
FP        	S11       	2020-02-05 00:00:00	   8
FP        	S12       	2020-02-05 00:00:00	   4
FP        	S13       	2020-02-05 00:00:00	   7
*/

/*Sa se afle nota maxima*/
select max(Nota) as [Nota Maxima] from tNote
/*
Nota Maxima
10
*/

/*Sa se afle nota minima*/
/*
Nota Minima
4
*/

/*Sa se afle media notelor*/
select avg(Nota) as [Media Notelor] from tNote
/*
Media Notelor
6
*/

/* Obs. Daca argumentul functiei avg este de tip intreg atunci si rezultatul este numar intreg.
Pentru a obtine un rezultat de tip real trebuie sa convertim argumentul la tip real.
Putem folosi una din variantele urmatoare:
*/
select avg(Nota+0.0) as [Media Notelor] from tNote
select avg(Nota*1.0) as [Media Notelor] from tNote
select avg(convert(decimal(4,2),Nota)) as [Media Notelor] from tNote
select avg(cast(Nota as decimal(4,2))) as [Media Notelor] from tNote
/*
Media Notelor
6.636363
*/

/*Sa se afle numarul notelor*/
select count(Nota) as [Numar Note] from tNote
/*
Numar Note
11
*/

/*Sa se afle suma notelor supra numarul notelor 
Sa observati ca raportul a doua numere intregi este un numar intreg 
*/
select sum(Nota)/count(Nota) as [Media Notelor] from tNote
/*
Media Notelor
6
*/

select 1.0*sum(Nota)/count(Nota) as [Media Notelor]  from tNote
/*
Media Notelor
6.636363636363
*/

/*Sa se afiseze CodStudent,Nume,CodCurs,Nota*/
select A.CodStud,Nume,CodCurs,Nota
	from tStudenti as A  inner join tNote as B
	on A.CodStud=B.CodStud
/*
CodStud		Nume	  CodCurs	  Nota
S01       	Florin		ASD       	7
S02       	Mihai		ASD       	9
S03       	Alexandra	ASD       	8
S04       	Andreea		ASD       	5
S01       	Florin		FP        	5
S02       	Mihai		FP        	6
S03       	Alexandra	FP        	4
S04       	Andreea		FP        	10
S11       	Flavius		FP        	8
S12       	Marian		FP        	4
S13       	Adrian		FP        	7
*/

/*Sa se afiseze studentii care au luat cea mai mare nota*/
select A.CodStud,Nume,CodCurs,Nota
	from tStudenti as A inner join tNote as B 
	on A.CodStud=B.CodStud
	where Nota=(select max(Nota) from tNote)
/*
CodStud		Nume	  CodCurs	   Nota
S04       	Andreea		FP        	10
*/

/*Sa se afiseze studentii care au luat nota cea mai mica*/
select CodStud,Nume,Prenume,CodCurs,Nota
	from tStudenti as A inner join tNote as B 
	on A.CodStud=B.CodStd
	where Nota=(select min(Nota) from tNote)
/*
CodStud		Nume	 CodCurs	  Nota
S03       	Alexandra	FP        	4
S12       	Marian		FP        	4
*/

/*Sa se afiseze colegii de specializare ai studentei  Alexandra*/
select CodStud,Nume,CodSpec
	from tStudenti 
	where CodSpec=(select CodSpec from tStudenti where Nume='Alexandra')
/*
CodStud		Nume		CodSpec
S01       	Florin		Info      
S02       	Mihai		Info      
S03       	Alexandra	Info      
S04       	Andreea		Info      
*/

  /*Sa se afiseze studentii care au media  notelor mai mare decat media generala a tuturor notelor studentilor*/
select A.CodStud,Nume,avg(Nota*1.0) as Media
	from tStudenti as A inner join tNote as B
	on A.CodStud=B.CodStud
	group by  A.CodStud,Nume
	having avg(Nota*1.0)>(select avg(Nota*1.0) from tNote)
/*
CodStud		Nume		Media
S02       	Mihai		7.500000
S04       	Andreea		7.500000
S11       	Flavius		8.000000
S13       	Adrian		7.000000
*/


/*Sa se afiseze CodStud,Nume,Prenume,Medie student, Media notelor tuturor studentilor*/ 
select A.CodStud,Nume,avg(Nota*1.0) as [Medie student],
	(select avg(Nota*1.0) from tNote) as [Media notelor]
	from tStudenti as A inner join tNote as B
	on A.CodStud=B.CodStud
	group by A.CodStud,Nume
/*
CodStud		Nume	Medie student	Media notelor
S01       	Florin		6.000000	6.636363
S02       	Mihai		7.500000	6.636363
S03       	Alexandra	6.000000	6.636363
S04       	Andreea		7.500000	6.636363
S11       	Flavius		8.000000	6.636363
S12       	Marian		4.000000	6.636363
S13       	Adrian		7.000000	6.636363
*/


/*Sa se determine CodCurs si Nota Maxima*/
select CodCurs,max(Nota) as [Nota Maxima]
	from tNote 
	group by CodCurs
/*
CodCurs		Nota Maxima
ASD       	9
FP        	10
*/

/*Sa se afiseze denumire curs si nota maxima*/
select Denumire,[Nota maxima] 
	from tCursuri as A inner join ( select CodCurs,max(Nota) as [Nota Maxima] from tNote 
	group by CodCurs) as B 
	on A.CodCurs=B.CodCurs
/*
Denumire					  Nota maxima
Algoritmi si structuri de date		9
Fundamentele Programarii		   10
*/

--Sa se afiseze denumirea specializarii si media la nivel de specializare
select A.Denumire, A.codSpec, avg(nota * 1.0) as [Media notelor]
	from tSpecializari as A inner join tStudenti as B 
	on A.codSpec = B.codSpec inner join tNote as C 
	on B.codStud = C.codStud
	group by A.Denumire, A.codSpec
/*
Denumire	codSpec		Media notelor
Informatica	Info      	6.750000
Matematica	Mate      	6.333333
*/

--Sa se afiseze cod specializare si media maxima obtinuta de studenti in cadrul specializarii
--1) codStud, CodSpec
select codStud,CodSpec from tStudenti
/*
codStud		CodSpec
S01       	Info      
S02       	Info      
S03       	Info      
S04       	Info      
S11       	Mate      
S12       	Mate      
S13       	Mate      
S21       	Bio       
S22       	Bio       
S31       	AM        
*/

--2) cod student, media
select codStud as [codStud], avg(nota * 1.0) as [Media]
	from tNote
	group by codStud
/*
codStud		 Media
S01       	6.000000
S02       	7.500000
S03       	6.000000
S04       	7.500000
S11       	8.000000
S12       	4.000000
S13       	7.000000
*/

--3) cod specializare, media maxima
select codSpec, max(Media) as [Media maxima]
	from tStudenti as A inner join (select codStud as [codStud], avg(nota * 1.0) as [Media]
	from tNote
	group by codStud) as B 
	on A.codStud = B.codStud
	group by codSpec
/*
codSpec		Media maxima
Info      	7.500000
Mate      	8.000000
*/
```
