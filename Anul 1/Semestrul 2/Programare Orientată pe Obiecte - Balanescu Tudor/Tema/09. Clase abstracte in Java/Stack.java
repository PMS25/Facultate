import java.util.ArrayList;

public class Stack extends AbstractList{
    private ArrayList<AbstractElem> list = new ArrayList<>();

    @Override
    public void add(AbstractElem e) {
        list.add(e);
    }

    @Override
    public AbstractElem item() {
        if(list.size()==0)
            return null;
        else{
            AbstractElem p = list.get(0);
            list.remove(0);
            return p;
        }
    }
}