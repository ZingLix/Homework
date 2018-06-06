import java.util.*;
public class Main {

    public static void main(String[] args) {
        TreeSet<Integer> tree=new TreeSet<>();
        tree.insert(7);
        tree.insert(19);
        tree.insert(12);
        tree.insert(4);
        tree.insert(6);
        tree.insert(8);
        tree.insert(17);
        Iterator<Integer> it=tree.iterator();
        System.out.print("After insert:");
        while (it.hasNext()){
            System.out.print(it.next()+" ");
        }
        System.out.println();
        tree.remove(4);
        tree.remove(12);
        tree.remove(99);
        it=tree.iterator();
        System.out.print("After remove:");
        while (it.hasNext()){
            System.out.print(it.next()+" ");
        }
        System.out.println();
    }
}
