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