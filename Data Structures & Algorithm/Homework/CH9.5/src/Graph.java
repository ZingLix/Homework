import javafx.util.Pair;

import java.util.*;

public class Graph {
    class Node implements Comparable<Node>{
        LinkedList<Pair<Node,Integer>> adj;
        int num;

        Node prev;
        int d;

        Node(int i){
            num=i;
            adj=new LinkedList<>();
        }

        public int compareTo(Node other){
            return d-other.d;
        }
    }

    ArrayList<Node> g;
    boolean weighted;


    Graph(int count){
        g=new ArrayList<>();
        for(int i=0;i<count;++i){
            g.add(new Node(i));
        }
        weighted=true;
    }

    void initialize(Node s){
        for (Node node : g) {
            node.prev=null;
            node.d=999999;
        }
        s.d=0;
    }

    void relax(Node u,Node v,int weight){
        if(v.d>u.d+weight){
            v.d=u.d+weight;
            v.prev=u;
        }
    }

    void Dijkstra(int i){
        Dijkstra(g.get(i-1));
    }

    void Dijkstra(Node s){
        initialize(s);
        TreeSet<Node> set=new TreeSet<>();
        PriorityQueue<Node> q=new PriorityQueue<>(g);
        while(!q.isEmpty()){
            Node u=q.remove();
            set.add(u);
            for(Pair<Node,Integer> n:u.adj){
                relax(u,n.getKey(),n.getValue());
                if(!set.contains(n.getKey())){
                    q.remove(n.getKey());
                    q.add(n.getKey());
                }
            }

        }
    }

    void print(int i){
        print(g.get(i-1));
    }

    void print(Node s){
        for(Node n:g){
            System.out.print(numToChar(n.num)+":"+n.d+"   ");
            Node tmp=n;
            while(tmp.prev!=null&&tmp!=s){
                System.out.print(numToChar(tmp.num));
                tmp=tmp.prev;
            }
            System.out.println(numToChar(s.num));
        }
    }

    char numToChar(int i){
        return (char) ('A'+i);
    }

    void setUnweighted(){
        weighted=false;
    }

    void add(int i,int j,int weight){
        if(!weighted) weight=1;
        g.get(i-1).adj.add(new Pair<>(g.get(j-1),weight));
    }

}
