import java.util.Scanner;

// Se citeste de la tastatura un sir de n numere naturale.
// Sa se scrie un program care afiseaza:
// - cea mai lunga secventa
// - cel mai lung subsir
// al sirului dat cu proprietatea ca suma elementelor sale este divizibila cu 3.
// Exemplu: Pentru sirul (5,8,3,12,4,1,2,8,6,4,2)
// - o secventa de lungime maxima este (8,3,12,4,1,2,8,6,4)
// - cel mai lung subsir al sirului (2,3,5,7,9,0,14) este (2,3,5,9,0,14).


class L12P03{


    public L12P03(){
        
    }

    public static Object[] CitireDateConsola(){
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.print("Dati vectorul: ");
        int A[] = new int[n+1];
        for(int i=1; i<=n; i++)
            A[i] = in.nextInt();

        in.close();
        return new Object[]{n,A};
    }

    public static void main(String[] args) {
        Object input[] = CitireDateConsola();
        int n = (int) input[0];
        int A[] = (int[]) input[1];

    }
}