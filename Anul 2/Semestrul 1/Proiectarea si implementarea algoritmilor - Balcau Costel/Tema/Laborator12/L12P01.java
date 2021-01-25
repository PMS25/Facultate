import java.util.Scanner;

// Sirul numerelor lui Fibonacci

class L12P01 {

    // Varianta top-down
    public static int Fibonacci1(int n) {
        if (n <= 1)
            return n;
        return Fibonacci1(n - 1) + Fibonacci1(n - 2);
    }

    // Varianta top-down folosind tehnica memorizarii
    public static int Fibonacci2(int n, int t[]) {
        if (n <= 1)
            return n;
        if (t[n] != 0)
            return t[n];
        t[n] = Fibonacci2(n - 1, t) + Fibonacci2(n - 2, t);
        return t[n];
    }

    // Varianta bottom-up, folosind un vector F pentru memorarea numerelor lui
    // Fibonacci
    public static int Fibonacci3(int n) {
        int[] F = new int[n + 1];
        F[0] = 0;
        F[1] = 1;
        for (int i = 2; i <= n; i++)
            F[i] = F[i - 1] + F[i - 2];
        return F[n];
    }

    // Varianta bottom-up, folosind doar trei variabile a, b, c
    public static int Fibonacci4(int n) {
        if (n <= 1)
            return n;
        int a = 0, b = 1, c = 0;
        for (int i = 2; i <= n; i++) {
            c = b + a;
            a = b;
            b = c;
        }
        return c;
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);
        System.out.print("Dati n = ");
        int n = in.nextInt();
        in.close();
        return new Object[] { n };
    }

    public static void main(String[] args) {
        int n = (int) CitireDateConsola()[0];
        int t[] = new int[n + 1];

        int f1 = Fibonacci1(n);
        int f2 = Fibonacci2(n, t);
        int f3 = Fibonacci3(n);
        int f4 = Fibonacci4(n);

        System.out.printf("Termenul %d din sirul lui Fibonacci: \n", n);
        System.out.printf("1: %d \n2: %d \n3: %d \n4: %d\n", f1, f2, f3, f4);
    }
}