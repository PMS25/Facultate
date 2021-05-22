import java.util.Scanner;

// Problema subsirului comun de lungime maxima.

class L13P01{

    private int m, A[], n, B[];
    private int L[][], P1[][], P2[][];
    private int s[], t[];

    public L13P01(int m, int A[], int n, int B[]){
        this.m = m;
        this.A = A;
        this.n = n;
        this.B = B;
        this.L = new int[m+2][n+2];
        this.P1 = new int[m+2][n+2];
        this.P2 = new int[m+2][n+2];
        this.s = new int[n+m+1];
        this.t = new int[n+m+1];
    }

    // Last -> First
    public void SubsirComunMax1(){
        int i, j;

        // Clean
        for(j = 1; j <= n+1; j++){
            L[m+1][j] = 0;
            P1[m+1][j] = -1;
            P2[m+1][j] = -1;
        }

        for(i = m; i >= 1; i--){
            L[i][n+1] = 0;
            P1[i][n+1] = -1;
            P2[i][n+1] = -1;
            for(j = n; j >= 1; j--){
                if(A[i] == B[j]){
                    L[i][j] = 1 + L[i+1][j+1];
                    P1[i][j] = i;
                    P2[i][j] = j;
                }else
                    if(L[i][j+1] >= L[i+1][j]){
                        L[i][j] = L[i][j+1];
                        P1[i][j] = P1[i][j+1];
                        P2[i][j] = P2[i][j+1];
                    }else{
                        L[i][j] = L[i+1][j];
                        P1[i][j] = P1[i+1][j];
                        P2[i][j] = P2[i+1][j];
                    }
            }
        }

        int k = L[1][1];
        if(k == 0)
            System.out.println("Nu exista subsir comun");
        else{
            s[1] = P1[1][1];
            t[1] = P2[1][1];
            for(j = 2; j <= k; j++){
                s[j] = P1[s[j-1] + 1][t[j-1] + 1];
                t[j] = P2[s[j-1] + 1][t[j-1] + 1];
            }
            for(j = 1; j<=k; j++)
                System.out.printf("[%d](a%d, b%d); ", A[s[j]], s[j], t[j]);
            System.out.println();
        }
    }

    // First -> Last
    public void SubsirComunMax2(){
        int i, j;

        // Clean
        for(j = 0; j<=n; j++){
            L[0][j] = 0;
            P1[0][j] = -1;
            P2[0][j] = -1;
        }

        for(i = 1; i<=m; i++){
            L[i][0] = 0;
            P1[i][0] = -1;
            P2[i][0] = -1;
            for(j = 1; j<=n; j++)
                if(A[i] == B[j]){
                    L[i][j] = 1 + L[i-1][j-1];
                    P1[i][j] = i;
                    P2[i][j] = j;
                }else
                    if(L[i][j-1] >= L[i-1][j]){
                        L[i][j] = L[i][j-1];
                        P1[i][j] = P1[i][j-1];
                        P2[i][j] = P2[i][j-1];
                    }else{
                        L[i][j] = L[i-1][j];
                        P1[i][j] = P1[i-1][j];
                        P2[i][j] = P2[i-1][j];
                    }
        }

        int k = L[m][n];
        if(k == 0)
            System.out.println("Nu exista subsir comun");
        else{
            s[k] = P1[m][n];
            t[k] = P2[m][n];
            for(j = k-1; j>=1; j--){
                s[j] = P1[s[j+1] - 1][t[j+1] - 1];
                t[j] = P2[s[j+1] - 1][t[j+1] - 1];
            }
            for(j = 1; j<=k; j++)
                System.out.printf("[%d](a%d, b%d); ", A[s[j]], s[j], t[j]);
            System.out.println();
        }
    }

    public static Object[] CitireDateConsola(){
        Scanner in = new Scanner(System.in);

        System.out.print("Dati m = ");
        int m = in.nextInt();

        System.out.println("Dati A: ");
        int A[] = new int[m+1];
        for(int i=1; i<=m; i++)
            A[i] = in.nextInt();

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.println("Dati B: ");
        int B[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            B[i] = in.nextInt();

        in.close();
        return new Object[]{m, A, n, B};
    }

    public static void main(String[] args) {
        Object input[] = CitireDateConsola();
        int m = (int) input[0];
        int A[] = (int[]) input[1];
        int n = (int) input[2];
        int B[] = (int[]) input[3];

        L13P01 obj = new L13P01(m,A,n,B);
        obj.SubsirComunMax1();
        obj.SubsirComunMax2();
    }
}