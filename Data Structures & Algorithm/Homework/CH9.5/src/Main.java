public class Main {

    public static void main(String[] args) {
        Graph g=new Graph(7);
       // g.setUnweighted();
        g.add(1,2,5);
        g.add(2,7,1);
        g.add(7,5,1);
        g.add(2,5,3);
        g.add(2,3,2);
        g.add(1,3,3);
        g.add(3,5,7);
        g.add(4,1,2);
        g.add(3,4,7);
        g.add(5,4,2);
        g.add(5,6,1);
        g.add(4,6,6);
        g.Dijkstra(1);
        g.print(1);
    }
}
