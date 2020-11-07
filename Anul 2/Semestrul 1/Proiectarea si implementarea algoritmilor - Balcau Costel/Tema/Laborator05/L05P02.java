import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Problema nebunilor pe tabla de sah.

public class L05P02 {
   
    private int[] x;
    private int n;
    private List<ArrayList<Integer>> solutii = null;

    public L05P02(int n){
        this.n = n;
        x = new int[n+1];
        solutii = new ArrayList<>();
    }

    private void AfisareSolutii() {
        System.out.println("\nAfisare Solutii:");

        int count = 0;

        for (ArrayList<Integer> solutie : solutii)
            System.out.println((++count) + ": " + solutie.subList(1,n).toString());
    }
    
    private void Stocare() {
        ArrayList<Integer> solutie = new ArrayList<>();
        for (int i = 0; i <= n; i++)
            solutie.add(x[i]);
        solutii.add(solutie);
    }

    private void CleanSolutii(){
        solutii = new ArrayList<>();
    }

    private void CleanX(){
        for(int i=0; i<=n; i++)
            x[i] = 0;
    }

    public void AfisareSolutiiN1(){
        System.out.println("\nDiagonala Neagra");
        AfisareSolutii();
    }

    private boolean Valid1(int k){
        for(int i=1; i<=k-1; i++)
            if(x[k]-x[i] == k-i)
                return false;
        return true;
    }

    private void Nebuni1(){
        int k = 1;
        CleanX();
        CleanSolutii();
        int ult = 2;

        while(k>0)
            if(x[k] < ult){
                x[k]++;
                if(Valid1(k))
                    if(k==n-1)
                        Stocare();
                else{
                    k++;
                    if(k<=n/2){
                        x[k] = 0;
                        ult = 2*k;
                    }
                    else{
                        x[k] = 2*k - n;
                        ult = n;
                    }
                }
            }
            else{
                k--;
                if(k<=n/2)
                    ult = 2*k;
                else
                    ult = n;
            }

    }

    public void AfisareSolutiiN2() {
        System.out.println("\nDiagonala Alba");
        AfisareSolutii();
    }

    private boolean Valid2(int k){
        if(x[k] == k)
            return false;
        for(int i=2; i<=k-1; i++)
            if(x[k] - x[i] == k - i)
                return false;
        return true;
    }

    public void Nebuni2(){
        int k = 2;
        CleanX();
        CleanSolutii();
        int ult = 3;
        while(k > 1)
            if(x[k] < ult){
                x[k]++;
                if(Valid2(k))
                    if(k==n-1){
                        x[1] = 1;
                        Stocare();
                        x[1] = n;
                    }
                    else{
                        k++;
                        if(k<=(n+1)/2){
                            x[k] = 0;
                            ult = 2*k - 1;
                        }else{
                            x[k] = 2*k - n - 1;
                            ult = n;
                        }
                    }
            }
            else{
                k--;
                if(k<=(n+1)/2)
                    ult = 2*k-1;
                else
                    ult = n;
            }
    }

    public static Object[] CitireDateConsola(){
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de dame n = ");
        int n = in.nextInt();

        in.close();
        return new Object[] { n };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
    
        L05P02 tabla = new L05P02(n);
        // Diagonala Neagra
        tabla.Nebuni1();
        tabla.AfisareSolutiiN1(); 

        // Diagonala Alba
        tabla.Nebuni2();
        tabla.AfisareSolutiiN2();
   } 
}
