# Curs02

Utilizarea fisierului de configurare "App.config" in cadrul aplicatiilor
de tip consola

App.config contine elemente de configurare (cheie-valoare) 
pentru valori care pot modificate dinamic, in timpul executiei programului

```
<appSettings>
		<add key="Key0" value="0" />
		<add key="Key1" value="1" />
		<add key="Key2" value="2" />
</appSettings>
```

In sectiunea "appSettings" vom adauga cheile de configurare.
O cheie are un nume ("key") si o valoare ("value")

Obs: structura este de tip XML. (EXtensible Markup Language)

```c#
       public void WriteToFile()
        {
            //vom utiliza cheia "PathToFile" din app.config
            //pentru a salva fisierul in diverse locatii
    
            //Cum accesam valoare unei chei?
            //(1) Se adauga referinta la "System.Configuration"
            //ConfigurationManager.AppSettings["PathToFile"] => valoare cheii "PathToFile"
    
            var pathToFile = ConfigurationManager.AppSettings["PathToFile"];
            var fileName = ConfigurationManager.AppSettings["FileName"];
            
            if (!Directory.Exists(pathToFile))
            {
                Directory.CreateDirectory(pathToFile);
            }
    
            File.AppendAllText(Path.Combine(pathToFile, fileName), ToString() + "\n");
        }
```

Pentru modificarea dinamica a cheilor, se va edita fisierul cu extensia
".config" si numele indentic cu cel al fisierului executabil!!

Introducere in aplicatiile de tip "Windows Forms"

Tip de proiect care permite creare de aplicatii cu interfata grafica 
(ferestre Windows, butoane, case de text, liste, etc)

Add new project => Window Forms Application (.NET)

Se adauga referinta la proiectul "StudentModel"

Se completeaza App.config cu cele doua chei.

Scheletul de cod C# pentru componentele vizuale este generat automat.

In continuare, putem adauga cod C# specific (vezi codul C# pentru cele doua
butoane "Save" si "LoadFromFile")

```c#
        private void button1_Click(object sender, EventArgs e)
        {
            //cod executat la click mouse pe "Save"
    
            //preiau informatiile din casete de text
            if(string.IsNullOrEmpty(tb_Id.Text)) //verificam daca e goala
            {
                MessageBox.Show("campul Id este gol!");
                return;
            }


​          

            if (string.IsNullOrEmpty(tb_Name.Text)) //verificam daca e goala
            {
                MessageBox.Show("campul Name este gol!");
                return;
            }
    
            if (string.IsNullOrEmpty(tb_Faculty.Text)) //verificam daca e goala
            {
                MessageBox.Show("campul Faculty este gol!");
                return;
            }
    
            if (string.IsNullOrEmpty(tb_Email.Text)) //verificam daca e goala
            {
                MessageBox.Show("campul Email este gol!");
                return;
            }


            if (string.IsNullOrEmpty(tb_Age.Text)) //verificam daca e goala
            {
                MessageBox.Show("campul Age este gol!");
                return;
            }
    
            //asiguram faptul ca Age este numar!
            int age = 0;
            if(!int.TryParse(tb_Age.Text, out age))
            {
                MessageBox.Show($"Valoarea {tb_Age.Text} nu este un numar intreg!");
                return;
            }
    
            Student s = new Student(tb_Id.Text, tb_Faculty.Text, tb_Email.Text, tb_Name.Text, age);
            s.WriteToFile();
    
            var pathToFile = ConfigurationManager.AppSettings["PathToFile"];
            var fileName = ConfigurationManager.AppSettings["FileName"];
    
            MessageBox.Show($"Studentul [{s}] a fost salvat in fisierul [{Path.Combine(pathToFile, fileName)}]");
    
            richTextBox1.Clear(); //curatam caseta!
            richTextBox1.Text = File.ReadAllText(Path.Combine(pathToFile, fileName));
        }
```

```c#
      private void button2_Click(object sender, EventArgs e)
        {
            var pathToFile = ConfigurationManager.AppSettings["PathToFile"];
            var fileName = ConfigurationManager.AppSettings["FileName"];
    
            richTextBox1.Clear(); //curatam caseta!
            richTextBox1.Text = File.ReadAllText(Path.Combine(pathToFile, fileName));
        }
```