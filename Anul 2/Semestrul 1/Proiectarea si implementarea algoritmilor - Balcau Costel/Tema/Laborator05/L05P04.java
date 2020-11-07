import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

// Pe o tabla de sah de dimensiune n se afla un cal in pozitia (x0,y0).
// Afisati cel mai scurt traseu pe care trebuie sa il parcurga calul pentru a ajunge in pozitia (x1,y1),
// fara a trece de doua ori prin aceeasi pozitie.
// Exemplu: Pentru n = 5, x0 = 1, y0 = 1, x1 = 5, y1 = 5 solutia este:
// (1,1), (2,3), (1,5), (3,4), (5,5).

public class L05P04 {
    public static class Coordonate {
        int x, y;

        Coordonate() {
        }

        Coordonate(int x, int y) {
            this.x = x;
            this.y = y;
        }

        Coordonate add(Coordonate p) {
            Coordonate np = new Coordonate();
            np.x = x + p.x;
            np.y = y + p.y;
            return np;
        }

        boolean egal(Coordonate p) {
            return x == p.x && y == p.y;
        }

        @Override
        public String toString() {
            return String.format("(%d, %d)", x, y);
        }
    }

    private int n, x[];
    private Coordonate p_final, T[], mutari[];
    private List<ArrayList<Coordonate>> solutii;

    L05P04(int n, Coordonate p_start, Coordonate p_final) {
        this.n = n;
        this.p_final = p_final;
        x = new int[2 * n + 1];
        T = new Coordonate[2 * n + 1];
        T[0] = p_start;
        Initializare_Mutari();
        solutii = new ArrayList<>();
    }

    // Coordonate
    private void Initializare_Mutari() {
        mutari = new Coordonate[9];
        mutari[0] = new Coordonate(0, 0);
        mutari[1] = new Coordonate(-2, +1);
        mutari[2] = new Coordonate(-1, +2);
        mutari[3] = new Coordonate(+1, +2);
        mutari[4] = new Coordonate(+2, +1);
        mutari[5] = new Coordonate(+2, -1);
        mutari[6] = new Coordonate(+1, -2);
        mutari[7] = new Coordonate(-1, -2);
        mutari[8] = new Coordonate(-2, -1);
    }

    // Afisare
    public void ToateSolutiile() {
        for (int i = 0; i < solutii.size(); i++)
            System.out.printf("%d : %s\n", i + 1, solutii.get(i));
    }

    public void CeaMaiScurta() {
        Collections.sort(solutii, new Comparator<ArrayList<Coordonate>>() {
            public int compare(ArrayList<Coordonate> a1, ArrayList<Coordonate> a2) {
                return a1.size() - a2.size();
            }
        });
        System.out.printf("Solutie optima: %s\n", solutii.get(0));
    }

    // Backtracking
    private void Stocare(int k) {
        ArrayList<Coordonate> solutie = new ArrayList<>();
        for (int i = 0; i <= k; i++)
            solutie.add(T[i]);
        solutii.add(solutie);
    }

    private boolean Valid(int k) {
        // E pe Tabla
        if (!(T[k].x >= 1 && T[k].x <= n && T[k].y >= 1 && T[k].y <= n))
            return false;
        // Unicitate pozitie
        for (int i = 0; i < k; i++)
            if (T[i].egal(T[k]))
                return false;
        // Daca avem solutie
        if (T[k].egal(p_final))
            Stocare(k);
        return true;
    }

    void Back() {
        int k = 1;
        while (k > 0) {
            if (k == 2 * n)
                k--;
            else if (x[k] <= 7) {
                x[k]++;
                T[k] = T[k - 1].add(mutari[x[k]]);
                if (Valid(k))
                    k++;
            } else
                x[k--] = 0;
        }
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati dimensiunea tablei de sah n = ");
        int n = in.nextInt();

        System.out.print("Dati pozitia de start (x,y): ");
        int x0 = in.nextInt();
        int y0 = in.nextInt();
        Coordonate p_start = new Coordonate(x0, y0);

        System.out.print("Dati pozitia de final (x,y): ");
        int x1 = in.nextInt();
        int y1 = in.nextInt();
        Coordonate p_final = new Coordonate(x1, y1);

        in.close();
        return new Object[] { n, p_start, p_final };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        Coordonate p_start = (Coordonate) input[1];
        Coordonate p_final = (Coordonate) input[2];

        L05P04 tabla = new L05P04(n, p_start, p_final);
        tabla.Back();
        // tabla.CeaMaiScurta();
        tabla.ToateSolutiile();
    }
}
