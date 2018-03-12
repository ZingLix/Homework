public class Main {

    public static void main(String[] args) {
        Person<Employee> employeePerson=new Person<>(new Employee("123",3000));
        Person<Students> studentsPerson=new Person<>(new Students("35","CS"));
    }
}
