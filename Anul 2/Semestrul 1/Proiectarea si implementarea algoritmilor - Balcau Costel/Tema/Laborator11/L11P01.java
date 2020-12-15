import java.util.Scanner;

// Problema sortarii - Sortarea rapida (quicksort) - 2 algoritmi.

class L11P01 {

    private int n, A[];

    public L11P01(int A[], int n) {
        this.A = A;
        this.n = n;
    }

    private void SwapA(int p, int u) {
        int aux = A[p];
        A[p] = A[u];
        A[u] = aux;
    }

    private int Pivot(int p, int u) {
        int cp = 0, cu = -1;
        while (p < u) {
            if (A[p] > A[u]) {
                SwapA(p, u);
                int m = cp;
                cp = -cu;
                cu = -m;
            }
            p += cp;
            u += cu;
        }
        return p; // k = p
    }

    private void QuickSort1(int p, int u) {
        if (p < u) {
            int k = Pivot(p, u);
            QuickSort1(p, k - 1);
            QuickSort1(k + 1, u);
        }
    }

    private void QuickSort2(int p, int u) {
        int k = (u + p) / 2;
        int med = A[k], min = p, max = u;
        do {
            while (A[min] < med)
                min++;
            while (A[max] > med)
                max--;
            if (min <= max) {
                SwapA(min, max);
                min++;
                max--;
            }
        } while (min <= max);
        if (p < max)
            QuickSort2(p, max);
        if (u > min)
            QuickSort2(min, u);
    }

    public void QuickSort() {
        QuickSort1(1, n);
        QuickSort2(1, n);
    }

    public void AfisareSolutie() {
        System.out.println("Solutie: ");
        for (int i = 1; i <= n; i++)
            System.out.printf("%d, ", A[i]);
        System.out.println("\b\b ");
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.print("Dati A[] = ");
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

        L11P01 obj = new L11P01(A, n);
        obj.QuickSort();
        obj.AfisareSolutie();
    }
}