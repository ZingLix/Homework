public class Stack<T> implements operation<T>{
    public Stack(){
        top=new node<T>();
    }

    public Stack(T newdata){
        top=new node<T>(newdata);
    }

    public void push(T dat) {
        top=new node<T>(dat,top);
    }

    public T pop(){
        if(empty()) {
            return null;
        }
        T tmp=top.data;
        top=top.next;
        return tmp;
    }

    public boolean empty(){
        return top.next==null;
    }

    public void print(){
        while (!empty()) System.out.print(pop());
    }

    private static class node<T>{
        public node(){
            data=null;
            next=null;
        }
        public node(T newdata){
            data=newdata;
            next=null;
        }
        public node(T newdata,node<T> newnode){
            data=newdata;
            next=newnode;
        }


        public T data;
        public node<T> next;
    }

    private node<T> top;
}
