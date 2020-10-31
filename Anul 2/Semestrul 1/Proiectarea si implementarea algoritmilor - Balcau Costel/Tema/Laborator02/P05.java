// Se da n numar natural <= 10.
// Afisati toate nr cu exact n cifre, toate impare, a.i. sa nu existe 2 cifre egale una langa alta.

import java.util.Scanner;

public class P05 {

    static void PrelSol(int[] a, int n) {
        for (int i = 1; i <= n; i++)
            System.out.print(a[i]);
        System.out.println("");
    }

    static boolean Valid(int[] a, int k) {
        for (int i = 2; i <= k; i++)
            if (a[i - 1] == a[i])
                return false;
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();

        // Backtracking
        int[] a = new int[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = -1;

        int k = 1;
        while (k > 0)
            if (k == n + 1) {
                PrelSol(a, n);
                k--;
            } else if (a[k] <= 7) {
                a[k] = a[k] + 2;
                if (Valid(a, k))
                    k++;
            } else {
                a[k] = -1;
                k--;
            }

    }
}