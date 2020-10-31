import java.util.Scanner;

// Se citeste de la tastatura un numar natural de exact 4 cifre. Sa se verifice daca numarul este:
// Echilibrat - numarul de cifre pare este egal cu numarul de cifre impare
// Pitic - toate cifrele sunt mai mici decat 4
// Generos - suma cifrelor lui e mai mare decat n+2.
// Corect - suma si produsul cifrelor sunt patrate perfecte.

public class Problema02 {

    public static boolean Echilibrat(int n){
        int p=0, i=0;
        while(n != 0){
            p += (n%10 + 1)%2;
            i += (n%10)%2;
            n /= 10;
        }
        return p == i;
    }

    public static boolean Pitic(int n){
        while(n != 0){
            if(n%10 > 3)
                return false;
            n /= 10;
        }
        return true;
    }

    public static boolean Generos(int n){
        int s = 0, cn = n;
        while(n != 0){
            s += n%10;
            n /= 10;
        }
        return s > cn+2;
    }

    public static boolean Corect(int n){
        int s = 0, p = 1;
        while (n != 0) {
            s += n % 10;
            p *= n % 10;
            n /= 10;
        }
        boolean b1 = (Math.sqrt(s) == Math.floor(Math.sqrt(s)));
        boolean b2 = (Math.sqrt(p) == Math.floor(Math.sqrt(p)));
        return b1 & b2;
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        System.out.print("n = ");
        int n = cin.nextInt();

        boolean echilibrat = Echilibrat(n);
        boolean pitic = Pitic(n);
        boolean generos = Generos(n);
        boolean corect = Corect(n);

        if(echilibrat || pitic || generos || corect){
            System.out.print("Numarul este");
            if(echilibrat)
                System.out.print(" echilibrat");
            if(pitic)
                System.out.print(" pitic");
            if(generos)
                System.out.print(" generos");
            if(corect)
                System.out.print(" corect");
        }else
            System.out.println("Numarul nu respecta criteriile.");

        cin.close();
    }
}
