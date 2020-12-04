import java.util.Scanner;

// Fie n numere intregi a1, a2, ..., an.
// Sa se determine, folosind un algoritm "Divide et Impera", cel de-al k-lea cel mai mic element din sir.

public class L09P02 {

    private int n, x[], k;

    public L09P02(int n, int x[], int k) {
        this.n = n;
        this.x = x;
        this.k = k;
    }

    private int[] Minim(int x[], int s, int d) {
        if (s == d)
            return new int[] { x[s], s };
        else {
            int m = (s + d) / 2;
            int m1[] = Minim(x, s, m);
            int m2[] = Minim(x, m + 1, d);

            return (m1[0] < m2[0] ? m1 : m2);
        }
    }

    public void MinimK() {
        int temp[] = x.clone(), kk = k, minim = 0;
        while (kk != 0) {
            int aux[] = Minim(temp, 1, n);
            minim = aux[0];
            temp[aux[1]] = Integer.MAX_VALUE;
            kk--;
        }
        System.out.printf("Al %d minim este: %d\n", k, minim);
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.print("Dati lista de n: ");
        int x[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            x[i] = in.nextInt();

        System.out.print("Dati k = ");
        int k = in.nextInt();

        in.close();
        return new Object[] { n, x, k };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int x[] = (int[]) input[1];
        int k = (int) input[2];
        L09P02 obj = new L09P02(n, x, k);
        obj.MinimK();
    }
}
