import java.util.Scanner;

// O problema de acoperire.
// Exemplu: n=8, patratul unitar acoperit este pe linia 7, coloana 4
// Solutie: Plasam piesa 1 in centru astfel incat fiecare dintre cele 4 patrate de dimensiune 4 sa aiba cate un patrat unitar acoperit

//    1 2 3 4 5 6 7 8
// 1 | | | | | | | | |
// 2 | | | | | | | | |
// 3 | | | | | | | | |
// 4 | | | |1|1| | | |
// 5 | | | | |1| | | |
// 6 | | | | | | | | |
// 7 | | | |x| | | | |
// 8 | | | | | | | | |

// Continuam procedeul pentru fiecare dintre cele 4 patrate de dimensiune 4:
//     1  2  3  4  5  6  7  8
// 1 | 3| 3| 4| 4| 8| 8| 9| 9|
// 2 | 3| 2| 2| 4| 8| 7| 7| 9|
// 3 | 5| 2| 6| 6|10|10| 7|11|
// 4 | 5| 5| 6| 1| 1|10|11|11|
// 5 |13|13|14|14| 1|18|19|19|
// 6 |13|12|12|14|18|18|17|19|
// 7 |15|12|16| x|20|17|17|21|
// 8 |15|15|16|16|20|20|21|21|

public class L08P02 {

    private int[][] S;
    private int n, p, ip, jp;

    public L08P02(int n, int ip, int jp) {
        this.n = n;
        this.ip = ip;
        this.jp = jp;
        S = new int[n+1][n+1];
    }

    private void Afisare(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                System.out.printf("%" + 3 + "d", S[i][j]);
            System.out.println();
        }
    }

    private void CleanSolution(){
        p = 0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                S[i][j] = 0;
    }

    public void Acoperire(){
        CleanSolution();
        Acoperire(1,1,n,ip,jp);
        Afisare();
    }

    private void Acoperire(int i,int j,int nn,int ip,int jp) {
        if (nn > 1) {
            p++;
            int m = nn/2;

            // Coordonatele stanga-sus ale celor 4 patrate
            int i1 = i, i2 = i, i3 = i + m, i4 = i + m;
            int j1 = j, j2 = j + m, j3 = j, j4 = j + m;

            // Coordonatele patratelor unitare ce vor fi acoperite in cele 4 patrate
            int ip1 = ip, ip2 = ip, ip3 = ip, ip4 = ip;
            int jp1 = jp, jp2 = jp, jp3 = jp, jp4 = jp;

            if (i3 <= ip) {
                ip1 = i1 + m - 1; jp1 = j1 + m - 1;
                ip2 = i2 + m - 1; jp2 = j2;
                S[ip1][jp1] = S[ip2][jp2] = p;
            }else{
                ip3 = i3; jp3 = j3 + m - 1;
                ip4 = i4; jp4 = j4;
                S[ip3][jp3] = S[ip4][jp4] = p;
            }

            if(j2 <= jp){
                ip1 = i1 + m - 1; jp1 = j1 + m - 1;
                ip3 = i3; jp3 = j3 + m - 1;
                S[ip1][jp1] = S[ip3][jp3] = p;
            }else{
                ip2 = i2 + m - 1; jp2 = j2;
                ip4 = i4; jp4 = j4;
                S[ip2][jp2] = S[ip4][jp4] = p;
            }

            Acoperire(i1,j1,m,ip1,jp1);
            Acoperire(i2,j2,m,ip2,jp2);
            Acoperire(i3,j3,m,ip3,jp3);
            Acoperire(i4,j4,m,ip4,jp4);
        }
    }

    public static Object[] CitireDateConsola(){
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.print("Linia patratului unitar ip = ");
        int ip = in.nextInt();

        System.out.print("Coloana patratului unitar jp = ");
        int jp = in.nextInt();

        in.close();
        return new Object[] { n, ip, jp };
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        int ip = (int) input[1];
        int jp = (int) input[2];

        L08P02 obj = new L08P02(n,ip,jp);
        obj.Acoperire();
    }
}
