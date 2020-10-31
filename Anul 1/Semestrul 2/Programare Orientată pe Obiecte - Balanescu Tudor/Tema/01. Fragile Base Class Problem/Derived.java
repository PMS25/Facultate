public class Derived extends FragileBase{
    // In aceasta clasa, metoda inc_by_2() din clasa de baza a fost specializata (override)
    
    public void inc_by_2(){
        inc_by_1();
        inc_by_1();
    }
    
}
