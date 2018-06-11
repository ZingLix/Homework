
public class Main {

    public static void main(String[] args) {
        Graph<Integer> g=new Graph<>(9);
        for(int i=0;i<9;++i){
            g.setData(i+1,i+1);
        }
        g.addline(1,2);
        g.addline(2,3);
        g.addline(1,4);
        g.addline(4,3);
        g.addline(5,4);
        g.addline(5,6);
        g.addline(7,5);
        g.addline(8,6);
        g.addline(7,6);
        try {
            g.topsort();
        }catch (Exception e){
            System.out.println("Cycle Found!");
        }
        g.print();
    }
}
