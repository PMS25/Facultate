# Curs06

[TOC] 

## Tipul delegate

Tipul `delegate` permite încapsularea metodelor (ca referinţă) în obiecte.

Este similar pointerilor la funcţii din C++, dar de data aceasta varianta `object oriented`, prin intermediul unei referinţe. Dacă scriem o aplicatie în care se doreşte executarea unor anumite acţiuni, pentru care cunoaştem `semnătura` acestora (tip returnat, listă parametrii), dar nu ne interesează neapărat de implementarea lor (aceasta va putea fi stabilită ulterior), putem utiliza tipul `delegate`.

În acest fel aplicaţia capătă un caracter general, în sensul că acţiunea poate fi oricând modificată|optimizată|schimbată.

**Sintaxă**

```c#
public delegate tip_returnat nume_delegate([lista_param]);
```

**Exemplu**

```c#
public delegate int Operation(int a, int b);
```

Acest `delegate` poate încapsula orice funcţie (metodă) care returnează `double` şi are doi parametrii de tip `int`.

Cum se ataşează o metodă la un `delegat` (instanţierea delegatului)

```c#
namespace DelegateApp {
  class Methods {
    public static int Add(int a, int b) {
      return a + b;
    }
    public static int Mult(int a, int b) {
      return a * b;
    }
  }

  public delegate int Operation(int a, int b);
  public delegate int Operation1();

  class InstanceMethods {
    public int A { get; set; }
    public int B { get; set; }

    public int Add() {
      return A + B;
    }
    public int Mult() {
      return A * B;
    }
  }

  class Program {
    static void Main(string[] args) {
      // op este un obiect de tip delegat
      Operation op;
      op = new Operation(Methods.Mult);

      // Apelarea delegatului se face ca si cum am apela metoda incapsulata
      Console.WriteLine(op(3, 4));
      InstanceMethods obj = new InstanceMethods() { A = 10, B = 20 };
      Operation1 op1 = new Operation1(obj.Add);
      Console.WriteLine(op1());

      Console.ReadKey();
    }
  }
}
```

**Observaţie**: Un `delegate` poate încapsula de fapt mai multe metode (`multicast` cu `+` sau `+=`)

```c#
static void Main(string[] args) {
  // op este un obiect de tip delegat
  Operation op;
  op = new Operation(Methods.Mult);
  op += Methods.Add;

  // Apelarea delegatului se face ca si cum am apela metoda incapsulata
  Console.WriteLine(op(3, 4));

  //InstanceMethods obj = new InstanceMethods() { A = 10, B = 20 };
  //Operation1 op1 = new Operation1(obj.Add);
  //Console.WriteLine(op1());

  Console.ReadKey();
}
```