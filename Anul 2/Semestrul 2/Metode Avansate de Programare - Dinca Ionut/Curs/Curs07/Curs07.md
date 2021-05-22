# Curs 07

[TOC]

## Aplicații de tip Undo/Redo (multi-level) (Șablonul Command)

Pentru o aplicație cu interfață grafică (Agenda de Contacte), să se implementeze
mecanismul **undo/redo de nivel n**. Aplicația trece printr-o **suită de stări** provocată de o **suită de comenzi** efectuate!
$$
S_0 \Rightarrow S_1 \Rightarrow S_2\ ...\ S_n \Rightarrow S_{n+1}\\
C_0 \Rightarrow C_1 \Rightarrow C_2\ ...\ C_n \Rightarrow C_{n+1}
$$
**Executare `Undo`**: să anulez efectul comenzii $C_{n+1}$; aplicația va trece în starea $S_{n}$.

**Soluția**: pentru anularea unei comenzi se va memora cea mai mica informație posibilă: **diferența dintre starea curentă și cea anterioară**.

**Exemplu**: pentru $C_{n+1}$ memorez diferența dintre $S_{n+1}$ și $S_{n}$.

**Exemplu concret**: Dacă $C_{n+1}$ este: **adăugarea unui nou contact în agendă**!
adică voi memora noul contact adăugat și poziția pe care a fost adăugat!
$$
S_0 \Rightarrow S_1 \Rightarrow S_2\ ...\ S_i \Rightarrow S_{i+1}\ ...\ S_{n} \Rightarrow S_{n+1}\\
C_0 \Rightarrow C_1 \Rightarrow C_2\ ...\ C_{i}\ ...\ C_n \Rightarrow C_{n+1}
$$
Dacă avem $n$ comenzi executate la un moment dat, putem efectua `Undo` / `Redo`.

$$
C_{0} \Rightarrow C_{1} \Rightarrow C_{2}\ ...\ C_{i} \Rightarrow\ ...\ C_{n} \Rightarrow C_{n+1}\ -\ \mathrm{suita\ de\ comenzi\ efectuate}\\
\Leftarrow \mathrm{Undo}\ ...\Leftarrow \mathrm{Undo}\\
\mathrm{Redo} \Rightarrow
$$
Avem nevoie de o listă a ultimelor $n$ comenzi executate (`HistoryList`) - istoric al comenzilor. Cu ajutorul unui cursor, ne poziționăm pe comanda care urmează să fie anulată / refăcută!

1. **HistoryList**: istoric al comenzilor (listă cu cursor)
2. **Abstractizăm noțiunea de comandă** (de executat, de anulat, de refăcut)
3. **HistoryList** va conține comenzi abstracte

```c#
abstract class Command {
  public Receiver { get; } 
  // Obiectul asupra caruia se executa comanda (cel care trece prin stari succesive)
  // in cazul nostru, va fi AgendaGUI (interfata grafica pentru agenda de contacte)
  public string Name { get; }
  // Nume unic al comenzii
  public abstract void Execute();
  public abstract void Undo();
  // Metoda template
  public virtual void Redo() { Execute(); }
}

// Exemplu de comanda particulara:

class AddContact: Command {
  public ContactModel Contact { get; private set; }
  public int Position { get; private set; }
  public AddContact(int position, ContactModel contact, Receiver receiver) {
    Position = position;
    Contact = contact;
    Receiver = receiver;
  }
  public void Execute() {
    // Se adauga noul contact in baza de date se afiseaza
    // noua lista de contacte pe interfata (obiectul Receiver isi actualizeaza starea) - adaugare contact pe pozitia "Position"
  }
  public void Undo() {
    // Eliminare contact din baza de date
    // afisare noua lista de contacte (fara contactul eliminat)
  }
}
class RemoveContact: Commmand { }
class EditContact: Command { }
```

**Observaţie**: Dacă s-a executat cel puțin un `Undo` (cursorul nu mai este poziționat pe ultima comandă din listă) și se execută o nouă comandă (alta decât `undo` sau `redo`, care trebuie să ajungă în `HistoryList` pe ultima poziție, atunci toate comenzile din dreapta cursorului vor fi eliminate din lista - nu mai are sens să vorbim despre `Redo` pentru acestea.

```c#
public class HistoryList {
  static readonly int MAX_SIZE = 50; // Maxim al comenzilor
  List<Command> _commands;
  int _cursor;
  public HistoryList() {
    _commands = new List<Command>();
    _cursor = -1;
  }
  public void Add(Command newCommand) {
    // O noua comanda de executat se adauga in lista
    if (_commands.Count == MAX_SIZE) {
      // Efectuati deplasare la stanga a tuturor comenzilor cu o pozitie, astfel "cea mai veche comanda" se va pierde
    }
    if (_cursor < _commands.Count - 1) {
      // Avem cel putin un "Undo" elimin toate comenzile din dreapta cursorului!
      RemoveAllFromRight();
    }
    // Inserarea a noi comenzi pe ultima pozitie (alta varianta: lista circulara!!)                            
    _commands.Add(newCommand);
    _cursor = _commands.Count - 1; // Pozitionarea cursorului pe aceasta comanda
  }
  public void Remove(Command c) {
    // A se implementa o metoda Equals pentru obiectele comand dupa un camp cu o valoare unica (de exemplu numele comenzii) - unic sau un cod unic al comenzii (Guid)
  }
  public void RemoveAllFromRight() {
    // Eliminare comenzi din dreapta cursorului
  }
  public void Undo() {
    Item.Undo(); // Comanda de la pozitia cursorului este anulata!
    _cursor--; // Mutam cursorul la stanga
  }
  public Command Item {
    // Comanda de la pozitia cursorului
    get {
      return _commands[_cursor]; // Test _cursor!!
    }
  }
  public void Redo() {
    Item.Redo(); // Re-execut comanda de la pozitia cursorului
    _cursor++; // Mutam cursorul la dreapta
  }
  public bool BeforeFirst {
    // Not Undo (dezactivati posibilitatea de Undo pe interfata)
    get {
      return _cursor == -1;
    }
  }
  public bool OnLast { 
    // Not Redo (dezactivati posibilitaeta de Redo pe interfata)
    get {
      return _cursor == _commands.Count - 1;
    }
  }
}

// Clasa asupra carei sunt executate comenzile
public class Receiver {
  HistoryList History { get; set; }
  public Receiver() {
    History = new HistoryList();
  }
  //presupunem ca se executa la actionarea comenzii "Add" - adaugare Contact nou

  private void Add_Click(object sender, EventArgs e) {
    //vom crea obiectul Contact cu datele preluate de pe interfata
    var c = new Contact();
    var command = new AddContact(position, c, this);
    History.Add(command); //se va adauga pe ultima pozitie (cursor corect pozitionat)
    command.Execute(); //execut comanda
  }

  //la actionarea comenzii "Undo" - anulare ultima comanda
  private void Undo_Click(object sender, EventArgs e) {
    if (!History.BeforeFirst) //se recomanda sa dezactivati butonul Undo pe interfata
    {
      History.Undo(); //anuleaza comanda de la pozitia cursorului
    }
  }

  //la actionarea comenzii "Redo" - anulare ultima comanda
  private void Redo_Click(object sender, EventArgs e) {
    if (!History.OnLast) //se recomanda sa dezactivati butonul Undo pe interfata
    {
      History.Redo(); //anuleaza comanda de la pozitia cursorului
    }
  }
}
```





