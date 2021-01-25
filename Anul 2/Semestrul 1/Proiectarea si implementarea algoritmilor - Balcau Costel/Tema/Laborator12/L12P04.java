import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

// 4. Se dau doua siruri de numere intregi.
// Sa se afiseze subsirul crescator de lungime maxima al sirului obtinut prin intercalarea, in orice mod, a sirurilor date.
// Exemplu: Pentru sirurile (3,1,4), (2,2,1,5) se obtine (1,2,2,4,5).


// 2 siruri - a si b
// scriem un subsir CRESCATOR cu Lungimea Maxima cu elemente din ambele siruri, luate in orice mod
// 3 1 4
// 2 2 1 5
// => 1 2 2 4 5

// 2 2 1 3 1 4 5
// 3 1 2 2 1 4 5

public class L12P04 {
    
    private int n, A[], m, B[];
    private int L[], P[], t[];

    public L12P04(int n, int A[], int m, int B[]){
        this.n = n;
        this.A = A;
        this.m = m;
        this.B = B;
        this.L = new int[m + n + 2];
        this.P = new int[m + n + 2];
        this.t = new int[m + n + 2];
    }

    // boolean VerificareInBDeMaxim(int j, int x){
    //     while(j>=1){
    //         if(x <= B[j])
    //             return false;
    //         j--;
    //     }
    //     return true;
    // }

    boolean VerificareDeMaxim(int S[], int i, int x) {
        while (i >= 1) {
            if (x <= S[i])
                return false;
            i--;
        }
        return true;
    }

    ArrayList<Integer> IntercalareAtoB(int n, int A[], int m, int B[]){
        ArrayList<Integer> C = new ArrayList<>();
        int i = n, j = m;
        while (j >= 1 && i >= 1) {
            if (VerificareDeMaxim(B, j, A[i]) == false) {
                C.add(B[j]);
                j--;
            } else {
                C.add(A[i]);
                i--;
            }
        }
        while (j >= 1) {
            C.add(B[j]);
            j--;
        }
        while (i >= 1) {
            C.add(A[i]);
            i--;
        }
        C.add(0);
        Collections.reverse(C);
        return C;
    }

    // void IntercalareAtoB2(){
    //     ArrayList<Integer> C = new ArrayList<>();
    //     int i = n, j = m;
    //     while(j>=1 && i >= 1){
    //         if(VerificareInBDeMaxim(j, A[i]) == false){
    //             C.add(B[j]);
    //             j--;
    //         }else{
    //             C.add(A[i]);
    //             i--;
    //         }
    //     }
    //     while (j >= 1) {
    //         C.add(B[j]);
    //         j--;
    //     }
    //     while(i>=1){
    //         C.add(A[i]);
    //         i--;
    //     }
    //     System.out.println(C.toString());
    //     Collections.reverse(C);
    //     System.out.println(C.toString());
    // }

    public void Solutie(){
        ArrayList<Integer> s1 = IntercalareAtoB(n, A, m, B);
        ArrayList<Integer> s2 = IntercalareAtoB(m, B, n, A);

        System.out.println(s1.toString());
        System.out.println(s2.toString());

        Integer[] a1 = s1.stream().toArray(Integer[]::new);
        Integer[] a2 = s2.stream().toArray(Integer[]::new);

        SubsirMax1(a1, s1.size() - 1);
        //SubsirMax1(a2, s2.size() - 1);
    }

    private void Clean() {
        for (int i = 0; i <= n + m + 1; i++)
            L[i] = P[i] = t[i] = 0;
    }

    void SubsirMax1(Integer A[], int n) {
        //Clean();
        L[n] = 1;
        for (int i = n - 1; i >= 1; i--) {
            L[i] = 1;
            P[i] = -1;
            for (int j = i + 1; j <= n; j++)
                if (A[j] >= A[i] && 1 + L[j] > L[i]) {
                    L[i] = 1 + L[j];
                    P[i] = j;
                }
        }
        int k = L[1];
        t[1] = 1;
        for (int i = 2; i <= n; i++)
            if (L[i] > k) {
                k = L[i];
                t[1] = i;
            }
        for (int j = 2; j <= k; j++)
            t[j] = P[t[j - 1]];
        AfisareSubsir(k);
    }

    private void AfisareSubsir(int k) {
        System.out.print("Subsir maxim: ");
        for (int j = 1; j <= k; j++)
            System.out.printf("%d, ", A[t[j]]);
        System.out.printf("\b\b \n");
    }

    public static Object[] CitireDateConsola(){
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.print("Dati vectorul: ");
        int A[] = new int[n+1];
        for(int i=1; i<=n; i++)
            A[i] = in.nextInt();

        System.out.print("Dati m = ");
        int m = in.nextInt();

        System.out.print("Dati vectorul: ");
        int B[] = new int[m + 1];
        for (int i = 1; i <= m; i++)
            B[i] = in.nextInt();

        in.close();
        return new Object[]{n, A, m, B};
    }

    public static void main(String[] args) {
        Object input[] = CitireDateConsola();
        int n = (int) input[0];
        int A[] = (int[]) input[1];
        int m = (int) input[2];
        int B[] = (int[]) input[3];

        L12P04 obj = new L12P04(n,A,m,B);
        obj.Solutie();
    }
}
