
// Problema planificarii spectacolelor.

import java.util.Scanner;
import java.util.stream.Stream;

public class L03P04 {

    public static class Spectacol {
        public double start = 0, finis = 0;
        public String denumire;

        public Spectacol(String denumire) {
            this.denumire = denumire;
        }
    }

    private int n, m;
    public Spectacol[] date;
    private int[] c;

    public L03P04(Spectacol[] date) {
        this.date = date;
        n = date.length;
        c = new int[n];
    }

    public void Sortare1() {
        // Crescator, dupa ore de inchidere
        date = Stream.of(date).sorted((Spectacol o1, Spectacol o2) -> {
            if (o1.finis < o2.finis) return -1;
            else if (o1.finis > o2.finis) return 1;
            return 0;
        }).toArray(Spectacol[]::new);
    }

    public void Sortare2() {
        // Crescator, dupa ore de incepere
        date = Stream.of(date).sorted((Spectacol o1, Spectacol o2) -> {
            if (o1.start < o2.start) return -1;
            else if (o1.start > o2.start) return 1;
            return 0;
        }).toArray(Spectacol[]::new);
    }

    public void Afisare() {
        System.out.printf("Spectacole selectate: %d\n", m);
        for (int i = 0; i < n; i++)
            if (c[i] == 1)
                System.out.printf("%s: %.2f : %.2f \n", date[i].denumire, date[i].start, date[i].finis);
    }

    void Greedy1() {
        Sortare1();
        double t = date[0].start - 1;

        for (int i = 0; i < n; i++)
            if (date[i].start > t) {
                m++;
                c[i] = 1;
                t = date[i].finis;
            }
        Afisare();
    }

    void Greedy2() {
        Sortare2();
        double t = date[n - 1].finis - 1;

        for (int i = n - 1; i >= 0; i--)
            if (date[i].finis < t) {
                m++;
                c[i] = 1;
                t = date[i].start;
            }
        Afisare();
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de spectacole n = ");
        int n = in.nextInt();
        in.nextLine();

        System.out.println("Dati ora de inceput / sfarsit separate prin ;");
        Spectacol[] date = new Spectacol[n];
        for (int i = 0; i < n; i++) {
            date[i] = new Spectacol("S" + (i + 1));
            System.out.printf("%s: ", (i + 1));
            String[] line = in.nextLine().replace(",", ".").split(";");
            date[i].start = Double.parseDouble(line[0].trim());
            date[i].finis = Double.parseDouble(line[1].trim());
        }

        in.close();
        return new Object[]{date};
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        Spectacol[] date = (Spectacol[]) input[0];

        L03P04 sp = new L03P04(date);
        sp.Greedy1();
    }
}
