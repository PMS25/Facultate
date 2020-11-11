import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Permutari.

public class L06P05 {

    private int n, x[];
    private List<ArrayList<Integer>> solutii;

    public L06P05(int n) {
        this.n = n;
        x = new int[n + 1];
        solutii = new ArrayList<>();
    }

    public void Afisare() {
        int i = 0;
        System.out.println("\nAfisare solutii:");
        for (ArrayList<Integer> solutie : solutii)
            System.out.printf("%d: %s \n", ++i, solutie.subList(1, solutie.size()));
    }

    private void Stocare() {
        ArrayList<Integer> solutie = new ArrayList<>();
        solutie.add(0);
        for (int i = 1; i <= n; i++)
            solutie.add(x[i]);
        solutii.add(solutie);
    }

    private boolean Valid(int k) {
        for (int i = 1; i <= k - 1; i++)
            if (x[k] == x[i])
                return false;
        return true;
    }

    public void Permutari() {
        int k = 1;
        while (k > 0)
            if (x[k] < n) {
                x[k]++;
                if (Valid(k))
                    if (k == n) {
                        Stocare();
                        k--;
                    } else {
                        k++;
                        x[k] = 0;
                    }
            } else
                k--;
    }

    public void Permutari2() {
        int y[] = new int[n + 1];
        int k = 1;
        while (k > 0)
            if (x[k] < n) {
                x[k]++;
                if (y[x[k]] == 0)
                    if (k == n) {
                        Stocare();
                        y[x[--k]] = 0;
                    } else {
                        y[x[k]] = 1;
                        x[++k] = 0;
                    }
            } else
                y[x[--k]] = 0;
    }

    // Static
    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati cardinalul multimii n = ");
        int n = in.nextInt();

        in.close();
        return new Object[] { n };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];

        L06P05 obj = new L06P05(n);
        obj.Permutari();
        obj.Afisare();
    }
}
