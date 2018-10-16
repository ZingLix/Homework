
import java.util.*;

public class Graph<T>  {
    class Node implements Comparable<Node>{
        T data;
        public LinkedList<Node> adj;
        int indegree;
        int topnumber;
        Node(){
            adj=new LinkedList<Node>();
            indegree=0;
        }
        public int compareTo(Node n){
            return topnumber-n.topnumber;
        }
    }
    ArrayList<Node> g;

    Graph (int num){
        g=new ArrayList<Node>(num);
        for(int i=0;i<num;++i){
            g.add(new Node());
        }
    }

    void updateIndegree(){
        for(int i=0;i<g.size();++i){
            Iterator<Node> it=g.get(i).adj.iterator();
            while (it.hasNext()){
                it.next().indegree+=1;
            }
        }
    }

    void setData(int i,T d){
        g.get(i-1).data=d;
    }

    void addline(int i,int j){
        g.get(i-1).adj.add(g.get(j-1));
    }

    void topsort() throws Exception{
        updateIndegree();
        LinkedList<Node> list=new LinkedList<Node>();
        int counter=0;
        for(int i=0;i<g.size();++i){
            if(g.get(i).indegree==0) list.add(g.get(i));
        }
        while(!list.isEmpty()){
            Node n=list.peek();
            list.pop();
            n.topnumber=++counter;

            Iterator<Node> it =n.adj.listIterator();
            while (it.hasNext()){
                Node tmp=it.next();
                if(--tmp.indegree==0)
                    list.add(tmp);
            }

        }
        if(counter!=g.size())
            throw new Exception();
    }

    void print(){
        Collections.sort(g);
        for(int i=0;i<g.size();++i){
            System.out.print(g.get(i).data+" ");
        }
    }

}
