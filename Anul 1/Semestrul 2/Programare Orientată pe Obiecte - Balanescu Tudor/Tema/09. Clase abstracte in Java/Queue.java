import java.util.ArrayList;

public class Queue extends AbstractList {
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
            AbstractElem p = list.get(list.size()-1);
            list.remove(list.size()-1);
            return p;
        }
    }
}