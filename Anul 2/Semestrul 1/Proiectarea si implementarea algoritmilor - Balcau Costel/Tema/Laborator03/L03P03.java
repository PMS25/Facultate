import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.stream.Stream;

// Problema rucsacului, varianta continua.

public class L03P03 {

    public static class Date {
        public String denumire;
        public double greutate, valoare;

        public Date() {
            greutate = 1;
            valoare = 0;
        }
    }

    private final int n, G;
    private double C = 0;
    private Date[] date;
    private double[] x;

    public L03P03(Date[] date, int G) {
        n = date.length;
        this.date = date;
        this.G = G;
        x = new double[n + 1];
    }

    public void Afisare() {
        System.out.printf("Castig total: %.2f \n", Math.round(C * 100.0) / 100.0);

        for (int i = 0; i < n && x[i] != 0; i++) {
            double cantitate = x[i] * 100;
            double valoare = x[i] * date[i].valoare;
            double raport = date[i].valoare / date[i].greutate;
            System.out.printf("I%d; Obiect: %s ; Cantitate: %.2f%% ; Valoare: %.2f ; Raport: %.2f \n",
                    i, date[i].denumire, cantitate, valoare, raport);
        }
    }

    private void Sortare() {
        date = Stream.of(date).sorted((Date o1, Date o2) -> {
            double o1_value = o1.valoare / o1.greutate;
            double o2_value = o2.valoare / o2.greutate;

            if (o1_value < o2_value) return 1;
            else if (o1_value > o2_value) return -1;
            return 0;
        }).toArray(Date[]::new);
    }

    public void Greedy() {
        Sortare();
        int R = G; // Greutate Disponibila Rucsac

        int i = 0;
        while (R > 0)
            if (date[i].greutate <= R) {
                x[i] = 1;
                C += date[i].valoare;
                R -= date[i].greutate;
                i++;
            } else {
                x[i] = R / date[i].greutate;
                C += x[i] * date[i].valoare;
                R = 0;
                for (int j = i + 1; j < n; j++)
                    x[j] = 0;
            }
        Afisare();
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de obiecte n = ");
        int n = in.nextInt();
        in.nextLine();

        System.out.print("Dati greutatea masima a rucsacului G = ");
        int G = in.nextInt();
        in.nextLine();

        Date[] date = new Date[n];

        System.out.println("Dati denumirea / greutatea / valoarea obiectelor, separate prin ;");
        for (int i = 0; i < n; i++) {
            date[i] = new Date();
            System.out.printf("%d: ", (i + 1));
            String[] line = in.nextLine().replace(",", ".").split(";");
            date[i].denumire = line[0].trim();
            date[i].greutate = Double.parseDouble(line[1].trim());
            date[i].valoare = Double.parseDouble(line[2].trim());
        }

        in.close();
        return new Object[]{date, G};
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        Date[] date = (Date[]) input[0];
        int G = (int) input[1];

        L03P03 rucsac = new L03P03(date, G);
        rucsac.Greedy();
    }
}
