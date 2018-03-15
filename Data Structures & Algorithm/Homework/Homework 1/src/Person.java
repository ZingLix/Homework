public class Person<T extends Show> {
    public Person(){}
    public Person(T info){
        this.info=info;
    }
    public void setInfo(T info){
        this.info=info;
    }
    public T getInfo(){
        return info;
    }
    public static<Y> void show(Y y){
        System.out.println(y.getClass());
    }
    public void show(){
        info.show();
    }

    private T info;
}

