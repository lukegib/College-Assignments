import java.util.ArrayList;

public class Driver {

    public static void main(String[] args){

        // Create Students
        Student phoebe = new Student("Phoebe Buffay", 1965, 2, 16);
        Student ross = new Student("Ross Geller", 1967, 10, 18);
        Student monica = new Student("Monica Geller", 1969, 4, 2);
        Student joey = new Student("Joey Tribbiani", 1967, 1, 10);
        Student rachel = new Student("Rachel Green", 1969, 5, 5);
        Student chandler = new Student("Chandler Bing", 1968, 4, 12);

        // Create Modules
        Module french = new Module("French", "FR101", "Pierre Gasly");
        Module spanish = new Module("Spanish", "SP101", "Sergio Ramos");
        Module english = new Module("English", "EN101", "Lewis Hamilton");
        Module math = new Module("Mathematics", "MA101", "Leonardo da Vinci");
        Module science = new Module("Science", "SC101", "David Attenborough");
        Module business = new Module("Business", "BS101", "Steve Jobs");

        // Create Courses
        Course language = new Course("Languages", "L100", "Sergio Ramos", 1, 10, 12);
        Course comp_sci = new Course("Computer Science", "CS100", "Alan Turing", 1, 9, 24);
        Course general = new Course("General", "G100", "Leonardo Da Vinci", 1, 1, 6);

        // Add Courses to an ArrayList
        ArrayList<Course> courses = new ArrayList<>();
        courses.add(language);
        courses.add(comp_sci);
        courses.add(general);

        // Add Modules to the Courses
        language.addModule(french);
        language.addModule(spanish);
        language.addModule(english);

        comp_sci.addModule(math);
        comp_sci.addModule(science);

        general.addModule(french);
        general.addModule(math);
        general.addModule(science);
        general.addModule(business);

        // Add Students to the Courses
        language.enrollStudent(phoebe);
        language.enrollStudent(joey);

        comp_sci.enrollStudent(ross);
        comp_sci.enrollStudent(chandler);
        comp_sci.enrollStudent(rachel);

        general.enrollStudent(rachel);
        general.enrollStudent(monica);

        // Print out data for each Course in the ArrayList
        for(Course c: courses){
            String format = "%-20s%s%n";
            ArrayList<Module> courseModules = c.getModules();
            ArrayList<Student> courseStudents = c.getStudents();

            System.out.println("\n---------------------------------------------------------------------------------\n");
            System.out.println("****** " + c.getName() + " Course ******\n");
            System.out.printf(format, "ID:", c.getId());
            System.out.printf(format, "Coordinator: ", c.getCoordinator());
            System.out.print("\n");
            System.out.println("* Modules *");

            // Print data for each Module (name, id, teacher)
            for(Module m: courseModules){
                System.out.print("\n");
                System.out.printf(format, "Name: ", m.getName());
                System.out.printf(format, "ID: ", m.getId());
                System.out.printf(format, "Taught by: ", m.getTeacher());
            }

            System.out.print("\n");
            System.out.println("* Students *");

            // Print data for each Student (name, username, modules, courses)
            for(Student s: courseStudents){
                StringBuilder str = new StringBuilder();
                ArrayList<Module> stuModules = s.getModules();
                ArrayList<Course> stuCourses = s.getCourses();

                System.out.print("\n");
                System.out.printf(format, "Name: ", s.getName());
                System.out.printf(format, "Username: ", s.getUsername());

                for(Module m: stuModules){
                    str.append(m.getName()).append(", ");
                }

                // Remove final comma from string
                String newStr = str.substring(0, str.length() - 2);
                System.out.printf(format, "Modules: ", newStr);

                str.setLength(0);
                for(Course cs: stuCourses){
                    str.append(cs.getName()).append(", ");
                }

                // Remove final comma from string
                newStr = str.substring(0, str.length() - 2);
                System.out.printf(format, "Course(s): ", newStr);
            }
        }

        System.out.println("\n---------------------------------------------------------------------------------");
    }

}
