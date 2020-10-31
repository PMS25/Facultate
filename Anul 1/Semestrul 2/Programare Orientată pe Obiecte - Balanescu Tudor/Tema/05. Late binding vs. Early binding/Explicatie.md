# Explicaţie - Late binding vs. Early binding
## Petculescu Mihai-Silviu

- [Explicaţie - Late binding vs. Early binding](#explicaţie---late-binding-vs-early-binding)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
  - [Ce se afişează prin executarea programului? Explicaţi mecanismul de legare a metodei la implementare pentru fiecare linie afişată.](#ce-se-afişează-prin-executarea-programului-explicaţi-mecanismul-de-legare-a-metodei-la-implementare-pentru-fiecare-linie-afişată)

## Ce se afişează prin executarea programului? Explicaţi mecanismul de legare a metodei la implementare pentru fiecare linie afişată.

**Despre legarea statică / early binding**
Legarea statică se referă la evenimentele care au loc la momentul compilării. În principal, `early binding` se execută atunci cand toate informaţiile legate de apelul funcţiilor sunt cunoscute la momentul compilării. Datorită acestei particularităţii, aceste tipuri de funcţii sunt caracterizate printr-o viteză de apelare mai mare decât în cazul `late binding`.

**Despre legarea dinamică / late binding**
Legarea dinamică se execută în momentul rurării programului, aspect implementat în C++ prin intermediul funcţiilor virtuale. Aceste funcţii determină baza de cod ce va fi executată în funcţie de tipul de date al pointerului de la care porneşte apelul. Marele avantaj oferit de acestea ar fi flexibilitatea oferită în scrierea codului, care poate răspunde dinamic diferitelor cerinţe apărute pe durata rurării. Legat de viteză, astăzi diferenţele sunt suficient de mici pentru a trece ca insesizabile în marea majoritate a cazurilor cerute.  

**Rezultat**
```bash
A::st()
A::vrt()
A::stafis()
A::st()
A::vrt()
B::vrtafis()
B::st()
A::vrt()
```

Clasa `A` implementează 4 metode, două statice `void st(); void stafis();` şi două dinamice `void vrt(); void vrtafis();` prin declararea acestora cu keyword-ul `virtual`. Clasa `B` este subclasă a clasei `A` şi alege să suprascrie 3 dintre cele 4 metode ale superclasei sale, cele 2 statice şi funcţia virtuală `void vrtafis()`.

La executarea programului se crează un pointer `p` de tipul superclasei `A`, care este făcut să pointeze către o instanţă a subclasei `B`.

La apelarea liniei `p->st()` se va executa funcţia `st()` specifică clasei `A` întrucât aceasta a fost legată la compilare static. Se afişează `A::st()`.

Analog şi pentru linia `p->stafis()` unde sunt luate în considerare doar implementările funcţiilor de tipul pointerului `p` (adică al superclasei). Se afişează `A::stafis() A::st() A::vrt()`.

Linia `p->vrt()` este un caz mai special, căci cu toate ca se apelează o funcţie virtuală, aceasta nu are implementare în clasa `B` şi deci, în consecinţă, se alege implementarea moştenită de la superclasă. Se afişează `A::vrt()`.

Ultima linie `p->vrtafis()` prezintă un caz clasic de `late binding` întrucât vor fi apelate în executare, în principal, doar interpretările din clasa `B` (subclasă) şi în cazul în care lipsesc, la fel ca şi în cazul anterior, se apelează interpretarea moştenită de la superclasă. Se afişează `B::vrtafis()  B::st() A::vrt()`.