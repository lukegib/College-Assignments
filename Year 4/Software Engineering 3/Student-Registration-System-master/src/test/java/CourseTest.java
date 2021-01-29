import org.junit.Test;
import org.joda.time.LocalDate;
import java.util.ArrayList;
import static org.junit.Assert.*;

// Unit Tests for the Course Class

public class CourseTest {

    // Initialize a new Course object
    private Course c = new Course("Test Course", "TC101", "John Doe", 1, 9, 12);

    @Test
    public void testName(){
         String expectedName = "Test Course";

         // testing getName()
         assertEquals("Fail - Course did not return the expected name", expectedName, c.getName());

         c.setName("Changed Course");
         expectedName = "Changed Course";

         // testing setName()
         assertEquals("Fail - Course did not set the name correctly", expectedName, c.getName());
    }

    @Test
    public void testId(){
        String expectedId = "TC101";

        // testing getId()
        assertEquals("Fail - Course did not return the expected id", expectedId, c.getId());

        c.setId("CC201");
        expectedId = "CC201";

        // testing setId()
        assertEquals("Fail - Course did not set the id correctly", expectedId, c.getId());
    }

    @Test
    public void testCoordinator(){
        String expectedCoord = "John Doe";

        // testing getCoordinator()
        assertEquals("Fail - Course did not return the expected coordinator", expectedCoord, c.getCoordinator());

        c.setCoordinator("Sue Smith");
        expectedCoord = "Sue Smith";

        // testing setCoordinator()
        assertEquals("Fail - Course did not set the coordinator correctly", expectedCoord, c.getCoordinator());
    }

    @Test
    public void duration(){
        int expectedDuration = 12;

        // testing getDuration()
        assertEquals("Fail - Course did not return the expected duration", expectedDuration, c.getDuration());

        c.setDuration(24);
        expectedDuration = 24;

        // testing setDuration()
        assertEquals("Fail - Course did not set the duration correctly", expectedDuration, c.getDuration());

    }

    @Test
    public void testStart(){
        int expectedYear = LocalDate.now().getYear();
        LocalDate expectedStart = new LocalDate(expectedYear, 9, 1);

        // testing getStart()
        assertEquals("Fail - Course did not return the expected start date", expectedStart, c.getStart());

        expectedStart = new LocalDate(2050, 1, 1);
        c.setStart(expectedStart);

        // testing setStart() - LocalDate Option
        assertEquals("Fail - Course did not set the start date correctly", expectedStart, c.getStart());

        c.setStart(2050, 1, 1);

        // testing setStart() - Year, Month, Day Option
        assertEquals("Fail - Course did not set the start date correctly", expectedStart, c.getStart());

    }

    @Test
    public void testEnd(){
        int expectedYear = LocalDate.now().plusMonths(12).getYear();
        LocalDate expectedEnd = new LocalDate(expectedYear, 9, 1);

        // testing getEnd()
        assertEquals("Fail - Course did not return the expected end date", expectedEnd, c.getEnd());

        c.setStart(2050, 1, 1);
        expectedEnd = new LocalDate(2051, 1, 1);

        // testing that setStart() alters End correctly
        assertEquals("Fail - Course did not set the end date correctly", expectedEnd, c.getEnd());

        expectedEnd = new LocalDate(2052, 1, 1);
        c.setDuration(24);

        // testing that setDuration() sets the End correctly
        assertEquals("Fail - Course did not set the end date correctly", expectedEnd, c.getEnd());

    }

    @Test
    public void testModules(){
        ArrayList<Module> expectedModules = new ArrayList<>();

        // testing getModules()
        assertEquals("Fail - Course did not return the expected modules", expectedModules, c.getModules());

        Module m = new Module("Test Module", "T101", "John Doe");
        expectedModules.add(m);

        c.addModule(m);

        // testing addModule()
        assertEquals("Fail - Course did not add the module correctly", expectedModules, c.getModules());

        expectedModules.remove(m);
        c.removeModule(m);

        // testing removeModule()
        assertEquals("Fail - Course did not remove the module correctly", expectedModules, c.getModules());
    }

    @Test
    public void testStudents(){
        ArrayList<Student> expectedStudents = new ArrayList<>();

        // testing getStudents()
        assertEquals("Fail - Course did not return the expected students", expectedStudents, c.getStudents());

        Student s = new Student("John Doe", 2000, 1, 1);
        expectedStudents.add(s);

        c.enrollStudent(s);

        // testing enrollStudent()
        assertEquals("Fail - Course did not add the student correctly", expectedStudents, c.getStudents());

        expectedStudents.remove(s);
        c.unenrollStudent(s);

        // testing unenrollStudent()
        assertEquals("Fail - Course did not remove the student correctly", expectedStudents, c.getStudents());
    }
}