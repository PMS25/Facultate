import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Compuneri ale unui numar natural
// Exemplu: m = 4 ; n = 3
// 4 = 0+0+4 = 0+1+3 = 0+2+2 = 0+3+1 = 0+4+0
//   = 1+0+3 = 1+1+2 = 1+2+1 = 1+3+0 = 2+0+2
//   = 2+1+1 = 2+2+0 = 3+0+1 = 3+1+0 = 4+0+0.

public class L07P04 {

    private int n, m, x[];
    private List<ArrayList<Integer>> solutii;

    public L07P04(int n, int m) {
        this.n = n;
        this.m = m;
        x = new int[n + 1];
        solutii = new ArrayList<>();
    }

    public void CleanSolutii() {
        solutii.clear();
        for (int i = 1; i <= n; i++)
            x[i] = 0;
    }

    public void Afisare() {
        int count = 0;
        System.out.println("\nAfisare solutii:");
        for (ArrayList<Integer> solutie : solutii)
            System.out.printf("%d: %s\n", ++count, solutie.subList(1, n + 1));
    }

    private void Stocare() {
        ArrayList<Integer> solutie = new ArrayList<>();
        for (int i = 0; i <= n; i++)
            solutie.add(x[i]);
        solutii.add(solutie);
    }

    public void Compuneri1() {
        CleanSolutii();
        x[1] = -1;
        int k = 1, s = 0;
        while (k > 0)
            if (x[k] < m - s) {
                x[k]++;
                if (k == n - 1) {
                    x[n] = m - s - x[k];
                    Stocare();
                } else {
                    s += x[k];
                    k++;
                    x[k] = -1;
                }
            } else {
                k--;
                s -= x[k];
            }
    }

    public void Compuneri2() {
        CleanSolutii();
        x[1] = -1;
        int k = 1, s = 0;
        while (k > 0)
            if (k <= n - 1) {
                if (x[k] < m - s) {
                    x[k]++;
                    s += x[k];
                    k++;
                    x[k] = -1;
                } else {
                    k--;
                    s -= x[k];
                }
            } else {
                x[n] = m - s;
                Stocare();
                k--;
                s -= x[k];
            }
    }

    public void Compuneri_Cu_Termeni_Nenuli(){
        CleanSolutii();
        x[1] = 0;
        int k = 1, s = 0;
        while(k > 0)
            if(k <= n-1){
                if(x[k] < m - n + k - s){
                    x[k]++;
                    s+=x[k];
                    k++;
                    x[k] = 0;
                }else{
                    k--;
                    s -= x[k];
                }
            }else{
                x[n] = m - s;
                Stocare();
                k--;
                s-=x[k];
            }
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati nr de termeni n = ");
        int n = in.nextInt();

        System.out.print("Dati suma m = ");
        int m = in.nextInt();

        in.close();
        return new Object[] { n, m };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int m = (int) input[1];
        L07P04 obj = new L07P04(n, m);
        obj.Compuneri1();
        obj.Afisare();
        obj.Compuneri2();
        obj.Afisare();
        obj.Compuneri_Cu_Termeni_Nenuli();
        obj.Afisare();
    }
}
