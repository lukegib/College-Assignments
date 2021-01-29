import java.util.ArrayList;
import org.joda.time.LocalDate;

// The Course class is the core of the registration system the other classes (Student & Module) work through it.
// Students and Modules are added to the Course which in turn handles adding the student to the module and vice versa.

public class Course {

    //
    // Local Variables
    //

    private String name;
    private String id;
    private String coordinator;
    private int duration;

    private LocalDate start;
    private LocalDate end;

    private ArrayList<Module> modules = new ArrayList<>();
    private ArrayList<Student> students = new ArrayList<>();

    //
    // Constructor
    //

    public Course(String name, String id, String coordinator, int startDay, int startMonth, int duration) {
        this.name = name;
        this.id = id;
        this.coordinator = coordinator;
        this.duration = duration;

        int thisYear = LocalDate.now().getYear();

        setStart(thisYear, startMonth, startDay);
    }

    //
    // Methods to Add and Remove Modules / Students
    //

    public void addModule(Module m){
        if(!modules.contains(m)) {
            modules.add(m);

            // Add the Course to the Module
            m.addCourse(this);

            // Enroll each Student in the Module
            for (Student s : students) {
                s.addModule(m);
                m.enrollStudent(s);
            }
        }
    }

    public void removeModule(Module m){
        if(modules.contains(m)) {
            modules.remove(m);

            // Remove the Course from the Module object
            m.removeCourse(this);

            // Unenroll each of the Courses Students from the Module
            for (Student s : students) {
                s.removeModule(m);
                m.unenrollStudent(s);
            }
        }
    }

    public void enrollStudent(Student s){
        if(!students.contains(s)) {
            students.add(s);

            // Add the Course to the Student
            s.addCourse(this);

            // Enroll the Student in the Courses Modules
            for (Module m : modules) {
                m.enrollStudent(s);
                s.addModule(m);
            }
        }
    }

    public void unenrollStudent(Student s){
        if(students.contains(s)) {
            students.remove(s);

            // Remove the Course from the Student object
            s.removeCourse(this);

            // Unenroll the Student from the Courses Modules
            for (Module m : modules) {
                m.unenrollStudent(s);
                s.removeModule(m);
            }
        }
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

    public String getCoordinator() {
        return coordinator;
    }

    public void setCoordinator(String coordinator) {
        this.coordinator = coordinator;
    }

    public int getDuration(){
        return duration;
    }

    public void setDuration(int duration){
        this.duration = duration;

        // Set the end to represent the new Course duration
        setEnd(getStart().plusMonths(duration));
    }

    public LocalDate getStart() {
        return start;
    }

    public void setStart(LocalDate start) {
        this.start = start;

        // Set the end to represent the new Course starting date
        setEnd(start.plusMonths(duration));
    }

    public void setStart(int year, int month, int day){
        start = new LocalDate(year, month, day);

        // Set the end to represent the new Course starting date
        setEnd(start.plusMonths(duration));
    }

    public LocalDate getEnd() {
        return end;
    }

    private void setEnd(LocalDate end) {
        this.end = end;
    }

    public ArrayList<Module> getModules() {
        return modules;
    }

    public ArrayList<Student> getStudents() {
        return students;
    }
}
