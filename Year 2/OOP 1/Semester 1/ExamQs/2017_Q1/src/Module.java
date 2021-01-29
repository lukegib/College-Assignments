import java.util.ArrayList;

public class Module {

    String modCode;
    String modName;
    String description;
    private ArrayList<Student> students = new ArrayList<>();

    public Module(String modCode, String modName) {
        this.modCode = modCode;
        this.modName = modName;
    }

    public void addDescription(String desc){
        description = desc;
    }

    public void registerStudent(Student student){
        students.add(student);
    }

    public String toString(){
        String str = "Module Code: " + modCode;
        str += "\nModule Name: " + modName;
        str += "\nModule Description: " + description;
        str += "\nRegistered Students: \n";
        for(Student s: students){
            str += s;
        }
        return str;
    }
}
