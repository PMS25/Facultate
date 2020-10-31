import java.util.Scanner;

// Se citeste n numar natural de maxim 9 cifre de la tastatura. 
// Sa se afiseze o piramida formata din cifrele acestui numar astfel:
// - pe linia 1 - cifra/cifrele din mijloc
// - ...
// - pe ultima linie - numarul intreg n
// Se va asigura aspectul de triunghi isoscel plin al figurii!

public class Problema04 {
    
    public static int Length(int n){
        int k = 0;
        do{
            k++;
            n/=10;
        }while(n != 0);
        return k;
    }

    public static int Crop(int n, int l, int c){
        int crop_start = (int) Math.pow(10,l-c);
        int crop_final = (int) Math.pow(10,c);
        return (n % crop_start) / crop_final;
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        
        System.out.print("n = ");
        int n = cin.nextInt();
        int l = Length(n);
        
        for(int i=l/2-(l+1)%2; i>=1; i--)
            System.out.println(" ".repeat(i-1) + Crop(n,l,i));
        cin.close();
    }
}
