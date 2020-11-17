import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Partitii ale unui numar natural
// Exemplu: Numarul m = 6 are partitiile
// 6 = 6                        P(6,1)=1
//   = 1+5 = 2+4 = 3+3          P(6,2)=3
//   = 1+1+4 = 1+2+3 = 2+2+2    P(6,3)=3
//   = 1+1+1+3 = 1+1+2+2        P(6,4)=2
//   = 1+1+1+1+2                P(6,5)=1
//   = 1+1+1+1+1+1              P(6,6)=1
//   P(6)=11.

public class L07P05 {

    private int n, m, x[];
    private List<ArrayList<Integer>> solutii;

    public L07P05(int n, int m) {
        this.n = n;
        this.m = m;
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

    public void Partitii() {
        int k = 1, s = 0;
        while (k > 0)
            if (k <= n - 1) {
                if (x[k] < (m - s) / (n - k + 1)) {
                    x[k]++;
                    s += x[k];
                    k++;
                    x[k] = x[k - 1] - 1;
                } else {
                    k--;
                    s -= x[k];
                }
            } else {
                x[n] = m - s;
                Stocare();
                k--;
                s -= x[k];
            }
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul m = ");
        int m = in.nextInt();

        System.out.print("Dati dimensiunea partitiilor n = ");
        int n = in.nextInt();

        in.close();
        return new Object[] { n, m };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int m = (int) input[1];
        L07P05 obj = new L07P05(n, m);
        obj.Partitii();
        obj.Afisare();
    }
}
