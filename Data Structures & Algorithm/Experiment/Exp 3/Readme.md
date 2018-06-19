## 1. 需求分析

利用二叉搜索树实现一个 TreeSet ，并实现迭代器。

## 2. 相关知识及技术分析

二叉搜索树的插入与寻找

## 3. 系统架构设计

TreeSet 底层是一个二叉搜索树，所以实现二叉搜索树后调用其接口即可。

在二叉搜索树中，每个节点都有个指向前一个和后一个的指针，还有个头结点标记树的开始与结束。

## 4. 功能模块设计

树节点,记录左右结点、父节点以及迭代中前后结点。

``` java
private class _tree_node {
    _tree_node(){
    left=right= parent=null;
    }

    _tree_node(Value data) {
    value = data;
    left = right = parent = prev = next = null;
    }

    _tree_node left;
    _tree_node right;
    _tree_node parent;
    _tree_node prev;
    _tree_node next;
    Value value;
}
```

查找结点。根据二叉树性质找到给定值所在的结点。

``` java
_tree_node find_node(Value val){
    _tree_node it=root();
    while(it!=null) {
        if (val.compareTo(it.value) < 0) {
            it = it.left;
        } else if (val.compareTo(it.value) > 0) {
            it = it.right;
        } else {
            break;
        }
    }
    return it;
}
```


插入新元素。先根据二叉树性质找到要插入的位置，添加新节点，并修改相对应的指针。

``` java
void insert(Value val) {
    _tree_node tmp = new _tree_node(val);
    _tree_node it = root();
    _tree_node it2 = header;
    while (it != null) {
        it2=it;
        if (val.compareTo(it.value) <0){
            it = it.left;
        }else if(val.compareTo(it.value)>=0){
            it=it.right;
        }
    }
    if(it2==header){
        header.parent=tmp;
        header.left=tmp;
        header.right=tmp;
    }
    else if(val.compareTo(it2.value)<0){
        it2.left=tmp;
    }else{
        it2.right=tmp;
    }
    tmp.parent=it2;
    if(tmp==leftmost()) header.left=tmp;
    if(tmp==rightmost()) header.right=tmp;
    update_link(tmp);
}
```

移除元素。找到对应结点后将其删除，并修改对应指针。

``` java
void remove(Value val) {
    _tree_node node = find_node(val);
    if (node == null) return;
    _tree_node next;
    if (node.left == null) next = node.right;
    else if (node.right == null) next = node.left;
    else next = node.next;
    if (node == node.parent.left) {
        node.parent.left = next;
    } else {
        node.parent.right = next;
    }
    if(next!=null) {
        if(next.parent.left==next) next.parent.left=null;
        else next.parent.right=null;
        next.left = node.left;
        next.right = node.right;
        next.prev=node.prev;
        node.prev.next=next;
    }
    if(header.left==node) header.left=leftmost();
}
```

迭代器。利用对应的指针完成移动。

``` java
class TreeIterator implements Iterator<Value>{
    _tree_node cur;
    TreeIterator(){
        cur=header.left;
    }
    public Value next(){
        Value tmp=cur.value;
        cur=cur.next;
        return tmp;
    }
    public boolean hasNext(){
        return cur!=header;
    }
    public void remove(){

    }
}

public Iterator<Value> iterator(){
        return new TreeIterator();
}
```

在实现了二叉搜索树后，TreeSet转调用其接口即可。

``` java
public class TreeSet<Value extends Comparable<Value>> implements Iterable<Value>  {
    MyTree<Value> t;

    TreeSet(){
        t=new MyTree<>();
    }

    public void insert(Value val){
        t.insert_unique(val);
    }

    public void remove(Value val){
        t.remove(val);
    }

    @Override
    public Iterator<Value> iterator() {
        return t.iterator();
    }
}
```

## 5. 系统界面设计

？？？？

## 6. 系统测试

测试代码。其中用迭代器完成所有元素的遍历并输出，并测试插入和删除功能。

``` java
public static void main(String[] args) {
    TreeSet<Integer> tree=new TreeSet<>();
    tree.insert(7);
    tree.insert(19);
    tree.insert(12);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.insert(17);
    Iterator<Integer> it=tree.iterator();
    System.out.print("After insert:");
    while (it.hasNext()){
        System.out.print(it.next()+" ");
    }
    System.out.println();
    tree.remove(4);
    tree.remove(12);
    tree.remove(99);
    it=tree.iterator();
    System.out.print("After remove:");
    while (it.hasNext()){
        System.out.print(it.next()+" ");
    }
    System.out.println();
}
```

测试结果：

![](https://github.com/ZingLix/Homework/blob/master/Data%20Structures%20%26%20Algorithm/Experiment/Exp%203/img/1.png)