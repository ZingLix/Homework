import java.util.LinkedList;

public class Main {

    public static void main(String[] args) {
        MyLinkedList<Integer> test=new MyLinkedList<>();
        for(int i=0;i<10;i++){
            test.add(i);
        }
        System.out.println("6:"+test.contain(6));
        System.out.print("99:"+test.contain(99));
    }
}
