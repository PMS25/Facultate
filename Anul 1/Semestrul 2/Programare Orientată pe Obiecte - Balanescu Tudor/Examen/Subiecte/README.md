# Rezolvări

- [Rezolvări](#rezolvări)
    - [A3](#a3)
    - [B3](#b3)
    - [C3](#c3)
    - [D3](#d3)
    - [E3](#e3)
    - [F3](#f3)
    - [G3](#g3)
    - [H3](#h3)
    - [I3](#i3)
    - [J3](#j3)

### A3

```c++
#include <iostream>
#include <string.h>
#include <ostream>
using namespace std;

class Person
{
public:
    Person(char *n, int a)
    {
        name = new char(strlen(n) + 1);
        strcpy(name, n);
        age = a;
    }

protected:
    char *name;
    int age;
};


class PersonSpec : public Person{
    public:
        using Person::Person;
        int getAge() const{
            return age;
        }
        char* getName() const{
            return name;
        }
};

ostream& operator<<(ostream& stream, const PersonSpec& ps){
    stream << ps.getName() << ", " << ps.getAge();
    return stream;
}

PersonSpec operator+(const PersonSpec& p, int n){
    int a = p.getAge() + n;
    cout<<p.getName()<<", "<<a<<endl;
}


PersonSpec operator+(int n, const PersonSpec& p){
    int a = p.getAge() + 2*n;
    cout<<p.getName()<<", "<<a<<endl;
}

int main(){

    cout << "Operator Overloading" << endl;
    PersonSpec ps("Stefan", 20);
    cout<<ps<<endl;  //Stefan, 20
    cout<<ps+5<<endl; //Stefan, 25
    cout<<5+ps<<endl; //Stefan, 30
}
```

### B3

a)

```bash
8
```

b)

```bash
8
```

### C3

```bash
1
0
0
0
1
2
1
1
```

### D3

```bash
B()
D()
D::m()
B::s()
~D()
~B()
```

### E3

```bash
0
1
2
3
0
1
2
3
0
1
2
3
0
1
2
```

### F3

a)

```bash
B.m()
B.m()
```

b)

```bash
B.m()
B.set(): SETARE FOARTE IMPORTANTA 
Trebuie facuta la orice apel al metodei m()
B.m()
D.set()
```

### G3

```c++
class View2 : public AbstractView
{
public:
    View2()
    {
        out.open("output.txt", ios::out);
    }
    string get_command()
    {
        string rez;
        getline(std::cin, rez);
        return rez;
    }
    void write_result(int i)
    {
        out << i << endl;
    }

private:
    ifstream inp;
    ofstream out;
};
```

### H3

```bash
100
200
```

Clasa C conţine un constructor public ce primeşte ca paramentru unic un întreg pe care îl salvează în variabila privată, priprie instanţei `x`. În clasă sunt prezente 2 funcţii de afişare, `display`, ce primeşte ca parametru un întreg, denumit `x`, şi-l afişează, şi `display_x` care afişează variabila instanţei, `x`. 

La executarea funcţiei `main`, se creează o instanţă a clasei C, cu valoarea `x` de 200. La apelarea funcţiei `m`, specifică clasei C, se creează o noua variabilă locală, denumită tot x şi apoi sunt apelate cele 2 funcţii de afişare, `display(x)` şi `display_x`. Deoarece variabilele au denumiri care se intercalează, in blocul alocat funcţiei `m`, se ia în considerare variabila locală `x` cu valoarea 100, şi nu cea globală instanţei, cu valoarea de 200. astfel pentru primul apel, cel al funcţiei `display` cu paramentrul `x`, se va afişa valoarea 100 (specifică variabilei locale), iar în cazul funcţiei `display_x` se va afişa valoarea 200, specifică variabilei globale (întrucât variabila locală declarată în `m` nu are vizibilitate la nivelul funcţiei, ci doar în blocul de instrucţiuni în care a fost definită, şi ea nu interferează cu funcţia data).

### I3

```java
class NumePrenume implements Display{
    public void display(Person p){
        System.out.println(p.get_nume() + " " + p.get_prenume());
    }
}

class PrenumeNume implements Display{
    public void display(Person p){
        System.out.println(p.get_prenume() + " " + p.get_nume());
    }
}
```


### J3

```c++
//TREBUIE EXPLICAT LA a)
//b)
#include <iostream>
#include <string.h>
using namespace std;
class Person
{
public:
    Person(int a = 0)
    {
        agep = new int;
        *agep = a;
    }
    void change_age(int a) { *agep = a; }
    void print_age() { cout << *agep << endl; }

    int getAge() const{ return *agep; }
    Person& operator=(const Person& p){
        *agep = p.getAge();
        return *this;
    }


private:
    int *agep;
};

int main()
{
    cout << "Assignment overloading" << endl;
    Person p, q;
    p.change_age(20); // schimba varsta lui p,
    p.print_age();
    q.print_age();
    
    p = q;
    q.change_age(30);
    // s-a schimbat varsta lui q, dar si a lui p! DE CE?
    p.print_age();
    q.print_age();
    return 0;
}
```