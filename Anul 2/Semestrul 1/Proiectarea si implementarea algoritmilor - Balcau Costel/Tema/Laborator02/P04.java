// Se da un tablou patratic de dimensiune n cu componente nr nat <= 10000, 1<=n<=100.
// Afisati pentru fiecare linie cel mai mare / mic numar separate prin cate un spatiu.

import java.util.Scanner;

public class P04 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int a[][], n;
        n = cin.nextInt();
        a = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = cin.nextInt();
        cin.close();


        for(int i=1; i<=n; i++){
            int minim = a[i][1], maxim = a[i][1];
            for(int j=2; j<=n; j++){
                if(a[i][j] < minim)
                    minim = a[i][j];
                if (a[i][j] > maxim)
                    maxim = a[i][j];
            }
            System.out.print("Linie " + i + ": ");
            System.out.println("min: " + minim + " ; max: " + maxim);
        }
    }
}
