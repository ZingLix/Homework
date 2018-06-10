import java.util.*;

public class Main {


    public static void addLine(ArrayList<point> arr,int idx1,int idx2,ArrayList<line> lineArr){
        point p1=arr.get(idx1),p2=arr.get(idx2);
        float k = (p2.y-p1.y)/(p2.x-p1.x);
        float b=p1.y-k*p1.x;
        lineArr.add(new line(k,b,p1,p2));
    }

    public static void printLine(ArrayList<line> arr,int first,int last){
        HashSet<point> set=new HashSet<>();
        for(int i=first;i<=last;++i){
            set.add(arr.get(i).p1);
            set.add(arr.get(i).p2);
        }
        Iterator<point> it= set.iterator();
        while(it.hasNext()){
            point p=it.next();
            System.out.print("("+p.x+","+p.y+")");
        }
        System.out.println();
    }

    public static void process(ArrayList<point> arr){
        ArrayList<line> lineArrayList=new ArrayList<>();
        for(int i=0;i<arr.size();++i){
            for(int j=i+1;j<arr.size();++j){
                addLine(arr,i,j,lineArrayList);
            }
        }
        Collections.sort(lineArrayList);
        int j=0;
        line ex=lineArrayList.get(0);
        for(int i=1;i<lineArrayList.size();++i){
            if(lineArrayList.get(i).compareTo(lineArrayList.get(i-1))==0){
                j++;
            }else {
                if(j>=4)
                    printLine(lineArrayList,i-j,i-1);
                j=0;
            }
        }
        if(j>=4)
            printLine(lineArrayList,lineArrayList.size()-j,lineArrayList.size()-1);
    }

    public static void main(String[] args) {
        ArrayList<point> arr=new ArrayList<>(100);
        arr.add(new point(3,3));
        arr.add(new point(6,4));
        arr.add(new point(5,5));
        arr.add(new point(1,3));
        arr.add(new point(9,9));
        arr.add(new point(4,6));
        arr.add(new point(3,7));
        arr.add(new point(4,3));
        arr.add(new point(8,8));
        arr.add(new point(9,3));
        arr.add(new point(13,13));
        arr.add(new point(3,2));
        process(arr);
    }

}
