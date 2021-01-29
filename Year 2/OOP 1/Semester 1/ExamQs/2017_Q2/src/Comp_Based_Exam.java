public final class Comp_Based_Exam extends Exam_Based_Assessment{

    String platform;

    public Comp_Based_Exam(String name) {
        super(name);
    }

    public String getPlatform() {
        return platform;
    }

    public void setPlatform(String platform) {
        this.platform = platform;
    }
}
