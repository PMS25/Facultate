// Se da n numar natural cu cel mult 5 cifre. Afisati numerele prime din intervalul [n,2n].

import java.util.Scanner;

public class P01 {

    static boolean Prim(int n) {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        for (int i = 3; i < n; i += 2)
            if (n % i == 0)
                return false;
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("n = ");
        int n = in.nextInt();
        in.close();

        System.out.print("Numere prime: ");
        for (int i = n; i <= 2 * n; i++)
            if (Prim(i))
                System.out.print(i + ", ");
        System.out.println("\b\b ");
    }
}