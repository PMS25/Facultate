// Se da n numar natural cu cel mult 3 cifre. Afisati patratul si cubul lui n.

import java.util.Scanner;

public class Exemplu01 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        System.out.print("n = "); int n = cin.nextInt();
        cin.close();
        System.out.println("Patratul lui " + n + " este: " + n * n);
        System.out.println("Cubul lui " + n + " este: " + n * n * n);
    }
}
