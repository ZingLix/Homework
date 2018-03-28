import java.util.LinkedList;
import java.util.ListIterator;

public class Main {
    public static<T> LinkedList<T> intersection(LinkedList<T> l1,LinkedList<T> l2){
        ListIterator<T> it=l2.listIterator();
        LinkedList<T> result=new LinkedList<T>();
        while(it.hasNext()){
            T tmp=it.next();
            ListIterator<T> it1=l1.listIterator();
            while(it1.hasNext()){
                if(it1.next()==tmp) result.add(tmp);
            }
        }
        return result;
    }

    public static <T> LinkedList<T> union(LinkedList<T> l1,LinkedList<T> l2){
        ListIterator<T> it=l2.listIterator();
        LinkedList<T> result=new LinkedList<T>(l1);
        while(it.hasNext()){
            T tmp=it.next();
            int flag=0;
            ListIterator<T> it1=l1.listIterator();
            while(it1.hasNext()){
                if(it1.next()==tmp){
                    flag=1;
                    break;
                }
            }
            if(flag==0) result.add(tmp);
        }
        return result;
    }

    public static void main(String[] args) {
        LinkedList<Integer> a=new LinkedList<Integer>();
        LinkedList<Integer> b=new LinkedList<Integer>();
        a.add(3);
        a.add(6);
        a.add(9);
        a.add(8);
        b.add(7);
        b.add(9);
        b.add(8);
        b.add(3);
        b.add(44);
        LinkedList<Integer> ans=union(a,b);
        ListIterator<Integer> it=ans.listIterator();
        while(it.hasNext()) System.out.print(it.next()+"  ");
    }
}
