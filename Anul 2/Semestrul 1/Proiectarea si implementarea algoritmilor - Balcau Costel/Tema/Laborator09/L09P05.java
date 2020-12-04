import java.util.Scanner;

// Calculati folosind metoda "Divide et Impera" suma 1*2 + 2*3 + ... + n*(n+1)

public class L09P05 {

    private int n;

    public L09P05(int n) {
        this.n = n;
    }

    private int Suma(int s, int d) {
        if (s == d)
            return s * (s + 1);
        else {
            int m = (s + d) / 2;
            int x = Suma(s, m);
            int y = Suma(m + 1, d);
            return x + y;
        }
    }

    public void Suma() {
        System.out.printf("Suma 1*2 + 2*3 + ... + n*(n+1): %d\n", Suma(1, n));
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        in.close();
        return new Object[] { n };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        L09P05 obj = new L09P05(n);
        obj.Suma();
    }
}
