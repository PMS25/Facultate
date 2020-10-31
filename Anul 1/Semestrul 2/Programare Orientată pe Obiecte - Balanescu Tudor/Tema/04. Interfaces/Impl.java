public class Impl implements Interf{
    @Override
    public void verify(int i) throws Exception {
        if(i<100)
            System.out.println("Valoare corecta, mai mica decat 100");
        else if(i>100)
            throw new Exception("Valoare incorectă, mai mare decat 100");
    }
}