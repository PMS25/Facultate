import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
Se considera - un graf neorientat fara bucle G = (V, E), cu 
             - multimea nodurilor V = {1, 2, . . . , n},
             - un numar de m culori, numerotate cu 1, 2, . . . , m.
Se cere sa se determine toate modalitatile de colorare ale nodurilor grafului, utilizand cele m culori,
astfel incat oricare doua _noduri_ adiacente sa fie colorate cu culori diferite.

Exemplu 1:
- n = 6 (nr noduri)
- m = 4 (nr culori)
- A: 
0 1 0 1 0 1
1 0 1 1 1 0
0 1 0 0 1 1
1 1 0 0 1 1
0 1 1 1 0 1
1 0 1 1 1 0


Exemplu 2:
- n = 6 (nr noduri)
- m = 4 (nr culori)
- A: 
0 1 1 0 1 1
1 0 1 0 1 0
1 1 0 1 0 1
0 0 1 0 1 0
1 1 0 1 0 1
1 0 1 0 1 0
*/

public class L04P01 {

    private int[] x;
    private int[][] a;
    private int n, m;
    private List<ArrayList<Integer>> solutii = null;

    public L04P01(int n, int m, int[][] a) {
        this.n = n;
        this.m = m;
        this.a = a;
        x = new int[n + 1];
        solutii = new ArrayList<>();
    }

    public void AfisareSolutii() {
        System.out.println("\nAfisare Solutii:");
        int i = 0;

        for (ArrayList<Integer> solutie : solutii)
            System.out.println( (++i) + ": " + solutie.toString());
    }

    private void Stocare() {
        ArrayList<Integer> solutie = new ArrayList<>();
        for (int i = 1; i <= n; i++)
            solutie.add(x[i]);
        solutii.add(solutie);
    }

    // Afisare Traditionala;
    public void Afisare() {
        for (int i = 1; i <= n; i++)
            System.out.print(i + " ");
        System.out.println();
        for (int i = 1; i <= n; i++)
            System.out.print(x[i] + " ");
        System.out.println("\n");
    }

    private boolean Valid(int k) {
        for (int i = 1; i <= k - 1; i++)
            if (a[i][k] >= 1 && x[i] == x[k])
                return false;
        return true;
    }

    public void Back() {
        int k = 1;
        x[1] = 0;

        while (k > 0)
            if (x[k] < m) {
                x[k] += 1;
                if (Valid(k))
                    if (k == n)
                        Stocare();
                    else {
                        k++;
                        x[k] = 0;
                    }
            } else
                k--;
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Nr de noduri n = ");
        int nn = in.nextInt();

        System.out.print("Nr de culori m = ");
        int nm = in.nextInt();

        System.out.println("Dati matricea de adiacenta (" + nn + "x" + nn + "): ");
        int[][] A = new int[nn + 1][nn + 1];
        for (int i = 1; i <= nn; i++)
            for (int j = 1; j <= nn; j++)
                A[i][j] = in.nextInt();

        in.close();
        return new Object[] { nn, nm, A };
    }

    public static void main(String[] args) {
        Object[] date = CitireDateConsola();
        int n = (int) date[0];
        int m = (int) date[1];
        int[][] A = (int[][]) date[2];

        L04P01 cg = new L04P01(n, m, A);
        cg.Back();
        cg.AfisareSolutii();
    }
}
