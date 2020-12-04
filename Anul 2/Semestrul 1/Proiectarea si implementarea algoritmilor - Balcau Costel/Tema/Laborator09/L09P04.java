import java.util.ArrayList;
import java.util.Scanner;

// Fie un vector de n numere intregi, determinati prin "Divide et Impera"
// toate pozitiile pe care apare in tablou o anumita valoare v data.

public class L09P04 {

    private int n, v, x[];
    private ArrayList<Integer> pozitii;

    public L09P04(int n, int x[], int v) {
        this.n = n;
        this.x = x;
        this.v = v;
        pozitii = new ArrayList<>();
    }

    private void PozitiiV(int s, int d, int v) {
        if (s == d) {
            if (x[s] == v)
                pozitii.add(s);
        } else {
            int m = (s + d) / 2;
            PozitiiV(s, m, v);
            PozitiiV(m + 1, d, v);
        }
    }

    private void PozitiiV() {
        PozitiiV(1, n, v);
        System.out.printf("Pozitii valoare %d: ", v);
        for (int p : pozitii)
            System.out.printf("%d, ", p);
        System.out.print("\b\b \n");
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.print("Dati lista de n: ");
        int x[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            x[i] = in.nextInt();

        System.out.print("Dati v: ");
        int v = in.nextInt();

        in.close();
        return new Object[] { n, x, v };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int x[] = (int[]) input[1];
        int v = (int) input[2];
        L09P04 obj = new L09P04(n, x, v);
        obj.PozitiiV();
    }
}
