public void insert(Anytype x){
    arr.add(arr.get(0));
    arr.set(0,x);
    percolateDown(0);
}