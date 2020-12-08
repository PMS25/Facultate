import java.util.Scanner;

// Problema interclasarii. Interclasarea a doi vectori.

public class L10P02 {

    private int m, A[], n, B[];

    public L10P02(int m, int A[], int n, int B[]) {
        this.m = m;
        this.A = A;
        this.n = n;
        this.B = B;
    }

    public void Interclasare(int m, int A[], int n, int B[], int C[]) {
        int i = 1, j = 1, k = 1;
        while (i <= m && j <= n)
            if (A[i] <= B[j])
                C[k++] = A[i++];
            else
                C[k++] = B[j++];
        while (i <= m)
            C[k++] = A[i++];
        while (j <= n)
            C[k++] = B[j++];
    }

    public void AfisareInterclasare() {
        int C[] = new int[n + m + 1];
        Interclasare(m, A, n, B, C);
        System.out.print("Interclasarea celor 2 vectori: ");
        for (int i = 1; i < C.length; i++)
            System.out.printf("%d, ", C[i]);
        System.out.println("\b\b ");
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de elemente m = ");
        int m = in.nextInt();

        System.out.print("Dati vectorul A: ");
        int A[] = new int[m + 1];
        for (int i = 1; i <= m; i++)
            A[i] = in.nextInt();

        System.out.print("Dati numarul de elemente n = ");
        int n = in.nextInt();

        System.out.print("Dati vectorul B: ");
        int B[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            B[i] = in.nextInt();

        in.close();
        return new Object[] { m, A, n, B };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int m = (int) input[0];
        int A[] = (int[]) input[1];
        int n = (int) input[2];
        int B[] = (int[]) input[3];

        L10P02 obj = new L10P02(m, A, n, B);
        obj.AfisareInterclasare();
    }
}
