import java.util.*;

public class Course {

    String courseCode;
    String courseName;
    private ArrayList<Module> modules = new ArrayList<>();
    private ArrayList<Student> students = new ArrayList<>();

    public Course(String courseCode, String courseName) {
        this.courseCode = courseCode;
        this.courseName = courseName;
    }


    public void addModule(Module module) {
        modules.add(module);
    }

    public void registerStudent(Student student) {
        students.add(student);
        for (Module m : modules) {
            m.registerStudent(student);
        }
    }

}
