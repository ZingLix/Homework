public class SeperateChainingHashTable <Anytype>{

    private SinglyLinkedList<Anytype>[] list;
    private int curSize;

    private static int DEFAULT_SIZE=101;

    public SeperateChainingHashTable(){
        this(DEFAULT_SIZE);
    }

    public SeperateChainingHashTable(int size){
        list=new SinglyLinkedList[nextPrime(size)];
        for(int i=0;i<list.length;++i){
            list[i]=new SinglyLinkedList<>();
        }
    }

    private int hash(Anytype x){
        int hashVal=x.hashCode();
        hashVal%=list.length;
        if(hashVal<0) hashVal+=list.length;
        return hashVal;
    }

    public void insert(Anytype x){
        if(!list[hash(x)].contains(x)) list[hash(x)].add(x);
        ++curSize;
    }

    public void remove(Anytype x){
        if(list[hash(x)].contains(x)) list[hash(x)].remove(x);
        --curSize;
    }

    private boolean isPrime(int data){
        for(int i=2;i<Math.sqrt(data);++i){
            if(data%i==0) return false;
        }
        return true;
    }

    private int nextPrime(int data){
        while(true){
            if(isPrime(data)) break;
            data++;
        }
        return data;
    }

    public void print() {
        for(int i=0;i<list.length;++i){
            System.out.print(i+" :  ");
            list[i].print();
            System.out.println();
        }
    }
}
