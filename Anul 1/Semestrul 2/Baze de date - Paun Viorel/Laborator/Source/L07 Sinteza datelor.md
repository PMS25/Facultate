# L07 Sinteza datelor 

```sql
-- SINTEZA DATELOR
select  codSpec  ,nume , codCurs,Nota
	from tStudenti as A inner join tNote as B on A.codStud=B.codStud 
	union 
select codSpec, nume , '*', avg(convert (decimal,nota)) as media
	from tStudenti as A inner join tNote as B on A.codStud=B.codStud
	group by codSpec,Nume 
	union
select codSpec, '*' ,'*' , avg(convert (decimal,nota)) as media
	from tStudenti as A inner join tNote as B on A.codStud=B.codStud
	group by codSpec
	union 
select '*' ,'*','*' , avg (convert(decimal,nota)) as media
	from tStudenti as A inner join tNote as B on A.codStud=B.codStud
	order by codSpec ,Nume, codCurs
/*
codSpec		nume		codCurs		Nota
   *		*			*			6.636363
Info      	 *			*			6.750000
Info      	Alexandra	 *			6.000000
Info      	Alexandra	ASD       	8.000000
Info      	Alexandra	FP        	4.000000
Info      	Andreea		*			7.500000
Info      	Andreea		ASD       	5.000000
Info      	Andreea		FP        	10.000000
Info      	Florin		*			6.000000
Info      	Florin		ASD       	7.000000
Info      	Florin		FP        	5.000000
Info      	Mihai		*			7.500000
Info      	Mihai		ASD       	9.000000
Info      	Mihai		FP        	6.000000
Mate      	*			*			6.333333
Mate      	Adrian		*			7.000000
Mate      	Adrian		FP        	7.000000
Mate      	Flavius		*			8.000000
Mate      	Flavius		FP        	8.000000
Mate      	Marian		*			4.000000
Mate      	Marian		FP        	4.000000
*/

--Sa se modifice interogarea precedenta astfel incat sa apara nota maxima si nota minima la nivel de student , etc.
select  codSpec  ,nume , codCurs,Nota,' 'as [nota minima], ' ' as [ nota maxima]
	from tStudenti as A inner join tNote as B on A.codStud=B.codStud 
	union 
select codSpec, nume, '*', avg(convert (decimal,nota)) as media, str(min(nota)), str(max(nota))
	from tStudenti as A inner join tNote as B on A.codStud=B.codStud
	group by codSpec,Nume
	union
select codSpec, '*' ,'*' , avg(convert (decimal,nota)) as media,str(min(nota)), str( max(nota))
	from tStudenti as A inner join tNote as B on A.codStud=B.codStud
	group by codSpec
	union 
select '*' ,'*','*' , avg (convert(decimal,nota)) as media,str(min(nota)), str(max(nota))
	from tStudenti as A inner join tNote as B on A.codStud=B.codStud
	order by codSpec ,Nume, codCurs
/*
codSpec	        nume	codCurs		Nota	nota minima	 nota maxima
   *		*			*		6.636363		4	 	10
Info      	*			*		6.750000		4	     10
Info      	Alexandra	*		6.000000		4	      8
Info      	Alexandra	ASD       8.000000	 	 
Info      	Alexandra	FP        4.000000	 	 
Info      	Andreea		*		 7.500000		5	      10
Info      	Andreea		ASD       5.000000	 	 
Info      	Andreea		FP        10.000000	 	 
Info      	Florin		*		 6.000000		5	      7
Info      	Florin		ASD       7.000000	 	 
Info      	Florin		FP        5.000000	 	 
Info      	Mihai		*		 7.500000		6	      9
Info      	Mihai		ASD       9.000000	 	 
Info      	Mihai		FP        6.000000	 	 
Mate      	*			*		 6.333333		4	     8
Mate      	Adrian		*		 7.000000		7	      7
Mate      	Adrian		FP        7.000000	 	 
Mate      	Flavius		*		 8.000000		8	      8
Mate      	Flavius		FP        8.000000	 	 
Mate      	Marian		*		 4.000000		4	      4
Mate      	Marian		FP        4.000000	 	 
*/

--Varianta optimizata. Utilizarea clauzei ROLLUP 
select  codSpec  ,nume , codCurs, avg(convert(decimal,nota)) as media
	from tStudenti as A inner join tNote as B on A.codStud=B.codStud 
	group by  CodSpec, nume, CodCurs
	with rollup
/*
codSpec		nume		codCurs		media
Info      	Alexandra	ASD       	8.000000
Info      	Alexandra	FP        	4.000000
Info      	Alexandra	NULL		6.000000
Info      	Andreea		ASD       	5.000000
Info      	Andreea		FP        	10.000000
Info      	Andreea		NULL		7.500000
Info      	Florin		ASD       	7.000000
Info      	Florin		FP        	5.000000
Info      	Florin		NULL		6.000000
Info      	Mihai		ASD       	9.000000
Info      	Mihai		FP        	6.000000
Info      	Mihai		NULL		7.500000
Info      	NULL		NULL		6.750000
Mate      	Adrian		FP        	7.000000
Mate      	Adrian		NULL		7.000000
Mate      	Flavius		FP        	8.000000
Mate      	Flavius		NULL		8.000000
Mate      	Marian		FP        	4.000000
Mate      	Marian		NULL		4.000000
Mate      	NULL		NULL		6.333333
NULL		NULL		NULL		6.636363
*/

--Utilizarea clauzei CUBE
select  codSpec  ,nume , codCurs, avg(convert(decimal,nota)) as media
	from tStudenti as A inner join tNote as B on A.codStud=B.codStud 
	group by  CodSpec, nume, CodCurs
	with cube
/*
codSpec		nume		codCurs		media
Info      	Alexandra	ASD       	8.000000
NULL		Alexandra	ASD       	8.000000
Info      	Andreea		ASD       	5.000000
NULL		Andreea		ASD       	5.000000
Info      	Florin		ASD       	7.000000
NULL		Florin		ASD       	7.000000
Info      	Mihai		ASD       	9.000000
NULL		Mihai		ASD       	9.000000
NULL		NULL		ASD       	7.250000
Mate      	Adrian		FP        	7.000000
NULL		Adrian		FP        	7.000000
Info      	Alexandra	FP        	4.000000
NULL		Alexandra	FP        	4.000000
Info      	Andreea		FP        	10.000000
NULL		Andreea		FP        	10.000000
Mate      	Flavius		FP        	8.000000
NULL		Flavius		FP        	8.000000
Info      	Florin		FP        	5.000000
NULL		Florin		FP        	5.000000
Mate      	Marian		FP        	4.000000
NULL		Marian		FP        	4.000000
Info      	Mihai		FP        	6.000000
NULL		Mihai		FP        	6.000000
NULL		NULL		FP        	6.285714
NULL		NULL		NULL		6.636363
Info      	NULL		ASD       	7.250000
Info      	NULL		FP        	6.250000
Info      	NULL		NULL		6.750000
Mate      	NULL		FP        	6.333333
Mate      	NULL		NULL		6.333333
Mate      	Adrian		NULL		7.000000
NULL		Adrian		NULL		7.000000
Info      	Alexandra	NULL		6.000000
NULL		Alexandra	NULL		6.000000
Info      	Andreea		NULL		7.500000
NULL		Andreea		NULL		7.500000
Mate      	Flavius		NULL		8.000000
NULL		Flavius		NULL		8.000000
Info      	Florin		NULL		6.000000
NULL		Florin		NULL		6.000000
Mate      	Marian		NULL		4.000000
NULL		Marian		NULL		4.000000
Info      	Mihai		NULL		7.500000
NULL		Mihai		NULL		7.500000
*/

select  codSpec  ,nume+' '+prenume as nume , codCurs,Nota
	from tStudenti as A inner join tNote as B on A.codStud=B.codStd 
	order by nume

--TABELE PIVOT
select CodSpec , Nume,isnull( str(AG),'-') as [Alg gr],isnull(str( ASD),'-') as [Str date ],
	isnull(str( FP),'-') as [Fundamentele pr],isnull(str( BD),'-') as [Baze date ]
	from ( select  codSpec  ,nume as nume , codCurs,Nota
	from tStudenti as A inner join tNote as B on A.codStud=B.codStud ) as A 
	pivot (avg(nota) for CodCurs in ([AG],[ASD],[FP], [BD] )  ) as PVT
/*
CodSpec		Nume		Alg gr		Str date 	Fundamentele pr		Baze date 
Mate      	Adrian		-		-	         7			-
Info      	Alexandra	-		8	         4			-
Info      	Andreea		-		5	        10			-
Mate      	Flavius		-		-	         8			-
Info      	Florin		-		7	         5			-
Mate      	Marian		-		-	         4			-
Info      	Mihai		-		9	         6			-
*/
```

