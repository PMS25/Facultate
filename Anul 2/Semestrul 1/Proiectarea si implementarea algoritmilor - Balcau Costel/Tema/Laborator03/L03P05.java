import java.util.Scanner;

// Se considera o multime cu n numere intregi. Sa se determine o submultime a acesteia cu suma maxima.

public class L03P05 {

    private int n, s;
    private int[] x;
    private int[] multime;

    public L03P05(int[] multime) {
        this.multime = multime;
        n = multime.length;
        x = new int[n];
    }

    public void Afisare() {
        System.out.printf("Suma: %d \n", s);
        System.out.print("Submultime: ");
        for (int i = 0; i < n; i++)
            if (x[i] == 1)
                System.out.printf("%d ", multime[x[i]]);
        System.out.println();
    }

    public void Greedy() {
        s = 0;
        for (int i = 0; i < n; i++)
            if (multime[i] >= 0) {
                x[i] = 1;
                s += multime[i];
            }
        Afisare();
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de elemente n = ");
        int n = in.nextInt();
        in.nextLine();

        System.out.printf("Dati multimea de %d numere:\n", n);
        int[] x = new int[n];
        for (int i = 0; i < n; i++)
            x[i] = in.nextInt();

        in.close();
        return new Object[]{x};
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int[] x = (int[]) input[0];

        L03P05 m = new L03P05(x);
        m.Greedy();
    }
}
