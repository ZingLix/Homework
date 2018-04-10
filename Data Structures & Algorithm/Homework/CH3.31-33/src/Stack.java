public class Stack<T> {
    public Stack(){
        list=new SinglyLinkedList<>();
    }

    public void push(T val){
        list.addFront(val);
    }

    public T pop(){
        return list.removeFirst();
    }

    public T top(){
        return list.get(0);
    }

    public boolean isEmpty(){
        return list.isEmpty();
    }

    private SinglyLinkedList<T> list;
}
