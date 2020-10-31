// Se da n numar natural mai mic sau egal cu 15.
// Afisati valoarea sumei 1! + 2! +...+ n!. 

import java.util.Scanner;

public class R04 {
    static int n;

    static int factorial(int k) {
        if (k == 1)
            return 1;
        return factorial(k - 1) * k;
    }

    public static void main(String[] args) {
        int i, s = 0;
        Scanner in = new Scanner(System.in);
        System.out.print("n=");
        n = in.nextInt();
        in.close();
        for (i = 1; i <= n; i++)
            s += factorial(i);
        System.out.print(s);
    }
}