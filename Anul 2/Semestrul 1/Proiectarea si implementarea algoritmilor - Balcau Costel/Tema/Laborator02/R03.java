// Se da n numar natural cu cel mult 9 cifre.
// Afisati numerele palindrom mai mici sau egale cu n. 

import java.util.Scanner;

public class R03 {
    static int n;
    static Scanner in = new Scanner(System.in);

    static boolean palindrom(int k) {
        int aux, c, inv;
        inv = 0;
        aux = k;
        while (aux > 0) {
            c = aux % 10;
            inv = inv * 10 + c;
            aux /= 10;
        }
        if (inv == k)
            return true;
        return false;
    }

    public static void main(String[] args) {
        System.out.print("n=");
        n = in.nextInt();
        for (int i = 0; i <= n; i++)
            if (palindrom(i))
                System.out.print(i + " ");
        in.close();
    }
}