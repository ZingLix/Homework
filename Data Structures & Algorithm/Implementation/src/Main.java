import java.util.LinkedList;

public class Main {

    public static void main(String[] args) {
        MyLinkedList<Integer> test=new MyLinkedList<>();
        test.print();
        test.add(1);
        test.add(2);

        test.add(3);
        test.add(4);
        test.add(5);
        test.add(6);
        test.add(7);
        test.add(8);
        test.add(9);
        test.print();
        while (!(test.Size()==0)){
            test.removeLast();
            test.print();
        }

        test.print();
    }
}
