    public boolean contain(Anytype data){
        Node<Anytype> i=beg;
        while(i.next!=null){
            if(i.data==data) return true;
            i=i.next;
        }
        return false;
    }