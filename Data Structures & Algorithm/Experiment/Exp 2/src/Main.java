public class Main {

    public static void main(String[] args) {
        String[] str=new String[]{
                "(9/8+7)+(3*4/5)*(4-6*8)",
                "2+12*(6/4)",
                "(4+3*12/6-3)/7+(6/3*3+9)*(3*2)"
        };

        double[] ans=new double[]{
                -97.475,20,91
        };
        ExpressionProcessor p=new ExpressionProcessor("(9/8+7)+(3*4/5)*(4-6*8)");
      //  p.process();
        for(int i=0;i<3;++i){
            p.setExperssion(str[i]);
            double answer=p.ans();
            System.out.print(str[i]+"="+answer);
            System.out.println("       "+(Math.abs(answer-ans[i])<0.00001));

        }
        //System.out.println(p.process());
       // p.print();
    }
}
