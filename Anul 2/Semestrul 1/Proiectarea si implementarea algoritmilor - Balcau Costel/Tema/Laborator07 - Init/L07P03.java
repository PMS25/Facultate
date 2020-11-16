import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

// Permutari cu Repetitie
// Exemplu: m = 3 ; t1 = 2 ; t2 = t3 = 1 => n = 4
// (1,1,2,3), (1,1,3,2), (1,2,1,3), (1,2,3,1), (1,3,1,2), (1,3,2,1),
// (2,1,1,3), (2,1,3,1), (2,3,1,1), (3,1,1,2), (3,1,2,1), (3,2,1,1).

public class L07P03 {

    private int n, m, x[], t[];
    private List<ArrayList<Integer>> solutii;

    public L07P03(int m, int t[]) {
        this.m = m;
        this.t = t;
        n = Arrays.stream(t).sum();
        x = new int[n + 1];
        solutii = new ArrayList<>();
    }

    public void CleanSolutii() {
        solutii.clear();
        for (int i = 1; i <= n; i++)
            x[i] = 0;
    }

    public void Afisare() {
        int count = 0;
        System.out.println("\nAfisare solutii:");
        for (ArrayList<Integer> solutie : solutii)
            System.out.printf("%d: %s\n", ++count, solutie.subList(1, n + 1));
    }

    private void Stocare() {
        ArrayList<Integer> solutie = new ArrayList<>();
        for (int i = 0; i <= n; i++)
            solutie.add(x[i]);
        solutii.add(solutie);
    }

    private boolean Valid(int k, int p) {
        int q = 0;
        if (p == 0)
            return false;
        for (int i = 1; i <= k - 1; i++)
            if (x[i] == x[k])
                if (++q >= p)
                    return false;
        return true;
    }

    public void Permutari_Cu_Repetitie1() {
        CleanSolutii();
        int k = 1, p;
        while (k > 0)
            if (x[k] < m) {
                x[k]++;
                p = t[x[k]];
                if (Valid(k, p))
                    if (k == n) {
                        Stocare();
                        k--;
                    } else
                        x[++k] = 0;
            } else
                k--;
    }

    public void Permutari_Cu_Repetitie2() {
        CleanSolutii();
        int k = 1, y[] = new int[m + 1];
        while (k > 0)
            if (x[k] < m) {
                x[k]++;
                if (y[x[k]] < t[x[k]])
                    if (k == n) {
                        Stocare();
                        k--;
                        y[x[k]]--;
                    } else {
                        y[x[k]]++;
                        k++;
                        x[k] = 0;
                    }
            } else {
                k--;
                y[x[k]]--;
            }
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati m = ");
        int m = in.nextInt();

        System.out.println("Dati nr de repetitii pt fiecare termen:");
        int t[] = new int[m + 1];
        for (int i = 1; i <= m; i++) {
            System.out.printf("t%d: ", i);
            t[i] = in.nextInt();
        }

        in.close();
        return new Object[] { m, t };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int m = (int) input[0];
        int t[] = (int[]) input[1];
        L07P03 obj = new L07P03(m, t);
        obj.Permutari_Cu_Repetitie1();
        obj.Afisare();
        obj.Permutari_Cu_Repetitie2();
        obj.Afisare();
    }
}
