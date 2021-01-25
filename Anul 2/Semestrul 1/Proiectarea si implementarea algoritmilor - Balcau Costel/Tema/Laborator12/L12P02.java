import java.util.Scanner;

// 2. Problema subsirului crescator de lungime maxima.
// Exemplu: Determinati un subsir crescator de lungime maxima pentru A = (12,5,9,8,17,6,2,7,10,4).
// Avem n = 10
// L[1] = 1;
// L[2] = 1; P[2] = -1;
// L[3] = 2; P[3] = 2;
// L[4] = 2; P[4] = 2;
// L[5] = 3; P[5] = 3;
// L[6] = 2; P[6] = 2;
// L[7] = 1; P[7] = -1;
// L[8] = 3; P[8] = 6;
// L[9] = 4; P[9] = 8;
// L[10] = 2; P[10] = 7;
// Deci lungimea maxima a unui subsir crescator este: k = 4
// iar un subsir crescator de lungime maxima este dat de indicii:
// t4 = 9, t3 = P[t4] = 8, t2 = P[t3] = 6 , t1 = P[t2] = 2
// Adica subsirul: 5, 6, 7, 10

class L12P02 {
    
    private int n, A[], L[], P[], t[];

    public L12P02(int n, int A[]){
        this.n = n;
        this.A = A;
        this.L = new int[n + 1];
        this.P = new int[n + 1];
        this.t = new int[n + 1];
    }

    private void Clean(){
        for(int i=0; i<=n; i++)
            L[i] = P[i] = t[i] = 0;
    }

    void SubsirMax1(){
        Clean();
        L[n] = 1;
        for(int i=n-1; i>=1; i--){
            L[i] = 1;
            P[i] = -1;
            for(int j=i+1; j<=n; j++)
                if(A[j]>=A[i] && 1 + L[j] > L[i]){
                    L[i] = 1 + L[j];
                    P[i] = j;
                }
        }
        int k = L[1];
        t[1] = 1;
        for(int i=2; i<=n; i++)
            if(L[i] > k){
                k = L[i];
                t[1] = i;
            }
        for(int j = 2; j<=k; j++)
            t[j] = P[t[j-1]];
        AfisareSubsir(k);
    }

    void SubsirMax2(){
        Clean();
        L[1] = 1;
        for(int i = 2; i<=n; i++){
            L[i] = 1;
            P[i] = -1;
            for(int j = 1; j<=i-1; j++)
                if(A[i]<=A[j] && 1 + L[j] > L[i]){
                    L[i] = 1 + L[j];
                    P[i] = j;
                }
        }
        int k = L[1], m = 1;
        for(int i = 2; i<=n; i++)
            if(L[i] > k){
                k = L[i];
                m = i;
            }
        t[k] = m;
        for(int j = k-1; j>=1; j--)
            t[j] = P[t[j+1]];
        AfisareSubsir(k);
    }

    private void AfisareSubsir(int k){
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
        
        in.close();
        return new Object[]{n, A};
    }

    public static void main(String[] args) {
        Object input[] = CitireDateConsola();
        int n = (int) input[0];
        int A[] = (int[]) input[1];

        L12P02 obj = new L12P02(n,A);
        obj.SubsirMax1();
        obj.SubsirMax2();
    }
}
