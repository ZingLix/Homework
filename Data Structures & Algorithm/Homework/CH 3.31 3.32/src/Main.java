public class Main {

    public static class tmp{

        public int x;
    }

    public static void main(String[] args) {
        Stack<tmp> s=new Stack<>();
        tmp t=new tmp();
        t.x=44;
        s.push(t);
        t.x=66;
        System.out.print(s.pop().x);
    }

}
