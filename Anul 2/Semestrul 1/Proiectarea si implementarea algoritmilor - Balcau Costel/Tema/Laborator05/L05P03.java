import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Pe o tabla de sah de dimensiune n se afla un cal in pozitia (x0 , y0).
// Cunoscand de cate ori trece calul prin fiecare casuta a tablei, afisati toate posibilitatile calului
// de a parcurge aceasta tabla de sah.
// Exemplu: Daca n = 5, x0 = 1, y0 = 1 iar numarul de treceri prin fiecare casuta este dat de matricea
// | 1 0 2 0 0
// | 2 0 1 0 0
// | 0 1 1 1 0
// | 0 1 0 0 1
// | 0 0 2 0 0
// atunci una dintre solutii (exista 31 de astfel de solutii):
// (1,1); (2,3); (4,2); (2,1); (1,3); (2,1); (1,3); (3,4); (5,3); (3,2); (5,3); (4,5); (3,3).

public class L05P03 {
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

    private int n, ng, x[], M[][];
    private Coordonate T[], mutari[];
    private List<ArrayList<Coordonate>> solutii;

    L05P03(int n, Coordonate p_start, int[][] M) {
        this.n = n;
        this.M = M;
        ng = LungimeBack();
        x = new int[ng + 1];
        T = new Coordonate[ng + 1];
        T[0] = p_start;
        Initializare_Mutari();
        solutii = new ArrayList<>();
    }

    public void ToateSolutiile() {
        for (int i = 0; i < solutii.size(); i++)
            System.out.printf("%d : %s\n", i + 1, solutii.get(i).subList(0, ng));
    }

    private int LungimeBack() {
        int s = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                s += M[i][j];
        return s;
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

    // Backtracking
    private void Stocare() {
        ArrayList<Coordonate> solutie = new ArrayList<>();
        for (int i = 0; i <= ng; i++)
            solutie.add(T[i]);
        solutii.add(solutie);
    }

    private boolean Valid(int k) {
        // E pe Tabla
        if (!(T[k].x >= 1 && T[k].x <= n && T[k].y >= 1 && T[k].y <= n))
            return false;
        // E pe Pozitie Nepotrivita
        if (M[T[k].x][T[k].y] < 1)
            return false;
        return true;
    }

    public void Back() {
        int k = 1;
        while (k > 0) {
            if (k == ng) {
                Stocare();
                k--;
            } else if (x[k] <= 7) {
                x[k]++;
                T[k] = T[k - 1].add(mutari[x[k]]);
                if (Valid(k)) {
                    k++;
                    M[T[k - 1].x][T[k - 1].y]--;
                }
            } else {
                M[T[k - 1].x][T[k - 1].y]++;
                x[k--] = 0;
            }
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

        System.out.println("Dati matricea cu numarul de treceri: ");
        int M[][] = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                M[i][j] = in.nextInt();

        in.close();
        return new Object[] { n, p_start, M };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        Coordonate p_start = (Coordonate) input[1];
        int[][] M = (int[][]) input[2];

        L05P03 tabla = new L05P03(n, p_start, M);

        tabla.Back();
        tabla.ToateSolutiile();
    }
}
