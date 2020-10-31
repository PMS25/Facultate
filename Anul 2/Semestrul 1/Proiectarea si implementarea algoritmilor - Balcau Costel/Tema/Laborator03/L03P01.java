import java.util.Comparator;
import java.util.Scanner;
import java.util.stream.IntStream;

//  Produs scalar maxim / minim.

public class L03P01 {

    public static class MyArray {
        public int[] x;

        public MyArray(int n) {
            x = new int[n];
        }

        public void swap(int a, int b) {
            int aux = x[a];
            x[a] = x[b];
            x[b] = aux;
        }

        public void SortareC() {
            x = IntStream.of(x).boxed().sorted().mapToInt(Integer::intValue).toArray();
        }

        public void SortareD() {
            x = IntStream.of(x).boxed().sorted(Comparator.reverseOrder()).mapToInt(Integer::intValue).toArray();
        }
    }

    MyArray a, b;
    private int s, n;

    public L03P01(MyArray a, MyArray b, int n) {
        this.a = a;
        this.b = b;
        this.n = n;
    }

    public void Maxim1() {
        int k, m;
        s = 0;

        for (int i = 0; i < n; i++) {
            k = i;
            m = a.x[i];
            for (int j = i + 1; j < n; j++)
                if (a.x[j] < m) {
                    k = j;
                    m = a.x[j];
                }
            a.swap(i, k);

            k = i;
            m = b.x[i];
            for (int j = i + 1; j < n; j++)
                if (b.x[j] < m) {
                    k = j;
                    m = b.x[j];
                }
            b.swap(i, k);
            s += a.x[i] * b.x[i];
        }
        Afisare("maxima");
    }

    public void Maxim2() {
        a.SortareC();
        b.SortareC();
        s = 0;
        for (int i = 0; i < n; i++)
            s += a.x[i] * b.x[i];
        Afisare("maxima");
    }

    public void Minim1() {
        int k, m;
        s = 0;

        for (int i = 0; i < n; i++) {
            k = i;
            m = a.x[i];
            for (int j = i + 1; j < n; j++)
                if (a.x[j] < m) {
                    k = j;
                    m = a.x[j];
                }
            a.swap(i, k);

            k = i;
            m = b.x[i];
            for (int j = i + 1; j < n; j++)
                if (b.x[j] > m) {
                    k = j;
                    m = b.x[j];
                }
            b.swap(i, k);
            s += a.x[i] * b.x[i];
        }
        Afisare("minima");
    }

    public void Minim2() {
        a.SortareC();
        b.SortareD();
        s = 0;
        for (int i = 0; i < n; i++)
            s += a.x[i] * b.x[i];
        Afisare("minima");
    }

    private void Afisare(String tip) {
        System.out.printf("Suma %s = %d \n", tip, s);
        System.out.print("a: ");
        for (int i = 0; i < n; i++)
            System.out.printf("%d ", a.x[i]);
        System.out.println();
        System.out.print("b: ");
        for (int i = 0; i < n; i++)
            System.out.printf("%d ", b.x[i]);
        System.out.println();
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de componente n = ");
        int n = in.nextInt();
        in.nextLine();

        MyArray a = new MyArray(n);
        System.out.println("Dati elementele multimii a:");
        for (int i = 0; i < n; i++)
            a.x[i] = in.nextInt();

        MyArray b = new MyArray(n);
        System.out.println("Dati elementele multimii b:");
        for (int i = 0; i < n; i++)
            b.x[i] = in.nextInt();

        in.close();
        return new Object[]{n, a, b};
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        int n = (int) input[0];
        MyArray a = (MyArray) input[1];
        MyArray b = (MyArray) input[2];

        L03P01 obj = new L03P01(a, b, n);
        obj.Maxim1();
        obj.Minim1();
        obj.Maxim2();
        obj.Minim2();
    }
}
