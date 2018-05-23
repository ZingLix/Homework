import java.util.Random;

public class Main {

    public static void main(String[] args) {
        SeperateChainingHashTable<Integer> ht=new SeperateChainingHashTable<>(10);
        Random rand = new Random();
        for(int i=0;i<20;++i){
            int  n = rand.nextInt(100) + 1;
            ht.insert(n);
        }
//        ht.insert(33);
//        ht.insert(33);
        ht.print();
    }
}
