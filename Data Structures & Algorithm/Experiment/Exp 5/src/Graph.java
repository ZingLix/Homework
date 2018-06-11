
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class Graph<T>  {
    class Node{
        T data;
        public LinkedList<Node> adj;
        int indegree;
        int topnumber;
        Node(){
            adj=new LinkedList<Node>();
            indegree=0;
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

    void addline(int i,int j){
        g.get(i-1).adj.add(g.get(j-1));
    }

    void topsort() /*throws Exception*/{
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
        if(counter!=g.size()) return;
        // throw new Exception();
    }
}
