import java.util.Scanner;

// Se da un vector cu n numere intregi.
// Se imparte tabloul in trei grupe (echilibrate ca dimensiune),
// eliminandu-se in fiecare grup mijlocul/mijloacele (pentru grupele cu nr par de elemente).
// Se repeta procedeul pentru fiecare din cei sase subvectori obtinuti
// (din fiecare din cele trei grupe se obtin dupa eliminarea mijlocului/mijloacelor doi subvectori).
// Procedeul se repeta de p ori. Sa se afiseze vectorul obtinut dupa terminarea algoritmului.
// Exemplu: Pentru n = 50 si x[i] = i, p = 2 se va obtine in final vectorul
// x = (5,7,14,16,19,21,22,24,28,30,31,33,36,38,39,41,45,48,50).

public class L10P04 {
    
    private int n, p, V[];

    public L10P04(int n, int p){
        this.n = n;
        this.p = p;
        this.V = new int[n+1];
    }

    public void ImparteInGrupeDe2(int s, int d, int p){
        int k = d - s + 1;
        int m = (s + d) / 2;
        if(k%2 == 0){
            V[m] = -1;
            V[m+1] = -1;
            ImparteInGrupeDe3(s, m - 1, p - 1);
            ImparteInGrupeDe3(m + 2, d, p - 1);
        }else{
            V[m] = -1;
            ImparteInGrupeDe3(s, m-1, p-1);
            ImparteInGrupeDe3(m+1, d, p-1);
        }
    }

    public void ImparteInGrupeDe3(int s, int d, int p){
        if(s >= d || p == 0)
            return;

        int k = d - s + 1;
        int i1 = s - 1 + k/3;
        int i2 = i1 + (k - k/3)/2;

        ImparteInGrupeDe2(s, i1, p);
        ImparteInGrupeDe2(i1+1, i2, p);
        ImparteInGrupeDe2(i2+1, d, p);
    }

    public void AfisareSolutie() {
        System.out.println("Solutie:");
        for (int i = 1; i <= n; i++)
            if (V[i] == 0)
                System.out.printf("%d, ", i);
        System.out.println("\b\b ");
    }

    public void Algoritm(){
        ImparteInGrupeDe3(1, n, p);
        AfisareSolutie();
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);
        System.out.print("Dati n = "); int n = in.nextInt();
        System.out.print("Dati p = "); int p = in.nextInt();
        in.close();
        return new Object[] { n, p };
    }
    
    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int p = (int) input[1];

        L10P04 obj = new L10P04(n, p);
        obj.Algoritm();
    }
}
