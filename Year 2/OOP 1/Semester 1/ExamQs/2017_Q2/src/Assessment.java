public abstract class Assessment {

    String name;
    String description;
    String lecturer;
    double overallPercent = 0.0;

    public Assessment(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getLecturer() {
        return lecturer;
    }

    public void setLecturer(String lecturer) {
        this.lecturer = lecturer;
    }

    public double getOverallPercent() {
        return overallPercent;
    }

    public void setOverallPercent(double overallPercent) {
        this.overallPercent = overallPercent;
    }
}
