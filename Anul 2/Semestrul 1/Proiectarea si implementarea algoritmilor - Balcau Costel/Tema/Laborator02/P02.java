import java.util.Scanner;

// Se dau a si b numere naturale cu maxim 9 cifre fiecare.
// Pentru fiecare numar a, b, afisati suma si produsul cifrelor nenule.

public class P02 {

    static int SumaCifreN(int n) {
        int s = 0;
        while (n != 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

    static int ProdusCifreN(int n) {
        int p = 1;
        while (n != 0) {
            p *= (n % 10 != 0 ? n % 10 : 1);
            n /= 10;
        }
        return p;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("a = ");
        int a = in.nextInt();
        System.out.print("b = ");
        int b = in.nextInt();
        in.close();

        System.out.println("Suma " + a + ": " + SumaCifreN(a));
        System.out.println("Produs " + a + ": " + ProdusCifreN(a));
        System.out.println("Suma " + b + ": " + SumaCifreN(b));
        System.out.println("Produs " + b + ": " + ProdusCifreN(b));
    }
}
