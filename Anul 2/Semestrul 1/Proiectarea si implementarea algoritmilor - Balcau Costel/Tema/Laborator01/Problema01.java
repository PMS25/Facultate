// Se dau de la tastatura 2 cifre nenule a si b.
// Sa se afiseze pe ecran cele 2 numere care se pot forma cu acestea, in ordine crescatoare.
// Ex1: a=5 si b=2 => 25 52
// Ex2: a=0 si b=3 => 3 30

import java.util.Scanner;

public class Problema01 {
    
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        System.out.print("a = "); int a = cin.nextInt();
        System.out.print("b = "); int b = cin.nextInt();
        System.out.printf("%d %d \n", (a>b ? b*10+a:a*10+b), (a>b ? a*10+b:b*10+a));
        cin.close();
    }
}
