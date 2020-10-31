import java.util.Scanner;

// Se citeste de la tastatura o valoare naturala x (x>10).
// Daca cifra unitatilor este egala cu cifra zecilor se vor afisa primele doua numere naturale mai mari decat valoarea x.
// In caz contrar se va afisa cifra maxima dintre cifra zecilor si a unitatilor.
// Ex: Pentru x=3455 => 3456 3457
//     Pentru x=3485 => 8

public class Problema03 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        System.out.print("n = ");
        int n = cin.nextInt();
        if(n%10 == (n/10)%10)
            System.out.println((n+1) + " " + (n+2));
        else
            System.out.println((n/10)%10);
        cin.close();
    }
}
