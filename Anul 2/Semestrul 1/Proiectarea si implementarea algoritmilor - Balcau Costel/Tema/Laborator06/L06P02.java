import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Submultimi.

public class L06P02 {

    int n, x[], a[];
    private List<ArrayList<Integer>> solutii;

    public L06P02(int n, int a[]) {
        this.n = n;
        this.a = a;
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
            if (x[i] == 1)
                solutie.add(a[i]);
        solutii.add(solutie);
    }

    public void Submultimi() {
        int k = 1;
        while (k > 0)
            if (x[k] < 2) {
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

        System.out.print("Dati numarul de elemente n = ");
        int n = in.nextInt();

        System.out.println("Dati elementele multimii:");
        int a[] = new int[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            System.out.printf("%d: ", i);
            a[i] = in.nextInt();
        }

        in.close();
        return new Object[] { n, a };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int m[] = (int[]) input[1];

        L06P02 obj = new L06P02(n, m);
        obj.Submultimi();
        obj.Afisare();
    }

}
