import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
Se considera - un graf neorientat fara bucle G = (V, E), cu 
             - multimea nodurilor V = {1, 2, . . . , n},
             - un numar de m culori, numerotate cu 1, 2, . . . , m.
Se cere sa se determine toate modalitatile de colorare ale nodurilor grafului, utilizand cele m culori,
astfel incat oricare doua _muchii_ adiacente sa fie colorate cu culori diferite.

Exemplu 1:
- n = 6 (nr noduri)
- c = 4 (nr culori)
- A: 
0 1 0 1 0 1
1 0 1 1 1 0
0 1 0 0 1 1
1 1 0 0 1 1
0 1 1 1 0 1
1 0 1 1 1 0


Exemplu 2:
- n = 6 (nr noduri)
- c = 4 (nr culori)
- A: 
0 1 1 0 1 1
1 0 1 0 1 0
1 1 0 1 0 1
0 0 1 0 1 0
1 1 0 1 0 1
1 0 1 0 1 0
*/

public class L04P02 {

    private int[] x;
    private int[][] a;
    private int n, m, c;
    int[][] muchii = null;
    private List<ArrayList<Integer>> solutii = null;

    public L04P02(int n, int c, int[][] a) {
        this.n = n;
        this.c = c; // nr culori
        this.a = a;
        m = NumarMuchii();
        x = new int[m+1];
        solutii = new ArrayList<>();
        LoadMuchii();
    }

    public void AfisareSolutii() {
        System.out.println("\nAfisare Solutii:");
        
        for(int i=1; i<=m; i++)
            System.out.println(muchii[i][1] + " : " + muchii[i][2]);

        int i = 0;

        for (ArrayList<Integer> solutie : solutii)
            System.out.println((++i) + ": " + solutie.toString());
    }

    private int NumarMuchii(){
        int s = 0;
        for(int i=2; i<=n; i++)
            for(int j=1; j<i; j++)
                s+=a[i][j];
        return s;
    }

    private void LoadMuchii(){
        muchii = new int[m+1][3];
        int k = 0;
        for(int i=2; i<=n; i++)
            for(int j=1; j<i; j++)
                if(a[i][j] == 1){
                    ++k;
                    muchii[k][1] = i;
                    muchii[k][2] = j;
                }
    }

    private void Stocare() {
        ArrayList<Integer> solutie = new ArrayList<>();
        for (int i = 1; i <= m; i++)
            solutie.add(x[i]);
        solutii.add(solutie);
    }

    private boolean Valid(int k) {
        for (int i = 1; i <= k - 1; i++)
            if(muchii[i][1] == muchii[k][1] || muchii[i][1] == muchii[k][2] ||
               muchii[i][1] == muchii[k][1] || muchii[i][2] == muchii[k][2])
                if (x[i] == x[k])
                    return false;
        return true;
    }

    public void Back() {
        int k = 1;

        while (k > 0)
            if (x[k] < c) {
                x[k] += 1;
                if (Valid(k))
                    if (k == m)
                        Stocare();
                    else {
                        k++;
                        x[k] = 0;
                    }
            } else
                k--;
    }

    public static Object[] CitireDateConsola(){
        Scanner in = new Scanner(System.in);

        System.out.print("Nr de noduri n = ");
        int nn = in.nextInt();

        System.out.print("Nr de culori c = ");
        int nc = in.nextInt();

        System.out.println("Dati matricea de adiacenta (" + nn + "x" + nn + "): ");
        int[][] A = new int[nn + 1][nn + 1];
        for (int i = 1; i <= nn; i++)
            for (int j = 1; j <= nn; j++)
                A[i][j] = in.nextInt();

        in.close();
        return new Object[] { nn, nc, A };
    }

    public static void main(String[] args) {
        Object[] date = CitireDateConsola();
        int n = (int) date[0];
        int c = (int) date[1];
        int[][] A = (int[][]) date[2];

        L04P02 cg = new L04P02(n, c, A);
        cg.Back();
        cg.AfisareSolutii();
    }
}


