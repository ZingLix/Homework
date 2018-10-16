## 1.需求分析

实现拓扑排序。

## 2.相关知识及技术分析

图的表示，拓扑排序

## 3.系统架构设计

在实现图的基础上，实现拓扑排序相关操作

## 4.功能模块设计

图以邻接链表的方式存储，`topsort()` 进行拓扑排序，每个节点中的 `topnumber` 负责记录拓扑排序中的序号。

``` java
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
}
```

## 5.系统界面设计

以命令行的形式将拓扑排序后的结点序号依次输出。

## 6.系统测试

测试代码：

``` java 
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
        System.out.print("After topsort:");
        g.print();
    }catch (Exception e){
        System.out.println("Cycle Found!");
    }
}
```

输出结果：

![](https://github.com/ZingLix/Homework/blob/master/Data%20Structures%20%26%20Algorithm/Experiment/Exp%205/img/2.png)

对应的输入输出的图：

![](https://github.com/ZingLix/Homework/blob/master/Data%20Structures%20%26%20Algorithm/Experiment/Exp%205/img/4.png)

![](https://github.com/ZingLix/Homework/blob/master/Data%20Structures%20%26%20Algorithm/Experiment/Exp%205/img/5.png)


对于出现环的图对应的输出：

![](https://github.com/ZingLix/Homework/blob/master/Data%20Structures%20%26%20Algorithm/Experiment/Exp%205/img/3.png)

## 7.实验体会

拓扑排序后的结果并不唯一，但是该算法只能够找到其中一条，仍有改进的区间。
