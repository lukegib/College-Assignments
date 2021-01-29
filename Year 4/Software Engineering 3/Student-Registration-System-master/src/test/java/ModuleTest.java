import org.junit.Test;
import java.util.ArrayList;
import static org.junit.Assert.*;

// Unit Tests for the Student Class

public class ModuleTest {

    // Initialize a new Module object
    private Module m = new Module("Spanish", "S101", "Juan Lopez");

    @Test
    public void testName(){
        String expectedName = "Spanish";

        // testing getName()
        assertEquals("Fail - Module did not return the expected name", expectedName, m.getName());

        m.setName("French");
        expectedName = "French";

        // testing setName()
        assertEquals("Fail - Module did not set the name correctly", expectedName, m.getName());
    }

    @Test
    public void testId(){
        String expectedId = "S101";

        // testing getId()
        assertEquals("Fail - Module did not return the expected id", expectedId, m.getId());

        m.setId("F101");
        expectedId = "F101";

        // testing setId()
        assertEquals("Fail - Module did not set the id correctly", expectedId, m.getId());
    }

    @Test
    public void testTeacher(){
        String expectedTeacher = "Juan Lopez";

        // testing getTeacher()
        assertEquals("Fail - Module did not return the expected teacher", expectedTeacher, m.getTeacher());

        m.setTeacher("Jean Martin");
        expectedTeacher = "Jean Martin";

        // testing setTeacher()
        assertEquals("Fail - Module did not set the teacher correctly", expectedTeacher, m.getTeacher());
    }

    @Test
    public void testCourse(){
        ArrayList<Course> expectedCourses = new ArrayList<>();

        // testing getCourses()
        assertEquals("Fail - Module did not return the expected course(s)", expectedCourses, m.getCourses());

        Course c = new Course("Test Course", "1001", "John Doe", 1, 9, 3);
        expectedCourses.add(c);

        m.addCourse(c);

        // testing addCourse()
        assertEquals("Fail - Module did not add the course correctly", expectedCourses, m.getCourses());

        expectedCourses.remove(c);
        m.removeCourse(c);

        // testing removeCourse()
        assertEquals("Fail - Module did not remove the course correctly", expectedCourses, m.getCourses());
    }

    @Test
    public void testStudents(){
        ArrayList<Student> expectedStudents = new ArrayList<>();

        // testing getStudents()
        assertEquals("Fail - Module did not return the expected students", expectedStudents, m.getStudents());

        Student s = new Student("John Doe", 2000, 1, 1);
        expectedStudents.add(s);

        m.enrollStudent(s);

        // testing enrollStudent()
        assertEquals("Fail - Module did not add the student correctly", expectedStudents, m.getStudents());

        expectedStudents.remove(s);
        m.unenrollStudent(s);

        // testing unenrollStudent()
        assertEquals("Fail - Module did not remove the student correctly", expectedStudents, m.getStudents());
    }

}