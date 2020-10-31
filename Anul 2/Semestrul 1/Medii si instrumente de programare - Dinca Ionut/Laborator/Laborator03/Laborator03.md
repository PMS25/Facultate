# Laborator03

Sa se realizeze o aplicatie pentru administrare de contacte, cu posibilitate de - adaugare, stergere, modificare, cautare contact.

Un contact are urmatoarea structura:

```c#
class ContactModel
{
	public int Id {get;set;}
	public string Name {get;set;}
	public string Email {get;set;}
	public string Phone {get;set;}
	public string Address {get;set;}
	public string Country {get;set;}

	public override bool Equals(object obj)
	{
		if(obj == null)
		{
			return false;
		}
	
		if(!(obj is ContactModel))
		{
			return false;
		}
	
		ContactModel c = obj as ContactModel;
	
		return Id == c.Id && Name == c.Name && Email == c.Email && Phone == c.Phone;
	}
}
```

Se vor realiza 2 proiecte:

"Contact.Models" de tip library (.dll)
"Contact.UI" de tip "Windows forms"

In "Contact.Models" se vor implementa 2 clase: ContactModel si ContactList

```c#
public class ContactList
{
	public List<ContactModel> Contacts {get;set;}

	public ContactList()
	{
		Contacts = new List<ContactModel>();
	}


	public void Add(ContactModel contact)
	{
		Contacts.Add(contact);
	}
	
	public void Remove(ContactModel contact)
	{
		Contacts.Remove(contact);
	}
	
	public bool SearchByName(string name)
	{
		foreach(var contact in Contacts)
		{
			if(contact.Name == name)
			{
				return true;
			}			
	
		}
	
		return false;		
	}
	
	public bool SearchByEmail(string email)
	{
		
	}
	
	public void SaveOnDisk()
	{
		//salvati toate contactele intr-un fisier pe disk!
	}
	
	public void LoadFromDisk()
	{
		//colectia "Contacts" va fi incarcata cu contactele salvate pe disk
		//prin metoda anterioara
	}
}
```

In al doilea proiect va fi partea de interfata.

- o fereastra care permite adaugare/modificare/stergere/cautare(email sau nume) de
contacte si vizualizarea unei liste de contacte (un obiect de tip ContactList). 