public class Main {
    public  static void main(String[] args){
        Interf ma= new Impl();
        try{
            ma.verify(99);
            ma.verify(101);
        }catch(Exception e){ System.out.println("Valoare incorecta, mai mare decat 100"); }
    }
}