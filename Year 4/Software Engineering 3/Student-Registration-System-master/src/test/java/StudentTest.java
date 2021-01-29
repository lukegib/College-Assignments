import org.junit.Test;
import org.joda.time.LocalDate;
import org.joda.time.Period;
import java.util.ArrayList;
import static org.junit.Assert.*;

// Unit Tests for the Student Class

public class StudentTest {

    // Initialize a new Student object
    private Student s = new Student("John Doe", 1990, 10, 10);

    @Test
    public void testName(){
        String expectedName = "John Doe";

        // testing getName()
        assertEquals("Fail - Student did not return the expected name", expectedName, s.getName());

        s.setName("Sue Smith");
        expectedName = "Sue Smith";

        // testing setName()
        assertEquals("Fail - Student did not set the name correctly", expectedName, s.getName());
    }

    @Test
    public void testId(){
        // testing getId() - make sure it increments
        assertNotEquals("Fail - Student did not return the expected id", 0, s.getId());

        int expectedId = 1000;
        s.setId(1000);

        // testing setId()
        assertEquals("Fail - Student did not set the id correctly", expectedId, s.getId());
    }

    @Test
    public void testDOB(){
        LocalDate expectedDOB = new LocalDate(1990, 10, 10);

        // testing getDOB()
        assertEquals("Fail - Student did not return the expected DOB", expectedDOB, s.getDOB());

        expectedDOB = new LocalDate(2000, 1, 1);
        s.setDOB(expectedDOB);

        // testing setDOB() - LocalDate Option
        assertEquals("Fail - Student did not set the DOB correctly", expectedDOB, s.getDOB());

        s.setDOB(2000, 1, 1);

        // testing setDOB() - Year, Month, Day Option
        assertEquals("Fail - Student did not set the DOB correctly", expectedDOB, s.getDOB());
    }

    @Test
    public void testAge(){
        Period p = new Period(s.getDOB(), LocalDate.now());
        int expectedAge = p.getYears();

        // testing getAge()
        assertEquals("Fail - Student did not return the expected age", expectedAge, s.getAge());
    }

    @Test
    public void testUsername(){
        String expectedUsername = "JohnDoe" + s.getAge();

        // testing getUsername()
        assertEquals("Fail - Student did not return the expected age", expectedUsername, s.getUsername());

        expectedUsername = "test123";
        s.setUsername("t est 123");

        // testing setUsername()
        assertEquals("Fail - Student did not set the username correctly", expectedUsername, s.getUsername());
    }

    @Test
    public void testCourse(){
        ArrayList<Course> expectedCourses = new ArrayList<>();

        // testing getCourses()
        assertEquals("Fail - Course did not return the expected course(s)", expectedCourses, s.getCourses());

        Course c = new Course("Test Course", "1001", "John Doe", 1, 9, 3);
        expectedCourses.add(c);

        s.addCourse(c);

        // testing addCourse()
        assertEquals("Fail - Student did not add the course correctly", expectedCourses, s.getCourses());

        expectedCourses.remove(c);
        s.removeCourse(c);

        // testing removeCourse()
        assertEquals("Fail - Student did not remove the course correctly", expectedCourses, s.getCourses());
    }

    @Test
    public void testModule(){
        ArrayList<Module> expectedModules = new ArrayList<>();

        // testing getModules()
        assertEquals("Fail - Course did not return the expected course(s)", expectedModules, s.getModules());

        Module m = new Module("Test Module", "TM101", "John Doe");
        expectedModules.add(m);

        s.addModule(m);

        // testing addModule()
        assertEquals("Fail - Student did not add the course correctly", expectedModules, s.getModules());

        expectedModules.remove(m);
        s.removeModule(m);

        // testing removeModule()
        assertEquals("Fail - Student did not remove the course correctly", expectedModules, s.getModules());
    }
}