import java.util.Scanner;

// Problema sortarii. Sortarea prin interclasare (2 algoritmi).

public class L10P03 {

    private int n, A[], B[];

    public L10P03(int n, int A[]) {
        this.n = n;
        this.A = A;
        this.B = new int[n + 1];
    }

    private void Interclasare1(int p, int q, int m) {
        int i = p, j = m + 1, k = 1;

        while (i <= m && j <= q) {
            if (A[i] <= A[j])
                B[k++] = A[i++];
            else
                B[k++] = A[j++];
        }
        while (i <= m)
            B[k++] = A[i++];
        while (j <= q)
            B[k++] = A[j++];
        k = 1;
        for (i = p; i <= q; i++)
            A[i] = B[k++];
    }

    private void Interclasare2(int p, int q, int m) {
        int i = p, j = m + 1, k = 1;
        int lim;

        while (i <= m && j <= q) {
            if (A[i] <= A[j])
                B[k++] = A[i++];
            else
                B[k++] = A[j++];
        }
        if (j <= q)
            lim = j - 1;
        else {
            lim = q - m + i - 1;
            for (j = m; j >= i; j--)
                A[q - m + j] = A[j];
        }
        k = 1;
        for (i = p; i <= lim; i++)
            A[i] = B[k++];
    }

    private void SortareInterclasare1(int p, int q) {
        if (p < q) {
            int m = (p + q) / 2;
            SortareInterclasare1(p, m);
            SortareInterclasare1(m + 1, q);
            Interclasare1(p, q, m);
        }
    }

    private void SortareInterclasare2(int p, int q) {
        if (p < q) {
            int m = (p + q) / 2;
            SortareInterclasare2(p, m);
            SortareInterclasare2(m + 1, q);
            Interclasare2(p, q, m);
        }
    }

    public void Sortare() {
        SortareInterclasare1(1, n);
        SortareInterclasare2(1, n);
        System.out.println("Vector sortat:");
        for (int i = 1; i <= n; i++)
            System.out.printf("%d, ", A[i]);
        System.out.println("\b\b ");
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.print("Dati vectorul: ");
        int A[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            A[i] = in.nextInt();

        in.close();
        return new Object[] { n, A };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int A[] = (int[]) input[1];

        L10P03 obj = new L10P03(n, A);
        obj.Sortare();
    }
}
