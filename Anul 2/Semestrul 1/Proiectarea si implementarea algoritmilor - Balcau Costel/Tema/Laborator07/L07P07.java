import java.util.ArrayList;
import java.util.Scanner;

// Se citeste un numar natural n.
// Sa se determine numarul maxim obtinut prin eliminarea din numarul dat a k cifre.
// Exemplu: Pentru n=1324, k=2 se obtine valoarea 34

public class L07P07 {

    private int x[], n, kk, a[];
    private ArrayList<Integer> solutii;

    public L07P07(int nr, int k) {
        this.kk = k;
        n = LungimeNumar(nr);
        a = SpargereInCifre(nr);
        x = new int[n + 1];
        solutii = new ArrayList<>();
    }

    public void CleanSolutii() {
        solutii.clear();
        for (int i = 1; i <= n; i++)
            x[i] = 0;
    }

    public void Afisare() {
        int maxim = solutii.stream().reduce(Integer::max).get();
        System.out.printf("\nSolutie Maxima: %d\n", maxim);
    }

    private void Stocare() {
        int s = 0;
        for (int i = 1; i <= n; i++)
            if (x[i] == 1)
                s = s * 10 + a[i];
        solutii.add(s);
    }

    private boolean Valid(int k) {
        int s = x[k];
        for (int i = 1; i < k; i++)
            s += x[i];
        return (s <= kk);
    }

    public void Back() {
        CleanSolutii();
        int k = 1;
        x[1] = -1;
        while (k > 0)
            if (x[k] < 1) {
                x[k]++;
                if (Valid(k))
                    if (k == n) {
                        Stocare();
                        k--;
                    } else
                        x[++k] = -1;
            } else
                x[k--] = -1;
    }

    // Accesori
    public static int LungimeNumar(int nr) {
        int l = 0;
        do {
            l++;
            nr /= 10;
        } while (nr != 0);
        return l;
    }

    public static int[] SpargereInCifre(int nr) {
        int l = LungimeNumar(nr);
        int aux[] = new int[l + 1];
        for (int i = l; i > 0; i--) {
            aux[i] = nr % 10;
            nr /= 10;
        }
        return aux;
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul n = ");
        int n = in.nextInt();

        System.out.print("Dati numarul de cifre eliminate k = ");
        int k = in.nextInt();

        in.close();
        return new Object[] { n, k };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int k = (int) input[1];
        L07P07 obj = new L07P07(n, k);
        obj.Back();
        obj.Afisare();
    }

}
