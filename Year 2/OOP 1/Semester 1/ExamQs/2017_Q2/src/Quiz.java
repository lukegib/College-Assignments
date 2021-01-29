public final class Quiz extends Continuous_Assessment{

    String type;

    public Quiz(String name, String type) {
        super(name);
        this.type = type;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
}
