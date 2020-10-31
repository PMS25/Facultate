# L08 Limbajul de manipulare a datelor

```sql
use bdFacultati

--Sa se creeze tabelul tRestantieri cu studentii ce au obtinut note < 5
select CodSpec,A.CodStud,Nume,C.CodCurs,Denumire,Nota
	into tRestantieri
	from tStudenti as A inner join tNote as B on A.CodStud=B.codStud
   	inner join tCursuri as C on B.CodCurs=C.CodCurs
	where Nota<5

--Sa se afiseze tabelul tRestantieri
select * from tRestantieri

/*
CodSpec		CodStud		Nume		CodCurs		Denumire				Nota
Info      	S03       	Alexandra	 FP        	Fundamentele Programarii	4
Mate      	S12       	Marian		 FP        	Fundamentele Programarii	4
*/

--Sa se stearga continutul tabelului tRestantieri
truncate table tRestantieri

/*Comanda: `truncate table tRestantieri` este similara ca efect dar mult mai rapida decat `delete tRestantieri` 
*/

select * from tRestantieri
/*
CodSpec		CodStud		Nume		CodCurs		Denumire			Nota
*/

--Sa se adauge tabelului tRestantieri constrangerea primay key
alter table tRestantieri
add constraint pk_rest primary key (CodStud,CodCurs)

--sa se insereze in tRestantieri studentii restantieri
insert into tRestantieri
select CodSpec,A.CodStud,Nume,C.CodCurs,Denumire,Nota
	from tStudenti as A inner join tNote as B on A.CodStud=B.codStud
	inner join tCursuri as C on B.CodCurs=C.CodCurs
	where Nota<5

select * from tRestantieri
/*
CodSpec		CodStud		Nume		CodCurs		Denumire				Nota
Info      	S03       	Alexandra	FP        	Fundamentele Programarii	4
Mate      	S12       	Marian		FP        	Fundamentele Programarii	4
*/

--Sa se afiseze tabelul tNote
select * from tNote
/*
codCurs		codStud		dataExamen		   nota
ASD       	S01       	2020-02-08 00:00:00	7
ASD       	S02       	2020-02-08 00:00:00	9
ASD       	S03       	2020-02-08 00:00:00	8
ASD       	S04       	2020-02-08 00:00:00	5
FP        	S01       	2020-02-05 00:00:00	5
FP        	S02       	2020-02-05 00:00:00	6
FP        	S03       	2020-02-05 00:00:00	4
FP        	S04       	2020-02-05 00:00:00	10
FP        	S11       	2020-02-05 00:00:00	8
FP        	S12       	2020-02-05 00:00:00	4
FP        	S13       	2020-02-05 00:00:00	7
*/

--Sa se afiseze tabelul tStudenti
select * from tStudenti
/*
codStud	nume		CNP			codSpec	  anStudiu	codJud	localitate	dataNasterii
S01     Florin		1990514123456	Info      	1	AG      Pitesti		1999-05-14 00:00:00
S02     Mihai		1991130123456	Info      	1	AG      Costesti	1999-11-30 00:00:00
S03     Alexandra	2980117123456	Info      	2	AG      Pitesti		1998-01-17 00:00:00
S04     Andreea		2980824123456	Info      	2	AG      Stefanesti	1998-08-24 00:00:00
S11     Flavius		1990413123456	Mate      	1	AG      Mioveni		1999-04-13 00:00:00
S12     Marian		1980919123456	Mate      	2	AG      Pitesti		1998-09-19 00:00:00
S13     Adrian		1990718123456	Mate      	1	AG      Costesti	1999-07-18 00:00:00
S21     Raul		1991228123456	Bio       	1	AG      Pitesti		1999-12-28 00:00:00
S22     Corina		2991121123456	Bio       	1	AG      Stefanesti	1999-11-21 00:00:00
S31     Maria		2990426123456	AM        	1	AG      Pitesti		1999-04-26 00:00:00
S41     Ioana		5000421033333	EF        	1	AG      Pitesti		2000-04-21 00:00:00
S42     Codrut		6001212033333	EF        	1	AG      Pitesti		2000-12-12 00:00:00
S43     Sanziana	6011109033333	EF        	1	AG      Pitesti		2001-11-09 00:00:00
S44     Victoria	6010307033333	EF        	1	AG      Pitesti		2001-03-07 00:00:00
*/

select * from tNote where codStud='S03'
/*
codCurs		codStud		dataExamen		   nota
ASD       	S03       	2020-02-08 00:00:00	8
FP        	S03       	2020-02-05 00:00:00	4
*/

-- Sa se mareasca notele studentului 'S03' cu 1 punct
update tNote
	set Nota=Nota+1
	where CodStd='S03' and Nota<10
	
select * from tNote where codStud='S03'
/*
codCurs		codStud		dataExamen		   nota
ASD       	S03       	2020-02-08 00:00:00	9
FP        	S03       	2020-02-05 00:00:00	5
*/

/* Sa se modifice notele studentului 'S03' astfel încat la disciplina 'ASD'  nota să devină 8,
iar la 'FP' nota să devină 4*/
update tNote
	set Nota=8 
	where CodStud='S03' and codCurs='ASD'

update tNote
	set Nota=4 
	where CodStud='S03' and codCurs='FP'

--Sa se afiseze notele stud de la specializarea mate
select A.CodStud,nume,CodSpec,CodCurs,Nota
from tStudenti as A inner join tNote as B
               on A.codStud=B.codStud 
where CodSpec='Mate'
/*
CodStud		nume	CodSpec		CodCurs		Nota
S11       	Flavius	Mate      	FP        	8
S12       	Marian	Mate      	FP        	4
S13       	Adrian	Mate      	FP        	7
*/

--Sa se mareasca cu 1 punct notele studentilor de la mate
--Solutia 1-a - fara clauza from
update tNote
	set Nota=Nota+1 
	where CodStud in (select CodStud from tStudenti where codSpec='Mate')

select A.CodStud,nume,CodSpec,CodCurs,Nota
from tStudenti as A inner join tNote as B
               on A.codStud=B.codStud 
where CodSpec='Mate' and nota<10
/*
CodStud		nume	CodSpec		CodCurs		Nota
S11       	Flavius	Mate      	FP        	9
S12       	Marian	Mate      	FP        	5
S13       	Adrian	Mate      	FP        	8
*/

--Solutia a 2-a - cu clauza from
update tNote 
	set Nota=Nota+1
	from tStudenti as A inner join tNote as B on a.CodStud=B.codstud
	where codSpec='Mate' and nota<10

select A.CodStud,nume,CodSpec,CodCurs,Nota
from tStudenti as A inner join tNote as B
               on A.codStud=B.codStud 
where CodSpec='Mate'
/*
CodStud		nume	CodSpec	CodCurs		  Nota
S11       	Flavius	Mate      	FP        	10
S12       	Marian	Mate      	FP        	6
S13       	Adrian	Mate      	FP        	9
*/

--Sa se creeze tabelul tNoteProiect
create table tNoteProiect(
  codStud char(10),
  CodCurs char(10),
  nota int constraint ck_notaP check(nota between 1 and 10),
  constraint pk_NotePr primary key(CodStud,CodCurs)
)

--Sa se insereze notele de la proiect la FP studentilor s11,s12,s13
insert into tNoteProiect
values ('s11','FP',8),
       ('s12','FP',6),
       ('s13','FP',10)

--sa se adauge tabelului tNote coloana NotaProiect
alter table scoala.tNote
add NotaProiect int

-- sa se adauge constrangerea notaProiect intre 1 si 10
alter table scoala.tNote
add constraint ck_notaPr check(NotaProiect between  1 and 10)

select * from tNote
/*
codCurs	codStud 	dataExamen	   nota	NotaProiect
ASD     S01     2020-02-08 00:00:00	7	NULL
ASD     S02     2020-02-08 00:00:00	9	NULL
ASD     S03     2020-02-08 00:00:00	8	NULL
ASD     S04     2020-02-08 00:00:00	5	NULL
FP      S01     2020-02-05 00:00:00	5	NULL
FP      S02     2020-02-05 00:00:00	6	NULL
FP      S03     2020-02-05 00:00:00	4	NULL
FP      S04     2020-02-05 00:00:00	10	NULL
FP      S11     2020-02-05 00:00:00	10	NULL
FP      S12     2020-02-05 00:00:00	6	NULL
FP      S13     2020-02-05 00:00:00	9	NULL
*/
--sa se actualizeze tabelul tNote cu notele de la proiect memorate in tNoteProiect

update tNote
set notaProiect=B.Nota
from tNote as A inner join tNoteProiect as B 
        on A.CodStud=B.CodStud and A.CodCurs=B.CodCurs
/*
codCurs	codStud	  dataExamen	   nota	NotaProiect
ASD     S01     2020-02-08 00:00:00	7	NULL
ASD     S02     2020-02-08 00:00:00	9	NULL
ASD     S03     2020-02-08 00:00:00	8	NULL
ASD     S04     2020-02-08 00:00:00	5	NULL
FP      S01     2020-02-05 00:00:00	5	NULL
FP      S02     2020-02-05 00:00:00	6	NULL
FP      S03     2020-02-05 00:00:00	4	NULL
FP      S04     2020-02-05 00:00:00	10	NULL
FP      S11     2020-02-05 00:00:00	10	8
FP      S12     2020-02-05 00:00:00	6	6
FP      S13     2020-02-05 00:00:00	9	10
*/
```



 