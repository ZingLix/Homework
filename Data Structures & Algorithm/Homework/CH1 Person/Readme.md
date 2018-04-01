# Requirement

1. Define a generic class Person with the following members:
    * Private data member info with generic  data type T
    * Member function:
        + public Person(T info)   // constructor
        + public  void  setInfo( T info)
        + public T  getInfo()
        + public static method: show()  //print info   

 2. Define a class Employee with the following members:
    * data member: 
        + private String emp_no
        + private float salary
       member function:
    * public Employee(emp_no, salary)   // constructor
    * getter and setter methods for emp_no
    * getter and setter methods for salary         

3. Define a class Students with the following members: 
    * data member: 
        + private String stu_no
        + private String major
    * member function:
        + public Student(stu_no, major)   // constructor
        + getter and setter methods for stu_no
        + getter and setter methods for major  

4. Define a main function to test the generic class   
    1. new a Person by using Employee data type  and call it’s show() method.
    2. new a Person object by using Students data type and call it’s show() method.
    3.  Compare its result.  
