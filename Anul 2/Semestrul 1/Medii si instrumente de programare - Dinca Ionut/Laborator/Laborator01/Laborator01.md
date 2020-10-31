# Laborator01 - Medii şi instrumente de programare

- [Laborator01 - Medii şi instrumente de programare](#laborator01---medii-şi-instrumente-de-programare)
  - [Introducere in Visual Studio](#introducere-in-visual-studio)
  - [Tema de Laborator01](#tema-de-laborator01)

## Introducere in Visual Studio

**Download**: https://visualstudio.microsoft.com/vs/

Create new project => Console app .net framework
Aplicaţiile .net din Visual Studio sunt organizate în "solutions": `Laborator1_IntroCSharp.sln`
O soluţie conţine unul sau mai multe proiecte: `Laborator1_IntroCSharp.prj`

```c#
namespace Laborator1_IntroCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int an = 1;
            int grupa = 2;
            Console.WriteLine("Hello, informatica anul {0}, grupa {1}", an, grupa);
            Console.ReadKey();
        }
    }
}
```

- `namespace Laborator1_IntroCSharp` - numele proiectului stabileşte namespace-ul!
- `class Program` (de obicei, numele fişierului, prin convenţie, coincide cu numele clasei)
- funcţia principală `Main`: `static void Main(string[] args){}`
- în C# orice funcţie/metodă există într-o clasă
- `string[] args` - lista de argumente (parametrii) care reprezintă eventualele valori încărcate din linia de comanda.

## Tema de Laborator01

Într-un proiect Visual Studio de tip consolă, realizaţi o aplicaţie care permite calculul mediilor unui student şi salvarea notelor şi mediei într-un fisier.
- Notele sunt transmise ca parametrii în linie de comanda (vezi `string[] args` din funcţia main). 
- Numele studentului va fi citit de la tastatura.

```c#
static void Main(string[] args)
{
	//int an = 1;
    //int grupa = 2;
	//Console.WriteLine("Hello, informatica anul {0}, grupa {1}", an, grupa);

    //int p = 1;
    //foreach(var s in args)
	//{
    //    Console.WriteLine("Parametrul {0} este {1}", p++, s);
    //}

    // cum citim date de la conosola?
    Console.WriteLine("Introduceti numele studentului");
    string studentName = Console.ReadLine();
    
	// cum se scrie intr-un fisier?
    File.AppendAllText("Students.txt", studentName + "\n");

    // cum se converteste un string la int (număr)?
    string strValue = "275";
    int value = int.Parse(strValue);

	Console.ReadKey();
} 
        
```