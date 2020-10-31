public class Main{
    public static void main(String args[]){
        FragileBase o;

        System.out.println("Operatii asupra unui obiect din clasa de baza");
        o=new FragileBase();
        o.inc_by_1();
        o.inc_by_2();
        o.display_counter();

        System.out.println("Operatii asupra unui obiect din clasa derivata");
        o=new Derived();
        o.inc_by_1();
        o.inc_by_2();
        o.display_counter();
    }

}