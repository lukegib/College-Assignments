import java.util.ArrayList;

public class Module {

    //
    // Local Variables
    //

    private String name;
    private String id;
    private String teacher;

    private ArrayList<Student> students = new ArrayList<>();
    private ArrayList<Course> courses = new ArrayList<>();

    //
    // Constructor
    //

    public Module(String name, String id, String teacher){
        this.name = name;
        this.id = id;
        this.teacher = teacher;
    }

    //
    // Methods to Add and Remove Courses / Students
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

    public void enrollStudent(Student s){
        if(!students.contains(s)) {
            students.add(s);
        }
    }

    public void unenrollStudent(Student s){
            students.remove(s);
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

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getTeacher() {
        return teacher;
    }

    public void setTeacher(String teacher) {
        this.teacher = teacher;
    }

    public ArrayList<Student> getStudents() {
        return students;
    }

    public ArrayList<Course> getCourses() {
        return courses;
    }
}
