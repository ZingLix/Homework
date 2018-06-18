import javafx.util.Pair;
import sun.awt.image.ImageWatched;
import sun.reflect.generics.tree.Tree;

import java.util.*;

public class Graph_kruskal {
    class Node{
        char c;
        int num;

        Node(char ch){
            c=ch;
            num=numCount++;
        }
    }

    static int numCount=0;

    class Edge implements Comparable<Edge>{
        Node n1;
        Node n2;
        int weight;

        Edge(Node node1,Node node2,int w){
            n1=node1;
            n2=node2;
            weight=w;
        }

        public int compareTo(Edge other){
            return weight-other.weight;
        }
    }

    ArrayList<Node> g;
    ArrayList<ArrayList<Edge>> graph;

    Graph_kruskal(int count){
        g=new ArrayList<>();
        graph=new ArrayList<>();
        for(int i=0;i<count;++i){
            g.add(new Node((char)('A'+i)));
            graph.add(new ArrayList<>());
            for(int j=0;j<i;++j){
                graph.get(i).add(null);
            }
        }

    }

    void Kruskal(){
        DisjointSet disj=new DisjointSet(g.size());
        PriorityQueue<Edge> q=new PriorityQueue<>();

        for(int i=0;i<g.size();++i){
            for(int j=0;j<i;++j){
                if(graph.get(i).get(j)!=null){
                    q.add(graph.get(i).get(j));
                }
            }
        }
        LinkedList<Edge> ans=new LinkedList<>();
        while (!q.isEmpty()){
            Edge e=q.remove();
            if(disj.getFirst(e.n1.num)!=disj.getFirst(e.n2.num)){
                disj.union(e.n1.num,e.n2.num);
                ans.add(e);
            }
        }
        print(ans);
    }



    void addline(int i,int j, int weight){
        if(i<j){
            int tmp=i;
            i=j;
            j=tmp;
        }
        i=i-1;
        j=j-1;
        graph.get(i).set(j,new Edge(g.get(i),g.get(j),weight));
    }

    void print(LinkedList<Edge> list){
        for(Edge e:list){
            System.out.print("("+e.n1.c+","+e.n2.c+")");
        }
    }


    void print(TreeSet<Edge> list){
        for(Edge e:list){
            System.out.print("("+e.n1.c+","+e.n2.c+")");
        }
    }
}
