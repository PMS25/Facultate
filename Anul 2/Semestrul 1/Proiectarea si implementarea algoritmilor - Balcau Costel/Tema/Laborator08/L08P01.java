import java.util.Scanner;

// Problema turnurilor din Hanoi.

class L08P01 {

    private int m, i, j;

    public L08P01(int m, int i, int j) {
        this.m = m;
        this.i = i;
        this.j = j;
    }

    private void Afisare(int d, int i, int j) {
        System.out.printf("Mutam discul %d de la tija %d la tija %d.\n", d, i, j);
    }

    public void Hanoi() {
        Hanoi(m, i, j);
    }

    private void Hanoi(int m, int i, int j) {
        if (m == 1)
            Afisare(m, i, j);
        else {
            int k = 6 - i - j;
            Hanoi(m - 1, i, k);
            Afisare(m, i, j);
            Hanoi(m - 1, k, j);
        }
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de discuri m = ");
        int m = in.nextInt();

        System.out.print("Dati tija de start i = ");
        int i = in.nextInt();

        System.out.print("Dati tija de final j = ");
        int j = in.nextInt();

        in.close();
        return new Object[] { m, i, j };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int m = (int) input[0];
        int i = (int) input[1];
        int j = (int) input[2];

        L08P01 obj = new L08P01(m, i, j);
        obj.Hanoi();
    }
}