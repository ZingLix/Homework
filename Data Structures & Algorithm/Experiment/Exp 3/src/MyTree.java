import java.util.Iterator;

public class MyTree<Value extends Comparable<Value>> implements Iterable<Value> {
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

    _tree_node header;
    int node_count;

    private _tree_node min(_tree_node node){
        _tree_node tmp=node;
        while(node!=null){
            tmp=node;
            node=node.left;
        }
        return tmp;
    }

    private _tree_node max(_tree_node node){
        _tree_node tmp=node;
        while(node!=null){
            tmp=node;
            node=node.right;
        }
        return tmp;
    }

    _tree_node predesssor(_tree_node node){
        if(node.left!=null) return max(node.left);
        _tree_node y=node.parent;
        while(y!=header&&y.left==node){
            node=y;
            y=y.parent;
        }
        return y;
    }

    _tree_node successor(_tree_node node){
        if(node.right!=null) return min(node.right);
        _tree_node y=node.parent;
        while(y!=header&&y.right==node){
            node=y;
            y=y.parent;
        }
        return y;
    }

    private _tree_node root() {
        return header.parent;
    }

    MyTree() {
        header=new _tree_node();
        header.left = header.right = header;
        header.parent = null;
    }

    MyTree(Value val) {
        header=new _tree_node();
        header.left = header.right = header.parent = new _tree_node(val);
        _tree_node tmp = header.parent;
        tmp.parent = header;
    }

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

    _tree_node leftmost(){
        _tree_node it=root();
        while(it!=null&&it.left!=null) it=it.left;
        return it;
    }

    _tree_node rightmost(){
        _tree_node it=root();
        while(it!=null&&it.right!=null) it=it.right;
        return it;
    }

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

    void insert_unique(Value val) {
        _tree_node tmp = new _tree_node(val);
        _tree_node it = root();
        _tree_node it2 = header;
        while (it != null) {
            it2=it;
            if (val.compareTo(it.value) <0){
                it = it.left;
            }else if(val.compareTo(it.value)>0){
                it=it.right;
            }else {
                return;
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

    void update_link(_tree_node node){
        node.prev=predesssor(node);
        node.next=successor(node);
        node.prev.next=node;
        node.next.prev=node;
    }

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
        if(header.right==node) header.right=rightmost();
    }
}
