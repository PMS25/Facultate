import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Fie a=(a1,a2,...,an), n>=3 un sir de numere reale.
// Sa se obtina din a prin permutari tabloul b=(b1,b2,...,bn) care sa indeplineasca urmatoarele conditii:
// - b(i) >= b(i+1) pentru i=1,2,...,k−1
// - b(i) <= b(i+1) pentru i=k,...,n−1;
// unde k este n/2 pentru n par si (n+1)/2 pentru n impar
// Exemplu: Pentru vectorul a=(1,2,3,4,5) se obtin solutiile:
// (3,2,1,4,5),(4,2,1,3,5),(4,3,1,2,5),(5,2,1,3,4),(5,3,1,2,4),(5,4,1,2,3)

public class L07P06 {

    private int n, x[];
    private List<ArrayList<Integer>> solutii;

    public L07P06(int n) {
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

    public void CleanSolutii() {
        solutii.clear();
        for (int i = 1; i <= n; i++)
            x[i] = 0;
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

    private boolean Conditie() {
        int k = (n + n % 2) / 2;
        for (int i = 1; i <= k - 1; i++)
            if (x[i] < x[i + 1])
                return false;
        for (int i = k; i <= n - 1; i++)
            if (x[i] > x[i + 1])
                return false;
        return true;
    }

    public void Permutari_Conditie() {
        CleanSolutii();
        int k = 1;
        while (k > 0)
            if (x[k] < n) {
                x[k]++;
                if (Valid(k))
                    if (k == n) {
                        if (Conditie())
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
        CleanSolutii();
        int y[] = new int[n + 1];
        int k = 1;
        while (k > 0)
            if (x[k] < n) {
                x[k]++;
                if (y[x[k]] == 0)
                    if (k == n) {
                        if (Conditie())
                            Stocare();
                        y[x[--k]] = 0;
                    } else {
                        y[x[k]] = 1;
                        x[++k] = 0;
                    }
            } else
                y[x[--k]] = 0;
    }

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

        L07P06 obj = new L07P06(n);
        obj.Permutari_Conditie();
        obj.Afisare();
        obj.Permutari2_Conditie();
        obj.Afisare();
    }
}
