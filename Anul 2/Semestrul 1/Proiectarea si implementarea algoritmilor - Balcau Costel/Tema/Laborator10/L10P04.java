import java.util.Scanner;

// Se da un vector cu n numere intregi.
// Se imparte tabloul in trei grupe (echilibrate ca dimensiune),
// eliminandu-se in fiecare grup mijlocul/mijloacele (pentru grupele cu nr par de elemente).
// Se repeta procedeul pentru fiecare din cei sase subvectori obtinuti
// (din fiecare din cele trei grupe se obtin dupa eliminarea mijlocului/mijloacelor doi subvectori).
// Procedeul se repeta de p ori. Sa se afiseze vectorul obtinut dupa terminarea algoritmului.
// Exemplu: Pentru n = 50 si x[i] = i, p = 2 se va obtine in final vectorul
// x = (5,7,14,16,19,21,22,24,28,30,31,33,36,38,39,41,45,48,50).
// Solutie Program: 1,3,5,7,10,12,14,16,17,19,22,24,26,28,31,33,34,36,39,41,43,45,48,50

public class L10P04 {

    private int n, p, V[];

    public L10P04(int n, int p) {
        this.n = n;
        this.p = p;
        this.V = new int[n + 1];
    }

    public void Grupe(int s, int d, int p) {
        if (p == 0 || s >= d)
            return;
        int k = d - s + 1;
        int m = (s + d) / 2;
        if (k % 2 == 0) {
            V[m] = -1;
            V[m + 1] = -1;
            Grupe(s, m - 1, p - 1);
            Grupe(m + 2, d, p - 1);
        } else {
            V[m] = -1;
            Grupe(s, m - 1, p - 1);
            Grupe(m + 1, d, p - 1);
        }
    }

    public void StartGrupe() {
        int m1 = n / 3;
        int m2 = (n + m1) / 2;

        Grupe(1, m1, p + 1);
        Grupe(m1 + 1, m2, p + 1);
        Grupe(m2 + 1, n, p + 1);

        System.out.println("Solutie:");
        for (int i = 1; i <= n; i++)
            if (V[i] == 0)
                System.out.printf("%d, ", i);
        System.out.println("\b\b ");
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.print("Dati p = ");
        int p = in.nextInt();

        in.close();
        return new Object[] { n, p };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int p = (int) input[1];

        L10P04 obj = new L10P04(n, p);
        obj.StartGrupe();
    }
}
