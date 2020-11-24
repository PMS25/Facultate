import java.util.Scanner;

// Generalizati problema turnurilor din Hanoi pentru 2 tije de manevra. Enuntul ar suna astfel:
// Se dau 4 tije (1,2,3,4) si n discuri de diametre diferite.
// Initial, toate discurile sunt plasate pe tija 1 in ordinea descrescatoare a diametrelor, de la baza la varf.

// Problema cere sa se mute discurile de pe tija 1 -> tija 2, folosind ca tije de manevra tijele 3 si 4 si respectand regulile:
// - la fiecare pas se muta un singur disc,
// - un disc poate fi asezat peste alt disc mai mare sau poate fi primul disc de la baza tijei.

public class L08P03 {

    private int m, i, j;

    public L08P03(int m, int i, int j) {
        this.m = m;
        this.i = i;
        this.j = j;
    }

    private void Afisare(int d, int i, int j) {
        System.out.printf("Mutam discul %d de la tija %d la tija %d.\n", d, i, j);
    }

    private void Hanoi(int m, int t1, int t2, int a1, int a2) {
        if (m == 0)
            return;
        if (m == 1)
            Afisare(1, i, j);
        else {
            Hanoi(m - 2, t1, a1, a2, t2);
            Afisare(m - 1, t1, a2);
            Afisare(m, t1, t2);
            Afisare(m - 1, a2, t2);
            Hanoi(m - 2, a1, t2, t1, a2);
        }
    }

    public void Hanoi() {
        int a1 = -1, a2 = 0;
        for (int k = 1; k <= 4; k++)
            if (k != i && k != j)
                if (a1 == a2)
                    a2 = k;
                else
                    a1 = a2 = k;
        Hanoi(m, i, j, a1, a2);
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

        L08P03 obj = new L08P03(m, i, j);
        obj.Hanoi();
    }

}
