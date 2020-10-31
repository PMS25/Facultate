
// Determinarea maximului si minimului dintr-un vector.
// Evaluati complexitatea algoritmilor implementati.

import java.util.Scanner;

public class L03R03 {

    private int n;
    private int[] lista;
    private int Minim, Maxim;

    public L03R03(int[] lista){
        this.lista = lista;
        n = lista.length;
        MinMaxPer();
    }

    public void MinMax(){
        Minim = lista[0];
        Maxim = lista[0];
        for(int i=1; i<n; i++)
            if(lista[i] > Maxim)
                Maxim = lista[i];
            else
                if(lista[i] < Minim)
                    Minim = lista[i];
    }

    public void MinMaxPer(){
        Maxim = lista[n-1];
        Minim = lista[n-1];

        // Caz special pentru i = 0
        Maxim = Math.max(lista[0], Maxim);
        Minim = Math.min(lista[0], Minim);

        for(int i=1; i<n/2; i++)
            if(lista[2*i-1] > lista[2*i]){
                if(lista[2*i-1] > Maxim)
                    Maxim = lista[2*i-1];
                if(lista[2*i] < Minim)
                    Minim = lista[2*i];
            }else{
                if(lista[2*i] > Maxim)
                    Maxim = lista[2*i];
                if(lista[2*i-1] < Minim)
                    Minim = lista[2*i-1];
            }
    }

    public void Afisare(){
        System.out.printf("Minim: %d ; Maxim: %d \n", Minim, Maxim);
    }

    public static Object[] CitireDateConsola(){
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de elemente n = ");
        int n = in.nextInt();

        int[] lista = new int[n];
        System.out.println("Elementele listei: ");
        for(int i=0; i<n; i++)
            lista[i] = in.nextInt();

        in.close();
        return new Object[] {lista};
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int[] lista = (int[]) input[0];

        L03R03 r = new L03R03(lista);
        r.Afisare();
    }
}