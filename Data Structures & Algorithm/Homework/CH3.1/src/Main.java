import java.util.Iterator;
import java.util.LinkedList;

public class Main {

    public static void printLots(LinkedList<Integer> L,LinkedList<Integer> P){
        Iterator<Integer> it=L.listIterator();
        Iterator<Integer> itp= P.listIterator();
        int flag=0,pos= itp.next();
        while(it.hasNext()){
            if(flag==pos){
                System.out.print(it.next());
                if(itp.hasNext()){
                    pos=itp.next();
                }else {
                    break;
                }
            }else{
                it.next();
            }
            flag++;
        }
    }

    public static void main(String[] args) {
        LinkedList<Integer> list1=new LinkedList<>();
        for(int i=0;i<10;i++) list1.add(i);
        LinkedList<Integer> list2=new LinkedList<>();
        list2.add(1);
        list2.add(3);
        list2.add(4);
        list2.add(6);
        printLots(list1,list2);
    }
}
