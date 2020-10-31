// Se da un vector cu n componente numere naturale.
// Cate componente termeni din sirul lui Fibonacci (1, 1, 2, 3, 5, 8, 13, ...) sunt in vector?

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class P03 {

    public static ArrayList<Integer> Fibonacci(int maxim) {
        ArrayList<Integer> fib = new ArrayList<>();
        int a = 0, b = 1, c;
        fib.add(a);
        do {
            c = a + b;
            fib.add(b);
            a = b;
            b = c;
        } while (c <= maxim);
        return fib;
    }

    public static void main(String[] args) {
        ArrayList<Integer> array = new ArrayList<>();
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n: ");
        int n = in.nextInt();

        System.out.print("Dati sirul: ");
        for (int i = 1; i <= n; i++)
            array.add(in.nextInt());
        in.close();

        ArrayList<Integer> fib = Fibonacci(Collections.max(array));
        array.removeIf(s -> !fib.contains(s));

        System.out.println("Elemente: " + array.size());
        System.out.println(array.toString());
    }
}
