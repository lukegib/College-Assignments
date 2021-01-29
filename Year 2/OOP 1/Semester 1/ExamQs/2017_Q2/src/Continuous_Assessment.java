public abstract class Continuous_Assessment extends Assessment {

    String date;

    public Continuous_Assessment(String name) {
        super(name);
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }
}
