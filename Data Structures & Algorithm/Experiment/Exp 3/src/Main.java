import java.util.*;
public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World!");
        MyTree<Integer> tree=new MyTree<Integer>();
        tree.insert(7);
        tree.insert(19);
        tree.insert(12);
        tree.insert(4);
        tree.insert(6);
        tree.insert(8);
        tree.remove(4);
        Iterator<Integer> it=tree.iterator();
        while (it.hasNext()){
            System.out.print(it.hasNext());
        }
    }
}
