public class Letter {

    String county;

    public Letter(String county) {
        this.county = county;
    }

    public String getCounty() {
        return county;
    }

    public void setCounty(String county) {
        this.county = county;
    }

    @Override
    public String toString() {
        return "Letter{" +
                "county='" + county + '\'' +
                '}';
    }
}
