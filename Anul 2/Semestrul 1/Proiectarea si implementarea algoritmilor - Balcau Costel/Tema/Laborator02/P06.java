// Se da n numar natural mai mic sau egal cu 20.
// Afisati toate modalitatile de scriere a lui n ca suma de numere impare.

import java.util.Scanner;

public class P06 {

    static void PrelSol(int[] a, int k) {
        for (int i = 1; i <= k; i++)
            System.out.print(a[i] + " + ");
        System.out.println("\b\b ");
    }

    static boolean Valid(int[] a, int k, int n) {
        int s = a[1];
        for (int i = 2; i <= k; i++){
            if(a[i] < a[i-1])
                return false;
            s += a[i];
        }
        if(s == n)
            PrelSol(a, k);
        if(s > n)
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
            if (k == n + 1)
                k--;
            else if (a[k] <= 7) {
                a[k] = a[k] + 2;
                if (Valid(a, k, n))
                    k++;
            } else {
                a[k] = -1;
                k--;
            }

    }
}