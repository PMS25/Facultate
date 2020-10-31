# Explicaţie - Constructor
## Petculescu Mihai-Silviu

- [Explicaţie - Constructor](#explicaţie---constructor)
  - [Petculescu Mihai-Silviu](#petculescu-mihai-silviu)
    - [1. Se cere să explicaţi rezultatele obţinute prin executarea programului C++ de mai jos.](#1-se-cere-să-explicaţi-rezultatele-obţinute-prin-executarea-programului-c-de-mai-jos)
    - [2. Corectaţi programul, astfel ca pe cele doua linii să fie afişată aceeaşi valoare(20).](#2-corectaţi-programul-astfel-ca-pe-cele-doua-linii-să-fie-afişată-aceeaşi-valoare20)
    - [3. Rescrieţi în Java ambele variante.](#3-rescrieţi-în-java-ambele-variante)

### 1. Se cere să explicaţi rezultatele obţinute prin executarea programului C++ de mai jos.

**Rezultat**
```bash
20
0
```

Deoarece în programul dat, în clasa Person, vârsta este salvată doar ca şi o variabilă locală `age` programul va afişa vârsta trimisă ca şi parametru, în cazul nostru `20`, şi prin intermediul liniei `cout<<p.age<<endl` din `main()` valoarea albitrară alocată de compiler la construcţia acelei instanţe a clasei (care poate fi 0 sau orice altă valoare, depinzând de compilerul c++ folosit şi, eventual, de momentul execuţiei).

### 2. Corectaţi programul, astfel ca pe cele doua linii să fie afişată aceeaşi valoare(20).

Prin modificarea liniei `int age=a;` în `age=a;` (sau mai precis prin elimiarea re-declarării variabilei `age` în interiorul constructorului clasei `Person`), valoarea variabilei va fi memorată în zona de memorie asociată instanţei clasei, şi nu într-un sector random de memorie, ca în exemplul precedent.

### 3. Rescrieţi în Java ambele variante.

**Implementare prima variantă**

Person.java
```java
public class Person {
    int age;

    public Person(int a){
        age=a;
        System.out.println(age);
    }
}
```

Main.java
```java
public class Main {
    public static void main(String args[]){
        Person p = new Person(20);
        System.out.println(p.age);
    }
}
```

**Implementare a doua variantă**

Person.java
```java
public class Person {
    int age;

    public Person(int a){
        int age=a;
        System.out.println(age);
    }
}
```

Main.java
```java
public class Main {
    public static void main(String args[]){
        Person p = new Person(20);
        System.out.println(p.age);
    }
}
```
