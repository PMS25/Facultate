import java.util.Scanner; 

public class Main {
    public static void main(String args[]){
        System.out.println("Aplicatie cu caracter general, care prelucreaza date anstracte");
        AbstractList pal;

        Scanner in = new Scanner(System.in); 
        System.out.print("Tip (1:Stiva | 2:Coada): ");
        int tip = in.nextInt();
        in.close();

        if(tip==1)
            pal=new Stack();
        else
            pal=new Queue();

        pal.add(new Person("Sara"));
        pal.add(new Person("Andrei"));
        (pal.item()).process();
    }
}