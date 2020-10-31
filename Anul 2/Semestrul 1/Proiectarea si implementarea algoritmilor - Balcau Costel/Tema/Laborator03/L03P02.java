import java.util.Scanner;
import java.util.stream.Stream;

// Problema memorarii optime a unor texte de lungimi date pe o banda.
// Afisati lungimea totala parcursa pana la cuvantul cu numarul de ordine k memorat pe banda.

public class L03P02 {

    private int n;
    private String[] texte;
    private String[] texte_sortate;

    public L03P02(String[] texte) {
        this.texte = texte;
        n = texte.length;
        Sortare();
    }

    private void Sortare() {
        // Crescatoare, dupa lungime
        texte_sortate = Stream.of(texte).sorted((String s1, String s2) -> {
            if (s1.length() > s2.length()) return 1;
            else if (s1.length() < s2.length()) return -1;
            else return 0;
        }).toArray(String[]::new);
    }

    private void Afisare(int s, int k) {
        System.out.printf("Lungime: %d \n", s);
        for (int i = 0; i < k; i++)
            System.out.printf("%s, ", texte_sortate[i]);
        System.out.printf("[%s]", texte_sortate[k]);
    }

    void Greedy(int k) {
        if (k > n || k < 0) {
            System.out.println("Index depasit.");
            return;
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (texte[k].equals(texte_sortate[i]))
                Afisare(s, i);
            s += texte_sortate[i].length();
        }
    }

    public static Object[] CitireDateConsola() {
        Scanner in = new Scanner(System.in);

        System.out.print("Dati numarul de texte n = ");
        int n = in.nextInt();
        in.nextLine();

        System.out.println("Dati textele: ");
        String[] texte = new String[n];
        for (int i = 0; i < n; i++) {
            System.out.printf("%d: ", (i + 1));
            texte[i] = in.nextLine().trim();
        }

        System.out.print("Dati indexul cautat (1 -> n) k = ");
        int k = in.nextInt() - 1;

        in.close();
        return new Object[]{texte, k};
    }

    public static void main(String[] args) {
        Object[] input = CitireDateConsola();
        String[] texte = (String[]) input[0];
        int k = (int) input[1];

        L03P02 banda = new L03P02(texte);
        banda.Greedy(k);
    }
}
