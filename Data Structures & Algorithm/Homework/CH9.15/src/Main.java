public class Main {

    public static void main(String[] args) {
        //Graph_kruskal g=new Graph_kruskal(10);
        Graph_prim g=new Graph_prim(10);
        g.addline(1,2,3);
        g.addline(2,3,10);
        g.addline(1,4,4);
        g.addline(1,5,4);
        g.addline(2,5,2);
        g.addline(2,6,3);
        g.addline(3,6,6);
        g.addline(3,7,1);
        g.addline(4,5,5);
        g.addline(5,6,11);
        g.addline(6,7,2);
        g.addline(4,8,6);
        g.addline(5,8,2);
        g.addline(5,9,1);
        g.addline(6,9,3);
        g.addline(6,10,11);
        g.addline(7,10,8);
        g.addline(8,9,4);
        g.addline(9,10,7);
       //g.Kruskal();
        g.Prim();
    }
}
