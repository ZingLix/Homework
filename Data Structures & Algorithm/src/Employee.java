public class Employee implements Show{


    public Employee(String emp_no,float salary){
        this.emp_no=emp_no;
        this.salary=salary;
    }

    public String getEmp_no() {
        return emp_no;
    }

    public void setEmp_no(String emp_no){
        this.emp_no=emp_no;
    }

    public float getSalary(){
        return salary;
    }

    public void setSalary(float salary){
        this.salary=salary;
    }

    public void show(){
        System.out.println("Number: "+emp_no);
        System.out.println("Salary:"+salary);
    }

    private String emp_no;
    private float salary;
}
