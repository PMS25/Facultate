import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Sa se genereze toate permutarile multimii {1,2,...,n}
// cu proprietatea ca diferenta in modul dintre oricare doua numere consecutive este cel putin egala cu o valoare v citita de la tastatura.
// Exemplu: Pentru n=4, v=2 singurele solutii sunt: (2,4,1,3), (3,1,4,2).

public class L06P06 {

    private int n, x[], v;
    private List<ArrayList<Integer>> solutii;

    public L06P06(int n, int v) {
        this.n = n;
        this.v = v;
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

    public void Permutari_Conditie() {
        int k = 1;
        while (k > 0)
            if (x[k] < n) {
                x[k]++;
                if (Valid(k))
                    if (k == n) {
                        if (Conditie(k))
                            Stocare();
                        k--;
                    } else {
                        k++;
                        x[k] = 0;
                    }
            } else
                k--;
    }

    public void Permutari2_Conditie() {
        int y[] = new int[n + 1];
        int k = 1;
        while (k > 0)
            if (x[k] < n) {
                x[k]++;
                if (y[x[k]] == 0)
                    if (k == n) {
                        if (Conditie(k))
                            Stocare();
                        y[x[--k]] = 0;
                    } else {
                        y[x[k]] = 1;
                        x[++k] = 0;
                    }
            } else
                y[x[--k]] = 0;
    }

    private boolean Conditie(int k) {
        for (int i = 2; i <= k; i++)
            if (Math.abs(x[i - 1] - x[i]) < v)
                return false;
        return true;
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati cardinalul multimii n = ");
        int n = in.nextInt();

        System.out.print("Dati diferenta minima v = ");
        int v = in.nextInt();

        in.close();
        return new Object[] { n, v };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int v = (int) input[1];

        L06P06 obj = new L06P06(n, v);
        obj.Permutari_Conditie();
        obj.Afisare();
    }
}
