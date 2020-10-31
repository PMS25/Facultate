import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

/*
Fie n segmente situate pe o aceeasi dreapta, numerotate distinct, de la 1 la n.
Sa se scrie un program care determina numarul minim de culori necesare pentru a colora cele n segmente
astfel incat oricare doua segmente care se intersecteaza sa fie colorate diferit si, de asemenea, sa se determine o astfel de colorare.
Pentru fiecare segment de dreapta se da extremitatea initiala a segmentului si lungimea sa.

Exemplu:
Pentru n=5, extremitatile initiale (9,2,3,1,11) si lungimile (3,4,6,3,4) se obtine solutia:
Segmentul 1 culoarea 1,
Segmentul 2 culoarea 2,
Segmentul 3 culoarea 3,
Segmentul 4 culoarea 1,
Segmentul 5 culoarea 2.
Exista 36 de solutii.
*/

public class L04P04 {

    private int[] x, start, lungimi;
    private int n;
    private List<ArrayList<Integer>> solutii = null;

    public L04P04(int n, int[] start, int[] lungimi) {
        this.n = n;
        this.start = start;
        this.lungimi = lungimi;
        x = new int[n + 1];
        solutii = new ArrayList<>();
    }

    public void AfisareSolutii() {
        System.out.println("\nAfisare Solutii:");
        int i = 0;

        for (ArrayList<Integer> solutie : solutii) {
            System.out.println((++i) + ": " + solutie);
        }

    }

    private void Stocare() {
        ArrayList<Integer> solutie = IntStream.of(x).boxed().collect(Collectors.toCollection(ArrayList::new));
        solutii.add(solutie);
    }

    private boolean Valid(int k) {
        boolean[] check = new boolean[n+1];
        for (int i = 1; i <= k; i++)
            check[x[i]] = true;
        for (int i = 1; i < k; i++)
            if(check[i] == false && check[i+1] == true)
                return false;
        

        for (int i = 0; i < k-1; i++)
            if( start[i] < start[k-1] && start[k-1] < start[i] + lungimi[i] ||
                start[k-1] < start[i] && start[i] < start[k-1] + lungimi[k-1]
            )
                if( x[i+1] == x[k])
                    return false;
        return true;
    }

    public void Back() {
        int k = 1;

        while (k > 0)
            if (x[k] < k) {
                x[k] += 1;
                if (Valid(k))
                    if (k == n)
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

        System.out.print("Dati nr de segmente n = ");
        int n = in.nextInt();
        in.nextLine();

        System.out.print("Dati extremitatile initiale (separate prin ,): ");
        String line1 = in.nextLine();

        System.out.print("Dati lungimea segmentelor (separate prin ,): ");
        String line2 = in.nextLine();

        int[] extremitati = Stream.of(line1.split(","))
                                  .map(String::trim)
                                  .map(Integer::parseInt)
                                  .mapToInt(Integer::intValue)
                                  .toArray();

        int[] lungimi = Stream.of(line2.split(","))
                              .map(String::trim)
                              .map(Integer::parseInt)
                              .mapToInt(Integer::intValue)
                              .toArray();

        in.close();
        return new Object[] { n, extremitati, lungimi };
    }

    public static void main(String[] args) {
        Object[] date = CitireDateConsola();
        int n = (int) date[0];
        int[] start = (int[]) date[1];
        int[] lungimi = (int[]) date[2];

        for(int i=0; i<n; i++)
            System.out.print(start[i] + " ");
        System.out.println();

        for (int i = 0; i < n; i++)
            System.out.print(lungimi[i] + " ");
        System.out.println();

        L04P04 sg = new L04P04(n, start, lungimi);
        sg.Back();
        sg.AfisareSolutii();
    }
}