import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Aranjamente cu repetitie.

public class L06P03 {

    private int n, m, x[];
    private List<ArrayList<Integer>> solutii;

    public L06P03(int n, int m) {
        this.n = n;
        this.m = m;
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

    public void Aranjamente_Cu_Repetitie() {
        int k = 1;
        while (k > 0)
            if (x[k] < m) {
                x[k]++;
                if (k == n)
                    Stocare();
                else
                    x[++k] = 0;
            } else
                k--;
    }

    // Static
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
        Object input[] = CitireDateConsola();
        int n = (int) input[0];
        int m = (int) input[1];

        L06P03 obj = new L06P03(n, m);
        obj.Aranjamente_Cu_Repetitie();
        obj.Afisare();
    }
}
