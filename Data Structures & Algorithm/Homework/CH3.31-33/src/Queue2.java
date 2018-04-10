import java.util.ArrayList;

public class Queue2<T> implements Queue<T> {
    private static final int MAX_SIZE = 10;

    public Queue2(){
        this(MAX_SIZE);
    }

    public Queue2(int sz){
        array=new ArrayList<>(sz);
        while (sz--!=0) array.add(null);
        arrSize=array.size();
        front=0;
        size=0;
    }

    public void enqueue(T val) {
        if(!isFull()){
            int idx=(front+size)%(arrSize);
            array.set(idx,val);
            ++size;
        }
    }

    public T dequeue(){
        if(isEmpty()) return null;
        T tmp=array.get(front);
        if(front!=arrSize-1) front++;
        else front=0;
        --size;
        return tmp;
    }

    public boolean isEmpty() {
        return size==0;
    }

    public boolean isFull() {
        return size==arrSize;
    }

    public T front() {
        return array.get(front);
    }

    private ArrayList<T> array;
    private int front;
    private int size;
    private int arrSize;
}
