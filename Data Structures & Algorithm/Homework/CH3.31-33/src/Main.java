public class Main {
    public static void StackTest(){
        Stack<Integer> s=new Stack<>();
        s.push(3);
        s.push(2);
        s.push(1);
        System.out.print("Stack test:");
        while (!s.isEmpty()) System.out.print(s.pop()+" ");
        System.out.println();
    }

    public static void QueueTest(){
        Queue1<Integer> q=new Queue1<>();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.dequeue();
        q.enqueue(4);
        System.out.print("Queue Test:");
        while(!q.isEmpty()) System.out.print(q.dequeue()+" ");
        System.out.println();
    }

    public static void CircularQueueTest(){
        Queue2<Integer> q=new Queue2<>(3);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.dequeue();
        q.enqueue(4);
        System.out.print("Circular Queue Test:");
        while (!q.isEmpty()) System.out.print(q.dequeue()+" ");
        System.out.println();
    }

    public static void main(String[] args) {
        StackTest();
        QueueTest();
        CircularQueueTest();
    }
}
