import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;

public class Main {
    public static<T extends Comparable<T>> LinkedList<T> intersection(LinkedList<T> l1,LinkedList<T> l2){
        LinkedList<T> result=new LinkedList<>();
        Iterator<T> it1=l1.iterator();
        Iterator<T> it2=l2.iterator();
        T cur1=it1.next(),cur2=it2.next();
        boolean flag=true;
        if(cur1.compareTo(cur2)>0){
            flag=false;
        }else if(cur1.compareTo(cur2)==0){
            result.add(cur1);
        }
        while(it1.hasNext()&&it2.hasNext()){
            if(flag) cur1 = it1.next();
            else cur2 = it2.next();
            if(cur1.compareTo(cur2)==0){
                result.add(cur1);
            }else if(cur1.compareTo(cur2)>0){
                flag=false;
            }else{
                flag=true;
            }
        }


        return result;
    }

    public static <T extends Comparable<T>> LinkedList<T> union(LinkedList<T> l1,LinkedList<T> l2){
        LinkedList<T> result=new LinkedList<>();
        Iterator<T> it1=l1.iterator();
        Iterator<T> it2=l2.iterator();
        T cur1=it1.next(),cur2=it2.next();
        boolean flag=true;
        if(cur1.compareTo(cur2)>0){
            flag=false;
        }
        result.add(cur1);
        while(it1.hasNext()||it2.hasNext()){
            if(flag) cur1 = it1.next();
            else cur2 = it2.next();
            if(cur1.compareTo(cur2)==0){
            }else if(cur1.compareTo(cur2)>0){
                flag=false;
                if(cur2!=result.getLast())
                    result.add(cur2);
            }else{
                flag=true;
                if(cur1!=result.getLast())
                    result.add(cur1);

            }
        }
        if(result.getLast()==cur1) result.add(cur2);
        else result.add(cur1);

        return result;
    }

    public static void main(String[] args) {
        LinkedList<Integer> a=new LinkedList<Integer>();
        LinkedList<Integer> b=new LinkedList<Integer>();
        a.add(3);
        a.add(6);
        a.add(9);
        a.add(12);
        a.add(15);
        a.add(18);
        a.add(56);

        b.add(3);
        b.add(7);
        b.add(8);
        b.add(9);
        b.add(18);
        b.add(44);

        System.out.print("List A: ");
        ListIterator<Integer> it=a.listIterator();
        while(it.hasNext()) System.out.print(it.next()+"  ");
        System.out.println();

        System.out.print("List B: ");
        it=b.listIterator();
        while(it.hasNext()) System.out.print(it.next()+"  ");
        System.out.println();

        System.out.print("Intersection: ");
        LinkedList<Integer> ans=intersection(a,b);
        it=ans.listIterator();
        while(it.hasNext()) System.out.print(it.next()+"  ");
        System.out.println();


        System.out.print("Union: ");
        ans=union(a,b);
        it=ans.listIterator();
        while(it.hasNext()) System.out.print(it.next()+"  ");
        System.out.println();
    }
}


