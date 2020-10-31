# Curs01

- [Curs01](#curs01)
  - [Examen](#examen)
  - [Introducere în aplicaţii de tip consolă în Visual Studio](#introducere-în-aplicaţii-de-tip-consolă-în-visual-studio)
    - [Elemente de C# - Structura / Componente](#elemente-de-c---structura--componente)

## Examen

- 50% proiecte de laborator; 50 examen scris (online)

## Introducere în aplicaţii de tip consolă în Visual Studio

### Elemente de C# - Structura / Componente

Aplicatii de tip consola in VS au care rezultat un "executabil" (fisier cu extensia .exe) care poate fi executat in linie de comanda (cmd sau consola).

**Studiu de caz**:

Să se realizeze o aplicaţie de tip consolă care permite citirea de la consolă a informaţiilor despre un student şi salvarea acestora într-un fişier, pe disk. Ulterior, se oferă posibilitatea afişării la consolă parcurgând fişierul de pe disk.

**Structura aplicatii consola - (StudentApplication)**:

1. Solution (soluţie) un fisier cu extensia `.sln`
2. Unul sau mai multe proiecte in cadrul solutiei `.vsproj`

**Structura unui proiect**:

1. **Properties**: proprietăţii generale ale fișierului executabil rezultat (versiune, autor, descrieri, companie)

```assembly
# în fişierul AssemblyInfo
[assembly: AssemblyVersion("1.0.1.1")]
[assembly: AssemblyFileVersion("1.0.1.1")]	
```

2. **References**

Referinţe către alte librării `.dll` / proiecte din cadrul soluţiei. Vor putea fi ulterior utilizate cu `using` în fişierele ce conţin cod sursă c#

De exemplu, dacă dorim să construim clasa student în alt proiect decât cel curent, că să o putem utiliza în proiectul nostru, trebuie să adăugăm o referință către acesta.

1. referinţă către un proiect din cadrul soluţiei:

>  Vom crea al doilea proiect `StudentModel` (clasa `Student`) de tip `class library`:
> `References => Add reference => Projects => StudentModel`

2. referinţă către o librărie .NET existentă:

> `References => Add => Assemblies => System.Configuration`
>  Această librarie este utilă pentru administrarea fişierului de configurare `App.config`.

3. **`App.config`**

Este util pentru utilizarea diverselor chei de configurare care pot fi modificate şi accesate dinamic fără să fie necesară recompilarea fişierului executabil!

Exemplu: căi pe disk la foldere; adrese de servere, adrese de bază de date...

4. **`Program.cs`**

Conţine funcţia principală `Main` în cadrul unei clase C# implicite, cu numele`Program`:

`StudentApplication`:

```c#
using StudentModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using StudentModel;
//using pentru namespace-ul care contine clasa Student
//altfel, fara using, trebuie sa scriem numele full al clasei!!

namespace StudentApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            Student stud = new Student("2A", "Info", "Coco@upit.ro", "Cocolino", 45);
            Console.WriteLine(stud.ToString());
    
            stud.ReadInfo();
            stud.WriteToFile();
            stud.DisplayInfo();
            Console.ReadKey();
        }
    }
}
```

`StudentModel.cs`:

```c#
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentModel
{
    //o clasa C# care modeleaza notiunea de Student din lumea reala
    public class Student
    {
        //adaugam proprietatile unui student
        public string Id { get; set; }
        public string Faculty { get; set; }
        public string Email { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }

        public Student(string id, string faculty, string email, string name, int age)
        {
            Id = id;
            Faculty = faculty;
            Email = email;
            Name = name;
            Age = age;
        }
    
        public void ReadInfo()
        {
            Console.WriteLine("Id:");
            Id = Console.ReadLine();
    
            Console.WriteLine("Faculty:");
            Faculty = Console.ReadLine();
    
            Console.WriteLine("Name:");
            Name = Console.ReadLine();
    
            Console.WriteLine("Email:");
            Email = Console.ReadLine();
    
            Console.WriteLine("Age:");
            Age = int.Parse(Console.ReadLine());
        }
    
        public void DisplayInfo()
        {
            Console.WriteLine(ToString());
        }
    
        public void WriteToFile()
        {
            File.AppendAllText("Students.txt", ToString() + "\n");
        }
    
        //reprezentare ca string (sir de caractere) a obiectului curent
        public override string ToString()
        {
            return $"{Id},{Faculty},{Email},{Name},{Age}";
        }
    }
}
```





