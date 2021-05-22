import java.util.Scanner;

// Problema drumurilor de suma maxima/minima intr-o matrice.
// Exemplu: Pentru matricea A determinati un drum pentru care suma elementelor parcurse este
// a) maxima ; b) minima ;
// A = | 2 5 3 4 |
//     | 8 1 6 3 |
//     | 4 5 2 6 |
//     | 1 6 3 2 |
// Varianta inainte
// Suma maxima are valoarea: M = 24
// Drum de suma maxima: a42 = 6; a32 = 5; a21 = 8; a12 = 5;
// Suma minima are valoarea: M = 7
// Drum de suma minima: a44 = 2; a33 = 2; a22 = 1; a11 = 2;

public class L13P02 {
    
    private int A[][], m, n;
    private int S[][], P[][], t[];

    public void DrumMax1(){
        int i, j;
        for(j = 1; j <= n; j++)
            S[m][j] = A[m][j];

        for(i = m-1; i > 1; i--){
            P[i][1] = 0;
            if(S[i+1][2] > S[i+1][1])
                P[i][1] = 1;
            S[i][1] = A[i][1] + S[i+1][1+P[i][1]];

            for(j = 2; j <= n-1; j++){
                P[i][j] = -1;
                if(S[i+1][j] > S[i+1][j-1])
                    P[i][j] = 0;
                if(S[i+1][j+1] > S[i+1][j+P[i][j]])
                    P[i][j] = 1;
                S[i][j] = A[i][j] + S[i+1][j+P[i][j]];
            }

            P[i][n] = -1;
            if(S[i+1][n] > S[i+1][n-1])
                P[i][n] = 0;
            S[i][n] = A[i][n] + S[i+1][n+P[i][n]];
        }

        int M = S[1][1];
        t[1] = 1;

        for(j = 2; j<=n; j++)
            if(S[1][j] > M){
                M = S[1][j];
                t[1] = j;
            }
        
        for(i = 2; i <= m; i++)
            t[i] = t[i-1] + P[i-1][t[i-1]];
        
        System.out.printf("M = %d\n", M);
        
        for(i = 1; i<=m; i++)
            System.out.printf("%d ", A[i][t[i]]);
    }

    public static Object[] CitireDateConsola(){
        Scanner in = new Scanner(System.in);

        in.close();
        return new Object[]{};
    }

    public static void main(String[] args) {
        Object input[] = CitireDateConsola();
    }
}
