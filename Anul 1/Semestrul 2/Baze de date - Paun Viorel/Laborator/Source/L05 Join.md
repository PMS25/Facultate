# L05 Join 

```sql
use bdFacultati
select * from tCursuri
/*
codCurs			denumire					tipCurs	 nrCredite
AG		  Algoritmica Grafurilor				 B		 5
BD		  Baze de Date							B		6
EF		  Educatie Fizica						B		2
EN		  Limba Engleza							B		4
GC		  Geometrie Computationala				 B		 5
LMC		  Logica Matematica Si Computationala	  B		  6
OOP		  Programare Orientata Pe Obiecte		  B		  6
PED		  Pedagogie								F		4
*/

select * from tProfesori
/*
codProf	  nume		gradDidactic   codDep
P1       POPESCU		NULL		DMI       
P2       TEODORESCU		NULL		DMI       
P3       CONSTANTINESCU	NULL		DMI       
P4       MARINESCU		NULL		DEFS      
P5       IONESCU		NULL		DS        
P6       RADULESCU		NULL		DAMK      
P7       STANCIULESCU	NULL		DMI       
P8       BARBULESCU		NULL		DMI       
*/

alter table scoala.tCursProfesor
	alter column tipPredare char(2) 

alter table scoala.tCursProfesor
	drop constraint CK_tipPredare

/* Sa se impuna coloanei tipPredare valorile posibile 
'T'- predare teoretica(curs) si 'P'- predare practica(laborator,seminar, etc)
'TP'-predare teoretica(curs) si predare practica(laborator,seminar, etc)
*/

alter table Scoala.tCursProfesor
	add constraint CK_tipPredare check(tipPredare in ('T','P','TP'))

insert into tCursProfesor(codCurs,CodProf,tipPredare)
values ('AG','P1','T'), -- T- activitate teoretica(curs)
       ('AG','P2','P'), -- P-activitate practica(laborator,seminar)
       ('BD','P3','TP'),
       ('GC','P4','TP'),
       ('LMC','P4','TP'),
       ('OOP','P5','T'),
       ('OOP','P6','P')

select * from tCursProfesor
/*
codCurs		codProf		tipPredare
AG        	P1        	T 
AG        	P2        	P 
BD        	P3        	TP
GC        	P4        	TP
LMC       	P4        	TP
OOP       	P5        	T 
OOP       	P6        	P 
*/

-- Sa se afiseze disciplinele predate de profesori
select tProfesori.CodProf, Nume, CodCurs,tipPredare
	from tProfesori, tCursProfesor
	where tProfesori.CodProf = tCursProfesor.CodProf 
/*
CodProf		Nume		  CodCurs	tipPredare
P1        	POPESCU			AG        	T 
P2        	TEODORESCU		AG        	P 
P3        	CONSTANTINESCU	BD        	TP
P4        	MARINESCU		GC        	TP
P4        	MARINESCU		LMC       	TP
P5        	IONESCU			OOP       	T 
P6        	RADULESCU		OOP       	P 
*/

select tProfesori.CodProf, Nume, CodCurs,tipPredare
	from tProfesori inner join tCursProfesor on tProfesori.CodProf = tCursProfesor.CodProf
/*
CodProf		Nume		 CodCurs	tipPredare
P1        	POPESCU			AG        	T 
P2        	TEODORESCU		AG        	P 
P3        	CONSTANTINESCU	BD        	TP
P4        	MARINESCU		GC        	TP
P4        	MARINESCU		LMC       	TP
P5        	IONESCU			OOP       	T 
P6        	RADULESCU		OOP       	P 
*/

select A.CodProf, Nume, CodCurs, tipPredare
	from tProfesori as A inner join tCursProfesor as B on A.CodProf = B.CodProf
/*
CodProf		Nume		  CodCurs	tipPredare
P1        	POPESCU			AG        	T 
P2        	TEODORESCU		AG        	P 
P3        	CONSTANTINESCU	BD        	TP
P4        	MARINESCU		GC        	TP
P4        	MARINESCU		LMC       	TP
P5        	IONESCU			OOP       	T 
P6        	RADULESCU		OOP       	P 
*/

-- Sa se afiseze, in plus, si denumirea cursului in ordinea alfabetica a numelor profesorilor
select A.CodProf, Nume, C.CodCurs, Denumire as [Denumire Curs]
	from tProfesori as A inner join tCursProfesor as B on A.CodProf = B.CodProf
	inner join tCursuri as C on B.CodCurs = C.CodCurs
	order by Nume
/*
CodProf		Nume		  CodCurs	      Denumire Curs
P3        	CONSTANTINESCU	BD      Baze de Date
P5        	IONESCU			OOP     Programare Orientata Pe Obiecte
P4        	MARINESCU		GC      Geometrie Computationala
P4        	MARINESCU		LMC     Logica Matematica Si Computationala
P1        	POPESCU			AG      Algoritmica Grafurilor
P6        	RADULESCU		OOP     Programare Orientata Pe Obiecte
P2        	TEODORESCU		AG      Algoritmica Grafurilor
*/

-- Sa se afiseze Denumire Facultate, denumire specializare si nume studenti
select A.Denumire AS Facultate, C.Denumire as Specializare, D.Nume as Student
	from tFacultati as A 
	inner join tDepartamente as B on A.CodFac=B.CodFac
	inner join tSpecializari as C on B.CodDep=C.CodDep 
	inner join tStudenti as D on C.CodSpec = D.CodSpec
/*
	Facultate									Specializare		Student
Facultatea de Stiinte, Ed. Fizica si Informatica	Informatica			Florin
Facultatea de Stiinte, Ed. Fizica si Informatica	Informatica			Mihai
Facultatea de Stiinte, Ed. Fizica si Informatica	Informatica			Alexandra
Facultatea de Stiinte, Ed. Fizica si Informatica	Informatica			Andreea
Facultatea de Stiinte, Ed. Fizica si Informatica	Matematica			Flavius
Facultatea de Stiinte, Ed. Fizica si Informatica	Matematica			Marian
Facultatea de Stiinte, Ed. Fizica si Informatica	Matematica			Adrian
Facultatea de Stiinte, Ed. Fizica si Informatica	Biologie			Raul
Facultatea de Stiinte, Ed. Fizica si Informatica	Biologie			Corina
Facultatea de Stiinte, Ed. Fizica si Informatica	Asistenta Medicala	 Maria
*/

-- Numarul de studenti la nivel de specializare
select Denumire,count(CodStud) as NrStudenti 
	from tStudenti as A
	inner join tSpecializari as B on A.CodSpec =B.CodSpec
	group by Denumire
/*
Denumire		NrStudenti
Asistenta Medicala	 1
Biologie			2
Informatica			4
Matematica			3
*/

--Cod facultate,Denumire Facultate si numar Studenti
select D.CodFac,D.Denumire,count(CodStud) as [Nr Studenti]
	from tStudenti as A
	inner join tSpecializari as B on A.CodSpec=B.CodSpec
	inner join tDepartamente as C on B.CodDep=C.CodDep
	inner join tFacultati as D on C.CodFac=D.CodFac
	group by D.Denumire,D.CodFac
/*
CodFac	Denumire									Nr Studenti
FSEFI   Facultatea de Stiinte, Ed. Fizica si Informatica	10
*/

--Cod facultate,Denumire Facultate si numar Studenti
select A.CodFac,A.Denumire,count(CodStud) as [Nr Studenti]
	from tFacultati as A 
	inner join tDepartamente as B on A.CodFac=B.CodFac
	inner join tSpecializari as C on B.CodDep=C.CodDep 
	inner join tStudenti as D on C.CodSpec = D.CodSpec
	group by A.Denumire,A.CodFac
/*
CodFac	 Denumire									Nr Studenti
FSEFI   Facultatea de Stiinte, Ed. Fizica si Informatica	10
*/

insert into scoala.tProfesori(CodProf, Nume,  GradDidactic, CodDep)
values ('P7','STANCIULESCU',null,'DMI'),
('P8','BARBULESCU',null,'DMI')

--Profesori care nu au predau  
select A.CodProf, Nume, CodCurs
	from  tProfesori as A left join tCursProfesor as B on A.CodProf = B.CodProf
	where CodCurs is Null
/*
CodProf		    Nume	  CodCurs
P7        	STANCIULESCU	NULL
P8        	BARBULESCU		NULL
*/

--Sa se afiseze nr de studenti din Pitesti la nivel de specializare 
select Denumire,count(CodStud) as NrStudenti 
	from tStudenti as A
	inner join tSpecializari as B on A.CodSpec =B.CodSpec
	where Localitate='Pitesti'
	group by Denumire
/*
Denumire		NrStudenti
Asistenta Medicala	 1
Biologie			1
Informatica			2
Matematica			1
*/

--Sa se afiseze nr de studenti la nivel de specializare pentru specializarile cu cel putin 3 studenti
select Denumire,count(CodStud) as NrStudenti 
	from tStudenti as A
	inner join tSpecializari as B on A.CodSpec =B.CodSpec
	group by Denumire
	having count(CodStud) >= 3
/*
Denumire	NrStudenti
Informatica		4
Matematica		3
*/

```

