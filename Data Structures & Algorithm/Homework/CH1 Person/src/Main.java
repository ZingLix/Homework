public class Main {

    public static void main(String[] args) {
        Employee emp=new Employee("288",5000);
        Person<Employee> employeePerson=new Person<>();
        employeePerson.setInfo(emp);
        employeePerson.show();

        Students stu=new Students("999","CS");
        Person<Students> studentsPerson=new Person<>();
        studentsPerson.setInfo(stu);
        studentsPerson.show();
    }
}
