import java.util.ArrayList;
import java.util.Scanner;

// Sa se afiseze toate numerele naturale de n cifre care contin k cifre de 1.
// Exemplu: Pentru n = 3, k = 2 se obtin solutiile:
// 101, 110, 112, 113, ..., 119, 121, 131, 141, ...

class L07P08 {

    private int n, kk, count, x[];
    private ArrayList<Integer> solutii;

    public L07P08(int n, int k, int count) {
        this.n = n;
        this.kk = k;
        this.count = count;
        x = new int[n + 2];
        solutii = new ArrayList<>();
    }

    public void CleanSolutii() {
        solutii.clear();
        for (int i = 1; i <= n; i++)
            x[i] = 0;
    }

    public void Afisare() {
        System.out.println("\nAfisare solutii:");
        int minim;
        for (int i = 0; i < solutii.size(); i += count) {
            minim = Math.min(i + count, solutii.size());
            System.out.printf("%d - %d: ", i + 1, minim);
            System.out.printf("%s \n", solutii.subList(i, minim));
        }
    }

    private void Stocare() {
        int nr = 0;
        for (int i = 1; i <= n; i++)
            nr = nr * 10 + x[i];
        solutii.add(nr);
    }

    private boolean Valid(int k) {
        if (k == 1)
            return x[k] > 0;
        int s = 0;
        for (int i = 1; i <= k; i++)
            s += (x[i] == 1 ? 1 : 0);
        if (s > kk)
            return false;
        if (k == n)
            return s == kk;
        return true;
    }

    public void Back() {
        CleanSolutii();
        int k = 1;
        x[1] = -1;
        while (k > 0)
            if (x[k] < 9) {
                x[k]++;
                if (Valid(k))
                    if (k == n + 1) {
                        Stocare();
                        k--;
                    } else
                        x[++k] = -1;
            } else
                x[k--] = -1;
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de cifre n = ");
        int n = in.nextInt();

        System.out.print("Dati numarul de cifre de 1; k = ");
        int k = in.nextInt();

        System.out.print("Dati dimensiune afisare: ");
        int count = in.nextInt();

        in.close();
        return new Object[] { n, k, count };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int k = (int) input[1];
        int count = (int) input[2];
        L07P08 obj = new L07P08(n, k, count);
        obj.Back();
        obj.Afisare();
    }
}