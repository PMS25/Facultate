```java
public class Student {
  private String nume;
  private String prenume;
  public Student(String nume, String prenume) {
    this.nume = nume;
    this.prenume = prenume;
  }
  public void setNume(String nume) {
    this.nume = nume;
  }
  public String getNume() {
    return this.nume;
  }
  public void setPrenume(String prenume) {
    this.prenume = prenume;
  }
  public String getPrenume() {
    return this.prenume;
  }
}
```

```java
import java.util.ArrayList;
import java.util.List;

public class Grupa {
  private List<Student> studenti;
  Grupa() {
    studenti = new ArrayList<>();
  }
  public void adaugaStudent(Student s) {
    studenti.add(s);
  }
  //de adaugat metoda de stergere student din lista
  
  public void setStudenti(List<Student> lista){
      this.studenti = lista;
  }
  
  public List<Student> getStudenti(){
      return studenti;
  }
  
  //cauta student dupa nume
  public Student cautaStudent(String nume){
      // pentru fiecare student din lista de studenti
      for(Student st : studenti)
  		if(st.getNume()!= null && st.getNume().equals(nume))
            return st;
      return null;
  } 
   public boolean areStudenti(){
       return !studenti.isEmpty();
   } //...... 
  } 
```



Original

```java
public class Student { private String nume; private String prenume; public Student(String nume, String prenume){ this.nume = nume; this.prenume = prenume; } public void setNume(String nume){ this.nume = nume; } public String getNume(){ return this.nume; } public void setPrenume(String prenume){ this.prenume = prenume; } public String getPrenume(){ return this.prenume; } } 

import java.util.ArrayList; import java.util.List; public class Grupa { private List<Student> studenti; Grupa(){ studenti = new ArrayList<>(); } public void adaugaStudent(Student s){ studenti.add(s); } //de adaugat metoda de stergere student din lista public void setStudenti(List<Student> lista){ this.studenti = lista; } public List<Student> getStudenti(){ return studenti; } //cauta student dupa nume public Student cautaStudent(String nume){ for(Student st : studenti) // pentru fiecare student din lista de studenti if(st.getNume()!= null && st.getNume().equals(nume)) return st; return null; } public boolean areStudenti(){ return !studenti.isEmpty(); } //...... } 
```

