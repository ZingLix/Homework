import java.util.ArrayList;
import java.util.Collections;

public class Main {

    public static void main(String[] args) {
        int upperLimit = 1000000;
        int k = 3;

        ArrayList<Integer> data = new ArrayList<>();
        System.out.println("Size\tTime1\tTime2");
        for(Integer size=10;size<100000000;size*=10){
            // System.out.print("原始数据：");
            for (int i = 0; i < size; i++) {
                data.add((int) (Math.random() * upperLimit));
                //  System.out.print(data.get(i) + " ");
            }
            //System.out.println();
            long start = System.currentTimeMillis();
            int k1 = Selection.Select1(data, size/2);
            long end = System.currentTimeMillis();
            long time1=end-start;
            start=System.currentTimeMillis();
            int k2 = Selection.Select2(data, k);
            end= System.currentTimeMillis();
            long time2=end-start;

            System.out.println(data.size()+"\t\t"+time1+"\t\t"+time2);
           // System.out.println("第" + k + "大：" + k1 + "  Time:"+ time + "  \n");
            data.clear();
        }
    }
}
