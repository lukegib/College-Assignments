public class test {

    public static void main(String args[]){

        Course course = new Course("2BEE", "Bachelor of Engineering");

        Module ct2106 = new Module("CT2106", "Object Oriented Programming");
        ct2106.addDescription("This module... add own description");

        Module ee231 = new Module("EE231", "Instrument & Sensors");
        ee231.addDescription("This module... add own description");

        Module st1100 = new Module("ST1100", "Engineering Statistics");
        st1100.addDescription("This module... add own description");

        course.addModule(ct2106);
        course.addModule(ee231);
        course.addModule(st1100);

        Student student1 = new Student("Joanna", "Daly", 16223887);
        Student student2 = new Student("Kyle", "Walker", 15556773);
        Student student3 = new Student("Wyonna", "Ryder", 1787231);

        course.registerStudent(student1);
        course.registerStudent(student2);
        course.registerStudent(student3);

        System.out.println(ct2106);
    }
}
