import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Problema celor n dame pe tabla de sah.

// TO DO: Afisare, in fisier, sub forma unei table de sah.

public class L05P01{

    private int[] x;
    private int n;
    private List<ArrayList<Integer>> solutii = null;

    public L05P01(int n){
        this.n = n;
        this.x = new int[n+1];
        solutii = new ArrayList<>();
    }

    private void AfisareSolutii(){
        System.out.println("\nAfisare Solutii:");

        int count = 0;

        for (ArrayList<Integer> solutie : solutii)
            System.out.println((++count) + ": " + solutie.subList(1,n+1).toString());
    }

    private void Stocare(){
        ArrayList<Integer> solutie = new ArrayList<>();
        for (int i = 0; i <= n; i++)
            solutie.add(x[i]);
        solutii.add(solutie);
    }

    private boolean Valid(int k){
        for(int i=1; i<k; i++)
            if(x[k] == x[i] || k - i == Math.abs(x[k] - x[i]))
                return false;
        return true;
    }

    private void CleanX(){
        for(int i=0; i<=n; i++)
            x[i] = 0;
    }

    public void Dame(){
        int k = 1;
        CleanX();
        while(k > 0)
            if( x[k] < n ){
                x[k]++;
                if(Valid(k))
                    if(k == n){
                        Stocare();
                        k--;
                    }
                    else{
                        k++;
                        x[k] = 0;
                    }
            }
            else
                k--;
    }


    public static Object[] CitireDateConsola(){
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de dame n = ");
        int n = in.nextInt();

        in.close();
        return new Object[] {n};
    } 

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];

        L05P01 tabla = new L05P01(n);
        tabla.Dame();
        tabla.AfisareSolutii();
    }
}