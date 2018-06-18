import javafx.util.Pair;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.TreeSet;

public class Graph_prim {
    class Node implements Comparable<Node>{
        char c;
        int num;
        int key;
        Node parent;
        LinkedList<Pair<Node,Integer>> adj;

        Node(char ch){
            c=ch;
            num=numCount++;
            adj=new LinkedList<>();
        }

        public int compareTo(Node other){
            return key-other.key;
        }
    }

    static int numCount=0;

    class Edge implements Comparable<Edge>{
        Node n1;
        Node n2;
        int weight;

        Edge(Node node1, Node node2, int w){
            n1=node1;
            n2=node2;
            weight=w;
        }

        public int compareTo(Edge other){
            return weight-other.weight;
        }
    }

    ArrayList<Node> g;

    Graph_prim(int count){
        g=new ArrayList<>();
        for(int i=0;i<count;++i){
            g.add(new Node((char)('A'+i)));
        }
    }

    void Prim(){
        Node n=g.get(0);
        for(int i=0;i<g.size();++i){
            g.get(i).key=999999;
            g.get(i).parent=null;
        }
        n.key=0;
        PriorityQueue<Node> q=new PriorityQueue<>(g);
        while (!q.isEmpty()){
            Node u=q.remove();
            for(Pair<Node,Integer> p:u.adj){
                Node v=p.getKey();
                if(q.contains(v)&&p.getValue()<v.key){
                    v.parent=u;
                    v.key=p.getValue();
                    q.remove(v);
                    q.add(v);
                }
            }
        }
        print();
    }

    void addline(int i,int j,int weight){
        i--;j--;
        g.get(i).adj.add(new Pair<>(g.get(j),weight));
        g.get(j).adj.add(new Pair<>(g.get(i),weight));
    }

    void print(){
        for(Node n:g){
            if(n.parent!=null)
                System.out.print("("+n.c+","+n.parent.c+")");
        }
    }
}
