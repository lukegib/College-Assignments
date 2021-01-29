public class Student {

    String fname;
    String lname;
    long id;
    int year;

    public Student(String fname, String lname, long id) {
        this.fname = fname;
        this.lname = lname;
        this.id = id;
    }

    public String toString(){
        return (fname + " " + lname + " " + id + "\n");
    }
}
