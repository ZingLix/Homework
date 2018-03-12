public class Person<T> {
    public Person(T info){
        this.info=info;
    }
    public void setInfo(T info){
        this.info=info;
    }
    public T getInfo(){
        return info;
    }
    public static void show(){
        System.out.println("info");
    }


    private T info;
}

