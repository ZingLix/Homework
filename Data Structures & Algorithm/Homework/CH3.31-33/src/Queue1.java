public class Queue1 <T> implements Queue<T> {
    public Queue1(){
        list=new SinglyLinkedList<>();
    }

    public void enqueue(T val){
        list.addRear(val);
    }

    public T dequeue(){
        return  list.removeFirst();
    }

    public boolean isEmpty(){
        return list.isEmpty();
    }

    public boolean isFull() {
        return false;
    }

    public T front(){
        return list.get(0);
    }

    private SinglyLinkedList<T> list;
}
