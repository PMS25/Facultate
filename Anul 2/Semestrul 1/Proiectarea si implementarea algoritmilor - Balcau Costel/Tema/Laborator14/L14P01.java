import java.util.ArrayList;
import java.util.Scanner;

class L14P01{

    public static class Point{
        int x, y;

        public Point(){
            this.x = 0;
            this.y = 0;
        }

        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static class Node{
        int parent;
        int M[][];
        Point B;
        int cost;
        int level;
    }

    private ArrayList<Node> List = new ArrayList<>();

    private int n, Ms[][], Mf[][];

    private Point moves[], B;

    public L14P01(int n, int Ms[][], int Mf[][], Point B){
        this.n = n;
        this.Ms = Ms;
        this.Mf = Mf;
        this.B = B;
        LoadModes();
    }

    private void LoadModes(){
        moves = new Point[4];
        moves[0] = new Point(1,0); // jos
        moves[1] = new Point(0,-1); // stanga
        moves[2] = new Point(-1,0); // sus
        moves[3] = new Point(0,1); // dreapta
    }

    public Node NewNode(int M[][], Point B, Point newB, int lever, int parent) {
        Node node = new Node();
        node.M = new int[n+1][n+1];

        // Copy Matrix
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                node.M[i][j] = M[i][j];

        // Move Space to another possition
        int aux = node.M[B.x][B.y];
        node.M[B.x][B.y] = node.M[newB.x][newB.y];
        node.M[newB.x][newB.y] = aux;

        node.B = newB;
        node.cost = Integer.MAX_VALUE;
        node.level = lever;
        node.parent = parent;
        
        return node;
    }

    public int CalculateCost(int M1[][], int M2[][]){
        int count = 0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(M1[i][j] != M2[i][j])
                    count++;
        return count;
    }

    public boolean IsSafe(Point p){
        return (p.x >=1 && p.x <=n && p.y >=1 && p.y <=n);
    }

    public void PrintMatrix(int M[][]){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                System.out.printf("%d ", M[i][j]);
            System.out.println();
        }
        System.out.print("\n");
    }

    public void PrintPath(Node node){
        if(node.parent == -1)
            return;
        Node parent = List.get(node.parent);
        PrintPath(parent);
        System.out.printf("Step %d:\n", node.level);
        PrintMatrix(node.M);
    }

    private void Solution(Node node){
        System.out.println("\nSolutie:");
        PrintPath(node);
    }

    public void Solve(){
        ArrayList<Node> active = new ArrayList<>();

        Node root = NewNode(Ms, B, B, 0, -1);
        root.cost = CalculateCost(Ms, Mf);

        List.add(root);
        active.add(root);

        while(active.size() != 0){
            Node min = active.get(0);
            active.remove(0);

            if(min.cost == 0){
                Solution(min);
                return;
            }

            for(int i=0; i<4; i++){
                Point b = new Point(min.B.x + moves[i].x, min.B.y + moves[i].y);
                if(IsSafe(b)){
                    Node child = NewNode(min.M, min.B, b, min.level + 1, List.indexOf(min));
                    child.cost = CalculateCost(child.M, Mf);

                    List.add(child);
                    active.add(child);
                }
            }
        }
    }

    public static Object[] CitireDateConsola(){
        Scanner in = new Scanner(System.in);

        System.out.print("Dati n = ");
        int n = in.nextInt();

        System.out.println("Dati matricea de start (Ms): ");
        int Ms[][] = new int[n+1][n+1];
        Point B = new Point();

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++){
                Ms[i][j] = in.nextInt();
                if(Ms[i][j] == 0)
                    B = new Point(i,j);
            }

        System.out.println("Dati matricea de final (Mf): ");
        int Mf[][] = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                Mf[i][j] = in.nextInt();
                
        in.close();
        return new Object[]{n, Ms, Mf, B};
    }


    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int)input[0];
        int Ms[][] = (int[][])input[1];
        int Mf[][] = (int[][])input[2];
        Point B = (Point)input[3];

        L14P01 obj = new L14P01(n, Ms, Mf, B);
        obj.Solve();
    }
}