# Curs05

[TOC] 

## Implementarea interfeţelor în C#

- Ce este o interfaţa C#?

Este un tip care conţine un set de declarări de metode (implicit publice), fără implementare. O interfaţă evidenţiază metodele comune mai multor clase (publice) care ar trebui să fie utilizate de clasele client. Spunem o clasă aderă la o interfaţă dacă o implementează (implementează toate metodele acesteia).

```c#
public interface IMyMethods {
  void MyMethod(); // Metoda fara implementare - nu se specifica public
}

class MyConcreteMethods: IMyMethods {
  // Aici, obligatoriu, clasa trebuie sa implementeze toate metodele interfetei
  public void MyMethod() {
    //...
  }
}
```

- Care este marele avantaj al utilizării interfeţelor?

Putem scrie aplicaţii cu un caracter general, uşor de extins! De ce? Să presupunem că o clasă are nevoie să utilizeze metode ale clasei `MyConcreteMethods` (a caror implementare s-ar putea modifica în viitor, dar semnătura metodelor se păstrează).

```c#
class Client {
  MyConcreteMethods Methods { get; set; }
  public void Task() {
    Methods.MyMethod();
  }
}
```

Codul de mai sus spunem că depinde de clasa concretă `MyConcreteMethods`, prin urmare, dacă dorim să modificăm
codul metodei `MyMethod`, trebuie să recompilăm intreaga clasa.

Modul corect de a declara proprietatea (referinţa) `Methods` este prin intermediul interfeţei `IMyMethods`, deoarece aceasta va putea fi substituită ulterior cu orice clasă care o implementează.

```c#
class Client {
  IMyMethods Methods { get; set; }
  public Client(IMyMethods methods) {
    Methods = methods;
  }
  public void Task() {
    Methods.MyMethod();
  }
}
Client c = new Client(new MyConcreteMethods());
c.Task();
```

Clasa `Client` fiind absolut independentă de clasele concrete care implementează interfaţa, spunem că este extensibilă
din punct de vedere al metodei `MyMethod` utilizată în metoda `Task`. Deoarece putem oricând implementa o versiune diferită într-o clasă (noua) care implementeaza interfata!! (Fara sa fie necesar sa modificam codul clasei!!!)