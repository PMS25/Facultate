import java.util.Scanner;

// Determinati un subsir crescator de lungime maxima pentru A = (2,5,9,8,7,6,12,17,10,4).
// Exemplu: 2 5 9 12 17

public class L13P03 {
    private int A[], n, t[], l;

    public L13P03(int n, int A[]) {
        this.n = n;
        this.A = A;
        this.t = new int[n + 1];
    }

    public void SirCrescatorLungimeMaxima() {
        int i, j;

        // Clean
        for (i = 1; i <= n; i++)
            t[i] = 1;

        for (i = n; i >= 2; i--)
            for (j = i - 1; j >= 1; j--)
                if (A[i] >= A[j]) {
                    t[j] = Math.max(t[j], t[i] + 1);
                    l = Math.max(t[j], l);
                }

        Afisare();
    }

    private void Afisare() {
        for (int i = 1; i <= n; i++)
            if (t[i] == l) {
                System.out.printf("%d, ", A[i]);
                l--;
            }
        System.out.printf("\b\b \n");
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.println("Dati A: ");
        int A[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            A[i] = in.nextInt();

        in.close();
        return new Object[] { n, A };
    }

    public static void main(String[] args) {
        Object input[] = CitireDateConsola();
        int n = (int) input[0];
        int A[] = (int[]) input[1];

        L13P03 obj = new L13P03(n, A);
        obj.SirCrescatorLungimeMaxima();
    }

}
