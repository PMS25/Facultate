import java.util.Scanner;

// Sa se scrie un program pentru determinarea minimului dintr-un sir de numere intregi
// folosind "Divide et Impera".

class L09P01 {

    private int n, x[];

    L09P01(int x[], int n) {
        this.x = x;
        this.n = n;
    }

    private int Minim(int s, int d) {
        if (s == d)
            return x[s];
        else {
            int m = (s + d) / 2;
            int m1 = Minim(s, m);
            int m2 = Minim(m + 1, d);

            return (m1 < m2 ? m1 : m2);
        }
    }

    public int Minim() {
        return Minim(1, n);
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.print("Dati lista de n: ");
        int x[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            x[i] = in.nextInt();

        in.close();
        return new Object[] { n, x };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int x[] = (int[]) input[1];
        L09P01 obj = new L09P01(x, n);
        System.out.printf("Minim: %d", obj.Minim());
    }
}