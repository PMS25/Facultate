// public class FragileBase{
//     public void inc_by_1(){
//         counter ++;
//     }
    
//     public void inc_by_2(){
//         counter ++;
//         counter ++;
//     }
    
//     void display_counter(){
//         System.out.println("counter="+counter);
//     }
    
//     private int counter=0;
    
// }

//Noua versiune a clasei de baza

public class FragileBase{
    // Aceasta este o versiune noua a clasei FragileBase
    // in care metoda inc_by_1() a fost reimplementata
    // metoda reimplementata, "aparent" pastrand efectul de incrementare cu o unitate.
    
    public void inc_by_1(){
        inc_by_2();
        counter --;
    }
    
    public final void inc_by_2(){
        counter ++;
        counter ++;
    }
    
    void display_counter(){
        System.out.println("counter="+counter);
    }
    
    private int counter=0;
    
}