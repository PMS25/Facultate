import java.util.Scanner;

// Inmultirea numerelor mari - algoritmul Karatsuba.

public class L11P02 {

    public static int LungimeNumar(long nr) {
        int k = 0;
        do {
            k++;
            nr /= 10;
        } while (nr != 0);
        return k;
    }

    public static long Karatsuba(long x, long y) {
        int xLength = LungimeNumar(x);
        int yLength = LungimeNumar(y);
        int maxLength = Math.max(xLength, yLength);

        // Calculare valori mici
        if (maxLength < 16)
            return x * y;

        // Rotunjire lungime maxima
        maxLength = (maxLength / 2) + (maxLength % 2);

        // Multiplicator
        long maxLengthTen = (long) Math.pow(10, maxLength);

        // Calculare expresiile
        long b = x / maxLengthTen;
        long a = x - (b * maxLengthTen);
        long d = y / maxLengthTen;
        long c = y - (d * maxLengthTen);

        long z0 = Karatsuba(a, c);
        long z1 = Karatsuba(a + b, c + d);
        long z2 = Karatsuba(b, d);

        return z0 + ((z1 - z0 - z2) * maxLengthTen) + (long) (Math.pow(10, 2 * maxLength));
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati x = ");
        long x = in.nextLong();

        System.out.print("Dati y = ");
        long y = in.nextLong();

        in.close();
        return new Object[] { x, y };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        long x = (long) input[0];
        long y = (long) input[1];
        System.out.printf("Produs: %d\n", Karatsuba(x, y));
    }
}
