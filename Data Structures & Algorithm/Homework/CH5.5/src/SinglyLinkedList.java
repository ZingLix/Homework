public class SinglyLinkedList<Anytype> {
    private static class Node<Anytype>{
        public Node(Anytype d,Node<Anytype> n){
            data=d;
            next=n;
        }

        public Anytype data;
        public Node<Anytype> next;
    }

    public SinglyLinkedList(){
        size=0;
        beg=new Node<>(null,null);
    }

    public int size(){
        return size;
    }

    public boolean isEmpty(){
        return size==0;
    }

    public void add(Anytype T){
        if(size!=0){
            add(size-1,T);
        }else {
            beg=new Node<>(T,null);
            size++;
        }

    }

    public void add(int pos,Anytype T){
        if(pos!=-1){
            addAfter(getNode(pos),T);
        }else{
            beg=new Node<>(T,beg);
        }
        size++;
    }

    private void addFront(Anytype T){
        add(-1,T);
    }

    private void addRear(Anytype T){
        add(size-1,T);
    }

    private void addAfter(Node<Anytype> node,Anytype T){
        Node<Anytype> newNode=new Node<>(T,node.next);
        node.next=newNode;
        // size++;
    }

    private Node<Anytype> getNode(int idx){
        Node<Anytype> N;
        if(idx<0||idx>size){
            throw new IndexOutOfBoundsException();
        }

        N=beg;
        for(int i=0;i<idx;i++) N=N.next;

        return N;
    }

    public Anytype get(int idx){
        return getNode(idx).data;
    }

    public void set(int idx,Anytype NewVal){
        getNode(idx).data=NewVal;
    }

    public Anytype remove(int idx){
        if(idx!=0){
            return removeNext(getNode(idx));
        }else{
            return removeFirst();
        }
    }

    public Anytype remove(Anytype x){
        return remove(getIdx(x));
    }

    private Anytype removeFirst(){
        size--;
        Anytype tmp=beg.data;
        beg=beg.next;
        return tmp;
    }

    private Anytype removeLast(){
        return remove(size-1);
    }

    private Anytype removeNext(Node<Anytype> N){
        Anytype tmp=N.next.data;
        N.next=N.next.next;
        size--;
        return tmp;
    }

    public boolean contains(Anytype x){
        return getIdx(x)!=-1;
    }

    private int getIdx(Anytype x){
        Node<Anytype> cur=beg;
        int i=0;
        while (cur!=null){
            if(cur.data==x) return i;
            cur=cur.next;
            ++i;
        }
        return -1;
    }

    public void print(){
        Node<Anytype> cur=beg;
        while (cur!=null){
            System.out.print(cur.data+"  ");
            cur=cur.next;
        }
    }

    private int size;
    private Node<Anytype> beg;
}
