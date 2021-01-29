public class test {

    public static void main(String[] args){

        Essay Shakespeare = new Essay("Shakespeare Essay");
        Paper_Based_Exam writtenExam = new Paper_Based_Exam("2017 Exam");
        Comp_Based_Exam compExam = new Comp_Based_Exam("2017 Comp");

        Shakespeare.insertPercentage(90);
        writtenExam.insertPercentage(20);
        compExam.insertPercentage(60);

        System.out.println("Overall grade for esssy 1: " + Shakespeare.getOverallPercent());
        System.out.println("Overall grade for writtenExam 1: " + writtenExam.getOverallPercent());
        System.out.println("Overall grade for compExam 1: " + compExam.getOverallPercent());

        double OverallGrade = (Shakespeare.getOverallPercent() + writtenExam.getOverallPercent() + compExam.getOverallPercent()) / 3.0;

        System.out.println("Total Grade = " + OverallGrade);
    }
}
