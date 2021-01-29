public abstract class Exam_Based_Assessment extends Assessment implements Gradable{

    String examDate;
    String location;
    float duration;

    public Exam_Based_Assessment(String name) {
        super(name);
    }

    public String getExamDate() {
        return examDate;
    }

    public void setExamDate(String examDate) {
        this.examDate = examDate;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public float getDuration() {
        return duration;
    }

    public void setDuration(float duration) {
        this.duration = duration;
    }

    public void insertPercentage(double overallPercentage) {
        setOverallPercent(overallPercentage);
    }
}
