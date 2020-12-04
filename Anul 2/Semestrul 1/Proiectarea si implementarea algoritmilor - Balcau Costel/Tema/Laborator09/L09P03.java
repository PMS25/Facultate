import java.util.Scanner;

// Fie n un numar si a1,a2,...,an o secventa de n numere naturale citite de la tastatura.
// Scrieti un program, bazat pe metoda ”Divide et Impera” care sa calculeze cmmdc(a1,a2,...,an).
// Exemplu: cmmdc(1540, 6076, 490) = 14.

class L09P03 {

    private int n, x[];

    public L09P03(int x[], int n) {
        this.n = n;
        this.x = x;
    }

    private int Cmmdc(int s, int d) {
        if (s == d)
            return x[s];
        else {
            int m = (s + d) / 2;
            int x = Cmmdc(s, m);
            int y = Cmmdc(m + 1, d);

            while (y != 0) {
                int r = x % y;
                x = y;
                y = r;
            }
            return x;
        }
    }

    public void Cmmdc() {
        System.out.printf("Cmmdc: %d\n", Cmmdc(1, n));
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
        L09P03 obj = new L09P03(x, n);
        obj.Cmmdc();
    }
}