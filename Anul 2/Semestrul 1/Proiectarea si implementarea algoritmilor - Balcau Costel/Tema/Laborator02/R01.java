// Se da un vector cu n componente numere naturale mai mici sau egale cu 10000, 1<=n<=100.
// Afisati pe randuri diferite componentele pare, respectiv impare.

import java.util.Scanner;

public class R01 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] x = new int[n + 1];
        for (int i = 1; i <= n; i++)
            x[i] = in.nextInt();

        for (int i = 1; i <= n; i++)
            if (x[i] % 2 == 0)
                System.out.print(x[i] + " ");

        System.out.println();
        for (int i = 1; i <= n; i++)
            if (x[i] % 2 == 1)
                System.out.print(x[i] + " ");
        in.close();
    }
}