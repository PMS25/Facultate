// Se da un tablou patratic de dimensiune n cu componente nr nat <= 10000, 1<=n<=100.
// Ordonati crescator fiecare linie si apoi afisati tabloul.

import java.util.Scanner;

public class R02 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int[][] a = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = in.nextInt();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - 1; j++)
                for (int k = j + 1; k <= n; k++)
                    if (a[i][j] > a[i][k]) {
                        int aux = a[i][j];
                        a[i][j] = a[i][k];
                        a[i][k] = aux;
                    }
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                System.out.println(a[i][j] + " ");

        in.close();
    }
}
