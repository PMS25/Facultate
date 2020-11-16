# Temă - Laborator02

## Petculescu Mihai-Silviu

[TOC]

Să se extindă aplicația de la primul proiect cu următoarele noi funcționalități:

- Într-un nou proiect de tip `library .NET framework` se vor crea clasele `StudentModel`, `CourseModel` și `StudentList` (o colecție de studenți)

### StudentModel

```cs
class StudentModel {
  public string Name { get; set; }
  public string Email { get; set; }
  public int Id { get; set; }
  public string Faculty { get; set; }
  public List < CourseModel > Courses { get; set; }

  public StudentModel() {
    Courses = new List < CourseModel > ();
  }
}
```

### CourseModel

```c#
class CourseModel {
  public int Id { get; set; }
  public string Name { get; set; }
  public DateTime StartDate { get; set; }
  public DateTime EndDate { get; set; }
}
```

### StudentList

```c#
class StudentList {
  public List < StudentModel > Students { get; set; }
  public StudentList() {
    Students = new List < StudentModel > ();
  }

  // Metode 
  public void Add(StudentModel stud) {
    Students.Add(stud);
  }

  public void ReadStudentFromConsole() {
    // Se citesc toate datele despre un student (inclusiv cursurile)
    // Se creaza un obiect de tip StudentModel ca va fi
    // adaugat in lista cu metoda Add
  }

  public void DisplayInfoToConsole() {
    // Afiseaza informatiile despre studenti la consola
  }

  public void SaveOnDisk() {
    // Se salveaza lista de studenti in fisiere pe disk
    // cate un fisier pentru fiecare student 
    // cate un fisier cu pentru fiecare curs
    // pentru studenti se va crea un folder "Students"
    // pentru cursuri se va crea un folder "Courses"
    // studentii se vor salva in Students, in fisiere cu numele
    // "{id_sudent}.txt
    // analog pentru cursuri: "{id_course}.txt"
  }

  public void LoadDataFromDisk() {
    // Citindu-se continutul celor doua foldere 
    // se va genera lista de studenti corespunzatoare
  }
}
```

## Exemplu salvare pe disk:

```c#
StudentModel s = new StudentModel() {
  Id = 1,
  Name = "Ionescu",
  Faculty = "info",
  Email = "ion@upit.ro",
  Courses = new List < CourseModel > () {
    new CourseModel() { Id = 1, Name = "Medii si instrumente" },
    new CourseModel() { Id = 2, Name = "Metode de programare" }
  }
}
```

### Fișiere pe disk

```bash
# Students/1.txt
1,"Ionescu","info","ion@.upit.ro",1,2
# Courses/1.txt
"1","Medii si instrumente"
# Courses/2.txt
"2", "Metode de programare"
```

**Observație**: datele calendaristice pot fi citite ca string de la consolă și convertite cu metoda `DateTime.Parse`