import java.util.ArrayList;

public class DisjointSet {
    public ArrayList<Integer> set;

    DisjointSet(int count){
        set=new ArrayList<>();
        for(int i=0;i<count;++i)
            set.add(i);
    }

    int getFirst(int i){
        int tmp=i;
        while(set.get(tmp)!=tmp){
            tmp=set.get(tmp);
        }
        return tmp;
    }

    void union(int i,int j){
        set.set(getFirst(j),i);
    }
}
