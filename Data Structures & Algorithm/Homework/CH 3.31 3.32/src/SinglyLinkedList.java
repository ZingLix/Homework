public class SinglyLinkedList<T> {
    public void insert_front(node newnode){

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
