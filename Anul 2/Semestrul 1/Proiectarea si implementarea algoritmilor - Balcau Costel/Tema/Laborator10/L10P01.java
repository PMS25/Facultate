import java.util.Scanner;

// Problema cautarii
// a) Cautarea binara - varianta recursiva.
// b) Cautarea binara - varianta iterativa.
// Exemplu: Arborele binar de cautare asociat algoritmului cautarii binare pentru n = 10.
// Observatie: Elementul median este m = [(1+n)/2] = [(1+10)/2] = [11/2] = [5,5] = 5

class L10P01 {

    private int A[], n, x;

    public L10P01(int n, int A[], int x) {
        this.n = n;
        this.A = A;
        this.x = x;
    }

    public int CautareBinaraRecursiva(int p, int u) {
        if (p > u)
            return -1;
        int m = (p + u) / 2;
        if (x == A[m])
            return m;
        if (x < A[m])
            return CautareBinaraRecursiva(p, m - 1);
        return CautareBinaraRecursiva(m + 1, u);
    }

    public int CautareBinaraIterativa() {
        int p = 1, u = n;
        while (p <= u) {
            int m = (p + u) / 2;
            if (A[m] == x)
                return m;
            else if (x < A[m])
                u = m - 1;
            else
                p = m + 1;
        }
        return -1;
    }

    public void AfisareCautareBinara(){
        int p1 = CautareBinaraRecursiva(1, n);
        int p2 = CautareBinaraIterativa();

        System.out.printf("Cautare Binara Recursiva: %d pe pozitia %d\n", x, p1);
        System.out.printf("Cautare Binara Iterativa: %d pe pozitia %d\n", x, p2);
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de elemente n = ");
        int n = in.nextInt();

        System.out.print("Dati elementele: ");
        int A[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            A[i] = in.nextInt();

        System.out.print("Dati valoarea cautata x = ");
        int x = in.nextInt();

        in.close();
        return new Object[] { n, A, x };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int A[] = (int[]) input[1];
        int x = (int) input[2];
        
        L10P01 obj = new L10P01(n, A, x);
        obj.AfisareCautareBinara();
    }
}