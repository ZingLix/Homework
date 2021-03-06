import com.sun.org.apache.xalan.internal.xsltc.runtime.Node;

public class MyLinkedList<Anytype>
{
    private static class Node<Anytype>{
        public Node(Anytype d,Node<Anytype> p,Node<Anytype> n){
            data=d;
            prev=p;
            next=n;
        }

        public Anytype data;
        public Node<Anytype> prev;
        public Node<Anytype> next;
    }

    public MyLinkedList(){
        Init();
    }

    public void Init(){
        size=0;
    //    count=0;
        beg=new Node<>(null,null,null);
        end=new Node<>(null,beg,null);
        beg.next=end;
    }

    public int Size(){
        return size;
    }

    public boolean isEmpty(){
        return size==0;
    }

    public void add(Anytype T){
        add(size,T);
    }

    public void add(int pos,Anytype T){
        addBefore(getNode(pos),T);
    }

    private void addBefore(Node<Anytype> node,Anytype T){
        Node<Anytype> newNode=new Node<>(T,node.prev,node);
        node.prev=newNode;
        newNode.prev.next=newNode;
        size++;
    }

    private Node<Anytype> getNode(int idx){
        Node<Anytype> N;
        if(idx<0||idx>size){
            throw new IndexOutOfBoundsException();
        }
        if(idx<size/2){
            N=beg.next;
            for(int i=0;i<idx;i++) N=N.next;
        }else {
            N=end;
            for (int i=size;i>idx;i--) N=N.prev;
        }
        return N;
    }

    public Anytype get(int idx){
        return getNode(idx).data;
    }

    public void set(int idx,Anytype NewVal){
        getNode(idx).data=NewVal;
    }

    public void removeLast(){
        remove(size-1);
    }

    public void remove(int idx){
        remove(getNode(idx));

    }

    private void remove(Node<Anytype> N){
        N.prev.next=N.next;
        N.next.prev=N.prev;
        size--;
    }

    public void swap(int idx1,int idx2){
        Node<Anytype> node1=getNode(idx1);
        Node<Anytype> node2=getNode(idx2);
        if(idx2-idx1==1){
            node1.prev.next=node2;
            node2.next.prev=node1;
            node2.prev=node1.prev;
            node1.prev=node2;
            node1.next=node2.next;
            node2.next=node1;
        }else if(idx1-idx2==1){
            node2.prev.next=node1;
            node1.next.prev=node2;
            node1.prev=node2.prev;
            node2.prev=node1;
            node2.next=node1.next;
            node1.next=node2;
        }else{
            Node<Anytype> node1pre=node1.prev;
            Node<Anytype> node1next=node1.next;
            node1.prev.next=node2;
            node1.prev=node2.prev;
            node1.next.prev=node2;
            node1.next=node2.next;
            node2.prev.next=node1;
            node2.prev=node1pre;
            node2.next.prev=node1;
            node2.next=node1next;
        }
    }

    public boolean contain(Anytype data){
        Node<Anytype> i=beg;
        while(i.next!=null){
            if(i.data==data) return true;
            i=i.next;
        }
        return false;
    }

    public void print(){
        Node<Anytype> itr=beg.next;
        for(int i=0;i<size;i++){
            System.out.print(itr.data+" ");
            itr=itr.next;
        }
        System.out.println();
    }

//    private int count=0;
    private int size;
    private Node<Anytype> beg;
    private Node<Anytype> end;
}