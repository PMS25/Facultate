import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Produs cartezian.

class L06P01 {

    private int n, x[], m[];
    private List<ArrayList<Integer>> solutii;

    public L06P01(int n, int m[]) {
        this.n = n;
        this.m = m;
        x = new int[n + 1];
        solutii = new ArrayList<>();
    }

    public void Afisare() {
        int i = 0;
        System.out.println("\nAfisare solutii:");
        for (ArrayList<Integer> solutie : solutii)
            System.out.printf("%d: %s \n", ++i, solutie.subList(1, n + 1));
    }

    private void Stocare() {
        ArrayList<Integer> solutie = new ArrayList<>();
        solutie.add(0);
        for (int i = 1; i <= n; i++)
            solutie.add(x[i]);
        solutii.add(solutie);
    }

    public void Produs_Cartezian() {
        int k = 1;
        while (k > 0)
            if (x[k] < m[k]) {
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

        System.out.print("Dati numarul multimilor n = ");
        int n = in.nextInt();

        System.out.println("Dati cardinalul multimilor:");
        int m[] = new int[n + 1];
        m[0] = 0;
        for (int i = 1; i <= n; i++) {
            System.out.printf("%d: ", i);
            m[i] = in.nextInt();
        }

        in.close();
        return new Object[] { n, m };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int m[] = (int[]) input[1];

        L06P01 obj = new L06P01(n, m);
        obj.Produs_Cartezian();
        obj.Afisare();
    }
}