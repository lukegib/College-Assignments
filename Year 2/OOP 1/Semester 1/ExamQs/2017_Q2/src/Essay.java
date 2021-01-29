public final class Essay extends Continuous_Assessment implements Gradable{

    int numWords;

    public Essay(String name) {
        super(name);
    }

    public int getNumWords() {
        return numWords;
    }

    public void setNumWords(int numWords) {
        this.numWords = numWords;
    }

    @Override
    public void insertPercentage(double overallPercentage) {
        setOverallPercent(overallPercentage);
    }
}
