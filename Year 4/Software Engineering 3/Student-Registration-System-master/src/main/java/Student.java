import org.joda.time.LocalDate;
import org.joda.time.Period;
import java.util.ArrayList;

public class Student {

    //
    // Local Variables
    //

    private String name;
    private String username;
    private LocalDate DOB;
    private int age;

    static long count = 0;
    private long id;

    private ArrayList<Course> courses = new ArrayList<>();
    private ArrayList<Module> modules = new ArrayList<>();

    //
    // Constructor
    //

    public Student(String name, int birthYear, int birthMonth, int birthDay){
        this.name = name;

        this.DOB = new LocalDate(birthYear, birthMonth, birthDay);

        // Get age by calculating the difference between now and the DOB
        Period p = new Period(this.DOB, LocalDate.now());
        setAge(p.getYears());

        // Set the default Username to name+age
        setUsername(name + getAge());

        // Set the ID by incrementing the static count variable
        count++;
        id = count;
    }

    //
    // Methods to Add and Remove Courses / Modules
    //
    // Note: These should not be directly accessed - only done so through Course methods
    //

    public void addCourse(Course c){
        if(!courses.contains(c)) {
            courses.add(c);
        }
    }

    public void removeCourse(Course c){
        courses.remove(c);
    }

    public void addModule(Module m){
        if(!modules.contains(m)){
            modules.add(m);
        }
    }

    public void removeModule(Module m) {
        modules.remove(m);
    }

    //
    // Getters and Setters
    //

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        // Remove any whitespaces from the entered string
        this.username = username.replaceAll("\\s+","");
    }

    public LocalDate getDOB() {
        return DOB;
    }

    public void setDOB(LocalDate DOB) {
        this.DOB = DOB;

        // Set the age using the same technique as constructor
        Period p = new Period(this.DOB, LocalDate.now());
        this.setAge(p.getYears());
    }

    public void setDOB(int year, int month, int day){
        DOB = new LocalDate(year, month, day);

        // Set the age using the same technique as constructor
        Period p = new Period(this.DOB, LocalDate.now());
        this.setAge(p.getYears());
    }

    public int getAge() {
        return age;
    }

    private void setAge(int age) {
        this.age = age;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public ArrayList<Course> getCourses() {
        return courses;
    }

    public ArrayList<Module> getModules() {
        return modules;
    }
}
