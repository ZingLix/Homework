public class Students implements Show{
    public Students(){}
    public Students(String stu_no,String major){
        this.stu_no=stu_no;
        this.major=major;
    }

    public String getMajor() {
        return major;
    }

    public String getStu_no() {
        return stu_no;
    }

    public void setStu_no(String stu_no){
        this.stu_no=stu_no;
    }

    public void setMajor(String major){
        this.major=major;
    }

    public void show(){
        System.out.println("Number: "+stu_no);
        System.out.println("Major: "+major);
    }

    private String stu_no;
    private String major;
}
