import java.util.Iterator;

public class TreeSet<Value extends Comparable<Value>> implements Iterable<Value>  {
    MyTree<Value> t;

    TreeSet(){
        t=new MyTree<>();
    }

    public void insert(Value val){
        t.insert_unique(val);
    }

    public void remove(Value val){
        t.remove(val);
    }

    @Override
    public Iterator<Value> iterator() {
        return t.iterator();
    }
}
