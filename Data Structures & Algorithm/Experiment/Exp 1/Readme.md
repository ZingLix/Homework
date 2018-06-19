## 1. 需求分析

给定两个排好序的链表L1和L2，用基本的链表操作计算得到两个链表的交集与并集。

## 2. 相关知识和技术分析

链表及迭代器

## 3. 系统架构设计

利用两个链表的迭代器，由于给定的链表元素是确定顺序的，所以迭代器每次增加得到的元素有序，那么只要两个迭代器依次迭代，每次使指向较小元素的迭代器增加，便可以确定顺序的方式遍历所有的元素。

从而，对于交集，如果两个迭代器所指相同，说明该元素两个链表中都有，加入到结果中。对于并集，因为是以有序的顺序遍历，那么相同的元素必定一同出现，只要判断结果中最后一个是否与现在的元素相同，就可确定该元素是否已加入到结果中。

## 4. 功能模块设计

共分为两个部分，分别完成交集和并集的功能。传入两个链表，返回一个链表，记录传入的两个链表计算后的结果。

交集：

``` java
public static<T extends Comparable<T>> LinkedList<T> intersection(LinkedList<T> l1,LinkedList<T> l2){
    LinkedList<T> result=new LinkedList<>();
    Iterator<T> it1=l1.iterator();
    Iterator<T> it2=l2.iterator();
    T cur1=it1.next(),cur2=it2.next();
    boolean flag=true;
    if(cur1.compareTo(cur2)>0){
    flag=false;
    }else if(cur1.compareTo(cur2)==0){
    result.add(cur1);
    }
    while(it1.hasNext()&&it2.hasNext()){
    if(flag) cur1 = it1.next();
    else cur2 = it2.next();
    if(cur1.compareTo(cur2)==0){
        result.add(cur1);
    }else if(cur1.compareTo(cur2)>0){
        flag=false;
    }else{
        flag=true;
    }
    }
    return result;
}
```

并集：

``` java
public static <T extends Comparable<T>> LinkedList<T> union(LinkedList<T> l1,LinkedList<T> l2){
    LinkedList<T> result=new LinkedList<>();
    Iterator<T> it1=l1.iterator();
    Iterator<T> it2=l2.iterator();
    T cur1=it1.next(),cur2=it2.next();
    boolean flag=true;
    if(cur1.compareTo(cur2)>0){
    flag=false;
    }
    result.add(cur1);
    while(it1.hasNext()||it2.hasNext()){
    if(flag) cur1 = it1.next();
    else cur2 = it2.next();
    if(cur1.compareTo(cur2)==0){
    }else if(cur1.compareTo(cur2)>0){
        flag=false;
        if(cur2!=result.getLast())
        result.add(cur2);
    }else{
        flag=true;
        if(cur1!=result.getLast())
        result.add(cur1);
    }
    }
    if(result.getLast()==cur1) result.add(cur2);
    else result.add(cur1);
    return result;
}
```

## 5. 系统界面设计

？？？？没有界面

## 6. 系统测试

测试代码：

``` java
public static void main(String[] args) {
    LinkedList<Integer> a=new LinkedList<Integer>();
    LinkedList<Integer> b=new LinkedList<Integer>();
    a.add(3);
    a.add(6);
    a.add(9);
    a.add(12);
    a.add(15);
    a.add(18);
    a.add(56);

    b.add(3);
    b.add(7);
    b.add(8);
    b.add(9);
    b.add(18);
    b.add(44);

    System.out.print("List A: ");
    ListIterator<Integer> it=a.listIterator();
    while(it.hasNext()) System.out.print(it.next()+"  ");
    System.out.println();

    System.out.print("List B: ");
    it=b.listIterator();
    while(it.hasNext()) System.out.print(it.next()+"  ");
    System.out.println();

    System.out.print("Intersection: ");
    LinkedList<Integer> ans=intersection(a,b);
    it=ans.listIterator();
    while(it.hasNext()) System.out.print(it.next()+"  ");
    System.out.println();

    System.out.print("Union: ");
    ans=union(a,b);
    it=ans.listIterator();
    while(it.hasNext()) System.out.print(it.next()+"  ");
    System.out.println();
}
```

运行结果：

![](/img/1.png)

