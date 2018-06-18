
public class Main {

    public static void main(String[] args) {
        //CLRS Example
//        Graph<Integer> g=new Graph<>(9);
//        for(int i=0;i<9;++i){
//            g.setData(i+1,i+1);
//        }
//        g.addline(1,2);
//        g.addline(2,3);
//        g.addline(1,4);
//        g.addline(4,3);
//        g.addline(5,4);
//        g.addline(5,6);
//        g.addline(7,5);
//        g.addline(8,6);
//        g.addline(7,6);


        //ex 9.1
        Graph<Integer> g=new Graph<>(11);
        for(int i=0;i<11;++i){
            g.setData(i,i);
        }
        g.addline(0,1);
        g.addline(1,2);
        g.addline(2,3);
        g.addline(3,10);
        g.addline(4,1);
        g.addline(1,5);
        g.addline(5,3);
        g.addline(6,3);
        g.addline(0,4);
        g.addline(4,5);
        g.addline(5,6);
        g.addline(6,10);
        g.addline(0,7);
        g.addline(7,4);
        g.addline(7,5);
        g.addline(8,5);
        g.addline(5,9);
        g.addline(9,6);
        g.addline(9,10);
        g.addline(7,8);
        g.addline(8,9);



        try {
            g.topsort();
        }catch (Exception e){
            System.out.println("Cycle Found!");
        }
        g.print();
    }
}
