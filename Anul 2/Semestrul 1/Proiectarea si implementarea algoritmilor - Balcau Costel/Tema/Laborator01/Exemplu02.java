// Se da n numar natural nenul cu maxim 9 cifre. Afisati suma cifrelor lui n.

import java.util.Scanner;

public class Exemplu02 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        System.out.print("n = ");
        int n = cin.nextInt();
        cin.close();

        int S = 0;
        while(n > 0) {
            S += n % 10;
            n /= 10;
        }
        System.out.println(S);
    }
}
