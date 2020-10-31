public class Person extends AbstractElem{
    private String nume;

    Person(String nume){
        this.nume = nume;
    }

    @Override
    public void process() {
        System.out.println("Numele meu este: "+nume);
    }
}