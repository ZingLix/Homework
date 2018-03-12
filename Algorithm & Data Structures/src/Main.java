public class Main {

    public static void main(String[] args) {
        GenericMemoryCell<Integer> aaa=new GenericMemoryCell<>();
        for(int i=0;i<10;i++){
            aaa.write(i);
        }
        GenericMemoryCell<Character> bbb=new GenericMemoryCell<>();
        bbb.write('a');
        System.out.print(bbb.read());

    }
}
