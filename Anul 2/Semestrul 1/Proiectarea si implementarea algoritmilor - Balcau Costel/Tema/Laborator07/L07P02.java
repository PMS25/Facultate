import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Combinari cu Repetitie
// Exemplu: n = 4 ; m = 3
// (1,1,1,1), (1,1,1,2), (1,1,1,3), (1,1,2,2), (1,1,2,3),
// (1,1,3,3), (1,2,2,2), (1,2,2,3), (1,2,3,3), (1,3,3,3),
// (2,2,2,2), (2,2,2,3), (2,2,3,3), (2,3,3,3), (3,3,3,3).

public class L07P02 {

    private int n, m, x[];
    private List<ArrayList<Integer>> solutii;

    public L07P02(int n, int m) {
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

    public void Combinari_Cu_Repetitie() {
        CleanSolutii();
        int k = 1;
        while (k > 0)
            if (x[k] < m) {
                x[k]++;
                if (k == n)
                    Stocare();
                else
                    x[++k] = x[k - 1] - 1;
            } else
                k--;
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.print("Dati m = ");
        int m = in.nextInt();

        in.close();
        return new Object[] { n, m };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int m = (int) input[1];
        L07P02 obj = new L07P02(n, m);
        obj.Combinari_Cu_Repetitie();
        obj.Afisare();
    }
}
