# Temă - Laborator01
## Petculescu Mihai-Silviu

[TOC]

Într-un proiect Visual Studio (.Net Framework) de tip consolă, realizați o aplicație care permite calculul mediilor unui student și salvarea notelor și mediei într-un fișier.

Notele sunt transmise ca parametrii în linie de comandă. Numele studentului va fi citit de la tastatură.

### Help Menu

```bash
C:\...\bin\Debug>StudentCli.exe -h #[--help]
Usage: [-t] [-o] [input data]

Parameters:

-t : Type of Average. Options:
 | mean (Default) - Sum of values of a data set divided by number of values
 | median - Middle value separating the greater and lesser halves of a data set.
 | mode - most frequent value in a data set.

-o : Output Path
 | (Default) - Current Directory ; FileName: output.txt

Press Any Key to Continue.
```

### Program

```c#
namespace StudentCli {
  class Program {
    static bool help = false;
    static string type = "mean";
    static string name;
    static string path = AppDomain.CurrentDomain.BaseDirectory + @"\output.txt";
    static List < double > list = new List < double > ();
    static double result;

    static double Mean() {
      double r = 0;
      foreach(int i in list)
      r += i;
      return Math.Round(r / list.Count, 2);
    }

    static double Median() {
      list.Sort();
      int m = list.Count / 2;
      if (list.Count % 2 == 0) return Math.Round((list[m - 1] + list[m]) / 2.0, 2);
      return Math.Round(list[m], 2);
    }

    static double Mode() {
      double r = list.GroupBy(i =>i).OrderByDescending(grp =>grp.Count()).Select(grp =>grp.Key).First();
      return Math.Round(r, 2);
    }

    static void HelpMenu() {
      Console.WriteLine("Usage: [-t] [-o] [input data]\n");
      Console.WriteLine("Parameters:\n");
      Console.WriteLine("-t : Type of Average. Options: ");
      Console.WriteLine(" | mean (Default) - Sum of values of a data set divided by number of values");
      Console.WriteLine(" | median - Middle value separating the greater and lesser halves of a data set.");
      Console.WriteLine(" | mode - most frequent value in a data set.\n");
      Console.WriteLine("-o : Output Path");
      Console.WriteLine(" | (Default) - Current Directory ; FileName: output.txt\n");
      Console.WriteLine("Press Any Key to Continue.");
    }

    static void ParseMenu(string[] args) {
      if (args.Length == 0 || args[0] == "--help" || args[0] == "-h") {
        help = true;
        HelpMenu();
      }
      else for (int i = 0; i < args.Length; i++) {
        if (args[i] == "-t" && (args[i + 1] == "mean" || args[i + 1] == "median" || args[i + 1] == "mode")) type = args[++i];
        else if (args[i] == "-o") path = args[++i];
        else if (int.TryParse(args[i], out int n)) list.Add(int.Parse(args[i]));
      }
    }

    static void Run() {
      if (type == "mean") result = Mean();
      else if (type == "median") result = Median();
      else if (type == "mode") result = Mode();
    }

    static void Save() {
      try {
        File.WriteAllText(path, $ "Student: {name}\n");
        File.AppendAllText(path, $ "Note: {String.Join(", ",list)}\n");
        File.AppendAllText(path, $ "Medie de tip {type}: {result}");
        Console.WriteLine("The result was saved successfully");
      }
      catch(Exception e) {
        Console.WriteLine($ "Error: {e.Message}");
      }
    }

    static void Main(string[] args) {
      ParseMenu(args);
      if (help == false) {
        if (list.Count == 0) return;
        Console.Write("Dati numele studentului: ");
        name = Console.ReadLine();
        Run();
        Save();
      }

      Console.ReadKey();
    }
  }
}
```

### Execuție

```bash
# Input
C:\...\Debug>StudentCli.exe -t mean -o file.txt 4 5 5 6 7 8
Dati numele studentului: Andrei
The result was saved successfully
# file.txt
Student: Andrei
Note: 4,5,5,6,7,8
## Mean
Medie de tip mean: 5,83
## Median
Medie de tip median: 5,5
## Mode
Medie de tip mode: 5
```


