import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        int upperLimit = 100;
        int k = 3;

        ArrayList<Integer> data = new ArrayList<>();

        System.out.print("原始数据：");
        for (int i = 0; i < 10; i++) {
            data.add((int) (Math.random() * upperLimit));
            System.out.print(data.get(i) + " ");
        }
        System.out.println();

        int k1 = Selection.Select1(data, k);
        int k2 = Selection.Select2(data, k);

        System.out.println("第" + k + "大：" + k1 + "  " + k2 + "  \n");

    }
}
