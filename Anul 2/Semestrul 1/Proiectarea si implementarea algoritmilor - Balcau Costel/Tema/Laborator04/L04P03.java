import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;
import java.util.stream.Collectors;

/*
Se citesc denumirile a n culori.
Sa se alcatuiasca toate steagurile tricolore posibile astfel incat in mijloc sa se afle doar una din ultimele doua culori citite.
Se va afisa pe fiecare rand: numarul drapelului: culoare 1, culoare 2, culoare 3.

Exemplu:
n=4 si c=(rosu, albastru, galben, alb)
=>  1: (rosu,galben,albastru),
=>  2: (rosu,galben, alb),
=>  3: (rosu,alb,albastru),
=>  4: (rosu,alb,galben),
=>  5: (albastru,galben,rosu),
=>  6: (albastru,galben,alb),
=>  7: (albastru,alb,rosu),
=>  8: (albastru,alb,galben),
=>  9: (galben,alb,rosu),
=> 10: (galben,alb,albastru),
=> 11: (alb,galben,rosu),
=> 12: (alb, galben, albastru).
*/

public class L04P03 {

    private int[] x;
    private String[] colors;
    private int n;
    private List<ArrayList<Integer>> solutii = null;

    public L04P03(int n, String[] colors) {
        this.n = n;
        this.colors = colors;
        x = new int[n + 1];
        solutii = new ArrayList<>();
    }

    public void AfisareSolutii() {
        System.out.println("\nAfisare Solutii:");
        int i = 0;

        for (ArrayList<Integer> solutie : solutii) {
            String output = solutie.stream().map(x -> colors[x]).filter(Objects::nonNull).collect(Collectors.toList())
                    .toString();

            System.out.println((++i) + ": " + output);
        }

    }

    private void Stocare() {
        ArrayList<Integer> solutie = new ArrayList<>();
        for (int i = 1; i <= n; i++)
            solutie.add(x[i]);
        solutii.add(solutie);
    }

    private boolean Valid(int k) {
        if (x[k - 1] == x[k])
            return false;
        if (k == 2)
            return (x[k] == n || x[k] == n - 1);
        if (k == 3)
            return !(x[1] == x[3]);
        return true;
    }

    public void Back() {
        int k = 1;

        while (k > 0)
            if (x[k] < n) {
                x[k] += 1;
                if (Valid(k))
                    if (k == 3)
                        Stocare();
                    else {
                        k++;
                        x[k] = 0;
                    }
            } else
                k--;
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de culori n = ");
        int n = in.nextInt();
        in.nextLine();

        System.out.print("Dati denumirile culorilor (separate prin ,): ");
        String line = in.nextLine();
        String[] colors = new String[n + 1];

        for (int i = 1; i <= n; i++)
            colors[i] = line.split(",")[i - 1].trim();

        in.close();
        return new Object[] { n, colors };
    }

    public static void main(String[] args) {
        Object[] date = CitireDateConsola();
        int n = (int) date[0];
        String[] colors = (String[]) date[1];

        L04P03 cs = new L04P03(n, colors);
        cs.Back();
        cs.AfisareSolutii();
    }
}
